#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct cyr
{
  double y1;
  double y2;
  double area;
  bool cover;
  //bool lazy;
};

struct rect
{
  double x1;
  double y1;
  double x2;
  double y2;
};

const int maxn=204;
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