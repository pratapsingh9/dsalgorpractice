class PubSub {
    constructor() {
      this.channels = {};
    }
  
    subscribe(channel, callback) {
      if (!this.channels[channel]) {
        this.channels[channel] = [];
      }
      this.channels[channel].push(callback);
    }
    
    publish(channel, message) {
      if (this.channels[channel]) {
        this.channels[channel].forEach((callback) => callback(message));
      }
    }
  
    // Unsubscribe from a channel
    unsubscribe(channel, callback) {
      if (this.channels[channel]) {
        this.channels[channel] = this.channels[channel].filter(
          (cb) => cb !== callback
        );
      }
    }
  }
  
  // Usage
  const pubsub = new PubSub();
  
  // Subscriber 1
  const subscriber1 = (message) => {
    console.log("Subscriber 1 received:", message);
  };
  pubsub.subscribe("news", subscriber1);
  
  // Subscriber 2
  const subscriber2 = (message) => {
    console.log("Subscriber 2 received:", message);
  };
  pubsub.subscribe("news", subscriber2);
  
  // Publisher
  pubsub.publish("news", "Hello, World!");
  
  // Unsubscribe Subscriber 1
  pubsub.unsubscribe("news", subscriber1);
  
  // Publish again
  pubsub.publish("news", "Goodbye, World!");