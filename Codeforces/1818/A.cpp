#include<bits/stdc++.h>
using namespace std;
 
void solve()
{
    int n,k;
    cin>>n>>k;
 
    char arr[n][k];
    bool isRemoved[n];
    memset(isRemoved,0,sizeof(isRemoved));
 
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
 
    for(int i=0;i<k;i++)
    {
        bool isPos=arr[0][i]=='+';
 
        for(int j=1;j<n;j++)
        {
            if(isPos)
            {
                if(!isRemoved[j]&&arr[j][i]=='-')
                {
                    isRemoved[j]=1;
                }
            }
            else
            {
                if(!isRemoved[j]&&arr[j][i]=='+')
                {
                    isRemoved[j]=1;
                }
            }
        }
    }
 
    int sum=0;
    for(bool i:isRemoved)
        sum+=i;
    cout<<n-sum<<endl;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
 
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}
