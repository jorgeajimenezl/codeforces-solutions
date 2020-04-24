#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#if _DEBUG
    freopen("a.in", "r", stdin);
#endif

    int T;
    cin >> T;
    
    while (T--) {
        int64_t x, n, m;
        cin >> x >> n >> m;

        while (x >= 20 && n--)
            x = x / 2 + 10;
        while (m--)
            x -= 10;

        cout << (x > 0 ? "NO\n" : "YES\n");        
    }
}
