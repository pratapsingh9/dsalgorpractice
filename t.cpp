#include <iostream>
#include <set>   // Include set library
#include <map>   // Include map library

int main() {
    // ================== SET ==================
    // A set stores unique elements in sorted order.
    std::set<int> mySet;

    // Inserting elements into the set
    mySet.insert(10);  // Insert 10
    mySet.insert(5);   // Insert 5
    mySet.insert(20);
    mySet.insert(20);  // Insert 20
    mySet.insert(10);  // Duplicate value (will not be added)

    std::cout << "Elements in the set (unique and sorted): ";
    // Iterate through the set
    for (int val : mySet) {
        std::cout << val << " ";  // Outputs: 5 10 20 (sorted order)
    }
    std::cout << std::endl;

    // Check if a value is in the set
    if (mySet.find(10) != mySet.end()) {
        std::cout << "10 is in the set." << std::endl;
    } else {
        std::cout << "10 is not in the set." << std::endl;
    }

    mySet.erase(5);  // Remove 5
    std::cout << "After removing 5: ";
    for (int val : mySet) {
        std::cout << val << " ";  // Outputs: 10 20
    }
    std::cout << std::endl;
    std::map<std::string, int> myMap;

    myMap["Alice"] = 30;  
    myMap["Bob"] = 25;   
    myMap["Charlie"] = 35;
    myMap["Alice"] = 32; 

    std::cout << "Contents of the map (key-value pairs):" << std::endl;
    for (const auto& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    
    }

    // Accessing a value by key
    std::cout << "Bob's age is: " << myMap["Bob"] << std::endl;  // Outputs: 25

    // Check if a key exists in the map
    if (myMap.find("Dave") != myMap.end()) {
        std::cout << "Dave is in the map." << std::endl;
    } else {
        std::cout << "Dave is not in the map." << std::endl;
    }

    // Remove an element from the map
    myMap.erase("Charlie");  // Remove entry for "Charlie"
    std::cout << "After removing Charlie, the map is:" << std::endl;
    for (const auto& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
        // Outputs:
        // Alice: 32
        // Bob: 25
    }

    return 0;
}
