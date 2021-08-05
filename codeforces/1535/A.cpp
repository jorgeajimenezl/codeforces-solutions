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
        int s1, s2, s3, s4;
        cin >> s1 >> s2 >> s3 >> s4;

        if (max(s1, s2) < min(s3, s4) || max(s3, s4) < min(s1, s2))
            cout << "NO\n";
        else
            cout << "YES\n";
    }

#if _DEBUG
    cout << "Time elapsed: " << double(clock()) / double(CLOCKS_PER_SEC) << "s\n";
#endif
}