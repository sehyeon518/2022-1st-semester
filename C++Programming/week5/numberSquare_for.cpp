/***********************
숫자 정사각형 출력하기(1)
20213043 이세현
***********************/

#include <iostream>
using namespace std;


int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int count = 0; // 출력한 숫자 개수
        int k = 0; // 출력할 숫자 위치
        int out; // 출력할 숫자

        int lu = 1; int ru = n;          // 왼쪽 위 꼭짓점 값,   오른쪽 위 꼭짓점 값
        int lb = n*n-n+1; int rb = n*n;  // 왼쪽 아래 꼭짓점 값, 오른쪽 아래 꼭짓점 값

        if (n%4 == 1) out = 0;
        else out = 1;

        while(count < n*n) {
            if (n==1) {
                count++;
                cout << n;
            }
            else {
                while (k < ru) {
                    k++;
                    count++;
                    cout << out << " ";
                }
                ru += n-1;
                while (k < rb) {
                    k += n;
                    count++;
                    cout << out << " ";
                }
                rb -= n+1;
                while (k > lb) {
                    k--;
                    count++;
                    cout << out << " ";
                }
                lb -= n-1;
                while (k > lu + n) {
                    k -= n;
                    count++;
                    cout << out << " ";
                }
                lu += n+1;
                out = 1 - out;
            }
            cout << endl;
        }
    }
    return 0;
}