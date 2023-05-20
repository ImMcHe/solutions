#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>

const int MAX_VAL=1E5+1;
int n,k;
pii arr[MAX_VAL];

bool solve(int len)
{
    int curP=arr[0].first,curK=0;

    for(int i=1;i<n;i++)
    {
        curP+=len;
        while(curK<k&&arr[curK].second<curP)
            curK++;
        if(curK==k)
            return 0;
        curP=max(arr[curK].first,curP);
    }

    return 1;
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);freopen("socdist.in\
","r",stdin);
freopen("socdist.out","w",stdout);


    cin>>n>>k;
    for(int i=0;i<k;i++)
        cin>>arr[i].first>>arr[i].second;
    sort(arr,arr+k);
    

    int l=0,r=2E18;
    
    while(r-l>1)
    {
        int mid=(l+r)/2;
        if(solve(mid))
            l=mid;
        else
            r=mid;
    }
    if(solve(l))
        cout<<l;
    else
        cout<<r;
    cout<<endl;
    return 0;
}