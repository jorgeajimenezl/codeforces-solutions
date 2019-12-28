#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    //cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n + 1);
        vector<bool> in(n + 1);
        deque<int> a;

        for (int i = 1; i <= n; i++) {
            cin >> v[i];
            in[v[i]] = 1;

            if (v[i] == 0)
                a.push_back(i);
        }

        int last = 0, idx = 0;

        for (int i = 1; i <= n; i++) {
            if (!in[i]) {
                if (a.back() != i) {
                    v[a.back()] = i;                  
                    last = a.back();
                    idx = i;
                    a.pop_back();
                } else if (a.front() != i) {
                    v[a.front()] = i;
                    last = a.front();
                    idx = i;
                    a.pop_front();
                } else {
                    v[a.back()] = idx;
                    v[last] = i;

                    last = a.back();
                    idx = i;

                    a.pop_back();
                }
            }
        }

        cout << v[1];
        for (int i = 2; i <= n; i++)
            cout << " " << v[i];
    }
}