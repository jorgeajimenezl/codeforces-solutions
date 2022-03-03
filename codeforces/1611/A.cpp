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
        // int n;        
        // cin >> n;

        string s;
        cin >> s;
        if ((s[s.length() - 1] - '0') % 2 == 0)
            cout << "0\n";
        else if ((s[0] - '0') % 2 == 0)
            cout << "1\n";
        else {
            bool flag = 0;
            for (char x : s)
                if ((x - '0') % 2 == 0)
                    flag = 1;
            if (flag)
                cout << "2\n";
            else
                cout << "-1\n";
        }
    }

#if _DEBUG
    cout << "Time elapsed: " << double(clock()) / double(CLOCKS_PER_SEC) << "s\n";
#endif
}