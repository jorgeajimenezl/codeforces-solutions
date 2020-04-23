#include <bits/stdc++.h>

using namespace std;

int st[4 * 200005];

int query (int u, int s, int e, int l, int r) {
    if (e < l || s > r)
        return 1 << 30;
    if (l <= s && e <= r)
        return st[u];
    
    int m = (s + e) >> 1;
    return min(query(2 * u, s, m, l, r), query(2 * u + 1, m + 1, e, l, r));
}

void update (int u, int s, int e, int i, int x) {
    if (s == e) {
        st[u] = x;
        return;
    }

    int m = (s + e) >> 1;
    if (i <= m)
        update(2 * u, s, m, i, x);
    else
        update(2 * u + 1, m + 1, e, i, x);

    st[u] = min(st[2 * u], st[2 * u + 1]);
}

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

        vector<int> id(n + 1);
        vector<int> v(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
            id[v[i]] = i;
        }

        vector<int> dp(n + 1), mx(n + 1);
        multiset<int, greater<int>> mst;

        for (int i = 1; i <= n; i++) {
            dp[i] = i;
            mx[i] = 1;
            update(1, 1, n, i, i);
            mst.insert(1);
        }
        
        int hi = 1;
        bool flag = 1;

        for (int i = 1; i <= n; i++) {
            int u = id[i];
            if (mx[u] != *mst.begin()) {
                flag = 0;
                break;
            }

            auto d = mst.find(mx[u]);
            mst.erase(d);

            mx[u] = 0;
            update(1, 1, n, u, 1 << 30);

            int q = query(1, 1, n, u, n);
            if (q != 1 << 30) {
                mx[q]++;
                mst.insert(mx[q]);
            }
        }

        cout << (flag ? "Yes\n" : "No\n");

        for (int i = 0; i <= 4 * n + 5; i++)
            st[i] = 0;
    }
}
