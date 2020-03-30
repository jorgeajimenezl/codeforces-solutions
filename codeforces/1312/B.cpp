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
        vector<int> v(n);

        for (int i = 0; i < n; i++)
            cin >> v[i];

        for (int t = 0; t < n; t++)
            for (int j = 0; j < n; j++) {
                for (int i = 0; i < j; i++) {
                    if (j - v[j] == i - v[i]) {
                        swap(v[i], v[j]);
                    }                 
                }
            }

        for (int i = 0; i < n - 1; i++)
            cout << v[i] << " ";
        cout << v[n - 1];
        cout << "\n";
    }
}