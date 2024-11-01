#include <bits/stdc++.h>
using namespace std;

int maximiseMemeory(vector<int> memory) {
    sort(memory.rbegin() , memory.rend());
    int total = 0;
    for(int i =  0; i<memory.size(); i++) {
        total += (i+1) * (int)memory[i];
    }
    return total;
}

int main() {
    vector<int> meoory = {3,4,5};
    cout << maximiseMemeory(meoory) << endl;
    return 0;
}