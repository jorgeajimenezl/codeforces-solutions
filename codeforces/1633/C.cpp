// jorgeajimenezl
#include <bits/stdc++.h>
#define sign(x) ((x == 0) ? (0) : ((x > 0) ? (1) : (-1)))
#define debug(x) cerr << #x << ": " << x << endl;

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("a.in", "r", stdin);

    int T;
    cin >> T;

    while (T--) {
        uint64_t hc, dc, hm, dm, k, w, a;
        cin >> hc >> dc >> hm >> dm >> k >> w >> a;
        bool flag = 0;
        for (int i = 0; i <= k; i++) {
            uint64_t nh = hc + i * a;
            uint64_t nd = dc + w * (k - i);
            if (nh / dm + (nh % dm != 0 ? 1 : 0) >= 
                hm / nd + (hm % nd != 0 ? 1 : 0)) {
                flag = 1;
                break;
            }
        }
        cout << (flag ? "YES\n" : "NO\n");
    }

    return 0;
}