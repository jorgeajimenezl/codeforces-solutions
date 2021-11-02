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

        vector<int> v(n);
        for (int &x : v) cin >> x;

        string s;
        cin >> s;

        vector<int> b, r;
        for (int i = 0; i < n; i++)
            if (s[i] == 'B')
                b.push_back(v[i]);
            else
                r.push_back(v[i]);

        sort(b.begin(), b.end());
        sort(r.begin(), r.end(), greater<int>());

        int bp = 0, br = 0;
        int lo = 1, hi = n;

        for ( ; hi >= 1; hi--, br++) {
            while (br < r.size() && r[br] > hi)
                br++;
            if (br >= r.size() || r[br] > hi)
                break;
        }

        for ( ; lo <= n; lo++, bp++) {
            while (bp < b.size() && b[bp] < lo)
                bp++;
            if (bp >= b.size() || b[bp] < lo)
                break;
        }

        cout << (lo > hi ? "YES\n" : "NO\n");
    }
#if _DEBUG
    cout << "Time elapsed: " << double(clock()) / double(CLOCKS_PER_SEC) << "s\n";
#endif
}