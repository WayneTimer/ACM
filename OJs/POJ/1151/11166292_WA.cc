/*
林毅

题意：
给定一些矩形的左上角坐标和右下角坐标，问所有矩形覆盖到的面积是多少。

关键词：离散化 线段树

解法：
1、将矩形投影至x轴（或y轴），再离散化x坐标（即排序、去重）。将离散化后的区间作为线段树的区间。
2、将矩形按左下角y坐标排序，再依次加入进线段树中，每次加入至某点时，判断新加入的矩形的y坐标区间是否与之前的区间有重叠，有则更新结点y坐标上界和下界，没有则计算并累加之前的区间面积，同时区间上下界置为新加入矩形的y坐标上下界。

关于代码中的lazy标记：
最开始这题我是加入了lazy标记的，后来发现最多也就100个矩形，即199个区间，在log下来更本没多大，lazy标记略有点鸡肋，再加上之前精度问题wa了无数次就把lazy这部分注释了。
*/
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct cyr
{
  double y1; //区间中y坐标的下界
  double y2; //区间中y坐标的上界
  double area; //区间中已计算的面积
  bool cover; //当前区间是否被覆盖过
  //bool lazy;
};

struct rect
{
  double x1;
  double y1;
  double x2;
  double y2;
};

const int maxn=204;//这里开小了，下面的数组会发生诡异的越界
const double esp=1e-8;
cyr a[maxn<<2];
rect input[maxn];
int n;
int x,y,j,cnt;
double w[maxn<<1];
double thex[maxn<<1];

bool operator < (rect x,rect y)
{
  if (x.y2<y.y2) return true;
  return false;
}

bool inline same(double x,double y)
{
  if (x>=y)
    if ((x-y)<esp) return true;
  if (y>x)
    if ((y-x)<esp) return true;
  return false;
}

void insert(int l,int r,int now)
{
  if (l==r)
  {
    if (!a[now].cover)
    {
      a[now].y1=input[j].y1;
      a[now].y2=input[j].y2;
      a[now].cover=true;
      return;
    }
    else
    {
      if ((input[j].y2<=a[now].y1) || (same(input[j].y2,a[now].y1)))
      {
        if (input[j].y1>a[now].y1)
          a[now].y1=input[j].y1;
      }
      else
      {
        a[now].area+=(a[now].y1-a[now].y2)*w[l];
        a[now].y1=input[j].y1;
        a[now].y2=input[j].y2;
      }
      a[now].cover=true;
      return;
    }
  }
  /*
  if (a[now].lazy)
  {
    a[now<<1].y1=a[now].y1;
    a[now<<1].y2=a[now].y2;
    a[now<<1].lazy=true;
    a[now<<1|1].y1=a[now].y1;
    a[now<<1|1].y2=a[now].y2;
    a[now<<1|1].lazy=true;
    a[now].lazy=false;
  }
  */
  int mid;
  mid=(l+r)>>1;
  if (x<=mid) insert(l,mid,now<<1);
  if (y>mid) insert(mid+1,r,now<<1|1);
}

double cal(int l,int r,int now)
{
  double temp;
  if (l==r)
    if (a[now].cover)
    {
      temp=(a[now].y1-a[now].y2)*w[l];
      temp+=a[now].area;
      return temp;
    }
    else
      return 0.0;
  int mid;
  double t;
  mid=(l+r)>>1;
  t=cal(l,mid,now<<1);
  t+=cal(mid+1,r,now<<1|1);
  return t;
}

int findx(double x,int up)
{
  int i;
  for (i=1;i<=up;i++)
    if (same(x,thex[i]))
      return i;
}

int main()
{
  double sum,last;
  int i,T;
  scanf("%d",&n);
  T=0;
  while (n)
  {
    memset(a,0,sizeof(a));
    for (i=1;i<=n;i++)
    {
      scanf("%lf%lf%lf%lf",&input[i].x2,&input[i].y2,&input[i].x1,&input[i].y1);
      /*
      input[i].x2+=0.0001;
      input[i].y2+=0.0001;
      input[i].x1+=0.0001;
      input[i].y1+=0.0001;
      */
      thex[((i-1)<<1)+1]=input[i].x1;
      thex[((i-1)<<1)+2]=input[i].x2;
    }
    sort(thex+1,thex+(n<<1)+1);
    cnt=0;
    last=thex[1];
    for (i=2;i<=(n<<1);i++)
      if (!same(last,thex[i]))
      {
        cnt++;
        w[cnt]=thex[i]-last;
        last=thex[i];
        thex[cnt+1]=thex[i];
      }
    sort(input+1,input+n+1);
    for (i=1;i<=n;i++)
    {
      x=findx(input[i].x2,cnt+1);
      y=findx(input[i].x1,cnt+1)-1;
      j=i;
      insert(1,cnt,1);
    }
    sum=cal(1,cnt,1);
    T++;
    printf("Test case #%d\n",T);
    printf("Total explored area: %.2lf\n",sum);
    printf("\n");
    scanf("%d",&n);
  }
  return 0;
}
