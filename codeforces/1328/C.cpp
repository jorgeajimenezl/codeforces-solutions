#include <bits/stdc++.h>

using namespace std;    

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#if OFFLINE
    freopen("a.in", "r", stdin);
#endif

    int T;
    cin >> T;

    while (T--) {
        int64_t n;
        cin >> n;

        string s;
        cin >> s;

        string a = "", b = "";
        int st = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '2') {
                if (st == 0) {
                    a.push_back('1');
                    b.push_back('1');
                    continue;
                } 

                if (st == 1) {
                    a.push_back('0');
                    b.push_back('2');
                    continue;
                }
            }

            if (s[i] == '1') {
                if (st == 0) {
                    a.push_back('1');
                    b.push_back('0');
                    st = 1;
                    continue;
                }
                
                if (st == 1) {
                    a.push_back('0');
                    b.push_back('1');
                    continue;
                }
            }

            if (s[i] == '0') {
                a.push_back('0');
                b.push_back('0');
            }
        }

        cout << a << "\n" << b << "\n";

    }
}