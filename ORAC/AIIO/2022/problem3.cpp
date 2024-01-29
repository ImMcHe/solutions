#include<bits/stdc++.h>
using namespace std;
 
#define int short
#define pii pair<int,int>
 
pii*treey[2500];
pii*treex[2500];
pii tmp[2500];
signed w, h, n;
signed mp[2500][2500];
pair<pii,pii>ran[2500*2500];
 
pii query(int s, int l, int r, int dl, int dr, pii*arr)
{
	int mid = (l+r)/2;
	if(l>dr || r<dl)
		return pii(9999,-1);
	if(l>=dl && r<=dr)
		return arr[s];
 
	pii a = query(s*2+0, l, mid, dl, dr, arr);
	pii b = query(s*2+1, mid+1, r, dl, dr, arr);
	return pii(min(a.first,b.first), max(a.second,b.second));
}
void construct(int s, int l, int r, pii*og, pii*arr)
{
	int mid = (l+r)/2;
	if(l!=r)
	{
		construct(s*2+0, l, mid, og, arr);
		construct(s*2+1, mid+1, r, og, arr);
		arr[s] = pii(min(arr[s*2+0].first,arr[s*2+1].first), max(arr[s*2+0].second,arr[s*2+1].second));
		return;
	}
	
	arr[s] = og[l];
}
 
 
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cerr<<sizeof(pii);
 
	for(int i=0; i<2500; i++)
		treex[i] = (pii*)malloc(sizeof(pii)*8191),
		treey[i] = (pii*)malloc(sizeof(pii)*8191);
 
	cin>> h>> w>> n;
	for(int i=0; i<h; i++)
		for(int j=0; j<w; j++)
			cin>> mp[i][j], mp[i][j]--;
	
#define sy first.first
#define sx first.second
#define dy second.first
#define dx second.second
#define Cord(a,b,c,d) pair<pii,pii>(pii(a,b), pii(c,d))
 
	fill(ran, ran+2500*2500, Cord(9999,9999, -1,-1));
 
	for(int i=0; i<h; i++)
		for(int j=0; j<w; j++)
		{
			auto&r = ran[mp[i][j]];
 
			r = Cord(
				min(r.sy, i),
				min(r.sx, j),
				max(r.dy, i),
				max(r.dx, j)
			);
		}
 
	for(int i=0; i<h; i++)
	{
		fill(tmp, tmp+w, pii(0,0));
		for(int j=0; j<w; j++)
			tmp[j] = pii(ran[mp[i][j]].sy, ran[mp[i][j]].dy);
		construct(1, 0, w-1, tmp, treey[i]);
	}
 
	for(int i=0; i<w; i++)
	{
		fill(tmp, tmp+h, pii(0,0));
		for(int j=0; j<h; j++)
			tmp[j] = pii(ran[mp[j][i]].sx, ran[mp[j][i]].dx);
		construct(1, 0, h-1, tmp, treex[i]);
	}
 
#undef sx
#undef sy
#undef dx
#undef dy
 
	int r=-1;
	int debugCount = 0;
	for(int i=0; i<h; i++)
		for(int j=0; j<w; j++)
		{
			int size=max(r,(short)0);
			while(size+i<h && size+j<w)
			{
				//s l r dl dr arr
				int sx=j;
				int sy=i;
				int dx=j+size;
				int dy=i+size;
 
				pii qsy = query(1, 0, w-1, sx, dx, treey[sy]);
				pii qsx = query(1, 0, h-1, sy, dy, treex[sx]);
				pii qdy = query(1, 0, w-1, sx, dx, treey[dy]);
				pii qdx = query(1, 0, h-1, sy, dy, treex[dx]);
 
				if(qsy.first<sy || qsx.first<sx)
					break;
 
				if(qdx.second<=dx && qdy.second<=dy)
					r=size, size++;
 
				size = max(size, (short)max(qdy.second-sy, qdx.second-sx));
			}
		}
	
	cout <<r+1 <<endl;
}
 
 
 
 
 
 
 
 
 
 
 
 
