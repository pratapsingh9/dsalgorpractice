#include <iostream>
using namespace std;




int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int lcm (int a , int b) {
    return (a*b)/gcd(a,b);
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << "GCD: " << gcd(a, b) << endl;
    return 0;
}
