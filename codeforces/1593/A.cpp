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
        int a, b, c;
        cin >> a >> b >> c;
        int d = max({a, b, c});
        map<int, int> mp;
        mp[a]++;
        mp[b]++;
        mp[c]++;

        cout << max(0, d - a + 1 - (a == d && mp[d] == 1 ? 1 : 0)) << " " << max(0, d - b + 1 - (b == d && mp[d] == 1 ? 1 : 0)) << " " << max(0, d - c + 1 - (c == d && mp[d] == 1 ? 1 : 0)) << "\n";
    }
	
    
#if _DEBUG
    cout << "Time elapsed: " << double(clock()) / double(CLOCKS_PER_SEC) << "s\n";
#endif
}