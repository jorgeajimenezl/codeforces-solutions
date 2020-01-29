#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int x;
        cin >> x;

        if (x == 3)
            cout << 7 << "\n";
        else {
            for (int i = 0; i < x / 2; i++)
                if (i == 0 && x % 2 == 1)
                    cout << 7;
                else
                    cout << 1;
            cout << "\n";      
        }
    }

}