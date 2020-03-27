#include <bits/stdc++.h>

using namespace std;

vector<int> graph[200005];
int depth[200005], lca[200005][20];

void preprocess (int root) {
    depth[root] = 1;
    queue<int> q;

    q.push(root);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph[u]) {
            if (depth[v])
                continue;

            depth[v] = depth[u] + 1;
            lca[v][0] = u;
            q.push(v);

            int lg = __lg(depth[v]);
            for (int i = 1; i <= lg; i++)
                lca[v][i] = lca[lca[v][i - 1]][i - 1];
        }
    }
}

int query (int u, int v) {
    if (depth[u] < depth[v])
        swap(u, v);

    int lg = __lg(depth[u]);
    for (int i = lg; i >= 0; i--)
        if (depth[u] - (1 << i) >= depth[v])
            u = lca[u][i];

    if (u == v) return u;

    lg = __lg(depth[u]);
    for (int i = lg; i >= 0; i--)
        if (lca[u][i] && lca[u][i] != lca[v][i]) {
            u = lca[u][i];
            v = lca[v][i];
        }

    return lca[u][0];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#if OFFLINE
    freopen("a.in", "r", stdin);
#endif

    int n, q;
    cin >> n >> q;

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    preprocess(1);

    while (q--) {
        int k;
        cin >> k;

        vector<int> v(k);
        for (int i = 0; i < k; i++) {
            int x;
            cin >> x;
            v[i] = lca[x][0];
        }

        sort(v.begin(), v.end(), [](int u, int v) {
            return depth[u] > depth[v];
        });

        bool flag = 1;

        for (int i = 0; i < k - 1; i++) {
            int x = query(v[i], v[i + 1]);

            if (x != v[i] && x != v[i + 1]) {
                flag = 0;
                break;
            }
        }

        cout << (flag ? "YES\n" : "NO\n");
    }
}