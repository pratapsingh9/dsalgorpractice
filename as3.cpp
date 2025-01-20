#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findUnique(vector<int> &nums) {
    int unique = 0;
    for(int num:nums) {
        unique ^= num;
    }
    return unique;
}

int ocunt() {
    int num = 0;
    int ocunt = 0;
    while (n)
    {
        /* code */
        ocunt+= num & 1;
        num >>= 1;
    }

    return ocunt;
    
}

int main() {
    int num, i;
    cout << "Enter a number: ";
    cin >> num;
    cout << "Enter the bit position (0-indexed): ";
    cin >> i;

    if (num & (1 << i)) {
        cout << "The " << i << "-th bit is 1." << endl;
    } else {
        cout << "The " << i << "-th bit is 0." << endl;
    }
    return 0;
}
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_set<int> st;
        for(int n:nums1) {
            st.insert(n);
        }

        for(int n:nums2) {
            if(st.count(n)) {
                ans.push_back(n);
            }
        }
        return ans;
    }
};

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> st;
        for(char c:jewels) st.insert(c);

        int cnt = 0;
        for(char c:stones) {
            if(st.count(c)) cnt++;
        }

        return cnt;
    }
};

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,int> row , col ,  rowCount , colCount;
        int rowSize = mat.size();
        int colSize = mat[0].size();

        for(int i = 0; i<rowSize; i++) {
            for(int j = 0 ; j<colSize; j++) {
                row[mat[i][j]]=i;
                col[mat[i][j]]=j;
            }
        }
        for(int i = 0 ; i<arr.size(); i++) {
            int value = arr[i];
            rowCount[row[value]]++;
            colCount[col[value]]++;

            if(rowCount[row[value]]==rowSize || colCount[col[value]==colSize]) {
                return i;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int rowSize = mat.size();
        int colSize = mat[0].size();
        unordered_map<int, pair<int, int>> position;
        for (int i = 0; i < rowSize; i++) {
            for (int j = 0; j < colSize; j++) {
                position[mat[i][j]] = {i, j};
            }
        }
        vector<int> rowCount(rowSize, 0);
        vector<int> colCount(colSize, 0);

        for (int i = 0; i < arr.size(); i++) {
            int value = arr[i];
            auto [r, c] = position[value];
            rowCount[r]++;
            colCount[c]++;
            if (rowCount[r] == colSize || colCount[c] == rowSize) {
                return i;
            }
        }

        return -1;
    }
};


class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans = 0 ,  previour = INT_MIN;
        for(int num:nums) {
            int lowerbound = num-k;
            int upperBound = num + k;
            if(previour < lowerbound) {
                previour=lowerbound;
                ans++;
            }else if(previour<upperBound) {
                ans++;
                previour++;
            }
        }
        return ans;
    }
};

class Solution {
public:
    bool doesAliceWin(string s) {
        unordered_set<char> vowel = {'a','e','i','o','u'};
        int vowelCount = 0;
        for(auto ch:s) {
            if(vowel.find(ch)!=vowel.end()) vowelCount++;
        }
        if(vowelCount>=1) return true;
        return false;
    }
};

class Solution {
public:
    int maxOperations(string s) {
        
    }
};