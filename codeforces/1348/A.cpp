#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#if _DEBUG
    freopen("a.in", "r", stdin);
#endif

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        int64_t sum = 1LL << n;
        for (int i = 1; i < n / 2; i++)
            sum += (1LL << i);

        for (int i = n / 2; i < n; i++)
            sum -= (1LL << i);

        cout << sum << "\n";
    }
}
