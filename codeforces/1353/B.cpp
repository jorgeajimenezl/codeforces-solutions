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
        int64_t n, k;
        cin >> n >> k;

        vector<int> v1(n), v2(n);
        for (int &i : v1)
            cin >> i;
        for (int &i : v2)
            cin >> i;

        sort(v2.begin(), v2.end(), greater<int>());
        sort(v1.begin(), v1.end());
        for (int i = 0; i < k; i++)
            if (v1[i] < v2[i])
                swap(v1[i], v2[i]);

        int64_t sum = 0;
        for (int i : v1)
            sum += i;
        cout << sum << "\n";
    }
}
