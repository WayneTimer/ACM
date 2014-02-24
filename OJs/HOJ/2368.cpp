/*This Code is Submitted by Timer for Problem 2368 at 2013-03-06 11:31:11*/
//trick:答案为负数的时候应该向下取整，而机器处理是按上取整。
//eg: 机器运算 -7/2=-3，题目要求是 -7/2=-4
#include <cstdio>

struct cyr
{
  int a,b;
};

cyr left,right;
char str[2000];

inline void work(int u,cyr &t)
{
  int k;
  bool f,g;
  f=false;
  t.a=0;
  t.b=0;
  while (str[u])
  {
    g=false;
    k=0;
    while (str[u]!='-' && str[u]!='+')
    {
      if (str[u]>='0' && str[u]<='9')
        k=k*10+str[u]-'0';
      if (str[u]=='x')
        g=true;
      u++;
      if (!str[u] || str[u]=='=') break;
    }
    if (g)
    {
      if (k==0) k=1;
      if (f) k=-k;
      t.b+=k;
    }
    else
    {
      if (f) k=-k;
      t.a+=k;
    }
    if (!str[u] || str[u]=='=') break;
    if (str[u]=='-') f=true;
      else f=false;
    u++;
  }
}

int main()
{
  int T,i,t,s,ans;
  bool flag;
  scanf("%d",&T);
  while (T--)
  {
    scanf("%s",str);
    i=0;
    while (str[i]!='=') i++;
    work(0,left);
    work(i+1,right);
    s=right.a-left.a;
    t=left.b-right.b;
    if (t==0)
    {
      if (s==0) puts("IDENTITY");
      else puts("IMPOSSIBLE");
    }
    else
    {
      flag=false;
      ans=s/t;
      if (ans<=0)
      {
        if (s<0) 
        {
          s=-s;
          flag=!flag;
        }
        if (t<0)
        {
          t=-t;
          flag=!flag;
        }
        if (!flag) printf("%d\n",ans);
        else
        {
          ans=s/t;
          if (s%t) ans++;
          printf("%d\n",-ans);
        }
      } 
      else
        printf("%d\n",ans);
    }
  }
  return 0;
}