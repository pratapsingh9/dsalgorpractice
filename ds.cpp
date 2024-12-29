#include <bits/stdc++.h>
using namespace std;

long long sumOfDistinctCounts(const vector<int>& categories) {
  unordered_map<int, int> lastSeen;
  int start = 0;
  long long result = 0;

  for (int end = 0; end < categories.size(); ++end) {
    int current = categories[end];
    if (lastSeen.count(current) && lastSeen[current] >= start) {
      start = lastSeen[current] + 1;
    }
    lastSeen[current] = end;
    result += (end - start + 1);
  }
  return result;
}

int main() {
  vector<int> categories = {1, 2, 1};
  cout << "Output: " << sumOfDistinctCounts(categories) << endl;
  return 0;
}

vector<int> subarrayWithSUm(vector<int> nums, int target) {
  unordered_map<int, int> mp;
  int cumSum = 0;
  for (int i = 0; i < nums.size(); i++) {
    cumSum += nums[i];
    if (cumSum == target) return {0, i};
    if (mp.find(target - cumSum) != mp.end()) {
      return {mp[target - cumSum], i};
    }
    mp[cumSum] = i;
  }
  return vector<int>{};
}

bool isIsomorphic(string a, string b) {
  if (a.size() != b.size()) return false;

  unordered_map<char, char> atob, btoa;

  for (int i = 0; i < a.size(); i++) {
    char a = s[i], b = t[i];

    if (atob.count(a) !=) }
}

class Solution {
 public:
  int maximumBeauty(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int maxbeatury = 1;
    int left = 0;
    for (int i = 0; i < n; i++) {
      /* code */
      while (nums[i] - nums[left] > 2 * k) {
        left++;
      }
      maxbeatury = max(maxbeatury, i - left + 1);
    }
    return maxbeatury;
  }
};
class Solution {
 public:
  int fillCups(vector<int>& amount) {
    sort(amount.begin(), amount.end());
    if (amount[2] > amount[0] + amount[1]) return amount[2];

    return (amount[0] + amount[1] + amount[2] + 1) / 2;
  }
};

class Solution {
 public:
  int fillCups(vector<int>& amount) {
    priority_queue<int> pq;
    for (int x : amount) {
      if (x > 0) pq.push(x);
    }
    int time = 0, ;
    while (!pq.empty()) {
      int first = pq.top();
      pq.pop();
      if (!pq.empty()) {
        int second = pq.top();
        pq.pop();
        if (--first > 0) pq.push(first);
        if (--second > 0) pq.push(second);
      } else {
        if (--first > 0) pq.push(first);
      }
      time++;
    }
    return time;
  }
};

class Solution {
 public:
  bool compareOperator(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first > b.first;
  }
  int minSetSize(vector<int>& arr) {
    unordered_map<int, int> mp;
    for (int x : arr) {
      mp[x]++;
    }
    vector<pair<int, int>> vec;

    for (auto& entry : mp) {
      vec.push_back({entry.second, entry.first});
    }

    sort(vec.begin(), vec.end(), compareOperator);

    int target = arr.size() / 2;
    int answer = 0;
    int removed = 0;
    for (auto& p : vec) {
      removed += p.first;
      answer++;
      if (removed >= target) break;
    }
    return answer;
  }
};

class Solution {
 public:
  vector<int> rearrangeBarcodes(vector<int>& barcodes) {
    unordered_map<int, int> freq;
    for (int x : barcodes) {
      freq[x]++;
    }

    vector<pair<int, int>> freqvec;
    for (auto& it : freq) {
      freqvec.push_back({it.second, it.first});
    }

    sort(freqvec.begin(), freqvec.end());

    vector<int> result(barcodes.size(), 0);
    int index = 0;

    for (auto& [count, barcode] : freqvec) {
      for (int i = 0; i < count; i++) {
        /* code */
        result[index] = barcode;
        index += 2;
        if (index >= barcodes.size()) {
          index = 1;
        }
      }
    }
    return result;
  }
};

class Solution {
 public:
  typedef pair<int, string> P;
  vector<string> topKFrequent(vector<string>& words, int k) {
    if (words.empty()) return {};
    unordered_map<string, int> mp;
    for (string it : words) {
      mp[it]++;
    }
    priority_queue<P, vector<P>, greater<P>> pq;
    vector<string> result;
    for (auto it : mp) {
      pq.push({it.second, it.first});
      if (pq.size() > k) {
        pq.pop();
      }
    }
    while (!pq.empty()) {
      result.push_back(pq.top().second);
      pq.pop();
    }
    reverse(result.begin(), result.end());
    return result;
  }
};

class Solution {
 public:
  int maxProfitHelper(int day, bool canBuy, const vector<int>& prices,
                      vector<unordered_map<bool, int>>& memoDp) {
    if (day >= prices.size()) return 0;
    if (memoDp[day].count(canBuy)) return memoDp[day][canBuy];

    if (canBuy) {
      int buy = -prices[day] + maxProfitHelper(day + 1, false, prices, memoDp);
      int skip = maxProfitHelper(day + 1, true, prices, memoDp);
      memoDp[day][canBuy] = max(buy, skip);
    } else {
      int sell = prices[day] + maxProfitHelper(day + 2, true, prices, memoDp);
      int skip = maxProfitHelper(day + 1, false, prices, memoDp);
      memoDp[day][canBuy] = max(sell, skip);
    }

    return memoDp[day][canBuy];
  }

  int maxProfit(vector<int>& prices) {
    vector<unordered_map<bool, int>> memoDp(prices.size());
    return maxProfitHelper(0, true, prices, memoDp);
  }
};
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0;
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    for (int day = n - 1; day >= 0; day--) {
      dp[day][1] = max(-prices[day] + dp[day + 1][0], dp[day + 1][1]);
      dp[day][0] = max(prices[day] + day[day + 2][1], dp[day + 1][1]);
    }
    return dp[0][1];
  }
};
class Solution {
 public:
  int maximumPopulation(vector<vector<int>>& logs) {
    vector<int> popChanged(2051, 0);
    for (const auto& log : logs) {
      popChanged[log[0]]++;
      popChanged[log[1]]--;
    }
    int currentPopulation = 0, maxPopulation = 0, maxyear = 0;

    for (int year = 1950; year < 2051; year++) {
      currentPopulation += popChanged[year];
      if (currentPopulation > maxPopulation) {
        maxPopulation = currentPopulation;
        maxyear = year;
      }
    }
    return maxyear;
  }
};

class Solution {
 public:
  int numberOfPoints(vector<vector<int>>& nums) {
    vector<bool> isCovered(101, false);
    for (const auto& num : nums) {
      int start = num[0];
      int end = num[1];
      for (int i = start; i < end; i++) {
        isCovered[i] = true;
      }
    }
    int c = 0;
    for (int n : isCovered) {
      if (n) c++;
    }
    return c;
  }
};

class Solution {
 public:
  bool carPooling(vector<vector<int>>& trips, int capacity) {
    vector<int> passengerPrefix(1001, 0);
    for (const auto& query : trips) {
      int passenger = query[0];
      int start = query[1];
      int end = query[2];
      passengerPrefix[start] += passenger;
      passengerPrefix[end] -= passenger;
    }
    int currentPassenger = 0;
    for (int i = 0; i < 1001; i++) {
      currentPassenger += passengerPrefix[i];
      if (currentPassenger > capacity) return false;
    }
    return true;
  }
};

class MyCalendarTwo {
 public:
  vector<int> events;
  MyCalendarTwo() { events.resize(1000001); }

  bool book(int startTime, int endTime) {
    events[startTime] += 1;
    events[endTime] -= 1;

    int activeEvents = 0;
    for (int time = 0; time < 1000001; time++) {
      activeEvents += events[time];
      if (activeEvents > 2) {
        events[startTime] -= 1;
        events[endTime] += 1;
      }
    }
    return true;
  }
};

class Solution {
 public:
  string shiftingLetters(string s, vector<vector<int>>& shifts) {
    int n = s.size();
    vector<int> prefix(n + 1, 0);

    for (const auto& shift : shifts) {
      int start = shift[0];
      int end = shift[1];
      int direction = shift[2];
      prefix[start] += (direction == 1) ? 1 : -1;
      prefix[end + 1] += (direction == 1) ? -1 : 1;
    }

    int netShift = 0;
    for (int i = 0; i < n; i++) {
      netShift += prefix[i];
      prefix[i] = netShift;
    }

    for (int i = 0; i < n; i++) {
      int shift = prefix[i] % 26;
      s[i] = ((s[i] - 'a' + shift + 26) % 26) + 'a';
    }
    return s;
  }
};

class Solution {
 public:
  string shiftingLetters(string s, vector<int>& shifts) {
    int n = s.size();
    for (int i = n - 2; i >= 0; --i) {
      shifts[i] = (shifts[i] + shifts[i + 1]) % 26;
    }

    for (int i = 0; i < n; i++) {
      int shitng = shifts[i] % 26;
      s[i] = ((s[i] - 'a' + 26 + shitng) % 26) + 'a';
    }
    return s;
  }
};

class Solution {
 public:
  int numberOfSubstrings(string s) {
    int n = s.size();
    int ones = 0, zeros = 0;
    int left = 0;
    int count = 0;

    for (int right = 0; right < n; right++) {
      if (s[right] == '0')
        zeros++;
      else
        ones++;

      while (ones < zeros * zeros) {
        if (s[left] == '0')
          ones--;
        else
          zeros--;
        left++;
      }

      count += (right - left + 1);
    }
    return count;
  }
};

class Solution {
 public:
  long long countGood(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    long long pair = 0, result = 0;
    int left = 0;
    for (int right = 0; right < nums.size(); right += 1) {
      pair += mp[nums[right]]++;
      while (pair >= k) {
        result += nums.size()
      }
    }
  }
};

class Solution {
 public:
  int partitionString(string s) {
    int ans = 1;
    unordered_set<char> st;
    for (char c : s) {
      if (st.count(c)) {
        ans++;
        st.clear();
      }
      st.insert(c);
    }
    return ans;
  }
};
class Solution {
 public:
  int bagOfTokensScore(vector<int>& tokens, int power) {
    sort(tokens.begin(), tokens.end());
    int l = 0, int r = tokens.size() - 1;
    int score = 0, maxscore = 0;
    while (l <= r) {
      if (power >= tokens[i]) {
        power -= tokens[i];
        score++;
        l++;
        maxscore = max(maxscore, score);
      } else if (score > 0) {
      }
    }
  }
};

class Solution {
 public:
  int minimumOperations(vector<vector<int>>& grid) {
    int rows = grid.size();
    int column = grid[0].size();

    int ans = 0;
    for (int col = 0; col < column; col++) {
      for (int row = 0; row < rows; row++) {
        if (grid[row][col] >= grid[row + 1][col]) {
          int diff = grid[row][col] - grid[row + 1][col] + 1;
          grid[row + 1][col] += diff;
          ans += diff;
        }
      }
    }
    return ans;
  }
};


class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        
    }
};