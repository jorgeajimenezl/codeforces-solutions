#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << endl;

using namespace std;

int64_t clamp (int64_t x, int64_t a, int64_t b) {
    x = min(x, b);
    x = max(x, a);
    return x;
}

int main() {
#if _DEBUG
    freopen("a.in", "r", stdin);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif

    int T;
    //cin >> T;
    T = 1;
    
    while (T--) {
        int64_t n, s;
        cin >> n >> s;

        if (s / n > 1) {
            cout << "YES\n";
            for (int i = 0; i < n; i++)
                cout << (i != n - 1 ? s / n : s / n + s % n) << " \n"[i == n - 1];
            cout << "1\n";
        } else {
            cout << "NO\n";
        }
    }
}

