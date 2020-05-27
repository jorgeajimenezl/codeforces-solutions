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
        int n, m;
        cin >> n >> m;
        
        int ans = n / 2 * m + (n % 2 != 0 ? m / 2 + (m % 2) : 0);
        swap(n, m);
        ans = min(ans, n / 2 * m + (n % 2 != 0 ? m / 2 + (m % 2) : 0));
        cout << ans << "\n";
    }
}
