// Coder: jorgeajimenezl
#include <bits/stdc++.h>
// #pragma GCC optimize ("Ofast")

using namespace std;

#if _DEBUG
#define debug(x) cerr << #x << ": " << x << endl;
#else
#define debug(x)
#endif
#define max(a, b) ((a > b) ? a : b)

int main() {
#if _DEBUG
    freopen("a.in", "r", stdin);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int T = 1;
    cin >> T;   

    while (T--) {
        int n;
        cin >> n;

        vector<int64_t> v(n);
        for (int64_t &x : v) cin >> x;
        sort(v.begin(), v.end());

        int64_t sum = 0, ans = v[0];
        for (int i = 0 ; i < n; i++) {
            ans = max(ans, v[i] - sum);
            sum += (v[i] - sum);            
        }

        cout << ans << "\n";
    }
    
#if _DEBUG
    cout << "Time elapsed: " << double(clock()) / double(CLOCKS_PER_SEC) << "s\n";
#endif
}