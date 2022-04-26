/***********************
숫자의 모든 자리수 반복 곱하기
20213043 이세현
***********************/

#include <iostream>
using namespace std;

int productOfNum(long int x) {
    int result = 1;
    while (x > 0) {
        int oneNum = x % 10;
        x /= 10;
        if (oneNum != 0) {result *= oneNum;}
    }
    return result;
}
int main() {
    int t;
    cin >> t;

    for(int i=0; i<t; i++) {
        long int n;
        cin >> n;
        long int a = n;
        while (a > 9) {a = productOfNum(a);}
        cout << a << endl;
    }
    return 0;
}