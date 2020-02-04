#include <bits/stdc++.h>

using namespace std;

int main() {
    #ifdef OFFLINE_DEBUG
    freopen("a.in", "r", stdin);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);    

    int T;
    cin >> T;

    while (T--)
    {
        uint64_t n;
        cin >> n;
        if (n % 9 == 0)
            cout << (n - 1) / 9ULL * 10ULL + 9ULL << "\n";
        else
            cout << n / 9ULL * 10ULL + (n % 9ULL) << "\n";
    }    
}