/*
矩形覆盖问题。求周长。
(国家集训队99年陈宏的论文中讲到过这个问题)

分别对x轴、y轴投影，用两棵线段树分别计算x轴、y轴上的轮廓长度。
*/
#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAX_RECT 5010

using namespace std;

struct cyr
{
  int down,up; //分别表示区间中x/y值的下界、上界
  int s; //已计算的该区间中线段的个数
  bool cover; //表示该区间是否被覆盖过
};

struct rect
{
  int x1,y1,x2,y2;
};

rect in[MAX_RECT];
cyr a[MAX_RECT<<2];
int n,cntx,cnty,m,sum;
int thex[MAX_RECT<<1];
int they[MAX_RECT<<1];
int *the;
int x,y,t1,t2;
int lx[MAX_RECT<<1]; //投影到x轴的区间长度
int ly[MAX_RECT<<1]; //投影到y轴的区间长度
int *length;

void mysort_x(int l,int r)
{
  int i,j,mid;
  rect temp;
  i=l;
  j=r;
  mid=in[(l+r)>>1].x1;
  do
  {
    while (in[i].x1<mid) i++;
    while (in[j].x1>mid) j--;
    if (i<=j)
    {
      temp=in[i];
      in[i]=in[j];
      in[j]=temp;
      i++;
      j--;
    }
  } while (i<=j);
  if (l<j) mysort_x(l,j);
  if (i<r) mysort_x(i,r);
}

void mysort_y(int l,int r)
{
  int i,j,mid;
  rect temp;
  i=l;
  j=r;
  mid=in[(l+r)>>1].y1;
  do
  {
    while (in[i].y1<mid) i++;
    while (in[j].y1>mid) j--;
    if (i<=j)
    {
      temp=in[i];
      in[i]=in[j];
      in[j]=temp;
      i++;
      j--;
    }
  } while (i<=j);
  if (l<j) mysort_y(l,j);
  if (i<r) mysort_y(i,r);
}

inline int myfind(int u)
{
  int i;
  for (i=1;i<=m;i++)
    if (the[i]==u) return i;
}

void insert(int l,int r,int now)
{
  if (l==r)
  {
    if (!a[now].cover)
    {
      a[now].down=t1;
      a[now].up=t2;
      a[now].cover=true;
      return;
    }
    if (t2>a[now].up)
    {
      if (t1<=a[now].up)
	a[now].up=t2;
      else
      {
	a[now].s+=2;
	a[now].down=t1;
	a[now].up=t2;
      }
    }
    return;
  }
  int mid;
  mid=(l+r)>>1;
  if (x<=mid) insert(l,mid,now<<1);
  if (y>mid) insert(mid+1,r,now<<1|1);
}

int cal(int l,int r,int now)
{
  if (l==r)
  {
    if (a[now].cover)
    {
      return ((a[now].s+2)*length[l]);
    }
    return 0;
  }
  int mid,temp;
  mid=(l+r)>>1;
  temp=cal(l,mid,now<<1);
  temp+=cal(mid+1,r,now<<1|1);
  return temp;
}

int main()
{
  int i;
  while (scanf("%d",&n)==1)
  {
    for (i=1;i<=n;i++)
    {
      scanf("%d%d%d%d",&in[i].x1,&in[i].y1,&in[i].x2,&in[i].y2);
      thex[(i<<1)-1]=in[i].x1;
      thex[i<<1]=in[i].x2;
      they[(i<<1)-1]=in[i].y1;
      they[i<<1]=in[i].y2;
    }
    sort(thex+1,thex+1+(n<<1));
    cntx=1;
    for (i=2;i<=(n<<1);i++)
    {
      if (thex[cntx]!=thex[i])
      {
	lx[cntx]=thex[i]-thex[cntx];
	cntx++;
	thex[cntx]=thex[i];
      }
    }
    sort(they+1,they+1+(n<<1));
    cnty=1;
    for (i=2;i<=(n<<1);i++)
    {
      if (they[cnty]!=they[i])
      {
	ly[cnty]=they[i]-they[cnty];
	cnty++;
	they[cnty]=they[i];
      }
    }
    memset(a,0,sizeof(a));
    the=thex;
    length=lx;
    m=cntx;
    mysort_y(1,n);
    for (i=1;i<=n;i++)
    {
      x=myfind(in[i].x1);
      y=myfind(in[i].x2)-1;
      t1=in[i].y1;
      t2=in[i].y2;
      insert(1,m-1,1);
    }
    sum=cal(1,m-1,1);
    //-----------------------
    memset(a,0,sizeof(a));
    the=they;
    length=ly;
    m=cnty;
    mysort_x(1,n);
    for (i=1;i<=n;i++)
    {
      x=myfind(in[i].y1);
      y=myfind(in[i].y2)-1;
      t1=in[i].x1;
      t2=in[i].x2;
      insert(1,m-1,1);
    }
    sum+=cal(1,m-1,1);
    //-----------------------
    printf("%d\n",sum);
  }
  return 0;
}
