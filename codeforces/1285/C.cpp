//http://codeforces.com/contest/1285/problem/C
//Coder: jorgeajimenezl
#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int64_t n;
    cin >> n;

    int64_t sq = sqrt(n);
    int64_t ans = 1e13;

    for (int64_t i = 1; i <= sq; i++)
        if (n % i == 0 && __gcd(i, n / i) == 1)
            ans = min(ans, max(i, n / i));

    if (ans != 1 << 30)
        cout << ans << " " << n / ans;
    else
        cout << "1 " << n;
}