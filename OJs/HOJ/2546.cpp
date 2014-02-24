/*This Code is Submitted by Timer for Problem 2546 at 2012-07-10 23:24:06*/
#include <cstdio>
#include <cstring>

using namespace std;

struct cyr
{
  int h;
  int m;
};

cyr t[5];

int main()
{
  char e[500];
  int i,w,l,g,s,s2;
  while (gets(e))
  {
    memset(t,0,sizeof(t));
    l=strlen(e);
    l--;
    for (i=4;i>=1;i--)
    {
      s=0;
      g=1;
      while (e[l]!=':')
      {
        s+=g*(e[l]-'0');
        g=g*10;
        l--;
      }
      t[i].m=s;
      l--;
      s=0;
      g=1;
      while ((e[l]!=' ')&&(l>=0))
      {
        s+=g*(e[l]-'0');
        g=g*10;
        l--;
      }
      t[i].h=s;
      l--;
    }
    s=(t[3].h-t[2].h)*60+(t[3].m-t[2].m);
    s2=(t[4].h-t[1].h)*60+(t[4].m-t[1].m);
    s=s2-s;
    s=s/3*2;
    g=0;
    t[3].m+=s;
    if (t[3].m>=60)
    {
      g=t[3].m/60;
      t[3].m=t[3].m%60;
    }
    t[3].h+=g;
    t[3].h=t[3].h%24;
    printf("%d:",t[3].h);
    if (t[3].m<10) printf("0");
    printf("%d\n",t[3].m);
  }
  return 0;
}
 