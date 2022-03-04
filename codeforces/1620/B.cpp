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
// #define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)

template<typename T>
ostream& operator<< (ostream& os, const vector<T> &a) {
    for (size_t i = 0; i < a.size() - 1; i++)
        os << a[i] << " ";
    return (os << a.back());
}

bool equal(const string &s) {
    bool flag = 0;
    for (int i = 1; i < s.length(); i++)
        if (s[i] != s[i - 1])
            return false;
    return true;
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
        int w, h;
        cin >> w >> h;

        int k;
        cin >> k;
        vector<int64_t> h1(k);
        for (int64_t& x : h1) cin >> x;

        cin >> k;
        vector<int64_t> h2(k);
        for (int64_t& x : h2) cin >> x;

        cin >> k;
        vector<int64_t> v1(k);
        for (int64_t& x : v1) cin >> x;

        cin >> k;
        vector<int64_t> v2(k);
        for (int64_t& x : v2) cin >> x;

        sort(h1.begin(), h1.end());
        sort(h2.begin(), h2.end());
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        cout << max({(h1.back() - h1.front()) * h, 
                     (h2.back() - h2.front()) * h, 
                     (v1.back() - v1.front()) * w, 
                     (v2.back() - v2.front()) * w}) << "\n";
    }

#if _DEBUG
    cout << "Time elapsed: " << double(clock()) / double(CLOCKS_PER_SEC) << "s\n";
#endif
}