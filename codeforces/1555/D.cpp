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
    // cin >> T;

    while (T--) {
        int64_t n, m;
        cin >> n >> m;

        string s;
        cin >> s;

        vector<vector<int>> mp(10);
        string pattern = "abc";
        int p = 0;

        do {
            mp[p].resize(n + 1);
            for (int i = 0, j = 0; i < n; i++, j = (j + 1) % 3) 
                mp[p][i + 1] = mp[p][i] + (s[i] != pattern[j]);
            p++;
        } while (next_permutation(pattern.begin(), pattern.end()));

        while (m--) {
            int l, r;
            cin >> l >> r;

            int ans = INT_MAX;
            for (int i = 0; i < p; i++)
                ans = min(ans, mp[i][r] - mp[i][l - 1]);
            cout << ans << "\n";
        }
    }

#if _DEBUG
    cout << "Time elapsed: " << double(clock()) / double(CLOCKS_PER_SEC) << "s\n";
#endif
}