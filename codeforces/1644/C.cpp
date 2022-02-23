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
        int n, x;        
        cin >> n >> x;

        vector<int> a(n);
        for (int &i : a) cin >> i;

        vector<int> sum(n + 1);
        for (int i = 1; i <= n; i++)
            sum[i] = sum[i - 1] + a[i - 1];

        vector<int> ans(n + 1);
        vector<int> dp(n + 1, INT_MIN);
        for (int i = 1; i <= n; i++)
            for (int j = i; j <= n; j++)
                dp[j - i + 1] = max(dp[j - i + 1], sum[j] - sum[i - 1]);

        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= i; j++)
                ans[j] = max(ans[j], dp[i] + x * j);
        for (int i = 1; i <= n; i++)
            ans[i] = max(ans[i - 1], ans[i]);
        cout << ans << "\n";
    }

#if _DEBUG
    cout << "Time elapsed: " << double(clock()) / double(CLOCKS_PER_SEC) << "s\n";
#endif
}