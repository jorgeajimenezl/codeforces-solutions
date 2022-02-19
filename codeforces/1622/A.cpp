// Coder: jorgeajimenezl
#include <bits/stdc++.h>
// #pragma GCC optimize ("Ofast")

using namespace std;

#if _DEBUG
#define debug(x) cerr << #x << ": " << x << endl;
#else
#define debug(x)
#endif
// #define max(a, b) ((a > b) ? a : b)
// #define min(a, b) ((a < b) ? a : b)


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
        vector<int> a(3);
        cin >> a[0] >> a[1] >> a[2];
        sort(a.begin(), a.end());
        if ((a[0] == a[1] && a[2] % 2 == 0) ||
            (a[1] == a[2] && a[0] % 2 == 0) ||
            a[0] + a[1] == a[2] )
            cout << "YES\n";
        else
            cout << "NO\n";
    }

#if _DEBUG
    cout << "Time elapsed: " << double(clock()) / double(CLOCKS_PER_SEC) << "s\n";
#endif
}