/*This Code is Submitted by Timer for Problem 2120 at 2012-04-08 15:22:42*/
#include <cstdio>
#include <cstring>

int fa[1001], x, y, b[1001], flag, c[1001], k = 1;

int find_set(int i)
{
 if(fa[i] != i)
 {
  fa[i] = find_set(fa[i]);
 }
 return fa[i];
}


int main()
{
 int i,t;
 for (i=0;i<=1000;i++)
  fa[i]=i;
 flag=1;
 memset(b, 0, sizeof(b));
 memset(c, 0, sizeof(c));
 scanf("%d %d",&x,&y);
 while ((x!=-1)&&(y!=-1))
 {
  if (x==0)
  {   
    t=0;
    for(i = 0; i < 1001; i ++)
      if(b[i]) c[find_set(i)]++;
    for (i=0;i<1001;i++)
      if (c[i] > 1) t++;
    if (t>1) flag = 0;
      printf("Case %d is ", k ++);
    if (flag)
      printf("a tree.\n");
    else
      printf("not a tree.\n");
    for (i=0;i<=1000;i++)
      fa[i]=i;
    flag=1;
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
  }
  else
  { 
    b[x] = 1;
    b[y] = 1;
    if(fa[y] != y || find_set(x) == y) flag = 0;
    fa[y] = find_set(x);     
  }
  scanf("%d%d",&x,&y);
 }
 return 0;
}