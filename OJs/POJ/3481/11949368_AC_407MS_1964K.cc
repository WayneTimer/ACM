//SBT
#include <cstdio>

#define MAXN 1000030

struct eugin
{
  int v,s,lson,rson;
  int k;
};

eugin a[MAXN];
int root,up;

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

void insert(int &x,int k,int v)
{
  if (!x)
  {
    up++;
    x=up;
    a[x].v=v;
    a[x].k=k;
    a[x].s=1;
    a[x].lson=0;
    a[x].rson=0;
    return;
  }
  a[x].s++;
  if (v<=a[x].v) insert(a[x].lson,k,v);
  else insert(a[x].rson,k,v);
  maintain(x,v<=a[x].v);
}

inline int delmax(int &x)
{
  int t;
  t=x;
  if (!a[x].rson)
  {
    x=a[x].lson;
    return a[t].k;
  }
  while (a[a[t].rson].rson)
  {
    a[t].s--;
    t=a[t].rson;
  }
  int ret;
  ret=a[a[t].rson].k;
  a[t].s--;
  a[t].rson=a[a[t].rson].lson;
  return ret;
}

inline int delmin(int &x)
{
  int t;
  t=x;
  if (!a[x].lson)
  {
    x=a[x].rson;
    return a[t].k;
  }
  while (a[a[t].lson].lson)
  {
    a[t].s--;
    t=a[t].lson;
  }
  int ret;
  ret=a[a[t].lson].k;
  a[t].s--;
  a[t].lson=a[a[t].lson].rson;
  return ret;
}

int main()
{
  int op,x,y;
  root=0;
  up^=up;
  scanf("%d",&op);
  while (op)
  {
    if (op==1)
    {
      scanf("%d%d",&x,&y);
      insert(root,x,y);
    }
    else
    {
      if (!root) x=0;
      else if (op==2) 
        x=delmax(root);
      else
        x=delmin(root);
      printf("%d\n",x);
    }
    scanf("%d",&op);
  }
  return 0;
}