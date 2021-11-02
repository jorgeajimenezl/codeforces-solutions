// Coder: jorgeajimenezl
#include <bits/stdc++.h>
// #pragma GCC optimize ("Ofast")

using namespace std;

#if _DEBUG
#define debug(x) cerr << #x << ": " << x << endl;
#else
#define debug(x)
#endif
#define max(a, b) ((a > b) ? a : b)

int64_t solve(int64_t x, int64_t n) {
     if (x % 2 == 0 && n % 2 == 0)
        return ((n / 2) % 2 == 0 ? x : x + 1);
    if (x % 2 == 0 && n % 2 == 1)
        return ((n / 2) % 2 == 0 ? x - n : x + n + 1);
    if ((x % 2 == 1 || x % 2 == -1) && n % 2 == 1)
        return ((n / 2) % 2 == 1 ? x - n - 1 : x + n);
    if ((x % 2 == 1 || x % 2 == -1) && n % 2 == 0)
        return ((n / 2) % 2 == 1 ? x - 1 : x);
}

int64_t solve_bf(int64_t x, int64_t n) {
    for (int i = 1; i <= n; i++) {
        if (x % 2 == 0)
            x -= i;
        else
            x += i;
    }
    return x;
}

int main() {
#if _DEBUG
    freopen("a.in", "r", stdin);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int T = 1;
    cin >> T;   

    while (T--) {
        // int n;
        // cin >> n;
        int64_t x, n;
        cin >> x >> n;
        cout << solve(x, n) << "\n";
    }
#if _DEBUG
    cout << "Time elapsed: " << double(clock()) / double(CLOCKS_PER_SEC) << "s\n";
#endif
}