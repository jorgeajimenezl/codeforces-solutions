//http://codeforces.com/contest/1288/problem/C
//Coder: jorgeajimenezl
#include <bits/stdc++.h>

using namespace std;

const int64_t mod = 1e9+7;

int64_t dp[2005][2005];

void compute () {
    for (int i = 0; i <= 2000; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= 2000; i++)
        for (int j = 1; j <= i; j++)
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % mod;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    compute();

    int64_t n, m;
    cin >> n >> m;
    cout << dp[n + 2 * m - 1][2 * m];
}