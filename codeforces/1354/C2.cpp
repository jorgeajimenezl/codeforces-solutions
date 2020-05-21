#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << endl;

using namespace std;

// using point = complex<double>;

int main() {
#if _DEBUG
    freopen("a.in", "r", stdin);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);    
#endif

    cout.setf(ios::fixed);
	cout.precision(9);

    int T;
    cin >> T;

    const double pi = 2 * acos(0.0f);
    const double pi_over_180 = pi / 180.0f;
    const double inf = 1 << 30;
    
    while (T--) {
        int n;
        cin >> n;

        auto rad = [&](double deg) {
            return pi_over_180 * deg;
        };
        
        n *= 2;
        double angle = rad(360.0f / n);
        double a = 0.5f * 1.0f / tan(angle * 0.5f);
        double l = 1.0f / sqrt(2.0f * (1.0f - cos(angle)));
        
        double ans = inf;
        for (double s = 0; s <= 180; s += 1) {
            double minx = inf, maxx = -inf, miny = inf, maxy = -inf;

            for (int i = 0; i < n; i++) {
                double x = l * cos(rad(s) + angle * i);
                double y = l * sin(rad(s) + angle * i);
                
                minx = min(minx, x);
                maxx = max(maxx, x);

                miny = min(miny, y);
                maxy = max(maxy, y);
            }

            ans = min(ans, max(maxx - minx, maxy - miny));
        }

        cout << ans << "\n";
    }
}

