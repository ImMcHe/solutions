#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define x first
#define y second

const int MAX_VAL=1000;
bool reg[MAX_VAL*4+5][MAX_VAL*4+5];
int x=2001,y=2001,n,r;

bool check(int x,int y)
{
    return x<0?0:x>=MAX_VAL*4+5?0:y<0?0:y>=MAX_VAL*4+5?0:!reg[x][y];
}
void fillReg(int x,int y)
{
    queue<pii>q;
    q.push(pii(x,y));
    reg[x][y]=1;

    while(!q.empty())
    {
        pii f=q.front();
        q.pop();

        //cout<<f.x<<' '<<f.y<<endl;

        if(check(f.x-1,f.y))
        {
            reg[f.x-1][f.y]=1;
            q.push(pii(f.x-1,f.y));
        }
        if(check(f.x+1,f.y))
        {
            reg[f.x+1][f.y]=1;
            q.push(pii(f.x+1,f.y));
        }
        if(check(f.x,f.y-1))
        {
            reg[f.x][f.y-1]=1;
            q.push(pii(f.x,f.y-1));
        }
        if(check(f.x,f.y+1))
        {
            reg[f.x][f.y+1]=1;
            q.push(pii(f.x,f.y+1));
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
freopen("gates.in","r",stdin);
freopen("gates.out","w",stdout);

    cin>>n;
    cin.get();
    reg[x][y]=1;
    for(int i=0;i<n;i++)
    {
        char chr;
        chr=cin.get();
        //cout<<chr;
        for(int i=0;i<2;i++)
        {
            switch(chr)
            {
            case'N':
                y--;
                break;
            case'S':
                y++;
                break;
            case'E':
                x--;
                break;
            case'W':
                x++;
                break;
            }
            reg[x][y]=1;
        }
    }

    for(int i=0;i<MAX_VAL*4+5;i++)
        for(int j=0;j<MAX_VAL*4+5;j++)
            if(!reg[i][j])
            {
                fillReg(i,j);
                r++;
            }

    cout<<r-1;
    return 0;
}