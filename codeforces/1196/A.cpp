#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        vector<uint64_t> v(3);
        for (uint64_t &i : v)
            cin >> i;

        sort(v.begin(), v.end());
        uint64_t tm = v[0];
        v[0] += min(v[1] - v[0], v[2]);
        v[2] -= min(v[1] - tm, v[2]);

        cout << v[0] + v[2] / 2 << "\n";
    }
}