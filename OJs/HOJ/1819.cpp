/*This Code is Submitted by Timer for Problem 1819 at 2013-08-11 17:30:20*/
//SBT入门题 0.61s
#include <cstdio>
#include <cstring>

#define MAXN 100030
#define INF 247483637

struct eugin
{
  int v,lson,rson,s;
};

int n,low,ch,up,root;
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

int del(int &x)
{
  if (!x) return 0;
  int t,t2;
  t^=t;
  if (a[x].v+ch<low)
  {
    t=a[a[x].lson].s+1;
    t2=del(a[x].rson);
    t+=t2;
    x=a[x].rson;
  }
  else
  {
    t=del(a[x].lson);
    a[x].s-=t;
  }
  return t;
}

int find(int x,int y)
{
  if (!x) return -INF;
  if (a[x].s<y) return -INF;
  int s2;
  if (a[x].rson) s2=a[a[x].rson].s;
    else s2=0;
  if (y==s2+1) return a[x].v;
  if (y<=s2) return find(a[x].rson,y);
  return find(a[x].lson,y-s2-1);
}

int main()
{
  int x,ans;
  char op[6];
  a[0].s=0;
  while (scanf("%d%d",&n,&low)==2)
  {
    up^=up;
    ch^=ch;
    ans^=ans;
    root=0;
    while (n--)
    {
      scanf("%s%d",op,&x);
      if (op[0]=='I')
      {
        if (x>=low) insert(root,x-ch);
      }
      else if (op[0]=='A')
        ch+=x;
      else if (op[0]=='S')
      {
        ch-=x;
        ans+=del(root);
      }
      else
      {
        x=find(root,x);
        x+=ch;
        if (x<0) puts("-1");
        else
          printf("%d\n",x);
      }
    }
    printf("%d\n",ans);
  }
  return 0;
}

/*
0.70s
splay 有size域，找前驱，删除，找第k大
#include <cstdio>

#define MAXN 100030

struct eugin
{
  int v,fa,s;
  int son[2];
};

int n,s,low,up,root,ch;
eugin a[MAXN];

inline void rotate(int x,int flag)
{
  int y,z;
  y=a[x].fa;
  z=a[y].fa;
  a[y].son[!flag]=a[x].son[flag];
  a[a[x].son[flag]].fa=y;
  a[y].s=1;
  if (a[y].son[0])
    a[y].s+=a[a[y].son[0]].s;
  if (a[y].son[1])
    a[y].s+=a[a[y].son[1]].s;
  if (z)
    a[z].son[a[z].son[1]==y]=x;
  a[x].fa=z;
  a[x].son[flag]=y;
  a[y].fa=x;
  a[x].s=1;
  if (a[x].son[0])
    a[x].s+=a[a[x].son[0]].s;
  if (a[x].son[1])
    a[x].s+=a[a[x].son[1]].s;
}

inline void splay(int x,int goal)
{
  while (a[x].fa!=goal)
  {
    if (a[a[x].fa].fa==goal)
      rotate(x,a[a[x].fa].son[0]==x);
    else
    {
      int y,z,flag;
      y=a[x].fa;
      z=a[y].fa;
      flag=(a[z].son[0]==y);
      if (a[y].son[flag]==x)
      {
        rotate(x,!flag);
        rotate(x,flag);
      }
      else
      {
        rotate(y,flag);
        rotate(x,flag);
      }
    }
  }
  if (goal==0) root=x;
}

inline void insert(int v)
{
  up++;
  a[up].v=v;
  a[up].son[0]=0;
  a[up].son[1]=0;
  a[up].s=1;
  if (!root)
  {
    a[up].fa=0;
    root=up;
    return;
  }
  int x;
  x=root;
  while (a[x].son[v>a[x].v])
  {
    a[x].s++;
    x=a[x].son[v>a[x].v];
  }
  a[x].son[v>a[x].v]=up;
  a[up].fa=x;
  splay(up,0);
}

inline int pred(int v)
{
  if (!root) return 0;
  int x,ret;
  ret=0;
  x=root;
  while (a[x].son[v>a[x].v])
  {
    if (v>a[x].v) ret=x;
    x=a[x].son[v>a[x].v];
  }
  if (a[x].v<v) return x;
  return ret;
}

inline int del(int v)
{
  int x,ret;
  x=pred(v);
  if (!x) return 0;
  splay(x,0);
  ret=1;
  if (a[root].son[0])
    ret+=a[a[root].son[0]].s;
  root=a[root].son[1];
  a[root].fa=0;
  return ret;
}

inline int find(int k)
{
  int t,x;
  x=root;
  while (true)
  {
    if (a[x].son[0])
      t=a[a[x].son[0]].s;
    else
      t=0;
    if (t+1==k) return a[x].v+ch;
    if (k<=t)
      x=a[x].son[0];
    else
    {
      x=a[x].son[1];
      k-=t+1;
    }
  }
}

int main()
{
  char op[6];
  int v,ans;
  while (scanf("%d%d",&n,&low)==2)
  {
    up^=up;
    root^=root;
    s^=s;
    ch^=ch;
    while (n--)
    {
      scanf("%s%d",op,&v);
      if (op[0]=='I')
      {
        if (v>=low)
        {
          v-=ch;
          insert(v);
        }
      }
      else if (op[0]=='A')
        ch+=v;
      else if (op[0]=='S')
      {
        ch-=v;
        s+=del(low-ch);
      }
      else
      {
        if (v>a[root].s)
          ans=-1;
        else
          ans=find(a[root].s-v+1);
        printf("%d\n",ans);
      }
    }
    printf("%d\n",s);
  }
  return 0;
}
*/