#include <bits/stdc++.h>

using namespace std;

int64_t get_square (int64_t x) {
    int64_t r = 1 + 8LL * x;
    return (sqrt(r) - 1) / 2LL;
}   

int main() {   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int64_t a, b;
        cin >> a >> b;

        int64_t d = a;
        a = min(a, b);
        b = max(d, b);
        
        int64_t x = get_square(b - a);
        int64_t sum = x * (x + 1) / 2LL;
        
        if (sum + a == b)
            cout << x << "\n";

        else if (((sum + x + 1) + a - b) % 2 == 0)
            cout << x + 1 << "\n";
        else if (((sum + 2 * x + 3) + a - b) % 2 == 0)
            cout << x + 2 << "\n";
        else
            cout << x + 3 << "\n";
    }
}