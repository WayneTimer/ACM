/*This Code is Submitted by Timer for Problem 2602 at 2013-10-28 21:33:51*/
//树水题 普通树转二叉树
#include <cstdio>

#define MAXN 10011

struct eugin
{
  int fa,s,h;
};

char s[MAXN*3];
eugin a[MAXN];
int tot,height,s2;

inline int newnode(int h,int father)
{
  tot++;
  a[tot].fa=father;
  a[tot].s=0;
  a[tot].h=h;
  return tot;
}

inline int add(int x)
{
  int h,p;
  a[x].s++;
  p=newnode(a[x].s+a[x].h,x);
  if (a[p].h>s2) s2=a[p].h;
  return p;
}

int main()
{
  int o,i,ans,x;
  o=0;
  tot=0;
  newnode(0,-1);
  scanf("%s",s);
  while (s[0]!='#')
  {
    i=0;
    tot=1;
    a[1].s=0;
    height=0;
    ans=0;
    x=1;
    s2=0;
    while (s[i])
    {
      if (s[i]=='d')
      {
        height++;
        if (height>ans) ans=height;
        x=add(x);
      }
      else
      {
        height--;
        x=a[x].fa;
      }
      i++;
    }
    printf("Tree %d: %d => %d\n",++o,ans,s2);
    scanf("%s",s);
  }
  return 0;
}