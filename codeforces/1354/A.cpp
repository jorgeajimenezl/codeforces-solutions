#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << endl;

using namespace std;

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
        int64_t a, b, c, d;
        cin >> a >> b >> c >> d;

        if (a > b and c <= d)        
            cout << "-1\n";
        else if (a <= b)
            cout << b << "\n";
        else {
            int64_t e = (a - b) / (c - d) + ((a - b) % (c - d) != 0);
            cout << b + e * c << "\n";
        }
    }
}

