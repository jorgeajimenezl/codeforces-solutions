//Coder: jorgeajimenezl
#include <bits/stdc++.h>

using namespace std;

#if _DEBUG
#define debug(x) cerr << #x << ": " << x << endl;
#endif

int main() {
#if _DEBUG
    freopen("a.in", "r", stdin);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        bool flag = 0;
        for (int c = 0; c <= 143 && !flag; c++)
            for (int b = 0; b <= 200 && !flag; b++) {
                if (c * 7 + b * 5 == n) {
                    cout << 0 << " " << b << " " << c << "\n";
                    flag = 1;
                }
                else if (c * 7 + b * 5 < n && (n - c * 7 - b * 5) % 3 == 0) {
                    cout << (n - c * 7 - b * 5) / 3 << " " << b << " " << c << "\n";
                    flag = 1;
                }
            }

        if (!flag)
            cout << "-1\n";
    }
	
    
#if _DEBUG
    cout << "Time elapsed: " << double(clock()) / double(CLOCKS_PER_SEC) << "s\n";
#endif
}