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
        string s;
        cin >> s;
        
        map<char, int> mp;
        for (auto x : s)
            mp[x]++;
        cout << (mp['N'] == 1 ? "NO\n" : "YES\n");
    }

#if _DEBUG
    cout << "Time elapsed: " << double(clock()) / double(CLOCKS_PER_SEC) << "s\n";
#endif
}