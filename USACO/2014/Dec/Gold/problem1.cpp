#include<bits/stdc++.h>
using namespace std;


#define int long long
#define pii pair<int,int>
#define vti vector<int>


signed main()
{
	freopen("guard.in","r",stdin);
	ofstream bruh123("guard.out");
	auto bruh234 = cout.rdbuf();
	cout.rdbuf(bruh123.rdbuf());
	stringstream cerr;

	int n, h;
	cin>> n>> h;
	vector<vti>arr(n,vti(3));
	for(vti&i:arr)
		cin>> i[0]>> i[1]>> i[2];

	// 0 = height
	// 1 = weight
	// 2 = strength

	vector<pii> dp(1<<n+1, {-1E18,0});
	dp[0] = {1E18,0};
	for(int m=0; m<(1<<n); m++)
	{
		for(int j=0; j<n; j++)
		{
			if((1<<j) & m)
			{
				pii val = dp[m^(1<<j)];
				dp[m] = max(dp[m], {min(val.first,arr[j][2]-val.second), val.second+arr[j][1]});
			}
		}
	}

	for(int i=0; i<(1<<n); i++)
		cerr <<bitset<22>(i).to_string() <<": "<<dp[i].first <<' ' <<dp[i].second <<endl;

	int res = -1E18+23;
	for(int m=0; m<(1<<n); m++)
	{
		int psb = 0;
		for(int j=0; j<n; j++)
			psb += ((1<<j)&m) ? arr[j][0] : 0;
		if(psb >= h)
			res = max(res, dp[m].first);
	}
	
	cout <<(res<0?"Mark is too tall":to_string(res));

cout.rdbuf(bruh234);
cout <<cerr.str();
}
