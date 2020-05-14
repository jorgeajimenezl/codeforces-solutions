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
        int64_t n, m;
        cin >> n >> m;

        if (n == 1)
            cout << 0 << "\n";
        else if (n == 2)
            cout << m << "\n";
        else
            cout << 2 * m << "\n";
    }
}
