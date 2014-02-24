/*This Code is Submitted by Timer for Problem 2500 at 2013-03-18 15:04:15*/
// 树形DP   堆栈逆推
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <map>

using namespace std;

struct eugin
{
  int x,y;
  bool xv,yv;//在作为边时没用到，在DP时用来记录是否unique
};

bool flag;
int h[202];
eugin e[400];
int n,mymax,up,r;
map <string,int> name;

eugin tree_dp(int x)
{
  int k;
  eugin t,g;
  t.x=0;
  t.y=0;
  t.xv=true;
  t.yv=true;
  k=h[x];
  while (k)
  {
    g=tree_dp(e[k].x);
    if (g.x>=g.y)
      t.y+=g.x;
    else 
      t.y+=g.y;
    if (g.x==g.y) t.yv=false;
    t.x+=g.y;
    if (!g.yv) t.xv=false;
    k=e[k].y;
  }
  t.x+=1;
  return t;
}

int main()
{
  string u,w;
  int i;
  eugin t;
  cin>>n;
  while (n)
  {
    name.clear();
    memset(h,0,sizeof(h));
    up=0;
    cin>>u;
    name[u]=1;
    r=1;
    for (i=2;i<=n;i++)
    {
      cin>>u;
      cin>>w;
      if (name[u]==0)
      {
        r++;
        name[u]=r;
      }
      if (name[w]==0)
      {
        r++;
        name[w]=r;
      }
      up++;
      e[up].x=name[u];
      e[up].y=h[name[w]];
      h[name[w]]=up;
    }
    mymax=0;
    flag=true;
    t=tree_dp(1);
    if (t.x>=t.y) 
    {  
      mymax=t.x;
      flag=t.xv;
      if (t.x==t.y) flag=false;
    }
    else 
    {
      mymax=t.y;
      flag=t.yv;
    }
    printf("%d ",mymax);
    if (flag) puts("Yes");
    else puts("No");  
    cin>>n;
  }
  return 0;
}