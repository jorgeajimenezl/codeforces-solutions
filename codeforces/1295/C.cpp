#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        string s;
        string t;
        cin >> s >> t;
        vector<vector<int>> v(256);

        for (int i = 0; i < s.length(); i++) {
            v[s[i]].push_back(i);
        }

        int ans = 1;
        int lst = -1;
        bool flag = 0;

        for (int i = 0; i < t.length(); i++) {           
            if (v[t[i]].empty()) {
                flag = 1;
                break;
            }

            auto pos = lower_bound(v[t[i]].begin(), v[t[i]].end(), lst + 1);
            
            if (pos == v[t[i]].end()) {
                ans ++;
                lst = v[t[i]][0];
            }
            else
                lst = *pos;
        }

        if (flag)
            cout << "-1\n";
        else
            cout << ans << "\n";        
    }
}