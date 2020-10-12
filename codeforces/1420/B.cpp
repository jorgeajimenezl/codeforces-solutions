//Coder: jorgeajimenezl
#include <bits/stdc++.h>

using namespace std;

#if _DEBUG
#define debug(x) cerr << #x << ": " << x << endl;
#endif

int main() {
#if _DEBUG
    freopen("a.in", "r", stdin);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> v(n);
        for (int& x : v)
            cin >> x;

        vector<int> m(35);

        int64_t ans = 0;

        for (int i = 0; i < n; i++) {
            int l = __lg(v[i]);
            ans += m[l];
            m[l]++;
        }

        cout << ans << "\n";
    }	
    
#if _DEBUG
    cout << "Time elapsed: " << double(clock()) / double(CLOCKS_PER_SEC) << "s\n";
#endif
}