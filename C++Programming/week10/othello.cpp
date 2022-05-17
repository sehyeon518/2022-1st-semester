/***********************
오셀로
20213043 이세현
***********************/
#include <iostream>
using namespace std;

int main() {

    int T; cin >> T;
    for (int i = 0; i < T; i++){
        // 오셀로 시작
        char othello[8][8];
        for (int x = 0; x < 8; x++) {
            for (int y = 0; y < 8; y++) 
                othello[x][y] = '+'; }
        othello[3][3] = othello[4][4] = 'O';
        othello[3][4] = othello[4][3] = 'X';

        int n; cin >> n; // 게임 turn 횟수
        for (int k = 0; k < n; k++) {
            int s, t;    // 1부터 8까지 정수
            cin >> s >> t;
            char o = k%2 ? 'O' : 'X';

            // 입력 받은 숫자를 0부터 시작하는 배열의 index로 바꾸기
            othello[--s][--t] = o;
            int posX = s; // 0부터 7까지 정수
            int posY = t; // 0부터 7까지 정수

            // 가로 왼쪽으로 훑어보기
            if (posY > 0 && othello[s][t-1] != '+' && othello[s][t-1] != o) {
                posY--;
                while (posY > 0 && othello[s][posY] != o && othello[s][posY] != '+')
                    posY--;
                if (posY >= 0 && othello[s][posY] == o)
                    for (int y = posY+1; y < t; y++) othello[s][y] = o;
            }

            // 가로 오른쪽으로 훑어보기
            posY = t;
            if (posY < 7 && othello[s][t+1] != '+' && othello[s][t+1] != o) {
                posY++;
                while (posY < 7 && othello[s][posY] != o && othello[s][posY] != '+') 
                    posY++;
                if (posY <= 7 && othello[s][posY] == o)
                    for (int y = posY-1; y > t; y--) othello[s][y] = o;
            }

            // 세로 위쪽으로 훑어보기
            if (posX > 0 && othello[s-1][t] != '+' && othello[s-1][t] != o) {
                posX--;
                while (posX > 0 && othello[posX][t] != o && othello[posX][t] != '+')
                    posX--;
                if (posX >= 0 && othello[posX][t] == o)
                    for (int x = posX+1; x < s; x++) othello[x][t] = o;
            }
            // 세로 아래로 훑어보기
            posX = s;
            if (posX < 7 && othello[s+1][t] != '+' && othello[s+1][t] != o) {
                posX++;
                while (posX < 7 && othello[posX][t] != o && othello[posX][t] != '+')
                    posX++;
                if (posX <= 7 && othello[posX][t] == o)
                    for (int x = posX-1; x > s; x--) othello[x][t] = o;
            }            

            // 대각선 왼쪽 위로 훑어보기
            posX = s; posY = t;
            if (posX > 0 && posY > 0 && othello[s-1][t-1] != '+' && othello[s-1][t-1] != o) {
                posX--; posY--;
                while (posX > 0 && posY > 0 && othello[posX][posY] != o && othello[posX][posY] != '+') {
                    posX--; posY--;
                }
                if (posX >= 0 && posY >= 0 && othello[posX][posY] == o)
                    for (int x = posX+1, y = posY+1; x < s && y < t; x++, y++) othello[x][y] = o;
            }

            // 대각선 왼쪽 아래로 훑어보기
            posX = s; posY = t;
            if (posX < 7 && posY > 0 && othello[s+1][t-1] != '+' && othello[s+1][t-1] != o) {
                posX++; posY--;
                while (othello[posX][posY] != o && posX < 7 && posY > 0 && othello[posX][posY] != '+') {
                    posX++; posY--;
                }
                if (posX <= 7 && posY >= 0 && othello[posX][posY] == o) 
                    for (int x = posX-1, y = posY+1; x > s && y < t; x--, y++) othello[x][y] = o;
            }

            // 대각선 오른쪽 위로 훑어보기
            posX = s; posY = t;
            if (posX > 0 && posY < 7 && othello[s-1][t+1] != '+' && othello[s-1][t+1] != o) {
                posX--; posY++;
                while (othello[posX][posY] != o && posX > 0 && posX < 7 && othello[posX][posY] != '+') {
                    posX--; posY++;
                }
                if (posX >= 0 && posY <= 7 && othello[posX][posY] == o)
                    for (int x = posX+1, y = posY-1; x < s && y > t; x++, y--) othello[x][y] = o;
            }

            // 대각선 오른쪽 아래로 훑어보기
            posX = s; posY = t;
            if (posX < 7 && posY < 7 && othello[s+1][t+1] != '+' && othello[s+1][t+1] != o) {
                posX++; posY++;
                while (othello[posX][posY] != o && posX < 7 && posY < 7 && othello[posX][posY] != '+') {
                    posX++; posY++;
                }
                if (posX <= 7 && posY <= 7 && othello[posX][posY] == o)
                    for (int x = posX-1, y = posY-1; x > s && y > t; x--, y--) othello[x][y] = o;
            }


        }

        int countX = 0;
        int countY = 0;
        for (int x = 0; x < 8; x++) {
            for (int y = 0; y < 8; y++) {
                if (othello[x][y]=='X') countX++;
                else if (othello[x][y] == 'O') countY++;
            }
        }
        cout << countX << ' ' << countY << endl;
        for (int x = 0; x < 8; x++) {
            for (int y = 0; y < 8; y++) cout << othello[x][y];
            cout << endl;
        } 
    }
    return 0;
}