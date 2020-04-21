#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifdef _OFFLINE
    freopen("a.in", "r", stdin);
#endif

    int T;
    cin >> T;

    while (T--) {
        int64_t n;
        cin >> n;

        if ((n / 2) % 2 == 1) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";

        int64_t sum = ((n/2)+1)*((n/2)+1) - ((n/2)+1);
        for (int64_t i = 1; i <= n / 2; i++)
            cout << 2 * i << " ";

        for (int64_t i = 1; i <= n / 2 - 1; i++) {
            cout << 2 * i - 1 << " ";  
            sum -= (2 * i - 1);                      
        }

        cout << sum << "\n";        

    }
}