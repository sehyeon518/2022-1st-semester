/***********************
11의배수
20213043 이세현
***********************/
#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        unsigned long long int n;
        cin >> n;
        unsigned long long int result = 0;

        int length = 0;
        int one;

        while (n>=100) {
            one = n % 10;
            result += one * pow(10, length++);
            n = n / 10 - one;
            cout << "result : " << result << endl;
            cout << "n      : " << n << endl;
        }

        if (n/10 - n%10) cout << 0 << endl;
        else cout << n/10 << result << endl;

    }

    return 0;
}