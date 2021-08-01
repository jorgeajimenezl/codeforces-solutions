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
    // cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        vector<set<int>> graph(n + 1);
        int ans = 0;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            graph[min(u, v)].insert(max(u, v));
        }
        for (int i = 1; i <= n; i++)
            if (graph[i].empty())
                ans++;

        int q;
        cin >> q;

        while (q--) {
            int t, u, v;
            cin >> t;
            if (t == 1) {
                cin >> u >> v;
                if (graph[min(u, v)].empty())
                    ans--;
                graph[min(u, v)].insert(max(u, v));
            }
            if (t == 2) {
                cin >> u >> v;
                if (graph[min(u, v)].size() == 1)
                    ans++;
                graph[min(u, v)].erase(max(u, v));
            }
            if (t == 3)
                cout << ans << "\n";
        }
    
    }

#if _DEBUG
    cout << "Time elapsed: " << double(clock()) / double(CLOCKS_PER_SEC) << "s\n";
#endif
}