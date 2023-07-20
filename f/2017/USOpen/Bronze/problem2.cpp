#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAX_VAL=101;
int n,m,r;
char no[MAX_VAL][MAX_VAL];
char yes[MAX_VAL][MAX_VAL];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);freopen("cownomics.out","w",stdout);
    freopen("cownomics.in","r",stdin);

    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>no[i];
    for(int i=0;i<n;i++)cin>>yes[i];

    for(int i=0;i<m;i++)
    {
        set<char>cows;
        for(int j=0;j<n;j++)
            cows.insert(no[j][i]);

        //for(char j:cows)
          //  cout<<j<<' ';
        //cout<<endl;
        
        bool isRight=1;
        for(int j=0;j<n;j++)
        {
            if(cows.find(yes[j][i])!=cows.end())
            {
                isRight=0;
                break;
            }
        }
        r+=isRight;
    }

    cout<<r<<endl;
    return 0;
}