#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>

const int MAX_VAL=5E4+1;
int n,k,r;
int arr[MAX_VAL];
int dp1[MAX_VAL],dp2[MAX_VAL];

int getVal(int n1)
{
    if(n1<0)
        return LONG_LONG_MIN/2;
    else
        return arr[n1];
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    fill(arr,arr+MAX_VAL,LONG_MAX);
//    freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
freopen("diamond.in","r",stdin);
freopen("diamond.out","w",stdout);

    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n); 


    int ptr1=1,ptr2=0;
    while(ptr2<n)
    {
        if((getVal(ptr1)-getVal(ptr2)<=k||ptr1-ptr2<=1)&&ptr1<n-1)
            ptr1++;
        else
            ptr2++;
        
        dp1[ptr1]=max(dp1[ptr1-1],dp1[ptr1]);
        if(getVal(ptr1)-getVal(ptr2)<=k)
            dp1[ptr1]=max(dp1[ptr1],ptr1-ptr2+1);
    }
    ptr1=n-2,ptr2=n-1;
    ///if(n>10){
    //cout<<"THIS IS AN ERR"<<endl;}
    while(ptr2>0)
    {
        //try
        //{
        if((getVal(ptr2)-getVal(ptr1)<=k||ptr2-ptr1<=1)&&ptr1>0)
            ptr1--;
        else
            ptr2--;
        //cout<<ptr1<<' '<<ptr2<<endl;
        
        dp2[ptr1]=max(dp2[ptr1+1],dp2[ptr1]);
        if(getVal(ptr2)-getVal(ptr1)<=k)
            dp2[ptr1]=max(dp2[ptr1],ptr2-ptr1+1);
        //}
        //catch(exception e)
        //{
        //    cout<<e.what()<<endl;
        //    return 0;
        //}
    }
    //cout<<"FFF"<<endl;
    dp1[n-1]=max(dp1[n-2],dp1[n-1]);
    dp2[0]=max(dp2[1],dp2[0]);


    /*for(int i=0;i<n;i++)
        cout<<arr[i]<<' ';
    cout<<endl;
    for(int i=0;i<n;i++)
        cout<<dp1[i]<<' ';
    cout<<endl;
    for(int i=0;i<n;i++)
        cout<<dp2[i]<<' ';
    cout<<endl;*/


    for(int i=0;i<n;i++)
        r=max(dp1[i]+dp2[i+1],r);


    cout<<r<<endl;
    return 0;
}