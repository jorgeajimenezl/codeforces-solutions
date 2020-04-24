#include <bits/stdc++.h>
#define MAXN 200005

using namespace std;

vector<int> graph[MAXN];
int depth[MAXN], sub[MAXN];
int sz = 0;

void dfs (int u, int p) {
    sub[u] = 1;
    
    for (int v : graph[u])
        if (v != p) {
            depth[v] = depth[u] + 1;
            dfs(v, u);
            sub[u] += sub[v];
        }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#if _DEBUG
    freopen("a.in", "r", stdin);
#endif

    int T = 1;
    //cin >> T;
    
    while (T--) {
        int n, k;
        cin >> n >> k;        

        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        dfs(1, 0);

        long long ans = 0;
        vector<long long> st;
        for (int u = 1; u <= n; u++) {
            sub[u]--;
            st.push_back(depth[u] - sub[u]);
        }

        sort(st.begin(), st.end(), greater<long long>());
        for (int i = 0; i < k; i++)
            ans += st[i];

        cout << (n > k ? ans : 0) << "\n";           
    }
}
