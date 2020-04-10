#include <bits/stdc++.h>

using namespace std;

int st[4 * 200005 + 5];

void build (int u, int s, int e, const vector<int>& v) {
    if (s == e) {
        st[u] = v[s];
        return;
    }

    int m = (s + e) >> 1;
    build(2 * u, s, m, v);
    build(2 * u + 1, m + 1, e, v);

    st[u] = max(st[2 * u], st[2 * u + 1]);
}

int query (int u, int s, int e, int l, int r) {
    if (e < l || s > r)
        return INT_MIN;

    if (l <= s && e <= r)
        return st[u];

    int m = (s + e) >> 1;
    return max(query(2 * u, s, m, l, r), query(2 * u + 1, m + 1, e, l, r));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#if _DEBUG
    freopen("a.in", "r", stdin);
#endif

    int n;
    cin >> n;

    vector<int> v(n + 1);
    map<int64_t, int> id;
    int64_t x, sum = 0;
    id[0] = 1;
    
    for (int i = 1; i <= n; i++) {
        cin >> x;
        sum += x;
        v[i] = id[sum];
        id[sum] = i + 1;
    }

    build(1, 1, n, v);
    int64_t ans = 0;

    for (int i = 1; i <= n; i++) {
        int lo = i, hi = n;

        while (lo < hi) {
            int m = (lo + hi) >> 1;

            if (query(1, 1, n, i, m) >= i)
                hi = m;
            else
                lo = m + 1; 
        }

        if (query(1, 1, n, i, lo) >= i)
            lo--;

        if (lo >= i)
            ans += lo - i + 1;
    }

    cout << ans;
}
