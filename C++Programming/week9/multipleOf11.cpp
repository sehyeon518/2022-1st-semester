/***********************
11의배수
20213043 이세현
***********************/
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        char n[100];
        cin >> n;

        // 몫을 저장하기 위한 배열
        int result [100];
        int resleng = 0;

        int length = 0;
        while (n[length] != 0) {
            length++;
        }
        int x[length];
        for (int i = 0; i < length; i++) {
            x[i] = n[i] - '0';
        }
        // 입력받은 문자를 정수 배열에 저장하기

        int one;
        for (int i = length; i > 2; i--) {
            one = x[i-1];
            result[i] = one;
            resleng++;
            x[i-2] -= one;
            int j = i;
            while (x[j-2] < 0) {
                x[j-2] += 10;
                x[j-3] -= 1;
                j--;
            }
        }
        if(x[0]-x[1]) cout << 0 << endl;        
        else {
            result[2] = x[1];
            int i = 0;
            while (!result[i]) i++;
            for (int j = i; j < length+1; j++) {
                cout << result[j];
            }
            cout << endl;
        }
    }

    return 0;
}