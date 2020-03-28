#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifdef OFFLINE
    freopen("a.in", "r", stdin);
#endif

    int T;
    cin >> T;

    while (T--) {
        int64_t n, k;
        cin >> n >> k;

        if (n < k * k || n % 2 != k % 2)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    
}