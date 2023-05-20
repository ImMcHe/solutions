#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define pii pair<int,int>
 
const int MAX_VAL=1E5+1;
int x,w,aud[MAX_VAL],wra[101],r;
 
int range(int a,int b)
{
    return aud[b]-aud[a];
}
 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
 
    cin>>x>>w;
 
    for(int i=0;i<x;i++)
        cin>>aud[i];
    for(int i=0;i<w;i++)
        cin>>wra[i];
 
    for(int i=1;i<x;i++)
        aud[i]+=aud[i-1];
 
    for(int i=0;i<w;i++)
    {
        int maxVal=0;
        for(int j=wra[i]-1;j<x;j++)
            maxVal=max(maxVal,range(j-wra[i],j));
        r+=maxVal;
    }
 
    cout<<r+aud[x-1];
    return 0;
}