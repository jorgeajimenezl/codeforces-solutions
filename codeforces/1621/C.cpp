#include <bits/stdc++.h>

#define int long long

using namespace std;

int query(int x)
{
	cout << "?" << " " << x << '\n';
	cout.flush();
	int qu;
	cin >> qu;
	return qu;
}

void answer(vector<int> vect)
{
	cout << "!";
	for(auto x : vect)
	{
		cout << " " << x;
	}
	cout << '\n';
	cout.flush();
	return;
}

int32_t main()
{
    int T;
    cin >> T;

    while(T--)
    {
    	int N;
    	cin >> N;

    	vector<bool> mk(N+1);

    	vector<int> ans(N);

    	for(int i = 1 ; i <= N ; i++)
    	{
    		if(!mk[i])
    		{
    			vector<int> ttt;

    			int qu = query(i);

    			ttt.push_back(qu);

    			while(1)
    			{
    				int qu = query(i);
    				if(qu == ttt[0])break;
    				ttt.push_back(qu);
    			}

    			for(auto x : ttt)
    			{
    				mk[x] = true;
    			}

    			int tam = ttt.size();

    			for(int x = 0 ; x < tam ; x++)
    			{
    				ans[ttt[x]-1] = ttt[(x+1)%tam];
    			}
    		}
    	}

    	answer(ans);
    }

    return 0;
}