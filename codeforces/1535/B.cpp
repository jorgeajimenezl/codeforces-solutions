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

        vector<int> v(n);
        for(int &x : v) cin >> x;

        sort(v.begin(), v.end(), [](int a, int b) {
            return (a & 1) < (b & 1);
        });

        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (__gcd(v[i], 2*v[j]) > 1)
                    ans++;
        cout << ans << "\n";
    }

#if _DEBUG
    cout << "Time elapsed: " << double(clock()) / double(CLOCKS_PER_SEC) << "s\n";
#endif
}