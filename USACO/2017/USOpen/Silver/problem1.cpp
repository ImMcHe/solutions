#include<bits/stdc++.h>
using namespace std;


#define int long long
#define pii pair<int,int>


const int MV=1E5;
pii cows[MV];


signed main()
{
freopen("pairup.in","r",stdin);
freopen("pairup.out","w",stdout);
	int n;
	cin>> n;
	for(int i=0; i<n; i++)
		cin>>cows[i].second>>cows[i].first;

	sort(cows,cows+n);

	int r=0;
	int f=0, s=n-1;
	while(f<=s)
	{
		r = max(cows[f].first + cows[s].first, r);
		int mv = min(cows[f].second, cows[s].second);
		cows[f].second -= mv;
		cows[s].second -= mv;

		if(cows[f].second<=0)
			f++;
		if(cows[s].second<=0)
			s--;
	}

	cout<<r <<endl;
}
