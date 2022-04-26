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

        int x = n;
        int aSquare[x][x];

        int out;
        if (x % 4 == 1) out = 0;
        else out = 1;

        // 값 채우기
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < x; j++) {
                aSquare[i][j] = 1 - out;
            }
        }    

        // 꼭짓점 찾기
        for (int i = 0; i < x; i += 2) {
            aSquare[i][i] = out;
        }

        // 꼭짓점에서 가로 모서리 채우기
        for (int i = 0; i < x/2; i+=2) {
            for (int j = i; j < x; j++) {
                if (j < x-i) {
                    aSquare[i][j] = out;
                }
            }
        }
        for (int i = x-1; i > x/2; i-=2) {
            for (int j = i; j > -1; j--) {
                if (j > x-i-2) {
                    aSquare[i][j] = out;
                }
            }
        }  
        // 꼭짓점에서 세로 모서리 채우기
        for (int j = 0; j < x/2; j+=2) {
            for (int i = j; i < x; i++) {
                if (i < x-j) {
                    aSquare[i][j] = out;
                }
            }
        }
        for (int j = x-1; j > x/2; j-=2) {
            for (int i = j; i > -1; i--) {
                if (i > x-j-2) {
                    aSquare[i][j] = out;
                }
            }
        }      

        // 출력하기
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < x; j++) {
                cout << aSquare[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}