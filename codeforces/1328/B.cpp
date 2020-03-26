#include <bits/stdc++.h>

using namespace std;

int64_t cb (int64_t n, int64_t k) {
    if(k == 0 || n == k) return 1;
    if(n == 0 && k > 0) return 0;
    return cb(n, k - 1) * (n - k + 1) / k;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#if OFFLINE
    freopen("a.in", "r", stdin);
#endif

    int T;
    cin >> T;

    while (T--) {
        int64_t n, k;
        cin >> n >> k;

#if OFFLINE_S
        string s = "";
        for (int i = 0; i < n - 2; i++)
            s += 'a';
        s += "bb";

        do {
            cout << s << "\n";
        } while (next_permutation(s.begin(), s.end()));
#endif
        int64_t c = 2;

        for (int i = n; i >= 1; i--) {
            int64_t p = cb(i - 1, c);
            
            if (p < k && c > 0) {
                cout << 'b';
                k -= p;
                c--;
            }
            else {
                cout << 'a';
            }
        }

        cout << "\n";
    }
}