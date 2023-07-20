#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define heav first
#define step second
#define idx second
#define deep first

const int MAX_VAL=1E5+1;
int n,k,arr[MAX_VAL],r[MAX_VAL];
map<int,int>numsWithLen;
pii bot[MAX_VAL];
multiset<pii>nums;
struct sndFirst
{
    bool operator()(pii first,pii second)
    {
        return first.second<second.second;
    }
};
multiset<pii,sndFirst>idxFst;
multiset<int>dist;
set<int>keys;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
freopen("snowboots.in","r",stdin);
freopen("snowboots.out","w",stdout);


    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<k;i++)
        cin>>bot[i].heav>>bot[i].step//,
    //cout<<i<<endl;
    ;

    for(int i=1;i<n-1;i++)
        nums.insert(pii(arr[i],i));

    
    dist.insert(n-1);
    idxFst.insert(pii(0,0));
    idxFst.insert(pii(0,n-1));
    numsWithLen[0]=n-1;
    while(!nums.empty())
    {
        int idx=nums.begin()->idx,curNum=nums.begin()->deep;
        idxFst.insert(*nums.begin());
        nums.erase(nums.begin());

        int idxL=(--idxFst.lower_bound(pii(curNum,idx)))->idx;
        int idxR=idxFst.upper_bound(pii(curNum,idx))->idx;

        //cout<<idx<<' '<<curNum<<' '<<idxL<<' '<<idxR<<endl;

        dist.erase(dist.find(idxR-idxL));
        dist.insert(idxR-idx);
        dist.insert(idx-idxL);
        if(numsWithLen.find(curNum)==numsWithLen.end())
            numsWithLen[curNum]=LLONG_MAX;
        numsWithLen[curNum]=min(numsWithLen[curNum],*dist.rbegin());
    }


    for(pii i:numsWithLen)
        keys.insert(i.first);
    
    for(int i=0;i<k;i++)
    {
        int lb=*(--keys.upper_bound(bot[i].heav));
        //cout<<bot[i].heav<<' '<<lb<<' '<<numsWithLen[lb]<<' ';
        if(numsWithLen[lb]>bot[i].step)
            cout<<0;
        else
            cout<<1;
        cout<<endl;
    }
    return 0;/*
for(int i=0;i<984;i++){
    int a;
    cin>>a;
    cout<<a<<endl;}*/
}