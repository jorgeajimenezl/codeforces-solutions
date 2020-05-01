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
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;
        sort(s.begin(), s.end());

        if (s[0] == s[n - 1]) {
            for (int i = 0; i < n / k + (n % k != 0); i++)
                cout << s[0];
            cout << "\n";
            continue;
        }

        vector<int> ct(300);
        for (char x : s)
            ct[x]++;

        string ans = "";
        int ret = k, l = n;
        bool fl2 = 0, fl3 = 0;

        for (int i = 'a'; i <= 'z' && ret; i++) {               
            if (!ct[i])
                continue;
            
            if (ct[i] < ret) {
                ret -= ct[i];
                l -= ct[i];
                fl2 = 1;
            }
            else {
                ct[i] -= ret;                
                ans += char(i);
                l -= ret;
                break;
            }
        }

        if (!fl2) {            
            bool cu = 0;
            
            for (int i = 'a'; i <= 'z'; i++) {
                if (!ct[i])
                    continue;

                if (l - ct[i] == 0) {
                    for (int j = 0; j < ct[i] / k + (ct[i] % k != 0); j++)
                        ans += char(i);

                    cu = 1;
                }

                break;                
            }

            if (cu) {
                cout << ans << "\n";
                continue;
            }
        }

        if (!fl2) {
             for (int i = 'a'; i <= 'z'; i++)
                for (int j = 0; j < ct[i]; j++)
                    ans += char(i);
        }

        cout << ans << "\n";
    }
}
