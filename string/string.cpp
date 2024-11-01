#include <bits/stdc++.h>
bool canConstruct(string ransomNote, string magazine) {
if(ransomNote.size() != magazine.size())  return false;
 unordered_map<char,int> mp;
 for(auto ch:ransomNote) {
 	mp[ch]++;
 }
 for(auto ch:magazine){
 	if(mp.find(ch) != mp.end()) {
 		mp[ch]--;
 		if(mp[ch] == 0) {
 			mp.erase(ch);
 		}
 	}
 }
 return mp.empty();
}