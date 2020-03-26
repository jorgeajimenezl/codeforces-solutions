#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#if OFFLINE
    freopen("a.in", "r", stdin);
#endif

    int T;
    cin >> T;

    while (T--) {
        int64_t a, b;
        cin >> a >> b;

        int64_t c = a / b;
        int64_t d = (c + (a % b != 0)) * b;
        cout << d - a << "\n";
    }
}