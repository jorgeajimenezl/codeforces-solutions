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
        int n, x, y;
        cin >> n >> x >> y;

        for (int i = 1; i <= max(x, y); i++)
            if ((x % i) == (y % i) && (y / i) - (x / i) <= n - 1) {
                int m = (x % i);
                int t = max(y / i - n + 1, m == 0 ? 1 : 0);
                
                while (n--) {
                    cout << (t * i + m) << " "[n == 0];
                    t++;                    
                }
                cout << "\n";
                break;
            }
    }
	
    
#if _DEBUG
    cout << "Time elapsed: " << double(clock()) / double(CLOCKS_PER_SEC) << "s\n";
#endif
}