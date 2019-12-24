#include <bits/stdc++.h>

using namespace std;

int st[200005];

int main() {   
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int sum = 0;
        for (int i = 0; i < 2 * n; i++) {
            cin >> st[i];
            st[i] = st[i] == 1 ? 1 : -1;
            sum += st[i];
        }

        if (sum == 0) {
            cout << "0\n";
            continue;
        }

        unordered_map<int, int> left, right;
        left[0] = n;
        right[0] = n - 1;

        int lsum = 0, rsum = 0;
        for (int i = n - 1; i >= 0; i--) {
            lsum += st[i];

            if (left.find(lsum) == left.end())
                left[lsum] = i;
        }

        for (int i = n; i < 2 * n; i++) {
            rsum += st[i];

            if (right.find(rsum) == right.end())
                right[rsum] = i;
        }

        int ans = 1 << 30;
        lsum = rsum = 0;
        for (int i = n - 1; i >= 0; i--) {
            lsum += st[i];

            if (right.find(sum - lsum) != right.end())
                ans = min(ans, right[sum - lsum] - i + 1);
        }

        for (int i = n; i < 2 * n; i++) {
            rsum += st[i];

            if (left.find(sum - rsum) != left.end())
                ans = min(ans, i - left[sum - rsum] + 1);
        }

        cout << ans << "\n";
    }
}