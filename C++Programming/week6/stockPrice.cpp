/***********************
주가 분석(1)
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
        int iArray[n];
        int count = 0;
        for (int k = 0; k < n; k++) {
            cin >> iArray[k];
        }
        //cout << "들어온 값 : ";
        for (int k = 0; k < n; k++) {
            //cout << iArray[k] << " ";
            if (k==0) count++;
            else if (iArray[k] != iArray[k-1]) count++;
        }
/*        cout << endl;
        cout << "연속된 값 제거했을 때 배열 개수 : ";
        cout << count << endl;                    */
        int rArray[count];
        int num = 0;
        rArray[0] == iArray[0];
        for (int k = 0; k < n; k++) {
            if (k==0) {
                rArray[num]=iArray[k];
                num++;
            }
            else if (iArray[k] != iArray[k-1]) {
                rArray[num] = iArray[k];
                num++;
            }
        }
/*        for (int k = 0; k < num; k++) {
            cout << rArray[k] << " ";
        }
        cout << endl;                  */
        int output = 0;
        for (int k = 1; k < num-1; k++) {
            if (rArray[k-1] < rArray[k] && rArray[k] > rArray[k+1]) output++;
            
        }
        cout << output << endl;
    }
    return 0;
}