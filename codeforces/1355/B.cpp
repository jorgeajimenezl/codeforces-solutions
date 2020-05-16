#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << endl;

using namespace std;

int64_t mn (int64_t x) {
    int64_t s = 10;
    while (x) {
        s = min(x % 10, s);
        x /= 10;
    }
    return s;
}

int64_t mx (int64_t x) {
    int64_t s = -1;
    while (x) {
        s = max(x % 10, s);
        x /= 10;
    }
    return s;
}

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
        int64_t n;
        cin >> n;

        vector<int> v(n);
        for (int &x : v) {
            cin >> x;
        }

        sort(v.begin(), v.end());

        int ans = 0;


        for (int i = 0; i < n; ) {
            bool flag = 1;
            for (int j = i; j < n; j++) {
                if (v[j] <= j - i + 1) {
                    i = j + 1;
                    flag = 0;
                    ans++;
                    break;
                }
            }

            if (flag)
                break;
        }

        cout << ans << "\n";
    }
}

