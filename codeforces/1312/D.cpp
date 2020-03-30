#include <bits/stdc++.h>

using namespace std;

const int64_t mod = 998244353;

int64_t sq (int64_t x) {
    return (x * x) % mod;
}

int64_t pw (int64_t a, int64_t b) {
    if (b < 0)
        return pw(pw(a, mod - 2), b * -1LL);
    if (b == 0)
        return 1LL;
    if (b > 0)
        return (b & 1) ? (pw(a, b - 1LL) * a) % mod : sq(pw(a, b >> 1LL));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#if _DEBUG
    freopen("a.in", "r", stdin);
#endif

    int64_t n, m;
    cin >> n >> m;

    vector<int64_t> fact = { 1 };
    for (int64_t i = 1LL; i <= m; i++)
        fact.push_back((i * fact.back()) % mod);

    int64_t ans = (((((fact[m] * (pw((fact[n - 1] * fact[m - n + 1]) % mod, -1))) % mod) * 
                    (n - 2)) % mod) * pw(2LL, n - 3)) % mod;

    cout << ans << "\n";
}