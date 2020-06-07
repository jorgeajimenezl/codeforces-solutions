#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << endl;

using namespace std;

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
        int n;
        cin >> n;

        vector<int> a(n), b(n);

        for (int &x : a)
            cin >> x;

        for (int &x : b)
            cin >> x;

        auto t = minmax_element(b.begin(), b.end());
        bool flag = *t.first != *t.second;
        if (!flag) {
            flag = 1;

            for (int i = 1; i < n; i++)
                if (a[i] < a[i - 1])
                    flag = 0;
        }
        cout << (flag ? "Yes\n" : "No\n");
    }
}
