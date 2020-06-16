#include <bits/stdc++.h>
#include <unistd.h>
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
        vector<int> v(n);

        int ct = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            ct += (v[i]  & 1 ? -1 : 1);
            ans += (v[i] % 2 != i % 2 ? 1 : 0);
        }

        if (abs(ct) > 1 || n % 2 == 0 && abs(ct) != 0 || n % 2 == 1 && ct == -1) {
            cout << "-1\n";
            continue;
        }

        cout << (ans >> 1) << "\n";
    }
    
}

