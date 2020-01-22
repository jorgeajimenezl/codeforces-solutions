#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("a.in", "r", stdin);
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int64_t a, b, c, n;
        cin >> a >> b >> c >> n;

        int m = max(a, max(b, c));
        n -= (m - a);
        n -= (m - b);
        n -= (m - c);

        if (n >= 0 && n % 3 == 0 || n == 0)
            cout << "YES\n";
        else
        {
            cout << "NO\n";
        }
        

    }
}