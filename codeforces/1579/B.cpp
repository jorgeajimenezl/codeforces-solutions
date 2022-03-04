// Coder: jorgeajimenezl
#include <bits/stdc++.h>
// #pragma GCC optimize ("Ofast")

using namespace std;

#if _DEBUG
#define debug(x) cerr << #x << ": " << x << endl;
#pragma GCC optimize("trapv")
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
        int n;
        cin >> n;

        vector<int> a(n);
        for (int& x : a) cin >> x;

        vector<tuple<int, int, int>> ans;
        for (int i = 0; i < n; i++) {
            int m = i;
            for (int j = i + 1; j < n; j++)
                if (a[j] < a[m])
                    m = j;

            if (m - i != 0)
                ans.push_back({i + 1, m + 1, m - i});
            for (int j = m; j >= i; j--)
                a[j] = a[j - 1];
        }
        cout << ans.size() << "\n";
        for (auto x : ans)
            cout << get<0>(x) << " " << get<1>(x) << " " << get<2>(x) << "\n";
    }

#if _DEBUG
    cout << "Time elapsed: " << double(clock()) / double(CLOCKS_PER_SEC) << "s\n";
#endif
}