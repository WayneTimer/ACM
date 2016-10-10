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
  k=h[x];
  while (k)
  {
    g=tree_dp(e[k].x);
    if (g.x>=g.y)
      t.y+=g.x;
    else 
      t.y+=g.y;
    t.x+=g.y;
    k=e[k].y;
  }
  t.x+=1;
  if (t.x>mymax)
  {
    mymax=t.x;
    flag=true;
  }
  else if (t.x==mymax)
    flag=false;
  if (t.y>mymax)
  {
    mymax=t.y;
    flag=true;
  }
  else if (t.y==mymax)
    flag=false;
  return t;
}

int main()
{
  string u,w;
  int i;
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
    tree_dp(1);
    printf("%d ",mymax);
    if (flag) puts("Yes");
    else puts("No");  
    cin>>n;
  }
  return 0;
}