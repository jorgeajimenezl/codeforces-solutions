// jorgeajimenezl
#include <bits/stdc++.h>
#define sign(x) ((x == 0) ? (0) : ((x > 0) ? (1) : (-1)))
#define debug(x) cerr << #x << ": " << x << endl;

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("a.in", "r", stdin);

    int T;
    cin >> T;

    while (T--) {
        string s;
        cin >> s;

        int n = s.length();
        int cnt0 = 0, cnt1 = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            cnt0 += (s[i] == '0');
            cnt1 += (s[i] == '1');

            if (i > 0 && cnt0 > 0 && cnt1 > 0 && cnt0 != cnt1)
                ans = min(cnt0, cnt1);
        }
        cout << ans << "\n";
    }

    return 0;
}