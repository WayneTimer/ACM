/*This Code is Submitted by Timer for Problem 2569 at 2013-03-21 01:42:42*/
#include <cstdio>
#include <cstring>

char a[10];
bool b[10];

int main()
{
  int i,j,t;
  bool flag,ans;
  while (scanf("%s",a)==1)
  {
    i=0;
    t=0;
    flag=false;
    memset(b,false,sizeof(b));
    while (a[i])
    {
      b[a[i]-'0']=true;
      if (a[i]-'0'>0)
        if (t==0 || a[i]-'0'<t) t=a[i]-'0';
      if (a[i]=='0') flag=true;
      i++;
    }
    i--;
    ans=false;
    while (i>=0)
    {
      for (j=a[i]-'0'+1;j<=9;j++)
        if (b[j])
        {
          a[i]='0'+j;
          ans=true;
          break;
        }
      if (ans) break;
      if (flag) a[i]='0';
        else a[i]='0'+t;
      i--;
    }
    if (!ans)
      printf("%d",t);
    printf("%s\n",a);
  }
  return 0;
}