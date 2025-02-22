class Storage<T> {
    private items: T[] = [];
  
    addItem(item: T): void {
      this.items.push(item);
    }
  
    getItems(): T[] {
      return this.items;
    }
  }
  
  // Using the generic class
  const numberStorage = new Storage<number>();
  numberStorage.addItem(5);
  numberStorage.addItem(10);
  console.log(numberStorage.getItems()); // Output: [5, 10]
  
  const stringStorage = new Storage<string>();
  stringStorage.addItem("Hello");
  console.log(stringStorage.getItems()); // Output: ["Hello"]
  