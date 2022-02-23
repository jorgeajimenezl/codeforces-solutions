// Coder: jorgeajimenezl
#include <bits/stdc++.h>
// #pragma GCC optimize ("Ofast")

using namespace std;

#if _DEBUG
#define debug(x) cerr << #x << ": " << x << endl;
#else
#define debug(x)
#endif
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)

template<typename T>
ostream& operator<< (ostream& os, const vector<T> &a) {
    for (size_t i = 0; i < a.size(); i++)
        os << a[i] << " \0"[i == a.size() - 1];
    return os;
}

int main() {
#if _DEBUG
    freopen("a.in", "r", stdin);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    
    int T = 1;
    cin >> T;

    while (T--) {
        int n;
        
        cin >> n;
        vector<int> a(n);
        iota(a.begin(), a.end(), 1);
        reverse(a.begin(), a.end());
        cout << a << "\n";
        for (int i = 0; i < n - 1; i++) {
            swap(a[i], a[i + 1]);
            cout << a << "\n";
            swap(a[i], a[i + 1]);
        }
    }

#if _DEBUG
    cout << "Time elapsed: " << double(clock()) / double(CLOCKS_PER_SEC) << "s\n";
#endif
}