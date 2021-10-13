//Coder: jorgeajimenezl
#include <bits/stdc++.h>
// #pragma GCC optimize ("Ofast")

using namespace std;

#if _DEBUG
#define debug(x) cerr << #x << ": " << x << endl;
#else
#define debug(x)
#endif


int main() {
#if _DEBUG
    freopen("a.in", "r", stdin);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int T = 1;
    const int mxn = 1e5 + 5;
    // cin >> T;

    while (T--) {
        int n, x;
        cin >> n;

        vector<vector<int64_t>> dp(mxn, vector<int64_t>(2));
        vector<int64_t> cnt(mxn);
        for (int i = 0; i < n; i++) {
            cin >> x;
            cnt[x]++;
        }

        for (int64_t i = 1; i <= 1e5; i++) {
            dp[i][1] = (cnt[i] * i) + dp[i - 1][0];
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        }

        cout << max(dp[1e5][0], dp[1e5][1]) << "\n";
    }
	
    
#if _DEBUG
    cout << "Time elapsed: " << double(clock()) / double(CLOCKS_PER_SEC) << "s\n";
#endif
}