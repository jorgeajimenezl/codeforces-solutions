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
        int n, k;
        cin >> n >> k;

        vector<int> v(n);
        for (int &x : v) cin >> x;
        sort(v.begin(), v.end(), greater<int>());
        int ans = 0;
        double sum = 0;

        for (int i = 0; i < n; i++)
            if (double(sum + v[i]) / double(i + 1) >= k) {
                sum += v[i];
                ans++;
            }      

        cout << ans << "\n";               
    }
}
