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
       int n, m;
       cin >> n >> m;
       cout << (n % m == 0 ? "YES\n" : "NO\n");
    }
}