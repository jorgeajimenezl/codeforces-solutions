//Coder: jorgeajimenezl
#include <bits/stdc++.h>
#define MAXN 100

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

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<vector<int>> graph(n + 1);
        vector<int> sz(n + 1);

        function<int (int, int)> build = [&](int u, int p) {
            int leaf = u;
            sz[u] = 1;
            for (int v : graph[u])
                if (v != p) {
                    leaf = build(v, u);
                    sz[u] += sz[v];
                }
            return leaf;
        };

        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        if (n & 1) {
            cout << "1 " <<  graph[1].front() << "\n";            
            cout << "1 " <<  graph[1].front() << "\n";
            continue;  
        }

        build(1, -1);
        int centroid = 1, parent = -1;
        while (1) {
            int heavy = -1;
            bool flag = 1;

            for (int v : graph[centroid]) {
                if (v == parent)
                    continue;
                if (heavy == -1 || sz[heavy] < sz[v])
                    heavy = v;
                if (sz[v] > (n >> 1))
                    flag = 0;
            }

            if (flag)
                break;
            else {
                parent = centroid;
                centroid = heavy;
            }
        }

        int k = -1, leaf = -1;
        for (int v : graph[centroid]) {
            leaf = build(v, centroid);
            if (sz[v] == (n >> 1)) {
                k = v;
                break;
            }
        }
        
        if (k == -1) {
            cout << "1 " <<  graph[1].front() << "\n";            
            cout << "1 " <<  graph[1].front() << "\n";
        } else {
            cout << leaf << " " << graph[leaf].front() << "\n";
            cout << centroid << " " << leaf << "\n";
        }
    }
	
    
#if _DEBUG
    cout << "Time elapsed: " << double(clock()) / double(CLOCKS_PER_SEC) << "s\n";
#endif
}