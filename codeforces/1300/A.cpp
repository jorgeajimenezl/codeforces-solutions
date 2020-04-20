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
        int sum = 0;
        int ans = 0;

        while (n--) {
            int x; cin >> x;
            sum += x == 0 ? 1 : x;
            ans += (x == 0);
        }

        cout << ans + (sum == 0) << "\n";
    }
}