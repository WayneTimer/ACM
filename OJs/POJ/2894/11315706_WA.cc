//差分数列
#include <cstdio>
#include <cstring>

int a[1010];
int s[1010];
int n;
char str[6];

int main()
{
  int T,i,x,y,up;
  scanf("%d",&T);
  while (T--)
  {
    up=0;
    memset(a,0,sizeof(a));
    scanf("%d",&n);
    while (n--)
    {
      scanf("%s",str);
      scanf("%d%d",&x,&y);
      if (y>up) up=y;
      a[x]++;
      a[y]--;
    }
    s[0]=0;
    for (i=1;i<=up;i++)
    {
      s[i]=s[i-1]+a[i];
      if (s[i]>=1 && s[i]<=26)
	printf("%c",'A'+s[i]-1);
    }
    puts("");
  }
  return 0;
}