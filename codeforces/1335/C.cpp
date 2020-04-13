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
        vector<int> v(n);
        map<int, int> mp;
        for (int &x : v) {
            cin >> x;
            mp[x]++;
        }

        if (n == 1) {
            cout << "0\n";
            continue;
        }

        int ans = 0;
        for (auto i : mp) {
            ans = max(ans, min(int(mp.size() - 1), i.second));
            if (i.second > int(mp.size()))
                ans = max(ans, min(int(mp.size()), i.second));
        }

        cout << ans << "\n";
    }
}
