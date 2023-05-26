#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define x first
#define y second

int n,k;
int arr[1002][1002];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);freopen("paintbarn.in","r",stdin);
freopen("paintbarn.out","w",stdout);


    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        pii s,f;
        cin>>s.x>>s.y>>f.x>>f.y;
        arr[s.x][s.y]+=1;
        arr[s.x][f.y]+=-1;
        arr[f.x][s.y]+=-1;
        arr[f.x][f.y]+=1;
    }

    for(int i=1;i<1002;i++)
    {
        for(int j=0;j<1002;j++)
            arr[i][j]+=arr[i-1][j];
    }
    for(int i=0;i<1002;i++)
        for(int j=0;j<1002;j++)
            arr[i][j]+=arr[i][j-1];

    /*for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            cout<<arr[i][j]<<' ';
        }
        cout<<endl;
    }*/

    int r=0;
    for(int i=0;i<1002;i++)
    {
        for(int j=0;j<1002;j++)
            r+=arr[i][j]==k;
    }

    cout<<r<<endl;
    return 0;
}