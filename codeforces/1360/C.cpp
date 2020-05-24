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

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> v(n);
        int p = 0, i = 0;
        map<int, int> mp;
        for (int &x : v) {
            cin >> x;
            p += (x % 2 == 0);
            i += (x % 2 != 0);
            mp[x] = 1;
        }

        if (p % 2 == 0 && i % 2 == 0) {
            cout << "YES\n";
            continue;
        }
        if (p % 2 != i % 2) {
            cout << "NO\n";
            continue;
        }

        bool ans = 0;
        for (int i = 0; i < n; i++)
            if (mp[v[i] - 1] || mp[v[i] + 1])
                ans = 1;

        cout << (ans ? "YES\n" : "NO\n");
    }
}

