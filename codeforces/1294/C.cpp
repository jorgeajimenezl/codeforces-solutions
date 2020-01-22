#include <bits/stdc++.h>

using namespace std;

int n;
string ans;

int main() {
    //freopen("a.in", "r", stdin);
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int sq = sqrt(n);
        vector<int> div;

        for (int i = 2; i <= sq; i++) {
            if (n % i == 0 && i * i != n) {
                div.push_back(i);
                div.push_back(n / i);
            }
        }

        bool flag = 0;

        for (int i = 0; i < div.size() && !flag; i++) {
            int d = n / div[i];
            int sr = sqrt(d);

            for (int j = 2; j <= sr; j++) {
                if (d % j == 0 && div[i] != d / j && div[i] != j && j * j != d) {
                    cout << "YES\n";
                    cout << n / d << " " << d / j << " " << j << "\n";
                    flag = 1;
                    break;
                }
            }
        }

        if (!flag)
            cout << "NO\n";
    }
}