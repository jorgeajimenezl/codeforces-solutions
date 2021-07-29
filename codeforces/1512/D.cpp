//Coder: jorgeajimenezl
#include <bits/stdc++.h>
// #pragma GCC optimize ("Ofast")

using namespace std;

#if _DEBUG
#define debug(x) cerr << #x << ": " << x << endl;
#endif

int main() {
#if _DEBUG
    freopen("a.in", "r", stdin);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif

    int T = 1;
    cin >> T;

    while (T--) {
        int64_t n;
        cin >> n;

        int64_t sum = 0;
        n += 2;
        vector<int64_t> v(n);
        map<int64_t, int64_t> cnt;
        for (int64_t &x : v) {
            cin >> x;
            sum += x;
            cnt[x]++;
        }
        vector<int64_t> ans;
        for (int64_t i = 0; i < n; i++) {
            if ((sum - v[i]) % 2 == 0) {
                int64_t d = (sum - v[i]) / 2;
                // debug(sum);
                if (v[i] == d && cnt[d] >= 2 ||
                    v[i] != d && cnt[d] >= 1) {
                    bool flag = 0;
                    for (int64_t j = 0; j < n; j++) {
                        if (i == j)
                            continue;
                        if (v[j] == d) {
                            if (flag)
                                ans.push_back(v[j]);
                            if (!flag)
                                flag = 1;
                            continue;
                        }
                        ans.push_back(v[j]);
                    }
                    break;
                }
            }
        }
        if (ans.size() == 0) {
            cout << "-1\n";
            continue;
        }

        for (int64_t i = 0; i < ans.size(); i++)
            cout << ans[i] << " \n"[i == ans.size() - 1];
    }

#if _DEBUG
    cout << "Time elapsed: " << double(clock()) / double(CLOCKS_PER_SEC) << "s\n";
#endif
}
