#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifdef _OFFLINE
    freopen("a.in", "r", stdin);
#endif

    int T;
    cin >> T;

    while (T--) {
        int n, k;
        cin >> n >> k;

        vector<int64_t> v(n);
        vector<int> f(2 * k + 1), sum(k + 1), sumt(k + 2);

        for (int i = 0; i < n; i++) {
            cin >> v[i];            
        }

        for (int i = 0; i < n / 2; i++) {
            f[v[i] + v[n - i - 1]]++;
            sum[max(v[i], v[n - i - 1])]++;
            sumt[min(v[i], v[n - i - 1])]++;
        }

        for (int i = 1; i <= k; i++)
            sum[i] += sum[i - 1];

        for (int i = k; i >= 1; i--)
            sumt[i] += sumt[i + 1];

        int ans = 1 << 30;

        for (int i = k + 1; i <= 2 * k; i++)
            ans = min(ans, sum[i - k - 1] + n / 2 - f[i]);

        for (int i = 2; i <= k; i++)
            ans = min(ans, sumt[i] + n / 2 - f[i]);

        cout << ans << "\n";
    }
}