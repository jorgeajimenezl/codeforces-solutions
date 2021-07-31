//Coder: jorgeajimenezl
#include <bits/stdc++.h>
// #pragma GCC optimize ("Ofast")

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

    int T = 1;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> a(n + 1), b(n + 1), pa(n + 1), suma(n + 1), sumb(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            suma[i] = suma[i - 1] + a[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
            sumb[i] = sumb[i - 1] + b[i];
        }

        int ans = INT_MAX;
        for (int i = 1; i <= n; i++) {
            // int partial = 0;
            // for (int j = 1; j <= n; j++)
            //     partial = max(partial, (i >= j ? 0 : suma[j] - suma[i]) + (j >= i ? 0 : sumb[i - 1] - sumb[j - 1]));
            ans = min(ans, max(suma[n] - suma[i], sumb[i - 1]));
        }

        cout << ans << "\n";
    }

#if _DEBUG
    cout << "Time elapsed: " << double(clock()) / double(CLOCKS_PER_SEC) << "s\n";
#endif
}