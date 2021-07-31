//Coder: jorgeajimenezl
#include <bits/stdc++.h>
// #pragma GCC optimize ("Ofast")

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

    int T = 1;
    cin >> T;

    while (T--) {
        int64_t n;
        cin >> n;
        if (n < 6) {
            cout << "15\n";
            continue;
        }

        int64_t ans = (n / 6) * 15;
        int64_t r = n % 6;
        
        if (r == 0)
            cout << ans << "\n";
        else if (r == 1 || r == 2)
            cout << ans + 5 << "\n";
        else if (r == 3 || r == 4)
            cout << ans + 10 << "\n";
        else 
            cout << ans + 15 << "\n";
    }

#if _DEBUG
    cout << "Time elapsed: " << double(clock()) / double(CLOCKS_PER_SEC) << "s\n";
#endif
}