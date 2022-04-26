/***********************
두 사각형 면적 및 둘레 구하기
20213043 이세현
***********************/

#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {

        int px1, py1, qx1, qy1;          // 왼쪽 아래 좌표, 오른쪽 위 좌표 0보다 크고 100보다 작음
        cin >> px1 >> py1 >> qx1 >> qy1;
        int px2, py2, qx2, qy2;
        cin >> px2 >> py2 >> qx2 >> qy2;

        int area, border;
        int overh, overl;

        if (qx1 <= px2 || px1 >= qx2) overh = 0; // 맞닿는 세로변 없음
        else overh = min(qx1,qx2) - max(px1,px2);

        if (qy1 <= py2 || qy2 <= py1) overl = 0; // 맞닿는 가로변 없음
        else overl = min(qy1, qy2) - max(py1, py2);

        if (overh == 0 || overl == 0) {
            overh = 0;
            overl = 0;
        }

        area = (qy1-py1) * (qx1-px1) + (qy2-py2) * (qx2-px2) - (overh * overl);
        border = 2 * ((qy1-py1) + (qx1-px1) + (qy2-py2) + (qx2-px2) - (overh + overl));
            cout << area << " " << border << endl;
    }
    return 0;
}