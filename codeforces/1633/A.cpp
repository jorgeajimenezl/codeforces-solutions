// jorgeajimenezl
#include <bits/stdc++.h>
#define sign(x) ((x == 0) ? (0) : ((x > 0) ? (1) : (-1)))
#define debug(x) cerr << #x << ": " << x << endl;

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("a.in", "r", stdin);

    int T;
    cin >> T;

    while (T--) {
        string s;
        cin >> s;

        if (stoi(s) % 7 == 0)
            cout << s << "\n";
        else {
            int ans = -1, ct = 0;
            vector<int> p = {1, 10, 100, 1000};
            for (int i = p[s.length() - 1]; i <= p[s.length()] - 1; i++) {
                if (i % 7 != 0)
                    continue;
                string m = to_string(i);
                int cnt = 0;
                for (int j = 0; j < m.size(); j++)
                    if (m[j] != s[j])
                        cnt++;
                if (ans == -1 || cnt < ct) {
                    ct = cnt;
                    ans = i;
                }
            }
            cout << ans << "\n";                
        }


    }

    return 0;
}