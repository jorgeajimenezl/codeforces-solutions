#include <bits/stdc++.h>

using namespace std;

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

        vector<pair<int64_t, int64_t>> v(n);
        for (auto &x : v) cin >> x.first >> x.second;
        
        int64_t ans = 0, bst = LLONG_MAX;

        for (int i = 0; i < n; i++) {
            ans += max(v[(i + 1) % n].first - v[i].second, int64_t(0));
            bst = min(bst, min(v[(i + 1) % n].first, v[i].second));
        }

        cout << ans + bst << "\n";
    }
}
