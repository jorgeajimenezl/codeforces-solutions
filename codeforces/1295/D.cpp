#include <bits/stdc++.h>

using namespace std;

int64_t query (int64_t a, int64_t b, int64_t x) {
    int64_t ans = 0;
    vector<int64_t> v;

    int64_t u = x;
    int64_t sq = sqrt(x);
    for (int i = 2; i <= sq; i++)
        if (u % i == 0) {
            while (u % i == 0)
                u /= i;

            v.push_back(i);
        }

    if (u > 1)
        v.push_back(u);

    int n = v.size();
    for (int i = 0; i < (1 << n); i++) {
        int64_t p = 1;

        for (int j = 0; j < n; j++)
            if (i & (1 << j))
                p *= v[j];

        if (__builtin_popcount(i) & 1)
            ans -= (b - a) / p;
        else
            ans += (b - a) / p;
    }

    return ans;
}

int main () {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int64_t a, m;
        cin >> a >> m;

        int64_t p = __gcd(a, m);
        int64_t sq = sqrt(m);
        int64_t ans = m / p;

        for (int i = 1; i <= sq; i++)
            if (m % i == 0) {
                if (i > p && i % p == 0)
                    ans -= query(a / i, (m - 1 + a) / i, m / i);

                if (i * i != m && m / i > p && (m / i) % p == 0)
                    ans -= query(i * a / m, (m - 1 + a) / (m / i), i);
            }

        cout << ans << "\n";
    }
}