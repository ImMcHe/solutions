#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>

const int MV=2E5+2;
int n,lst[MV],ln,dist[MV],op1,op2,dstEdgeMin,dstEdgeMax;

signed main()
{
    ios_base::sync_with_stdio(0);
    freopen("in.txt","r",stdin);
freopen("socdist1.in","r",stdin);
freopen("socdist1.out","w",stdout);

    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++)
    {
        if(cin.get()=='1')
        {
            lst[ln]=i;
            ln++;
        }
    }
    swap(n,ln);
    if(n==0)
    {
        cout<<ln-1;
        return 0;
    }

    for(int i=0;i<n-1;i++)
        dist[i]=lst[i+1]-lst[i];
    n--;
    dstEdgeMin=lst[0];
    dstEdgeMax=ln-lst[n]-1;
    if(dstEdgeMin>dstEdgeMax)
        swap(dstEdgeMin,dstEdgeMax);

    if(n==0)
        dist[0]=INT_MAX;
    sort(dist,dist+n);

    if(n>=1)
        op1=min(dist[0],dist[n-1]/3);
    op1=max(op1,min(dist[0],dstEdgeMax/2));
    if(n>=2)
        op2=min(dist[0],min(dist[n-1]/2,dist[n-2]/2));
    if(n>=1)
        op2=max(op2,min(dist[0],min(dist[n-1]/2,dstEdgeMax)));
    op2=max(op2,min(dist[0],dstEdgeMin));

    cout<<max(op1,op2);
    return 0;
}