#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#if _DEBUG
    freopen("a.in", "r", stdin);
#endif

    int T;
    cin >> T;
    
    while (T--) {
        int n;
        cin >> n;        

        vector<int> a(n), b(n);
        for (int &x : a) cin >> x;
        for (int &x : b) cin >> x;

        bool r = 0, s = 0, flag = 1;

        for (int i = 0; i < n; i++) {
            if (a[i] > b[i] && !r) {
                flag = 0;
                break;
            }
            if (a[i] < b[i] && !s) {
                flag = 0;
                break;
            }

            if (a[i] == -1)
                r = 1;
            if (a[i] == 1)
                s = 1;
        }   

        cout << (flag ? "YES\n" : "NO\n");
    }
}
