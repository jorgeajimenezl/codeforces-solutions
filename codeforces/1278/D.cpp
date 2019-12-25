#include <bits/stdc++.h>

using namespace std;

struct segment {
    int l, r;
} st[500005];

int dsu[500005];

int find (int u) {
    if (dsu[u] == u)
        return u;

    return dsu[u] = find(dsu[u]);
}

int main() {   
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> st[i].l >> st[i].r;
        dsu[i] = i;
    }

    sort(st, st + n, [](const segment &a, const segment &b) {
        return a.l != b.l ? a.l < b.l : a.r < b.r;
    });
    int k = n - 1;
    set<pair<int, int>> s;

    for (int u = 0; u < n; u++) {      
        s.erase(s.begin(), s.upper_bound({st[u].l, n + 1}));
        auto hi = s.upper_bound({st[u].r, n + 1});
        
        for (auto v = s.begin(); v != hi; v++) {
            int x = find(u);
            int y = find(v->second);

            if (x == y) {
                cout << "NO";
                return 0;
            }
            
            dsu[y] = x;
            k--;
        }

        s.insert({st[u].r, u});
    }

    cout << (!k ? "YES" : "NO");
}