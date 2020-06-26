#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << endl;
#define all(x) x.begin(), x.end()

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
        // Code here
        int64_t a, b, c;
        cin >> a >> b >> c;

        cout << (a < c ? 1 : -1) << " " << (a * b > c ? b : -1) << "\n";
    }
}
