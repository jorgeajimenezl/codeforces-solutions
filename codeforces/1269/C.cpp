//http://codeforces.com/contest/1269/problem/C
//Coder: jorgeajimenezl
#include <bits/stdc++.h>

using namespace std;

string s;

int main() {   
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    cin >> s;
    bool flag = 0;

    for (int i = k; i < n; i++) {
        if (s[i] > s[i - k]) {            
            for (int j = k - 1; j >= 0; j--) {
                if (s[j] != '9') {
                    s[j]++;
                    break;
                } else {
                    s[j] = '0';
                }
            }

            break;
        } else if (s[i] != s[i - k]) {
            break;
        }
    }

    for (int i = k; i < n; i++)
        s[i] = s[i - k];    

    cout << n << "\n";
    cout << s;
}