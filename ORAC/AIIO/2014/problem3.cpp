#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define pii pair<int,int>
 
const int MV=1E5;
int n,m,arr[MV],psb[MV];
int ch[MV*10+1],totAmount;
set<pii>stFwd={{INT_MIN,INT_MIN}},stBwd={{INT_MIN,INT_MIN}};
struct Comp{
    bool operator()(pii a,pii b)
    {
        return a.second-a.first==b.second-b.first?a<b:a.second-a.first<b.second-b.first;
    }
};
set<pii,Comp>lgs;
 
signed main()
{
    fill(ch,ch+sizeof(ch)/sizeof(int),-1);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        int c;
        cin>>c;
        ch[c]=i;
    }
    for(int i=0;i<m;i++)
        cin>>arr[i];
 
    for(int i=0;i<m;i++)
    {
        if(ch[arr[i]]!=-1&&i-ch[arr[i]]>=0)
            psb[i-ch[arr[i]]]++;
    }
    for(int i=0;i<m;i++)
        if(psb[i]==n)
        {
            totAmount++;
            int fwd=i,bwd=i+n;
            // cout<<' '<<fwd<<' '<<bwd<<' '<<(--stBwd.upper_bound({fwd,INT_MAX}))->first<<' '<<(--stBwd.upper_bound({fwd,INT_MAX}))->second<<endl;
            // for(pii i:stBwd)
            //     cout<<i.first<<','<<i.second<<' ';
            // cout<<endl;
 
            if((--stBwd.upper_bound({fwd,INT_MAX}))->first==fwd)
            {
                pii ub=*(--stBwd.upper_bound({fwd,INT_MAX}));
 
                // cout<<ub.first<<' '<<ub.second<<endl;
 
                stBwd.erase(ub);
                stFwd.erase({ub.second,ub.first});
 
                stFwd.insert({ub.second,bwd});
                stBwd.insert({bwd,ub.second});
 
                // cout<<(pii){bwd,ub.second}.first<<' '<<(pii){bwd,ub.second}.second<<endl;
            }
            else
                stFwd.insert({fwd,bwd}),stBwd.insert({bwd,fwd});
        }
    // cout<<endl;
 
    for(pii i:stFwd)
        lgs.insert(i);
 
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        // for(pii i:stFwd)
        //     cout<<i.first<<','<<i.second<<' ';
        // cout<<endl;
        // for(pii i:stBwd)
        //     cout<<i.first<<','<<i.second<<' ';
        // cout<<endl;
        // for(pii i:lgs)
        //     cout<<i.first<<','<<i.second<<' ';
        // cout<<endl;
        // for(int i=0;i<m;i++)
        //     cout<<arr[i]<<' ';
        // cout<<endl;
        int c,v;
        cin>>c>>v;
        if(ch[arr[c-1]]!=-1)
        {
            if((c-1-ch[arr[c-1]]>=0?psb[c-1-ch[arr[c-1]]]:-1)==n)
            {
                // cout<<"DecreasedAmount"<<endl;
                totAmount--;
                int fwd=c-1-ch[arr[c-1]];
                int bwd=fwd+n;
 
                auto ub=--stFwd.upper_bound({fwd,INT_MAX});
                if(ub->second>=bwd)
                {
                    pii _ub=*ub;
                    lgs.erase(_ub);
                    stBwd.erase({ub->second,ub->first});
                    stFwd.erase(ub);
    
                    if(_ub.first!=fwd)
                        stFwd.insert({_ub.first,fwd}),stBwd.insert({fwd,_ub.first}),lgs.insert({_ub.first,fwd});
                    if(_ub.second!=bwd)
                        stFwd.insert({bwd,_ub.second}),stBwd.insert({_ub.second,bwd}),lgs.insert({bwd,_ub.second});
                }
            }
            if(c-1-ch[arr[c-1]]>=0)
                psb[c-1-ch[arr[c-1]]]--;
        }
        if(ch[v]!=-1)
        {
            if(c-1-ch[v]>=0)
                psb[c-1-ch[v]]++;
            if((c-1-ch[v]>=0?psb[c-1-ch[v]]:-1)==n)
            {
                // cout<<"InsertedAmount"<<endl;
                totAmount++;
                int fwd=c-1-ch[v];
                int bwd=fwd+n;
 
                auto fb=stFwd.lower_bound({bwd,INT_MIN});
                auto ub=--stBwd.upper_bound({fwd,INT_MAX});
                pii _fb=*fb,_ub=*ub;
 
                bool psble1=fb->first==bwd,psble2=ub->first==fwd;
                if(fb==stFwd.end())
                    psble1=0;
 
                if(psble1&&psble2)
                {
                    lgs.erase(_fb),lgs.erase({_ub.second,_ub.first});
                    stBwd.erase({fb->second,fb->first});
                    stFwd.erase({ub->second,ub->first});
                    stFwd.erase(fb);
                    stBwd.erase(ub);
 
                    lgs.insert({_ub.second,_fb.second});
                    stFwd.insert({_ub.second,_fb.second});
                    stBwd.insert({_fb.second,_ub.second});
                }
                else if(psble1)
                {
                    lgs.erase(_fb);
                    stBwd.erase({fb->second,fb->first});
                    stFwd.erase(fb);
 
                    lgs.insert({fwd,_fb.second});
                    stFwd.insert({fwd,_fb.second});
                    stBwd.insert({_fb.second,fwd});
                }
                else if(psble2)
                {
                    lgs.erase({_ub.second,_ub.first});
                    stFwd.erase({ub->second,ub->first});
                    stBwd.erase(ub);
 
                    lgs.insert({_ub.second,bwd});
                    stBwd.insert({bwd,_ub.second});
                    stFwd.insert({_ub.second,bwd});
                }
                else
                {
                    lgs.insert({fwd,bwd});
                    stBwd.insert({bwd,fwd});
                    stFwd.insert({fwd,bwd});
                }
 
                // cout<<fwd<<' '<<bwd<<endl;
            }
        }
        arr[c-1]=v;
 
        cout<<totAmount<<' '<<(lgs.rbegin()->second-lgs.rbegin()->first)/n<<endl;
    }
}