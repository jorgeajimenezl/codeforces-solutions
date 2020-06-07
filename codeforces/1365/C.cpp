#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << endl;

using namespace std;

int main() {
#if _DEBUG
    freopen("a.in", "r", stdin);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif

    int T = 1;
    // cin >> T;
    
    while (T--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n), ida(n + 1), idb(n + 1);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            ida[a[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            cin >> b[i];
            idb[b[i]] = i;
        }
        map<int, int> mp;

        auto mod = [n](int x) {
            return x >= 0 ? x % n : x + n;
        };

        for (int i = 1; i <= n; i++)
            mp[mod(ida[i] - idb[i])]++;              

        cout << max_element(mp.begin(), mp.end(), [](auto i, auto j) {
            return i.second < j.second;
        })->second << "\n";
    }
}