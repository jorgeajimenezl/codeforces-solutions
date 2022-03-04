// Coder: jorgeajimenezl
#include <bits/stdc++.h>
// #pragma GCC optimize ("Ofast")

using namespace std;

#if _DEBUG
#define debug(x) cerr << #x << ": " << x << endl;
#pragma GCC optimize("trapv")
#else
#define debug(x)
#endif
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)

template<typename T>
ostream& operator<< (ostream& os, const vector<T> &a) {
    for (size_t i = 0; i < a.size() - 1; i++)
        os << a[i] << " ";
    return (os << a.back());
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
        for (int& x : a) cin >> x;

        list<int> s;
        s.push_back(a[0]);
        for (int i = 1; i < n; i++)
            if (a[i] > s.front())
                s.push_back(a[i]);
            else
                s.push_front(a[i]);

        vector<int> ans(s.begin(), s.end());
        cout << ans << "\n";            
    }

#if _DEBUG
    cout << "Time elapsed: " << double(clock()) / double(CLOCKS_PER_SEC) << "s\n";
#endif
}