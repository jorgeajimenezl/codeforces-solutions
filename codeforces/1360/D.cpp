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
        int n, k;
        cin >> n >> k;
        
        int ans = 1 << 30;
        for (int i = 2; i * i <= n && i <= k; i++)
            if (n % i == 0) {
                ans = min(ans, n / i);
                if (n / i <= k)
                    ans = min(ans, i);
            }

        if (n <= k)
            ans = 1;
        cout << (ans != 1 << 30 ? ans : n) << "\n";
    }
}

