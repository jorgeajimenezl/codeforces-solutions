//Coder: jorgeajimenezl
#include <bits/stdc++.h>
// #pragma GCC optimize ("Ofast")

using namespace std;

#if _DEBUG
#define debug(x) cerr << #x << ": " << x << endl;
#endif

int64_t rmq[200005][25];

int build (const vector<int64_t> &v) {
    int n = v.size();
    int lg = __lg(v.size());

    for (int i = 0; i < n; i++)
        rmq[i][0] = v[i];

    for (int j = 1; j <= lg; j++)
        for (int i = 0; i + (1 << (j - 1)) < n; i++)
            rmq[i][j] = __gcd(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
}

int64_t query (int a, int b) {
    int lg = __lg(b - a + 1);
    return __gcd(rmq[a][lg], rmq[b - (1 << lg) + 1][lg]);
}

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

        vector<int64_t> v(n);
        for (int64_t &x : v) cin >> x;
        
        vector<int64_t> dp(n - 1);        

        for (int i = 0; i < n - 1; i++) {
            dp[i] = abs(v[i] - v[i + 1]);
        }
        
        build(dp);
        
        int64_t l = 0;
        int64_t ans = 1;

        for (int r = 0; r < n - 1; r++) {
            while (l < r && query(l, r) == 1)
                l++;
            if (l <= r)
                ans = max(ans, r - l + (dp[l] != 1) + (dp[r] != 1));
        }
        
        cout << ans << "\n";
    }

#if _DEBUG
    cout << "Time elapsed: " << double(clock()) / double(CLOCKS_PER_SEC) << "s\n";
#endif
}