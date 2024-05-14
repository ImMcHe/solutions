#include<bits/stdc++.h>
using namespace std;


#define int long long
#define pii pair<int,int>


const int MV=500;
string spot[MV];
string plan[MV];


signed main()
{
freopen("cownomics.in","r",stdin);
freopen("cownomics.out","w",stdout);
	int n, m;
	cin>> n>> m;
	for(int i=0; i<n; i++)
		cin>> spot[i];
	for(int i=0; i<n; i++)
		cin>> plan[i];

	int r=0;
	
	for(int i=0; i<m; i++)
		for(int j=i+1; j<m; j++)
			for(int k=j+1; k<m; k++)
			{
				set<int>st1;
				set<int>st2;

				for(int _=0; _<n; _++)
					st1.insert(spot[_][i]*0xFFFF+spot[_][j]*0xFF+spot[_][k]);
				for(int _=0; _<n; _++)
					st2.insert(plan[_][i]*0xFFFF+plan[_][j]*0xFF+plan[_][k]);

				set<int>st3;
				for(int i:st1)
					st3.insert(i);
				for(int i:st2)
					st3.insert(i);
				
				if(st3.size()==st1.size()+st2.size())
					r++;
			}

	cout <<r <<endl;
}
