//http://codeforces.com/contest/1288/problem/A
//Coder: jorgeajimenezl
//Solution: Using optimization
// f(x) = (x^2 + x + d) / (x + 1) <= n we need find a x that meets this
//let find the first derivate for look the minimun values when x have positive values
//f'(x) = (2*x+1)/(x+1)-(x^2+x+d)/(x+1)^2
//let solve this with f'(x) = 0
//f'(x) = 0 when x = [-sqrt(d) - 1] or x = [sqrt(d) - 1]
//here don't relevant the negative results for this only matter the second result
//let sustitute [sqrt(d) - 1] in f(x)
//so this is the f([sqrt(d) - 1]) when x is minimun 2d - sqrt(d) / sqrt(d)
//remember the ceil function
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int64_t n, d;
        cin >> n >> d;

        if (d <= n) {
            cout << "YES\n";
            continue;
        }

        if (ceil((2 * d - sqrt(d)) / sqrt(d)) <= n)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    
}