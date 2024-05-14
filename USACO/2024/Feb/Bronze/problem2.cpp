#include<bits/stdc++.h>
using namespace std;


#define int long long
#define pii pair<int,int>


const int MV = 2E5;
int n, m;
string swp;
int arr[MV];
int loop[MV];


int fwd(int idx)
{
	char sw = swp[idx];
	if(sw == 'L')
		return (idx - 1 + n)%n;
	return (idx + 1)%n;
}
int bwd(int idx)
{
	char sw = swp[idx];
	if(sw == 'R')
		return (idx - 1 + n)%n;
	return (idx + 1)%n;
}


signed main()
{
	cin>> n>> m;
	cin>> swp;
	for(int i=0; i<n; i++)
		cin>>arr[i];

	vector<int>lens;

	char ch = swp[0];
	bool isFullLoop = 1;
	for(char i : swp)
		if(i != ch)
			isFullLoop = 0;
	if(isFullLoop)
	{
		int s = 0;
		for(int i=0; i<n; i++)
			s+=arr[i];
		cout <<s <<endl;
		return 0;
	}

	for(int i=0; i<n; i++)
	{
		if(swp[i] == 'R')
		{
			if(fwd(fwd(i)) == i)
				loop[i] = 1,
				loop[fwd(i)] = -1;
		}
		if(swp[i] == 'L')
		{
			if(fwd(fwd(i)) == i)
				loop[i] = -1,
				loop[fwd(i)] = 1;
		}
	}

	for(int i=0; i<n; i++)
		cerr <<loop[i] <<' ';
	cerr <<endl;

	for(int i=0; i<n; i++)
	{
		if(loop[i] != 0)
		{
			if(loop[bwd(i)] != 0)
				continue;

			int sm = 0;
			int idx = i;
			while(1)
			{
				int nwIdx = bwd(idx);

				if(swp[nwIdx] != swp[idx])
					break;

				idx = nwIdx;
				sm += arr[idx];
			}

			lens.push_back(sm);
		}
	}
	sort(lens.begin(), lens.end());

	for(int i : lens)
		cerr <<i <<' ';
	cerr <<endl;

	int sub = 0;
	int totMinus = 0;
	for(int i=0; i<lens.size(); i++)
	{
		sub += min(max(m,0LL), max(lens[i]-totMinus, 0LL)) * (lens.size() - i);
		m -= max(lens[i]-totMinus, 0LL);
		cerr <<m <<',' <<sub <<' ';
		totMinus = lens[i];
	}
	cerr <<endl;

	cerr <<sub <<endl;

	int lSum = 0;
	for(int i=0; i<n; i++)
		lSum += arr[i];

	cerr <<lSum <<endl;

	cout <<lSum - sub <<endl;
}

