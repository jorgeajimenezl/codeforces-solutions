#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int64_t a, b;
        cin >> a >> b;
        
        int64_t lgb = log10(b + 1);  
        cout << a * lgb << "\n";
    }  
}