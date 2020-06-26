#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << endl;
#define all(x) x.begin(), x.end()

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
        // Code here
        string s;
        cin >> s;

        auto bf = [](const string &t) {
            int res = 0, init = 0;
            while (1) {
                int cur = init++;
                bool ok = 1;
                for (auto i : t) {
                    res++;
                    cur += (i == '+' ? 1 : -1);
                    if (cur < 0) {
                        ok = 0;
                        break;
                    }
                }
                if (ok)
                    break;
            }
            return res;
        };

        int64_t cur = 0, ans = s.length();
        for (int i = 1; i <= s.size(); i++) {
            cur += (s[i - 1] == '+') ? 1 : -1;
            if (cur < 0) {
                ans += i;
                cur = 0;
            }
        }
        cout << ans << "\n";
    }
}

