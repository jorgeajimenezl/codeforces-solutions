#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << endl;

using namespace std;

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
        int n;
        cin >> n;

        vector<int64_t> v(n);
        for (int64_t &x : v)
            cin >> x;

        int64_t ans = 0;

        for (int i = 0; i < n; i++)
            ans = max(ans, v[i]);

        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                ans = max(ans, v[i] | v[j]);

        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                for (int k = j + 1; k < n; k++)
                    ans = max(ans, v[i] | v[j] | v[k]);

        cout << ans << "\n";
    }
}
