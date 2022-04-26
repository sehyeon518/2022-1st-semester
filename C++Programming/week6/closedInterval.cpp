#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int over, length;

        if (b < c || d < a) {
            over = 0;
            length = b-a + d-c;
        }
        if (a <= c && c <= b) {
            if (b <= d) {
                over = b-c;
                length = d-a;
            }
            else {
                over = d-c;
                length = b-a;
            }
        }
        else if (c <= a && a <= d) {
            if (d <= b) {
                over = d-a;
                length = b-c;
            }
            else {
                over = b-a;
                length = d-c;
            }
        }
        cout << over << " " << length << endl;
        
    }

    return 0;
}