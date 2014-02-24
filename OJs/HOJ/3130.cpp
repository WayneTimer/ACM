/*This Code is Submitted by Timer for Problem 3130 at 2013-02-05 14:16:12*/
#include <cstdio>
#include <cstring>

int n,m;
char a[1000][1000];
bool b[1000][1000];

bool check(int i,int x,int y)
{
  int j;
  b[i][x]=false;
  for (j=x+1;j<=y;j++)
  {
    b[i][j]=false;
    if (a[i][j]!=a[i][x]) return false;
  }
  if (y+1<m)
    if (a[i][y+1]=='#') return false;
  if (a[i][x]=='#') return check(i+1,x,y);
  return true;
}

int main()
{
  int i,j,k,s;
  bool flag;
  scanf("%d%d",&n,&m);
  while (n || m)
  {
    for (i=0;i<n;i++)
      scanf("%s",a[i]);
    memset(b,true,sizeof(b));
    s^=s;
    flag=true;
    for (i=0;i<n;i++)
      if (flag)
        for (j=0;j<m;j++)
        {
          if (a[i][j]=='#' && b[i][j])
          {
            b[i][j]=false;
            s++;
            for (k=j+1;k<m;k++)
              if (a[i][k]=='#' && b[i][k])
                b[i][k]=false;
              else
                break;
            k--;
            if (!check(i+1,j,k))
            {
              flag=false;
              break;
            }
          }
        }
    if (flag) printf("%d\n",s);
      else puts("Oh!My God!");
    scanf("%d%d",&n,&m);
  }
  return 0;
}