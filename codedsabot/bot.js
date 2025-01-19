const { Telegraf, Markup } = require("telegraf");
const axios = require("axios");

const bot = new Telegraf("8115597059:AAEjQLbcBpGqO67xwkm3NXywEzhp1St-YyA");

const getCodeforcesQuestion = async (rating) => {
  try {
    const response = await axios.get(
      "https://codeforces.com/api/problemset.problems"
    );
    const problems = response.data.result.problems;
    const filteredProblems = problems.filter(
      (problem) => problem.rating === rating
    );

    if (filteredProblems.length === 0) return null;

    const randomProblem =
      filteredProblems[Math.floor(Math.random() * filteredProblems.length)];
    return {
      name: randomProblem.name,
      link: `https://codeforces.com/problemset/problem/${randomProblem.contestId}/${randomProblem.index}`,
      rating: randomProblem.rating,
    };
  } catch (error) {
    console.error("Error fetching Codeforces problem:", error);
    return null;
  }
};


bot.start((ctx) => {
  ctx.reply(
    "👋 Welcome to the Codeforces Problem Bot! 🧩\n\n" +
    "I can help you find coding problems from Codeforces. Here are my commands:\n\n" +
    "• /getcf [rating] - Get a Codeforces problem by specific rating\n" +
    "• /random - Get a random Codeforces problem\n\n" +
    "Example: /getcf 1200 or /random",
    Markup.keyboard([
      ["Get Problem by Rating", "Random Problem"],
    ]).resize()
  );
});


bot.help((ctx) => {
  ctx.reply(
    "🤖 Codeforces Problem Bot Help 🆘\n\n" +
    "Available Commands:\n" +
    "• /getcf [rating] - Fetch a Codeforces problem\n" +
    "   Usage: /getcf 1200 (gets a problem rated 1200)\n" +
    "• /random - Get a random Codeforces problem\n\n" +
    "Supported Ratings: 800, 1200, 1600, 2000\n" +
    "Choose a rating that matches your skill level!"
  );
});

bot.command("getcf", async (ctx) => {
  const args = ctx.message.text.split(" ").slice(1);
  const rating = parseInt(args[0]);
  const validRatings = [800, 1200, 1600, 2000];
  if (isNaN(rating) || !validRatings.includes(rating)) {
    return ctx.reply(
      "❌ Invalid rating! Please use one of these ratings: 800, 1200, 1600, 2000\n" +
      "Example: /getcf 1200"
    );
  }
  try {
    const problem = await getCodeforcesQuestion(rating);
    if (problem) {
      ctx.reply(
        `🧩 Codeforces Problem (Rating ${rating}):\n\n` +
        `📝 *Name*: ${problem.name}\n` +
        `⭐ *Rating*: ${problem.rating}\n` +
        `🔗 *Link*: [Solve Problem](${problem.link})`,
        { parse_mode: "Markdown" }
      );
    } else {
      ctx.reply("😓 No problems found for this rating. Try another rating!");
    }
  } catch (error) {
    console.error("Problem fetching error:", error);
    ctx.reply("🚨 An error occurred while fetching the problem. Please try again.");
  }
});

bot.command("random", async (ctx) => {
  const randomRatings = [800, 1200, 1600, 2000];
  const randomRating = randomRatings[Math.floor(Math.random() * randomRatings.length)];

  try {
    const problem = await getCodeforcesQuestion(randomRating);
    if (problem) {
      ctx.reply(
        `🎲 Random Codeforces Problem!\n\n` +
        `📝 *Name*: ${problem.name}\n` +
        `⭐ *Rating*: ${problem.rating}\n` +
        `🔗 *Link*: [Solve Problem](${problem.link})`,
        { parse_mode: "Markdown" }
      );
    } else {
      ctx.reply("😓 Couldn't fetch a random problem. Please try again.");
    }
  } catch (error) {
    console.error("Random problem error:", error);
    ctx.reply("🚨 An error occurred while fetching a random problem.");
  }
});

bot.on("new_chat_members", async (ctx) => {
  try {
    const botUsername = ctx.botInfo.username;
    const newMembers = ctx.message.new_chat_members;
    
    const isBotAdded = newMembers.some(
      member => member.username === botUsername
    );

    if (isBotAdded) {
      await ctx.reply(
        `👋 Hello! I'm the Codeforces Problem Bot\n\n` +
        `I can help you find coding problems from Codeforces:\n` +
        `• /getcf [rating] - Get a problem by rating\n` +
        `• /random - Get a random problem\n` +
        `• /help - Show available commands`
      );
    }
  } catch (error) {
    console.error("Group join handler error:", error);
  }
});

bot.catch((err, ctx) => {
  console.error(`Error for ${ctx.updateType}:`, err);
});

// Start the bot
bot.launch({
  dropPendingUpdates: true
})
.then(() => console.log("✅ Bot is running..."))
.catch((err) => console.error("❌ Bot launch failed:", err));

// Enable graceful stop
process.once('SIGINT', () => bot.stop('SIGINT'));
process.once('SIGTERM', () => bot.stop('SIGTERM'));