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

const int MAXN = 510;

int A[MAXN][MAXN];

int dp[MAXN][MAXN];

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

    	for(int i = 0 ; i < 2*N ; i++)
    	{
    		for(int j = 0 ; j < 2*N ; j++)
    		{
    			cin >> A[i][j];
    			dp[i][j] = 0;
    		}
    	}

    	int res = 0;

    	for(int i = 0 ; i < N ; i++)
    	{
    		for(int j = 0 ; j < N ; j++)
    		{
    			res += A[i][j];
    			A[i][j] = 0;
    			dp[i][j] = 1;
    		}
    	}

    	for(int i = N ; i < 2*N ; i++)
    	{
    		for(int j = N ; j < 2*N ; j++)
    		{
    			res += A[i][j];
    			A[i][j] = 0;
    			dp[i][j] = 2;
    		}
    	}

    	// for(int i = 1 ; i <= 2*N ; i++)
    	// {
    	// 	for(int j = 1 ; j <= 2*N ; j++)
    	// 	{
    	// 		cout << A[i][j] << " ";
    	// 	}
    	// 	cout << '\n';
    	// }
    	// cout << '\n';

    	int ans = 1e18;

    	for(int i = 0 ; i < 2*N ; i++)
    	{
    		for(int j = 0 ; j < 2*N ; j++)
    		{
    			if(dp[i][j])continue;

    			bool flag = false;

    			if(i == N-1 && j == N)flag = true;
    			if(i == N && j == N-1)flag = true;
    			if(i == 0 && j == 2*N-1)flag = true;
    			if(i == 2*N-1 && j == 0)flag = true;

    			if(i == 0 && j == N)flag = true;
    			if(i == N && j == 0)flag = true;
    			if(i == N-1&& j == 2*N-1)flag = true;
    			if(i == 2*N-1 && j == N-1)flag = true;

    			if(!flag)continue;

				int R = 0;
				int L = 0;
				int U = 0;
				int D = 0;

				int tam = 2*N;

				for(int x = 0 ; x < N ; x++)
				{
					R += A[i][(j+tam+x)%tam];
					if(dp[i][(j+tam+x)%tam])
					{
						break;
					}
    			}

    			for(int x = 0 ; x < N ; x++)
				{
					L += A[i][(j+tam-x)%tam];
					if(dp[i][(j+tam-x)%tam])
					{
						break;
					}
    			}

    			for(int x = 0 ; x < N ; x++)
				{
					D += A[(i+tam+x)%tam][j];
					if(dp[(i+tam+x)%tam][j])
					{
						break;
					}
    			}

    			for(int x = 0 ; x < N ; x++)
				{
					U += A[(i+tam-x)%tam][j];
					if(dp[(i+tam-x)%tam][j])
					{
						break;
					}
    			}

    			ans = min(ans, U+R-A[i][j]);
    			ans = min(ans, U+L-A[i][j]);
    			ans = min(ans, D+R-A[i][j]);
    			ans = min(ans, D+L-A[i][j]);

    			// dbl(i,j);
    			// db(U,D,R,L);
    			// db(ans);
    		}
    	}

    	// db(res);

    	cout << res + ans << '\n';
    }

    return 0;
}