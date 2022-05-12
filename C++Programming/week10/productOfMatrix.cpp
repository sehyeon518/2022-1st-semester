/***********************
행렬곱셉
20213043 이세현
***********************/
#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++){
        int r, s, t;
        cin >> r >> s >> t;

        int A[r][s];
        for (int x = 0; x < r; x++) {
            for (int y = 0; y < s; y++) cin >> A[x][y];
        }    
        int B[s][t];
        for (int x = 0; x < s; x++) {
            for (int y = 0; y < t; y++) cin >> B[x][y];
        }   

        int answer[r][t];
        for (int x = 0; x < r; x++) {
            for (int y = 0; y < t; y++) {
                answer[x][y] = 0;
                for (int k = 0; k < s; k++) {
                    answer[x][y] += A[x][k] * B[k][y];
                }
                cout << answer[x][y] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}