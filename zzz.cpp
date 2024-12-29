#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int numUniqueEmails(vector<string>& emails) {
    set<string> st;
    for (int i = 0; i < emails.size(); i++) {
      string email = emails[i];
      string cleanstring = " ";
      for (int j = 0; j < email.size(); j++) {
        if (email[j] == '.')
          continue;

        else if (email[j] == '@' || email[j] == '+') {
          break;
        }
        cleanstring += string[j];
      }
      cleanstring += email.substr(email.find(@), email.size());
      st.insert(cleanstring);
    }
    return st.size();
  }
};

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size() / 2 ;
        vector<int> vec(10001,0);
        for(int i = 0 ;i<nums.size(); i++) {
            vec[nums[i]]++;
            if(vec[i] == n) {
                return i; 
            }
        }
        return -1;
    }
};

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        
    }
};