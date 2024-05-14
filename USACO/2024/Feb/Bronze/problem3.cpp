#include<bits/stdc++.h>
using namespace std;


#define int long long
#define pii pair<int,int>


const int MV = 2E5;
int n, q;
int arr[MV];
int tmi[MV];
int nw[MV];


signed main()
{
	cin>> n>> q;
	for(int i=0; i<n; i++)
		cin>>arr[i];
	for(int i=0; i<n; i++)
		cin>>tmi[i];

	for(int i=0; i<n; i++)
		nw[i] = arr[i] - tmi[i];
	sort(nw, nw+n);

	for(int i=0; i<q; i++)
	{
		int s, v;
		cin>> v>> s;

		int num = upper_bound(nw, nw+n, s) - nw;
		num = n - num;

		cout <<(num>=v?"YES":"NO") <<endl;
	}
}
