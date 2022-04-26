/***********************
자리수 거듭제곱 수
20213043 이세현
***********************/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;

    for(int i=0; i<t; i++) {
        int n;
        int k = 0;
        int total = 0;
        int result = 0;

        cin >> n;
        int n1; int n2;
        n1 = n2 = n;

        while (n1 > 0) {
            n1 /= 10;
            k++;
        }

        while (n2 > 0) {
            int one = n2%10;
            n2 = n2/=10;
            one = pow(one, k);
            total += one;
        }
        if (total == n) result = 1;
        cout << result << endl;
    }
    return 0;
}