/*This Code is Submitted by Timer for Problem 1447 at 2012-02-22 14:42:51*/
#include <cstdio>
#include <cstring>

using namespace std;

char a[105][35];
char b[105][35];
int f[105][105];
char s[105][105][2500];
int n,m;

int max(int x,int y)
{
  if (x>y) return x;
    else return y;
}

int main()
{
  char x[35];
  int l,i,j;
  while (scanf("%s",x)==1)
  {
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    n=0;
    m=0;
    while (strcmp(x,"#")!=0)
    {
      n++;
      strcpy(a[n],x);
      scanf("%s",x);
    }
    scanf("%s",x);
    while (strcmp(x,"#")!=0)
    {
      m++;
      strcpy(b[m],x);
      scanf("%s",x);
    }
    memset(f,0,sizeof(f));
    memset(s,0,sizeof(s));
    for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
      {
        l=0;
        if (strcmp(a[i],b[j])==0)
          {
            l=f[i-1][j-1]+1;
          }
        if (f[i][j-1]>=f[i-1][j])
        {
          f[i][j]=f[i][j-1];
          strcpy(s[i][j],s[i][j-1]);
        }
        else
        {
          f[i][j]=f[i-1][j];
          strcpy(s[i][j],s[i-1][j]);
        }
        if (l>f[i][j])
        {
          f[i][j]=l;
          strcpy(s[i][j],s[i-1][j-1]);
          strcat(s[i][j],a[i]);
          strcat(s[i][j]," ");
        }
      }
    l=strlen(s[n][m]);
    s[n][m][l-1]='\0';
    printf("%s\n",s[n][m]);
  }
  return 0;
}