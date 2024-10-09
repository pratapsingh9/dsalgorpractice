#include <bits/stdc++.h>

#include <iostream>
using namespace std;

bool Isanagram(string s , string t) {
  if(s.size()  != t.size()) return false;
  vector<int> freq(26,0);
  for(int i = 0; i<s.size(); i++) {
    freq[s[i] - 'a']++;
    freq[t[i] - 'a']--;
  }
  for(int ele:freq) {
    if (ele != 0) return false;
  }

  return true;
}

bool isAnagram(string s, string t) {
  if (s.length() != t.length()) return false;
  vector<int> freq(26, 0);
  for (int i = 0; i < s.length(); i++) {
    freq[s[i] - 'a']++;
    freq[t[i] - 'a']++;
  }
  for (auto ele : freq) {
    if (ele != 0) return false;
  }
  return true;
}

void showFrequency(string s) {
  vector<int> frequency(26, 0);

  for (auto ele : s) {
    if (isalpha(ele)) {
      frequency[tolower(ele) - 'a']++;
    }
  }

  for (int i = 0; i < 26; i += 1) {
    if (frequency[i] > 0) {
      cout << char(i + 'a') << " have appeared " << frequency[i] << endl;
    }
  }
}

int main() {
  string s = "pratapsinghsidoiya";

  showFrequency(s);
}
