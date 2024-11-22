#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string decodeMessage(string key, string message) {
    unordered_map<char, int> map;
    char currentChar = 'a';

    for (char c : key) {
      if (c != ' ' && map.find(c) == map.end()) {
        map[c] = currentChar++;
      }
    }
    string decodedString = "";
    for (char c : message) {
      if (c == ' ') {
        decodedString += ' ';
      } else {
        decodeMessage += map[c];
      }
    }
    return decodedString;
  }
};
