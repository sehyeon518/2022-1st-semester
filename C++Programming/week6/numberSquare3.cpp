/***********************
정사각형 출력(3)
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

        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {
                if (  ( (x==0) || (x==(n-1)/2) || (x==n-1) ) && ( (y==0) || (y==(n-1)/2) || (y==n-1) )  ) {
                    if (x==y && x==(n-1)/2) cout << "*";
                    else cout << "+";
                }
                else if ( (x==0) || (x==(n-1)/2) || (x==n-1) ) cout << "|";
                else if ( (y==0) || (y==(n-1)/2) || (y==n-1) ) cout << "-";
                else if (x==y) cout << "\\";
                else if (x+y==n-1) cout << "/";
                else cout << ".";                
            }
            cout << endl;
        }

    }

    return 0;
}