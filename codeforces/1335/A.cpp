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
        int64_t n;
        cin >> n;
        cout << n / 2 - ((n % 2) == 0) << "\n";
    }
}
