#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int64_t n, k;
        cin >> n >> k;

        int64_t d = n / k;
        int64_t r = n - k * d;

        cout << d * k + min(k / 2, r) << "\n";
    }
}