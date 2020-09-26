//Coder: jorgeajimenezl
#include <bits/stdc++.h>

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

    int T;
    cin >> T;

    while (T--) {
        // TODO: Here        
        int64_t a, b, x, y, n;
        cin >> a >> b >> x >> y >> n;

        int64_t t1 = (b - n >= y) ? n : (b - y);
        int64_t t2 = (a - n >= x) ? n : (a - x);

        int64_t ans = min((b - t1) * (a - ((a - (n - t1) >= x) ? (n - t1) : (a - x))),
                    (a - t2) * (b - ((b - (n - t2) >= y) ? (n - t2) : (b - y))));

        cout << ans << "\n";
    }
	
    
#if _DEBUG
    cout << "Time elapsed: " << double(clock()) / double(CLOCKS_PER_SEC) << "s\n";
#endif
}