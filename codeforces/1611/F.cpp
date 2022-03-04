// Coder: jorgeajimenezl
#include <bits/stdc++.h>
// #pragma GCC optimize ("Ofast")

using namespace std;

#if _DEBUG
#define debug(x) cerr << #x << ": " << x << endl;
// #pragma GCC optimize("trapv")
#else
#define debug(x)
#endif
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)

template<typename T>
ostream& operator<< (ostream& os, const vector<T> &a) {
    for (size_t i = 0; i < a.size() - 1; i++)
        os << a[i] << " ";
    return (os << a.back());
}

int main() {
#if _DEBUG
    freopen("a.in", "r", stdin);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    
    int T = 1;
    cin >> T;

    while (T--) {
        int n, s;
        cin >> n >> s;

        int l = __lg(n);
        vector<int64_t> a(n + 1);
        vector<vector<int64_t>> rmq(n + 1, vector<int64_t>(l + 1));
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            a[i] += a[i - 1];
            rmq[i][0] = a[i];
        }
        
        for (int j = 1; j <= l; j++)
            for (int i = 1; i + (1 << (j - 1)) <= n; i++)
                rmq[i][j] = min(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);

        auto query = [&](int u, int v) {
            int lg = __lg(v - u + 1);
            return min(rmq[u][lg], rmq[v - (1 << lg) + 1][lg]);
        };

        int l1 = 0, l2 = 0;
        bool flag = 1;

        for (int i = 1; i <= n; i++) {
            int lo = i, hi = n;
            while (lo < hi) {
                int m = (lo + hi) >> 1;
                int64_t k = query(i, m);

                if (a[i - 1] - k <= s)
                    lo = m + 1;
                else
                    hi = m;
            }
            if (lo > n || a[i - 1] - query(i, lo) > s)
                lo--;
            if (lo >= i &&
                a[i - 1] - query(i, lo) <= s &&
                (flag || lo - i > l2 - l1)) {
                flag = 0;
                l1 = i;
                l2 = lo;
            }
        }
        if (!flag)
            cout << l1 << " " << l2 << "\n";
        else
            cout << "-1\n";
    }

#if _DEBUG
    cout << "Time elapsed: " << double(clock()) / double(CLOCKS_PER_SEC) << "s\n";
#endif
}