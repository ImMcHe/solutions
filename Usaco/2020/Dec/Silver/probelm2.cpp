#include<bits/stdc++.h>
using namespace std;

#define int long long
//#define debug d

int n,r;
const int MAX_VAL=2501;
pair<int,int>cords[MAX_VAL];
int prefix[MAX_VAL][MAX_VAL];

int findArea(int x1,int y1,int x2,int y2)
{
    return prefix[x2][y2]-(x1==0?0:prefix[x1-1][y2])-(y1==0?0:prefix[x2][y1-1])+(x1==0||y1==0?0:prefix[x1-1][y1-1]);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("")

    cin>>n;
    for(int i=0;i<n;i++)cin>>cords[i].first>>cords[i].second;

    sort(cords,cords+n);

    for(int i=0;i<n;i++)
    cords[i].first=i;

    sort(cords,cords+n,[&](pair<int,int>a,pair<int,int>b){return a.second<b.second;});

    for(int i=0;i<n;i++)cords[i].second=i;

    for(int i=0;i<n;i++)prefix[cords[i].first][cords[i].second]=1;

    for(int i=0;i<MAX_VAL;i++)
        for(int j=1;j<MAX_VAL;j++)
            prefix[i][j]+=prefix[i][j-1];
    for(int i=1;i<MAX_VAL;i++)
        for(int j=0;j<MAX_VAL;j++)
            prefix[i][j]+=prefix[i-1][j];
#ifdef debug
cout<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<prefix[i][j]<<' ';
        }cout<<endl;
    }cout<<endl<<endl;;
    #endif
        
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int x1=min(cords[i].first,cords[j].first),x2=max(cords[i].first,cords[j].first);
            int left=(x1==0?0:findArea(0,cords[i].second,x1-1,cords[j].second))+1;
            int right=(x2==n-1?0:findArea(x2+1,cords[i].second,n-1,cords[j].second))+1;
            r+=left*right;
            
            #ifdef debug
            cout<<"Cords: "<<x1<<' '<<cords[i].second<<' '<<x2<<' '<<cords[j].second<<" Left: "<<left<<" Right: "<<right<<endl;
            #endif
        }
    }
    #ifdef debug
    cout<<endl<<endl;
    #endif

    cout<<r+1+n<<endl;
    return 0;
}