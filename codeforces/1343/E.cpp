#include <bits/stdc++.h>

using namespace std;

vector<int> graph[200005]; 

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifdef _OFFLINE
    freopen("a.in", "r", stdin);
#endif

    int T;
    cin >> T;

    while (T--) {
        int n, m, a, b, c;
        cin >> n >> m >> a >> b >> c;

        vector<long long> p(m + 1);
        for (int i = 1; i <= m; i++)
            cin >> p[i];

        sort(p.begin(), p.end());

        for (int i = 1; i <= m; i++)
            p[i] += p[i - 1];

        for (int i = 0; i <= 3 * m; i++)
            p.push_back(1e15);

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;

            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<int> cnt_a(n + 1), cnt_b(n + 1), cnt_c(n + 1);

        auto build = [&](int root, vector<int> &cnt) {
            queue<int> q;
            fill(cnt.begin(), cnt.end(), 1 << 30);
            q.push(root);
            cnt[root] = 0;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : graph[u])
                    if (cnt[v] > cnt[u] + 1) {
                        cnt[v] = cnt[u] + 1;
                        q.push(v);                                                
                    }
            }
        };

        build(a, cnt_a);
        build(b, cnt_b);
        build(c, cnt_c);

        long long ans = 1e15;

        for (int k = 1; k <= n; k++) {               
            int x = cnt_a[k];
            int y = cnt_b[k];
            int z = cnt_c[k];

            int xz = min(x, z);
            int zx = max(x, z);
            
            ans = min(ans, 2LL * p[y] + p[zx + y] - p[y] + p[xz + zx + y] - p[y + zx]);
        }

        cout << ans << "\n";

        for (int i = 0; i <= n; i++)
            graph[i].clear();
    }
}