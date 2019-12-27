#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        long long  n, k;
        cin >> n >> k;
        vector<long long> v(n + 1);

        for (int i = 1; i <= n; i++) {
            cin >> v[i];
            v[i] += v[i - 1];
        }

        if (v[n] <= k) {
            cout << "0\n";
            continue;
        }

        int idx = 1;
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            if (v[i] - v[i - 1] > v[idx] - v[idx - 1])
                idx = i;
            
            if (v[i] - v[idx] + v[idx - 1] <= k) 
                ans = idx;            
        }

        cout << ans << "\n";
    }
}