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
        uint64_t n, k;
        cin >> n >> k;
        
        vector<bool> vst(100, false);
        bool flag = 1;

        for (int i = 0; i < n; i++) {
            uint64_t x;
            cin >> x;

            int len = 0;
            while (x) {
                if (x % k != 0 && x % k != 1) {
                    flag = 0;
                    break;
                }

                if (x % k == 1 && vst[len]) {
                    flag = 0;
                    break;
                }

                if (x % k == 1)
                    vst[len] = true;

                len++;
                x /= k;                 
            }
        }

        cout << (flag ? "YES\n" : "NO\n");        
    }
}