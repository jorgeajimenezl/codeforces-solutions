//Coder: jorgeajimenezl
#include <bits/stdc++.h>
// #pragma GCC optimize ("Ofast")

using namespace std;

#if _DEBUG
#define debug(x) cerr << #x << ": " << x << endl;
#endif

int const maxn = 1e6+5;
int st[maxn * 5];
int lazy[maxn * 5];

inline void clear(int u) {
    if (!lazy[u]) 
        return;

    st[u << 1] += lazy[u];
    st[u << 1 | 1] += lazy[u];

    lazy[u << 1] += lazy[u];
    lazy[u << 1 | 1] += lazy[u];

    lazy[u] = 0;
}

void update(int u, int s, int e, int l, int r, int x) {
    if (r < s || l > e)
        return;

    if (l <= s && e <= r) {
        st[u] += x;
        lazy[u] += x;
        return;
    }

    clear(u);
    int m = (s + e) >> 1;
    update(u << 1, s, m, l, r, x);
    update(u << 1 | 1, m + 1, e, l, r, x);

    st[u] = min(st[u << 1], st[u << 1 | 1]);
}

int query(int u, int s, int e, int l, int r) {
    if (r < s || l > e)
        return INT_MAX;

    if (l <= s && e <= r)
        return st[u];

    clear(u);
    int m = (s + e) >> 1;
    return min(query(u << 1, s, m, l, r), query(u << 1 | 1, m + 1, e, l, r));
}

struct segment {
    int l, r, w;
};

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

        vector<segment> v(n);
        for (auto &x : v) cin >> x.l >> x.r >> x.w;
        sort(v.begin(), v.end(), [](const segment& a, const segment& b) {
            return a.w < b.w;
        });

        int r = 0;
        int ans = INT_MAX;

        for (int l = 0; l < n; l++) {
            while (r < n && query(1, 1, maxn, 1, m - 1) == 0) {
                update(1, 1, maxn, v[r].l, v[r].r - 1, +1);
                r++;
            }  

            if (query(1, 1, maxn, 1, m - 1) != 0)
                ans = min(ans, v[r - 1].w - v[l].w);

            update(1, 1, maxn, v[l].l, v[l].r - 1, -1);
        }

        cout << ans << "\n";
    }

#if _DEBUG
    cout << "Time elapsed: " << double(clock()) / double(CLOCKS_PER_SEC) << "s\n";
#endif
}