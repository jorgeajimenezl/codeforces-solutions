#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << endl;

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
        int n;
        cin >> n;
        vector<int> v(2*n);
        int64_t sum = 0;

        for (int i = 0; i < 2*n; i++) {
            cin >> v[i];
            sum += v[i];
        }

        //sort(v.begin(), v.end());
        // bool flag = 0;

        for (int gcd = 2; gcd <= 2000; gcd++) {           
            vector<vector<int>> mod(gcd);
            for (int i = 0; i < 2*n; i++)
                mod[v[i] % gcd].push_back(i + 1);

            int ret = 0;

            for (int i = 0; i < gcd; i++)
                if ((gcd - i) % gcd != i)
                    ret += abs((int)(mod[i].size() - mod[(gcd - i) % gcd].size()));
                else
                    ret += (mod[i].size() % 2) * 2;

            if (ret / 2 <= 2) {
                int len = 0;
                for (int i = 0; i <= gcd / 2; i++) {
                    if ((gcd - i) % gcd != i) {
                        while (!mod[i].empty() && !mod[(gcd - i) % gcd].empty() && len < n - 1) {
                            cout << mod[i].back() << " " << mod[(gcd - i) % gcd].back() << "\n";
                            mod[i].pop_back();
                            mod[(gcd - i) % gcd].pop_back();
                            len++;
                        }
                    } else {
                        if (mod[i].size() >= 2)
                            for (int j = 0; j < mod[i].size() && len < n - 1; j += 2)
                                if (j < mod[i].size() - 1) {
                                    cout << mod[i][j] << " " << mod[i][j + 1] << "\n";
                                    len++;
                                }
                    }
                }

                break;
            }
        }
    }
}

