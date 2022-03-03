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
        int n;
        cin >> n;
        
        vector<int> b(n + 1);
        vector<int> p(n + 1);
        vector<vector<int>> graph(n + 1);
        vector<int> depth(n + 1);
        vector<int> dist(n + 1);
        int root = -1;

        for (int i = 1; i <= n; i++) {
            cin >> b[i];
            if (b[i] != i)
                graph[b[i]].push_back(i);
            else
                root = i;
        }
        for (int i = 1; i <= n; i++)
            cin >> p[i];

        queue<int> q;
        q.push(root);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : graph[u]) {
                depth[v] = depth[u] + 1;
                q.push(v);
            }
        }

        vector<int> id(n + 1);
        for (int i = 1; i <= n; i++)
            id[p[i]] = i;
        
        bool flag = 0;
        for (int i = 1; i <= n; i++)
            if (id[b[i]] > id[i]) 
                flag = 1;
        if (flag) {
            cout << "-1\n";
            continue;
        }

        int cnt = 0;
        vector<int> ans(n);
        for (int i = 1; i <= n; i++) {
            ans[p[i] - 1] = cnt - dist[b[p[i]]];
            dist[p[i]] = cnt;
            cnt++;
        }

        cout << ans << "\n";
    }

#if _DEBUG
    cout << "Time elapsed: " << double(clock()) / double(CLOCKS_PER_SEC) << "s\n";
#endif
}