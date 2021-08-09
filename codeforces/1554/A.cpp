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
        int n;
        cin >> n;
        
        vector<int64_t> v(n);
        for (auto &x : v) cin >> x;
        int64_t ans = 0;
        
        for (int i = 0; i < n; i++) {
            if (i > 0)
                ans = max(ans, v[i] * v[i - 1]);
            if (i < n - 1)
                ans = max(ans, v[i] * v[i + 1]);
        }
        
        cout << ans << "\n";
    }
#if _DEBUG
    cout << "Time elapsed: " << double(clock()) / double(CLOCKS_PER_SEC) << "s\n";
#endif
}