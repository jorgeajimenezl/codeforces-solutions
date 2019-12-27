#include <bits/stdc++.h>

using namespace std;

int st[1000005];
int n, k;

int query (int i) {
    int ans = 0;
    while (i) {
        ans += st[i];
        i -= (i & -i);
    }
    return ans;
}

void update (int i) {
    while (i <= n) {
        st[i] ++;
        i += (i & -i);
    }
}

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        cin >> n >> k;
        vector<int> v(n);
        unordered_map<int, int> mp;
        vector<int> b(n);

        for (int i = 0; i <= n; i++)
            st[i] = 0;

        for (int i = 0; i < n; i++) {
            cin >> v[i];
            mp[v[i]] = i;
        }

        long long ans = 0;
        int u = 0, x;

        for (int i = 0; i < k; i++) {
            cin >> x;
            int idx = mp[x];     
            
            if (u < idx + 1) {
                ans += 2LL * (idx - query(idx + 1)) + 1LL;
                u = idx;
            } else {
                ans ++;
            }

            update(idx + 1);
        }

        cout << ans << "\n";
    }
}