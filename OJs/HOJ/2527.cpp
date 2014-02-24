/*This Code is Submitted by Timer for Problem 2527 at 2013-09-26 00:21:35*/
//SBT   插入，找前驱，找后继
#include <cstdio>

#define MAXN 10030
#define INF 1<<30

struct eugin
{
  int v,s,lson,rson;
};

int n,root,ans;
int up;
eugin a[MAXN];

inline void RR(int &x)
{
  int t;
  t=a[x].lson;
  if (!t) return;
  a[x].lson=a[t].rson;
  a[t].rson=x;
  a[t].s=a[x].s;
  a[x].s=a[a[x].lson].s+1+a[a[x].rson].s;
  x=t;
}

inline void LR(int &x)
{
  int t;
  t=a[x].rson;
  if (!t) return;
  a[x].rson=a[t].lson;
  a[t].lson=x;
  a[t].s=a[x].s;
  a[x].s=a[a[x].lson].s+1+a[a[x].rson].s;
  x=t;
}

void maintain(int &x,bool flag)
{
  if (!x) return;
  if (flag)
  {
    if (a[x].lson && a[a[x].lson].lson &&
      (!a[x].rson || a[a[a[x].lson].lson].s>a[a[x].rson].s))
        RR(x);
    else if (a[x].lson && a[a[x].lson].rson &&
      (!a[x].rson || a[a[a[x].lson].rson].s>a[a[x].rson].s))
      {
        LR(a[x].lson);
        RR(x);
      }
    else
      return;
  }
  else
  {
    if (a[x].rson && a[a[x].rson].rson &&
      (!a[x].lson || a[a[a[x].rson].rson].s>a[a[x].lson].s))
        LR(x);
    else if (a[x].rson && a[a[x].rson].lson &&
      (!a[x].lson || a[a[a[x].rson].lson].s>a[a[x].lson].s))
      {
        RR(a[x].rson);
        LR(x);
      }
    else
      return;
  }
  maintain(a[x].lson,true);
  maintain(a[x].rson,false);
  maintain(x,true);
  maintain(x,false);
}

int pred(int x,int v)
{
  if (!x) return -INF;
  if (a[x].v==v) return v;
  if (v>a[x].v)
  {
    int ret;
    ret=pred(a[x].rson,v);
    if (ret==-INF) return a[x].v;
    return ret;
  }
  else
    return pred(a[x].lson,v);
}

int succ(int x,int v)
{
  if (!x) return INF;
  if (a[x].v==v) return v;
  if (v<a[x].v)
  {
    int ret;
    ret=succ(a[x].lson,v);
    if (ret==INF) return a[x].v;
    return ret;
  }
  else
    return succ(a[x].rson,v);
}

inline void find(int &x,int v)
{
  int t1,t2,s1,s2;
  t1=pred(x,v);
  t2=succ(x,v);
  s1=v-t1;
  s2=t2-v;
  if (s1<=s2)
    ans+=s1;
  else
    ans+=s2;
}

void insert(int &x,int v)
{
  if (!x)
  {
    up++;
    x=up;
    a[x].v=v;
    a[x].s=1;
    a[x].lson=0;
    a[x].rson=0;
    return;
  }
  a[x].s++;
  if (v<=a[x].v) insert(a[x].lson,v);
  else insert(a[x].rson,v);
  maintain(x,v<=a[x].v);
}

int main()
{
  int x,T;
  scanf("%d",&T);
  while (T--)
  {
    scanf("%d",&n);
    root=0;
    up=0;
    scanf("%d",&x);
    insert(root,x);
    ans=0;
    n--;
    while (n--)
    {
      scanf("%d",&x);
      find(root,x);
      insert(root,x);
    }
    printf("%d\n",ans);
  }
  return 0;
}