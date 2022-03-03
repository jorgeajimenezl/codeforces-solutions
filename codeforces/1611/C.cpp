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

bool check(const vector<int>& a, list<int> l) {
    list<int> m1, m2;
    while (!l.empty()) {
        if (l.front() < l.back()) {
            m1.push_front(l.front());
            m2.push_front(l.front());
            l.pop_front();
        } else if (l.size() > 1) {
            m1.push_back(l.back());
            m2.push_back(l.back());
            l.pop_back();
        } else {
            m1.push_back(l.back());
            m2.push_front(l.back());
            break;
        }
    }
    bool flag = 1;
    int i = 0;
    for (auto x : m1)
        if (x != a[i++])
            flag = 0;
    if (flag)
        return true;
    i = 0;
    flag = 1;
    for (auto x : m2)
        if (x != a[i++])
            flag = 0;
    return flag;
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

        list<int> l1, l2;
        int lo = 0, hi = n - 1;
        while (lo <= hi) {
            if (a[lo] < a[hi]) {
                l1.push_front(a[lo]);
                l2.push_front(a[lo]);
                lo++;
            } else if (hi - lo >= 1) {
                l1.push_back(a[hi]);
                l2.push_back(a[hi]);
                hi--;
            } else {
                l1.push_front(a[lo]);
                l2.push_back(a[lo]);
                break;
            }
        }

        if (check(a, l1)) {
            vector<int> ans(l1.begin(), l1.end());
            cout << ans << "\n";
            continue;
        }
        if (check(a, l2)) {
            vector<int> ans(l2.begin(), l2.end());
            cout << ans << "\n";
            continue;
        }

        cout << "-1\n";
    }

#if _DEBUG
    cout << "Time elapsed: " << double(clock()) / double(CLOCKS_PER_SEC) << "s\n";
#endif
}