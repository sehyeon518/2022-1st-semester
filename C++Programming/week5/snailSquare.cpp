/***********************
숫자 정사각형 달팽이 모양 출력하기
20213043 이세현
***********************/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i=0; i<t; i++) {
        int n;
        int a, b;
        cin >> n >> a >> b; // 한 변의 길이, 첫번째 출력 값, 마지막 출력 값
        long int k = 0;          // 출력할 숫자
        int count = 0;      // a와 b 사이의 값만 출력하기 위한 카운트 용도
      
        int lu = 1; int ru = n;          // 왼쪽 위 꼭짓점 값,   오른쪽 위 꼭짓점 값
        int lb = n*n-n+1; int rb = n*n;  // 왼쪽 아래 꼭짓점 값, 오른쪽 아래 꼭짓점 값
        //cout << lu << ru << lb << rb << endl;
        while(count <= b) {
            if(n==1) {count = 2; cout << 1;}
            else {
                while (k < ru) {
                    k++;
                    count++;
                    if (count >= a && count <= b) cout << k << " ";
                }
                ru += n-1;
                while (k < rb) {
                    k += n;
                    count++;
                    if (count >= a && count <= b) cout << k << " ";
                }
                rb -= n+1;
                while (k > lb) {
                    k--;
                    count++;
                    if (count >= a && count <= b) cout << k << " ";
                }
                lb -= n-1;
                while (k > lu + n) {
                    k -= n;
                    count++;
                    if (count >= a && count <= b) cout << k << " ";
                }
                lu += n+1;
            }
        }
        cout << endl;
    }
    return 0;
}