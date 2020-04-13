#include <bits/stdc++.h>

using namespace std;

int v[10][10];

int mod (int i) {
    if (i == 9)
        return 1;
    else
        return i + 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#if _DEBUG
    freopen("a.in", "r", stdin);
#endif

    int T;
    cin >> T;
    
    while (T--) {
        string s;
        for (int i = 0; i < 9; i++) {
            cin >> s;
            for (int j = 0; j < 9; j++)
                v[i][j] = s[j] - '0';
        }   

        v[0][2] = mod(v[0][2] );
        v[1][5] = mod(v[1][5] );
        v[2][7] = mod(v[2][7] );

        v[3][0] = mod(v[3][0] );
        v[4][3] = mod(v[4][3] );
        v[5][8] = mod(v[5][8] );

        v[6][1] =mod(v[6][1] );
        v[7][4] =mod(v[7][4] );
        v[8][6] =mod(v[8][6] );

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                cout << v[i][j];
            cout << "\n";
        }
    }
}
