#include<bits/stdc++.h>
using namespace std;


#define int long long
#define pii pair<int,int>


string strMinus(string a, string b)
{
	for(int i=1; i<=a.size(); i++)
	{
		int idxA = a.size() - i;
		int idxB = b.size() - i;
		char ca, cb;
		ca = a[idxA];
		if(idxB < 0)
			cb = '0';
		else
			cb = b[idxB];

		ca -= cb - '0';
		if(ca < '0')
			ca += 10, a[idxA-1] -= 1;
		a[idxA] = ca;
	}

	int sub = 0;
	for(int i=0; i<a.size(); i++)
		if(a[i]=='0')
			sub++;
		else
			break;

	return a.substr(sub);
}


int test()
{
	string pd;
	cin>> pd;

	if(pd[pd.size()-1] == '0')
	{
		cout<<"E"<<endl;
		return 0;
	}

	cout <<'B' <<endl;
}


signed main()
{
	cerr <<strMinus("123","24");

	int t;
	cin>> t;
	while(t--)
		test();
}