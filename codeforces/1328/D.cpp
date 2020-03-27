#include <bits/stdc++.h>

using namespace std;    

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#if OFFLINE
    freopen("a.in", "r", stdin);
#endif

    int T;
    cin >> T;

    while (T--) {
        int64_t n;
        cin >> n;

        vector<int> v(n + 1);
        for (int i = 0; i < n; i++)
            cin >> v[i];

        bool s = 0;
        vector<int> ans;
        bool a = 0, b = 0, c = 0;
        bool fs = 0;

        for (int i = 0; i < n; i++) {
            if (s == false) {
                if (i == n - 1 && v[0] != v[i])
                    c = 1;
                else
                    a = 1;
            } else
                b = 1;

            if (v[(i + 1) % n] != v[i]) 
                s = !s;
        }

        bool sa = 0, sb = 0, sc = 0;
        s = 0;

        for (int i = 0; i < n; i++) {
            if (s == false) {
                if (i == n - 1 && v[0] != v[i]) {
                    ans.push_back(3);
                    sc = 1;
                }
                else {
                    ans.push_back(1);
                    sa = 1;
                }
            } else {
                ans.push_back(2);
                sb = 1;
            }

            if (v[(i + 1) % n] != v[i]) 
                s = !s;
            else if (!fs && c) {
                s = !s;
                fs = 1;
            }
        }
        
        cout << (sa + sb + sc) << "\n";
        cout << ans[0];
        for (int i = 1; i < n; i++) {
            cout << " " << ans[i];
        }
        cout << "\n";
    }
}