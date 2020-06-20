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

        if (n == 1) {
            cout << "FastestFinger\n";
            continue;
        }
        if (n == 2) {
            cout << "Ashishgup\n";
            continue;
        }
        
        if (n % 2 == 1)
            cout << "Ashishgup\n";
        else {             
            if ((1 << __lg(n)) == n) {
                cout << "FastestFinger\n";
                continue;
            } else {
                if ((n / 2) % 2 == 0) {
                    cout << "Ashishgup\n";
                    continue;
                } else {
                    int sum = 0;
                    while (n % 2 == 0)
                        n /= 2;

                    for (int i = 3; i * i <= n; i += 2)
                        while (n % i == 0) {
                            n /= i;
                            sum ++;
                        }

                    if (n > 1)
                        sum ++;
                    
                    if (sum >= 2) {
                        cout << "Ashishgup\n";
                        continue;
                    } else {
                        cout << "FastestFinger\n";
                        continue;
                    }
                }
            }
        }
    }
}

