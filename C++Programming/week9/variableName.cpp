/***********************
변수이름
20213043 이세현
***********************/
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int result = 1;
        char x[300];
        cin >> x;

        if ((x[0] < 'A' || x[0] > 'Z') && (x[0] < 'a' || x[0] > 'z') && (x[0] != '_')) {
            result = 0;
        }
        else {
            int j = 1;
            while(x[j] != 0) {
                if ((x[j]<'0' || x[j]>'9') && (x[j]<'A' || x[j]>'Z') && (x[j]<'a' || x[j]>'z') && x[j]!='_') {
                    result = 0;
                    break;
                }
                j++;
            }
        }
        cout << result << endl;       
    }

    return 0;
}