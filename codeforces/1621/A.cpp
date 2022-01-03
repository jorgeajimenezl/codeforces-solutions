#include <bits/stdc++.h>

#define int long long

using namespace std;



int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--)
    {
    	int N, K;
    	cin >> N >> K;

    	if(K > (N+1)/2)
    	{
    		cout << -1 << '\n';
    		continue;
    	}

    	for(int i = 0 ; i < N ; i++)
    	{
    		for(int j = 0 ; j < N ; j++)
    		{
    			if(i == j && i%2 == 0)
    			{
    				if(K)
    				{
    					cout << 'R';
    					K--;
    				}
    				else
    				{
    					cout << '.';
    				}
    			}
    			else
    			{
    				cout << '.';
    			}
    		}
    		cout << '\n';
    	}
    }

    return 0;
}