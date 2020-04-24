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
        int n;
        cin >> n;

        vector<int> v(n);
        for (auto &x : v)
            cin >> x;

        int ans = 0;
        for (int i = 1; i < n; i++)
            if (v[i] < v[i - 1]) {
                int x = v[i - 1] - v[i];
                v[i] = v[i - 1];
                for (int j = 0; j <= 30; j++)
                    if (x & (1 << j))
                        ans |= (1 << j);
            }

        cout << (ans ? __lg(ans) + 1 : 0) << "\n";
    }
}
