#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << endl;
#define all(x) x.begin(), x.end()

using namespace std;

int main() {
#if _DEBUG
    freopen("a.in", "r", stdin);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif

    int T;
    cin >> T;
    
    while (T--) {
        // Code here
        int64_t n;
        cin >> n;

        vector<int64_t> v(n);
        int64_t sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            if (!(i & 1)) sum += v[i];
        }
        
        int64_t s1 = 0, s2 = 0, cur1 = 0, cur2 = 0;
        for (int64_t i = 0; i < n - (n & 1); i += 2) {
            s1 += v[i];
            s2 += v[i + 1];

            if (s2 - s1 > 0) {
                cur1 = max(cur1, s2 - s1);
            } else
                s1 = s2 = 0;
        }

        s1 = 0, s2 = 0;

        for (int64_t i = 1; i < n - (!(n & 1)); i += 2) {
            s1 += v[i + 1];
            s2 += v[i];

            if (s2 - s1 > 0) {
                cur2 = max(cur2, s2 - s1);
            } else
                s1 = s2 = 0;
        }
        
        cout << max({sum, sum + cur1, sum + cur2}) << "\n";
    }
}

