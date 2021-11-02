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
        // int n;
        // cin >> n;

        string a, s;
        cin >> a >> s;

        vector<int> mp(256);
        for (int i = 0; i < a.length(); i++)
            mp[a[i]] = i;

        int ans = 0;
        for (int i = 1; i < s.length(); i++)
            ans += abs(mp[s[i]] - mp[s[i - 1]]);
        cout << ans << "\n";
    }
    
#if _DEBUG
    cout << "Time elapsed: " << double(clock()) / double(CLOCKS_PER_SEC) << "s\n";
#endif
}