#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    string w;
    for(int i = 0; i < t; i++) {
        cin >> w;
        cout << w.substr(0, w.length() - 2) << "i\n";
    }
    
    return 0;
}