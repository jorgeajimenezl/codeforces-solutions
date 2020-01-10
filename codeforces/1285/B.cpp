//http://codeforces.com/contest/1285/problem/B
//Coder: jorgeajimenezl
#include <bits/stdc++.h>

using namespace std;

int v[200005];

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        
        long long sum = 0;
        bool down = 0;

        for (int i = 0; i < n; i++) {
            cin >> v[i];
            sum += v[i];
            down |= v[i] < 0 ? 1 : 0;
        }

        long long xsum = 0;
        bool flag = 1;

        for (int i = 0; i < n - 1; i++) {           
            xsum += v[i];
            xsum = max(xsum, 0LL);

            if (xsum >= sum) {
                flag = 0;
                break;
            }
        }

        xsum = 0;

        for (int i = 1; i < n; i++) {           
            xsum += v[i];
            xsum = max(xsum, 0LL);

            if (xsum >= sum) {
                flag = 0;
                break;
            }
        }

        if (sum == 0)
            cout << "NO\n";
        else if (down == 0)
            cout << "YES\n";
        else
            cout << (flag || !down ? "YES\n" : "NO\n");
    }
}