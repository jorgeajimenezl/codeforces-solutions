//Coder: jorgeajimenezl
#include <bits/stdc++.h>

using namespace std;

#if _DEBUG
#define debug(x) cerr << #x << ": " << x << endl;
#endif

int mod (int i, int n) {
    return (i + n) % n;
}

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

        sort(v.begin(), v.end());

        int64_t ans = LONG_LONG_MIN;
        for (int i = 0; i < n; i++) {
            int64_t p = 1;
            for (int j = i; j > i - 5; j--)
                p *= v[mod(j, n)];
            ans = max(ans, p);
        }

        cout << ans << "\n";
    }
	
    
#if _DEBUG
    cout << "Time elapsed: " << double(clock()) / double(CLOCKS_PER_SEC) << "s\n";
#endif
}