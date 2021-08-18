//Coder: jorgeajimenezl
#include <bits/stdc++.h>
// #pragma GCC optimize ("Ofast")

using namespace std;

#if _DEBUG
#define debug(x) cerr << #x << ": " << x << endl;
#else
#define debug(x)
#endif

inline int64_t sum (int64_t x) {
    return (x * (x + 1)) / 2;
}

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

        vector<int> v(n);
        for (int &x : v) cin >> x;
        int ans = *min_element(v.begin(), v.end());
        for (int i = 0; i < n; i++)
            ans &= v[i];
        cout << ans << "\n";
    }

#if _DEBUG
    cout << "Time elapsed: " << double(clock()) / double(CLOCKS_PER_SEC) << "s\n";
#endif
}
