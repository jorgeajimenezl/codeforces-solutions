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
        // TODO: Here        
        int n, k;
        cin >> n >> k;

        vector<int> x(n), y(n), l(n), r(n);
        for (int i = 0; i < n; i++)
            cin >> x[i];
        for (int i = 0; i < n; i++)
            cin >> y[i];

        sort(x.begin(), x.end());
        
        for (int i = 0; i < n; i++) {
            int lo = lower_bound(x.begin(), x.end(), x[i] - k) - x.begin();
            l[i] = i > 0 ? max(i - lo + 1, l[i - 1]) : i - lo + 1;
        }

        for (int i = n - 1; i >= 0; i--) {
            int hi = upper_bound(x.begin(), x.end(), x[i] + k) - x.begin();
            r[i] = i < n - 1 ? max(hi - i, r[i + 1]) : hi - i;
        }

        int ans = 1;
        for (int i = 0; i < n - 1; i++)
            ans = max(ans, l[i] + r[i + 1]);
        cout << ans << "\n";
    }
	
    
#if _DEBUG
    cout << "Time elapsed: " << double(clock()) / double(CLOCKS_PER_SEC) << "s\n";
#endif
}