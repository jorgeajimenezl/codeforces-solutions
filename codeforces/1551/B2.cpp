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
        int n, k, x;
        cin >> n >> k;

        vector<vector<int>> buckets(k);
        vector<vector<int>> cnt(n + 1);
        vector<int> ans(n);

        int p = 0;
        for (int i = 0; i < n; i++) {
            cin >> x;
            cnt[x].push_back(i);
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < min(k, (int)cnt[i].size()); j++) {
                buckets[p].push_back(cnt[i][j]);
                p = (p + 1) % k;
            }
        }
        int m = 1 << 30;
        for (int i = 0; i < k; i++)
            m = min(m, (int)buckets[i].size());
        for (int i = 0; i < k; i++)
            for (int j = 0; j < min(m, (int)buckets[i].size()); j++)
                ans[buckets[i][j]] = i + 1;

        for (int i = 0; i < n; i++)
            cout << ans[i] << " \n"[i == n - 1];
    }

#if _DEBUG
    cout << "Time elapsed: " << double(clock()) / double(CLOCKS_PER_SEC) << "s\n";
#endif
}
