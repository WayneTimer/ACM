/*This Code is Submitted by Timer for Problem 1372 at 2012-07-31 16:54:11*/
#include <cstdio>
#include <cstring>

using namespace std;

const int H=4000037;
int n,m;
int k[7];
int p[7];
int ans;
int f[H],v[H];
bool use[H];
int mid;

int locate(int s)
{
  int h;
  h=s;
  while (h<0) h+=H;
  while (h>=H) h=h%H;
  while ((use[h]) && (f[h]!=s))
  {
    h++;
    if (h>=H) h-=H;
  } 
  return h; 
}

void insert(int s)
{
  int pos;
  pos=locate(s);
  if (!use[pos]) 
  {  
    use[pos]=true;
    f[pos]=s; 
  }
  v[pos]++;
}

void hash(int u,int sum)
{
  int i,t,s;
  if (u>mid) 
  {
    insert(sum);
    return;
  }
  for (i=1;i<=m;i++)
  {
    t=p[u];
    s=1;
    while (t--)
      s=s*i;
    s=k[u]*s;
    s=sum+s;
    hash(u+1,s);
  }
}

void sub(int u,int sum)
{
  if (u>n)
  {
    int pos;
    sum=-sum;
    pos=locate(sum);
    if (f[pos]==sum)
      ans+=v[pos];
    return;
  }
  int i,t,s;
  for (i=1;i<=m;i++)
  {
    t=p[u];
    s=1;
    while (t--)
      s=s*i;
    s=k[u]*s;
    s=sum+s;
    sub(u+1,s);
  }
}

int main()
{
  int i;
  while (scanf("%d",&n)==1)
  {
    scanf("%d",&m);
    for (i=1;i<=n;i++)
      scanf("%d%d",&k[i],&p[i]);
    memset(f,0,sizeof(f));
    memset(v,0,sizeof(v));
    memset(use,false,sizeof(use));
    mid=n>>1;
    ans=0;
    hash(1,0);
    sub(mid+1,0);
    printf("%d\n",ans);
  }
  return 0;
}