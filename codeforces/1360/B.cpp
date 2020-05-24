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
        for (int &x : v)
            cin >> x;

        int ans = 1 << 30;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                ans = min(ans, abs(v[i] - v[j]));

        cout << ans << "\n";
    }
}

