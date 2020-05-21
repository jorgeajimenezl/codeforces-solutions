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

    cout.setf(ios::fixed);
	cout.precision(7);

    int T;
    cin >> T;

    const double pi = 2 * acos(0.0f);
    const double pi_over_180 = pi / 180.0f;
    
    while (T--) {
        int n;
        cin >> n;

        auto rad = [&](double deg) {
            return pi_over_180 * deg;
        };
        
        n *= 2;
        double u = 0.5f * 1.0f / tan(rad(360.0f / n / 2.0f));
        double v = 1.0f / sqrt(2.0f * (1.0f - cos(rad(360.0f / n))));
        cout << min(u, v) * 2.0f << "\n";
    }
}

