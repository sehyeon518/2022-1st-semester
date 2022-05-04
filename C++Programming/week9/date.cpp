/***********************
요일 구하기
20213043 이세현
***********************/
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int y, m, d;
        cin >> y >> m >> d;

        int total = 0;
        for (int j = 0; j < y; j++) {
            if ((j%4==0 && j%100!=0) || (j%400==0)) {
                total += 366;
            }
            else total += 365;
        }
        for (int j = 1; j < m; j++) {
            switch(j) {
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12:
                    total += 31;
                    break;
                case 4:
                case 6:
                case 9:
                case 11:
                    total += 30;
                    break;
                case 2:
                    if ((y%4==0 && y%100!=0) || y%400==0) {
                        total += 29;
                    }
                    else total += 28;
                    break;
            }
        }
        total += d;

        cout << (total+5)%7 << endl;
    }
    return 0;
}