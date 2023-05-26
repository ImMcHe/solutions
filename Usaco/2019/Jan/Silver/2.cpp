#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>

const int MAX_VAL=1E3;
int n;
bool arrFill[MAX_VAL][MAX_VAL],arrPer[MAX_VAL][MAX_VAL],arrPerBef[MAX_VAL][MAX_VAL];
vector<pii>stuff;

bool getArFill(int x,int y)
{
    if(x<0||x>=n||y<0||y>=n)
        return 0;
    return arrFill[x][y];
}
bool getArPer(int x,int y)
{
    if(x<0||x>=n||y<0||y>=n)
        return 0;
    return arrPer[x][y];
}
bool getArPerBef(int x,int y)
{
    if(x<0||x>=n||y<0||y>=n)
        return 0;
    return arrPerBef[x][y];
}

int calAr(int x,int y)
{
    queue<pii>q;
    q.push(pii(x,y));
    int r=0;
    arrFill[x][y]=0;
    while(!q.empty())
    {
        pii cord=q.front();
        q.pop();
        if(getArFill(cord.first-1,cord.second))
        {
            q.push(pii(cord.first-1,cord.second));
            arrFill[cord.first-1][cord.second]=0;
        }
        if(getArFill(cord.first+1,cord.second))
        {
            q.push(pii(cord.first+1,cord.second));
            arrFill[cord.first+1][cord.second]=0;
        }
        if(getArFill(cord.first,cord.second-1))
        {
            q.push(pii(cord.first,cord.second-1));
            arrFill[cord.first][cord.second-1]=0;
        }
        if(getArFill(cord.first,cord.second+1))
        {
            q.push(pii(cord.first,cord.second+1));
            arrFill[cord.first][cord.second+1]=0;
        }
        r++;
    }
    return r;
}
int calPer(int x,int y)
{
    queue<pii>q;
    q.push(pii(x,y));
    int r=0;
    arrPer[x][y]=0;
    while(!q.empty())
    {
        pii cord=q.front();
        q.pop();
        r+=!getArPerBef(cord.first-1,cord.second)+
            !getArPerBef(cord.first+1,cord.second)+
            !getArPerBef(cord.first,cord.second-1)+
            !getArPerBef(cord.first,cord.second+1);
        if(getArPer(cord.first-1,cord.second))
        {
            q.push(pii(cord.first-1,cord.second));
            arrPer[cord.first-1][cord.second]=0;
        }
        if(getArPer(cord.first+1,cord.second))
        {
            q.push(pii(cord.first+1,cord.second));
            arrPer[cord.first+1][cord.second]=0;
        }
        if(getArPer(cord.first,cord.second-1))
        {
            q.push(pii(cord.first,cord.second-1));
            arrPer[cord.first][cord.second-1]=0;
        }
        if(getArPer(cord.first,cord.second+1))
        {
            q.push(pii(cord.first,cord.second+1));
            arrPer[cord.first][cord.second+1]=0;
        }
        /*cout<<cord.first<<' '<<cord.second<<' ';
        cout<<r<<endl;*/
    }
    return r;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);freopen("perimeter.in","r",stdin);
freopen("perimeter.out","w",stdout);


    cin>>n;
    for(int i=0;i<n;i++)
    {
        char arr1[n];
        cin>>arr1;
        for(int j=0;j<n;j++)
        {
            arrFill[i][j]=arr1[j]=='#';
            arrPer[i][j]=arr1[j]=='#';
            arrPerBef[i][j]=arr1[j]=='#';
        }
    }

    /*for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<arrFill[i][j];
        cout<<endl;
    }*/

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(arrFill[i][j])
                stuff.push_back(pii(calAr(i,j),-calPer(i,j)));

    pii maxEl=*max_element(stuff.begin(),stuff.end());
    cout<<maxEl.first<<' '<<-maxEl.second<<endl;
}