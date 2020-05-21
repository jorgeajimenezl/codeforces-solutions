#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << endl;

using namespace std;

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
        string s;
        cin >> s;

        int n = s.length();

        vector<vector<int>> dp(s.size() + 1, vector<int>(5));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 3; j++)
                dp[i][j] += dp[i - 1][j];
            
            dp[i][s[i - 1] - '0']++;
        }

        auto query = [dp](int a, int b) {
            for (int i = 1; i <= 3; i++)
                if (dp[b][i] - dp[a - 1][i] == 0)
                    return false;
            return true;
        };

        int ans = 1 << 30;
        for (int i = 1; i <= n; i++) {
            int lo = i, hi = n;

            while (lo < hi) {
                int m = (lo + hi) >> 1;
                if (query(i, m))
                    hi = m;
                else
                    lo = m + 1;
            }

            if (!query(i, lo))
                lo++;
                
            if (lo <= n && query(i, lo))
                ans = min(ans, lo - i + 1);
        }

        cout << (ans != 1 << 30 ? ans : 0) << "\n";
    }
}

