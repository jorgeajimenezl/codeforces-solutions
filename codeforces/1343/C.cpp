#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifdef _OFFLINE
    freopen("a.in", "r", stdin);
#endif

    int T;
    cin >> T;

    while (T--) {
        int64_t n;
        cin >> n;

        vector<int64_t> v(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> v[i];

        int64_t ans = 0;
        int64_t m = v[1];
        int64_t s = v[1] >= 0 ? 0 : 1;

        for (int i = 2; i <= n; i++) {           
            if (s == 0 && v[i] < 0 || s == 1 && v[i] >= 0) {                
                ans += m;
                s = v[i] < 0 ? 1 : 0;
                m = INT_MIN;
            } 

            m = max(m, v[i]);
        }

        cout << ans + m << "\n";
    }
}