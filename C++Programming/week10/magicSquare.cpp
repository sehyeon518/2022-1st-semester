/***********************
홀수 마방진
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

        int pointerX = 0;
        int pointerY = (n-1)/2;
        int magic[n][n];
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) magic[x][y] = 0;
        }        
        for (int j = 1; j < n*n + 1; j++) {
            magic[pointerX][pointerY] = j;
            int tmpX = pointerX--;
            int tmpY = pointerY++;
            if(pointerX < 0) pointerX = n-1;
            if(pointerY > n-1) pointerY = 0;
            if(magic[pointerX][pointerY] != 0) {
                pointerX = tmpX+1;
                pointerY = tmpY;
            }
        }

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) cout << magic[x][y] << " ";
            cout << endl;
        }
    }
    return 0;
}