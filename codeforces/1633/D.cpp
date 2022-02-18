// Coder: jorgeajimenezl
#include <bits/stdc++.h>
// #pragma GCC optimize ("Ofast")

using namespace std;

#if _DEBUG
#define debug(x) cerr << #x << ": " << x << endl;
#else
#define debug(x)
#endif
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)

int main() {
#if _DEBUG
    freopen("a.in", "r", stdin);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    
    int T;
    cin >> T;

    vector<int> pre(2005, 1 << 30);
    pre[0] = pre[1] = 0;
    for (int i = 1; i <= 1000; i++) {
        pre[i + 1] = min(pre[i + 1], pre[i] + 1);
        for (int j = 1; j <= i; j++)
            pre[i + i/j] = min(pre[i + i/j], pre[i] + 1);
    }

    while (T--) {
        int n, k;
        cin >> n >> k;

        vector<int> b(n), c(n);
        for (int& x : b) {
            cin >> x;
            x = pre[x];
        }
        for (int& x : c) cin >> x;

        vector<int> dp(k + 1);  
        for (int i = 0; i < n; i++)
            for (int j = k; j >= b[i]; j--)
                dp[j] = max(dp[j], dp[j - b[i]] + c[i]);

        int ans = 0;
        for (int i = 0; i <= k; i++)
            ans = max(ans, dp[i]);
        cout << ans << "\n";
    }

#if _DEBUG
    cout << "Time elapsed: " << double(clock()) / double(CLOCKS_PER_SEC) << "s\n";
#endif
}