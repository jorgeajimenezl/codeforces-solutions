#include <bits/stdc++.h>

using namespace std;

int main() {
    #ifdef OFFLINE_DEBUG
    freopen("a.in", "r", stdin);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);    

    int T = 1;
    //cin >> T;

    while (T--)
    {
        int64_t n, a, b, k;
        cin >> n >> a >> b >> k;

        int ans = 0;
        vector<int> v;

        for (int i = 0; i < n; i++) {
            int64_t x;
            cin >> x;

            int64_t u = (x - a) / (a + b);

            if (x - u * (a + b) <= a || x - (u + 1) * (a + b) > 0 && x - (u + 1) * (a + b) <= a)
                ans++;
            else {
                v.push_back((x - u * (a + b)) / a - 1 + ((x - u * (a + b)) % a != 0));
            }
        }

        sort(v.begin(), v.end());

        for (int i : v) {
            if (k - i >= 0) {
                ans++;
                k -= i;
            } else
                break;
        }

        cout << ans << "\n";
    }    
}