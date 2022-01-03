#pragma GCC optimize("O3","Ofast","no-stack-protector","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
// #pragma GCC target("avx2") //Enable AVX

#include <bits/stdc++.h>

#define int long long

using namespace std;

#ifdef LOCAL 
#include "/media/brayand/BrayanD/debugger.h"
#else
#define db(...) false
#define dbl(...) false
#define dbg(...) false
#define dbm(...) false
#define dbs(...) false
#define dbas(...) false
#endif

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--)
    {
    	int N;
    	cin >> N;

    	int me = 1e18;
    	int ma = -1e18;

    	map<int,int> mpa;
    	map<int,int> mpb;

    	map<pair<int,int>,int> mpab;

    	for(int i = 0 ; i < N ; i++)
    	{
    		int a, b, c;
    		cin >> a >> b >> c;

    		me = min(me, a);
    		ma = max(ma, b);

    		if(mpa[a] == 0)
    		{
    			mpa[a] = c;
    		}
    		else
    		{
    			mpa[a] = min(mpa[a], c);
    		}

    		if(mpb[b] == 0)
    		{
    			mpb[b] = c;
    		}
    		else
    		{
    			mpb[b] = min(mpb[b], c);
    		}

    		if(mpab[{a,b}] == 0)
    		{
    			mpab[{a,b}] = c;
    		}
    		else
    		{
    			mpab[{a,b}] = min(mpab[{a,b}], c);
    		}

    		int res = mpa[me]+mpb[ma];

    		if(mpab[{me,ma}])
    		{
    			res = min(res, mpab[{me,ma}]);
    		}

    		cout << res << '\n';
    	}
    }

    return 0;
}