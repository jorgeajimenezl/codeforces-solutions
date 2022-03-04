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

        set<pair<int, int>> a;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x > 0)
                a.insert({-x, i});
        }

        vector<pair<int, int>> ans;

        while (a.size() > 1) {
            auto i = a.begin();
            auto j = i;
            j++;
            if (j == a.end())
                break;

            int u = -i->first;   
            int v = -j->first;

            int pu = i->second;            
            int pv = j->second;

            if (u > 0 && v > 0) {
                ans.push_back({min(pu, pv), max(pu, pv)});
                a.erase(i);
                a.erase(j);

                if (u > 1)
                    a.insert({-(u - 1), pu});
                if (v > 1)
                    a.insert({-(v - 1), pv});
            }            
        }
        cout << ans.size() << "\n";
        for (auto x : ans)
            cout << x.first + 1 << " " << x.second + 1 << "\n";
    }

#if _DEBUG
    cout << "Time elapsed: " << double(clock()) / double(CLOCKS_PER_SEC) << "s\n";
#endif
}