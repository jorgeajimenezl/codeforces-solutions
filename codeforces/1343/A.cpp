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

        for (int k = 2; k <= 30; k++) {
            if ((n) % ((1 << k) - 1) == 0) {
                cout << n/ ((1 << k) - 1) << "\n";
                break;
            }
        }
    }
}