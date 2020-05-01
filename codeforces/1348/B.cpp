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
        int n, k;
        cin >> n >> k;

        vector<int64_t> v(n + 1);
        map<int, int> mp;
        for (int i = 1; i <= n; i++) {
            cin >> v[i]; 
            mp[v[i]] = 1;           
        }

        if (mp.size() > k) {
            cout << -1 << "\n";
            continue;
        }

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            int ret = k - mp.size() + 1;
            
            for (auto x : mp) {
                for (int j = 0; j < ret; j++)
                    ans.push_back(x.first);
                ret = 1;
            }
        }

    
        cout << ans.size() << "\n" << ans[0];
        for (int i = 1; i < ans.size(); i++)
            cout << " " << ans[i];
        cout << "\n";
    }
}
