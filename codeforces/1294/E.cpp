#include <bits/stdc++.h>

using namespace std;

int mod (int x, int m) {
    return x >= 0 ? x % m : x + m;
}

int main() {
    //freopen("a.in", "r", stdin);
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> st(n);

    for (int i = 0; i < n; i++) {
        st[i].resize(m);
        
        for (int j = 0; j < m; j++) {
            cin >> st[i][j];
            st[i][j]--;
        }
    }

    int64_t ans = 0;

    for (int j = 0; j < m; j++) {
        unordered_map<int, int> mp;
        
        for (int i = 0; i < n; i++)
            if (st[i][j] % m == j)
                if (st[i][j] < n * m)
                    mp[mod(i - st[i][j] / m, n)]++;

        int best = 1 << 30;
        for (auto i : mp)
            best = min(best, i.first + n - i.second);

        ans += min(n, best);
    }

    cout << ans << "\n";
}