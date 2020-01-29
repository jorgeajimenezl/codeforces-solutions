#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n >> x;
        string s;
        cin >> s;   

        int z = 0, o = 0;     
        int ans = 0;
        int zs = 0, os = 0;        

        for (int i = 0; i < n; i++) {
            zs += s[i] == '0';
            os += s[i] == '1';
        }

        bool flag = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '0')
                z++;
            if (s[i] == '1')
                o++;

            if (zs != os && (o + x - z) >= 0 && (zs - os) > 0 && (o + x - z) % (zs - os) == 0 ||
                zs != os && (z - o - x) >= 0 && (os - zs) > 0 && (z - o - x) % (os - zs) == 0 ||
                zs == os && z - o == x)
                ans++;

            if (o + x - z == 0 && zs - os == 0)
                flag = 1;
        } 

        if (x == 0)
            ans++;

        if (flag)
            cout << "-1\n";        
        else
            cout << ans << "\n";
    }

}