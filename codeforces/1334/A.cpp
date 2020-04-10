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

        vector<pair<int, int>> v(n);

        for (int i = 0; i < n; i++)
            cin >> v[i].first >> v[i].second;

        bool flag = 1;

        if (v[0].second > v[0].first)
            flag = 0;

        for (int i = 1; i < n; i++) {
            if (v[i].first < v[i - 1].first)
                flag = 0;
            else if (v[i].second < v[i - 1].second)
                flag = 0;
            else if (v[i].first - v[i - 1].first < v[i].second - v[i - 1].second)
                flag = 0;
        }

        cout << (flag ? "YES\n" : "NO\n");            
    }
}
