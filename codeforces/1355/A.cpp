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
        int64_t a, k;
        cin >> a >> k;
        k--;
        while (k--) {
            int64_t t = mn(a) * mx(a);
            a = a + t;
            if (!t)
                break;
        }

        cout << a << "\n";
    }
}

