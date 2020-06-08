#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << endl;

using namespace std;

namespace std {
    template <>
    struct hash<pair<int, int>> : public __hash_base<int, pair<int, int>>
    {
        int operator()(pair<int, int> __p) const noexcept
        { return __p.first * 311 + __p.second; }
    };
}

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

        vector<int64_t> a(n), b(n);
        for (int64_t &x : a) cin >> x;
        for (int64_t &x : b) cin >> x;

        if ((n & 1) and a[n >> 1] != b[n >> 1]) {
            cout << "No\n";
            continue;
        }
        
        unordered_map<pair<int, int>, int> mp;
        bool flag = 1;

        for (int i = 0; i < (n >> 1); i++)
            mp[{min(a[i], a[n - i - 1]), max(a[i], a[n - i - 1])}]++;

        for (int i = 0; i < (n >> 1); i++)
            if (mp[{min(b[i], b[n - i - 1]), max(b[i], b[n - i - 1])}]-- <= 0)
                flag = 0;

        cout << (flag ? "Yes\n" : "No\n");
    }
}
