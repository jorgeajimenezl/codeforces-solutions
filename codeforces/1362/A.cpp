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
        int64_t a, b;
        cin >> a >> b;

        if (a < b)
            swap(a, b);

        int64_t ans = 0;
        int64_t t = a / b;
        for (int64_t i = 3; i >= 1; i--)
            while (t % (1LL << i) == 0) {
                ans++;
                t >>= i;
            }

        cout << (t != 1 || a % b != 0 ? -1 : ans) << "\n";
    }
}
