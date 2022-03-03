// Coder: jorgeajimenezl
#include <bits/stdc++.h>
// #pragma GCC optimize ("Ofast")

using namespace std;

#if _DEBUG
#define debug(x) cerr << #x << ": " << x << endl;
#pragma GCC optimize("trapv")
#else
#define debug(x)
#endif
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)

template<typename T>
ostream& operator<< (ostream& os, const vector<T> &a) {
    for (size_t i = 0; i < a.size() - 1; i++)
        os << a[i] << " ";
    return (os << a.back());
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
        int n, k;
        cin >> n >> k;

        vector<vector<int>> graph(n + 1);
        vector<int> depth(n + 1);
        vector<int> parent(n + 1);
        vector<int> dist(n + 1, 1 << 30);
        vector<int> x(k);

        for (int &i : x) {
            cin >> i;
            dist[i] = 0;
        }

        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        queue<int> q;
        depth[1] = 1;
        q.push(1);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : graph[u]) {
                if (depth[v])
                    continue;

                parent[v] = u;
                depth[v] = depth[u] + 1;
                q.push(v);
            }
        }

        // up
        for (int u : x) {
            while (u != 1) {
                if (dist[parent[u]] <= dist[u] + 1)
                    break;
                dist[parent[u]] = dist[u] + 1;
                u = parent[u];
            }
        }

        // down        
        for (int u = 1; u <= n; u++)
            if (dist[u] != 1 << 30)
                q.push(u);
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : graph[u]) {
                if (dist[v] <= dist[u] + 1)
                    continue;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }

        bool flag = 0;
        for (int u = 2; u <= n; u++)
            if (graph[u].size() == 1 &&
                dist[u] > depth[u] - 1)
                flag = 1;

        cout << (flag ? "YES" : "NO") << "\n";
    }

#if _DEBUG
    cout << "Time elapsed: " << double(clock()) / double(CLOCKS_PER_SEC) << "s\n";
#endif
}