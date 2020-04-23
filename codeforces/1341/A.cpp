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
        int64_t n, a, b, c, d;
        cin >> n >> a >> b >> c >> d;

        if (n * (a + b) < c - d || n * (a - b) > c + d)
            cout << "No\n";
        else
            cout << "Yes\n";
    }
}
