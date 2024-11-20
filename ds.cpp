#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

long long sumOfDistinctCounts(const vector<int>& categories) {
    unordered_map<int, int> lastSeen; // To store the last seen index of each element
    int start = 0;                   // Start of the sliding window
    long long result = 0;            // Final result to store the sum of distinct counts

    for (int end = 0; end < categories.size(); ++end) {
        int current = categories[end];

        // If the current element was seen before, move the start of the window
        if (lastSeen.count(current) && lastSeen[current] >= start) {
            start = lastSeen[current] + 1; // Move start to exclude the previous occurrence
        }

        // Update the last seen index of the current element
        lastSeen[current] = end;

        // Calculate the number of subarrays ending at the current index
        // and add it to the result
        result += (end - start + 1);
    }

    return result;
}

int main() {
    vector<int> categories = {1, 2, 1};
    cout << "Output: " << sumOfDistinctCounts(categories) << endl;
    return 0;
}


vector<int> subarrayWithSUm(vector<int> nums , int target){
  //  will store the total sum till the index
  unordered_map<int,int> mp;

  int cumSum = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    /* code */
    cumSum+=nums[i];
    if(cumSum==target) return {0,i};
    if(mp.find(target-cumSum) != mp.end()) {
      return {mp[target-cumSum],i};
    }
    mp[cumSum]=i;
  }
  return vector<int> {};
}

bool isIsomorphic(string a , string b) {
  if(a.size() != b.size()) return false;

  unordered_map<char,char> atob,btoa;

  for(int i =0; i<a.size(); i++) {
    char a = s[i], b = t[i];

    if(atob.count(a) != )
  }
}

class Solution {
public:
    int firstUniqChar(string s) {
        
    }
};