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
        uint64_t n;
        cin >> n;

        auto div = [](uint64_t a, uint64_t b) {
            long double d = (long double)(a) / (long double)(b);
            return (uint64_t)round(d);
        };

        uint64_t ans = 0;
        uint64_t i = 1;

        for ( ; (1ULL << i) <= n; i++)
            ans += div(n, 1ULL << i) * i;

        ans += i;

        cout << ans << "\n";
    }
}

