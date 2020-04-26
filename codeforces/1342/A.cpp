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
        int64_t x, y, a, b;
        cin >> x >> y >> a >> b;
        cout << min(abs(x - y) * a + min(x, y) * b, x * a + y * a) << "\n";
    }
}
