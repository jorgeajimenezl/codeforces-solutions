//Coder: jorgeajimenezl
#include <bits/stdc++.h>
// #pragma GCC optimize ("Ofast")

using namespace std;

#if _DEBUG
#define debug(x) cerr << #x << ": " << x << endl;
#else
#define debug(x)
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
        string s;
        cin >> s;

        int n = s.length();
        int ans = 1 << 30;

        // int64_t m = 0;
        // int cnt = 0;
        
        // for (int i = 0; i < (1 << n); i++) {
        //     m = cnt = 0;
        //     for (int j = 0; j < n; j++)
        //         if (!(i & (1 << j)))
        //             m = m * 10 + (s[j] - '0');
        //         else
        //             cnt++;

        //     if (m % 25 == 0)
        //         ans = min(ans, cnt);
        // }
        // 00
        auto query = [&](const string &g) {
            int p = 0, cnt = 0;
            for (int i = n - 1; i >= 0; i--)
                if (s[i] != g[p])
                    cnt++;
                else {
                    p++;
                    if (p == g.size())
                        break;
                }
            return p == g.size() ? cnt : 1 << 30;
        };        

        cout << min({query("52"), query("00"), query("05"), query("57")}) << "\n";
    }
	
    
#if _DEBUG
    cout << "Time elapsed: " << double(clock()) / double(CLOCKS_PER_SEC) << "s\n";
#endif
}