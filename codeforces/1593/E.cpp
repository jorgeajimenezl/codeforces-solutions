// Coder: jorgeajimenezl
#include <bits/stdc++.h>
// #pragma GCC optimize ("Ofast")

using namespace std;

#if _DEBUG
#define debug(x) cerr << #x << ": " << x << endl;
#else
#define debug(x)
#endif

inline int mod (int x, int m) {
    if (x < 0)
        return m - ((-x) % m);
    return x % m;
}

#define max(a, b) ((a > b) ? a : b)

int main() {
#if _DEBUG
    freopen("a.in", "r", stdin);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int T = 1;
    cin >> T;    
    const int mxn = 1e6 + 1;

    while (T--) {
        int n, k;
        cin >> n >> k;

        vector<vector<int>> graph(n + 1);
        vector<int> degree(n + 1);

        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;

            graph[u].push_back(v);
            graph[v].push_back(u);

            degree[u]++;
            degree[v]++;
        }

        if (n <= 2) {
            cout << "0\n";
            continue;
        }

        queue<int> q;
        vector<bool> vst(n + 1);

        for (int u = 1; u <= n; u++)
            if (degree[u] <= 1) {
                q.push(u);
                vst[u] = 1;
            }

        int cnt = 0;        

        for (int i = 0; i < k && !q.empty(); i++) {            
            int m = q.size();
            cnt += m;

            while (m--) {
                int u = q.front();                
                q.pop();
                degree[u] = 0;

                for (int v : graph[u])
                    degree[v]--;

                for (int v : graph[u])
                    if (!vst[v] && degree[v] <= 1) {
                        degree[v]--;
                        vst[v] = 1;
                        q.push(v);
                    }
            }             
        }

        cout << n - cnt << "\n";
    }
    
#if _DEBUG
    cout << "Time elapsed: " << double(clock()) / double(CLOCKS_PER_SEC) << "s\n";
#endif
}