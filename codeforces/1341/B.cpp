#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#if _DEBUG
    freopen("a.in", "r", stdin);
#endif

    int T;
    cin >> T;
    
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> v(n + 3);

        for (int i = 1; i <= n; i++)
            cin >> v[i];

        vector<int> dp(n + 3);

        for (int i = 1; i <= n; i++) {
            dp[i] += dp[i - 1];
            dp[i] += (v[i] > v[i - 1] && v[i] > v[i + 1]);
        }

        int l = 1;
        
        for (int i = 1; i <= n - k + 1; i++) {
            if (dp[l + k - 2] - dp[l] < dp[i + k - 2] - dp[i])
                l = i;
        }

        cout << dp[l + k - 2] - dp[l] + 1 << " " << l << "\n";
    }
}
