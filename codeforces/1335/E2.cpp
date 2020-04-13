#include <bits/stdc++.h>

using namespace std;

int sum[200005][205];
vector<int> st[205];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#if _DEBUG
    freopen("a.in", "r", stdin);
#endif

    int T;
    cin >> T;
    
    while (T--) {
        int n;
        cin >> n;

        vector<int> v(n + 1);
        vector<int> ct(205);

        for (int i = 1; i <= n; i++) {
            cin >> v[i];
            
            for (int j = 0; j <= 200; j++)
                sum[i][j] = sum[i - 1][j];

            sum[i][v[i]]++;
            st[v[i]].push_back(i);
        }

        int ans = 1;

        for (int i = 0; i <= 200; i++)
            ans = max(ans, sum[n][i]);

        for (int x = 0; x <= 200; x++) {
            if (!sum[n][x])
                continue;
            
            for (int i = 0; i < st[x].size() >> 1; i++) {
                int lo = st[x][i], hi = st[x][st[x].size() - i - 1];

                for (int k = 0; k <= 200; k++) {
                    if (k == x || !sum[n][k])
                        continue;

                    int l = upper_bound(st[k].begin(), st[k].end(), lo) - st[k].begin() + 1;
                    int r = lower_bound(st[k].begin(), st[k].end(), hi) - st[k].begin();

                    ans = max(ans, 2 * (i + 1) + r - l + 1);
                }
            }
        }

        for (int i = 0; i <= 200; i++)
            st[i].clear();
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= 200; j++)
                sum[i][j] = 0;

        cout << ans << "\n";

    }
}
