/*This Code is Submitted by Timer for Problem 1086 at 2012-08-16 20:51:19*/
#include <cstdio>
#include <cstring>

int n,heng,shu;
char a[10][10];
int row[10][10],col[10][10];
bool map[110][110];
bool cover[110];
int link[110];

bool find(int v)
{
  int i,k;
  for (i=1;i<=shu;i++)
    if ((!cover[i]) && (map[v][i]))
    {
      k=link[i];
      link[i]=v;
      cover[i]=true;
      if ((k==0) || (find(k))) return true;
      link[i]=k;
    }
  return false;
}

int main()
{
  int i,j,s;
  scanf("%d",&n);
  while (n)
  {
    memset(map,false,sizeof(map));
    memset(link,0,sizeof(link));
    heng^=heng;
    shu^=shu;
    getchar();
    for (i=0;i<n;i++)
    {
      gets(a[i]);
      for (j=0;j<n;j++)
      {
        if (a[i][j]=='X') continue;
        if ((j==0) || (a[i][j-1]=='X'))
        {
          heng++;
          row[i][j]=heng;
        }
        else
          row[i][j]=heng;
      }
    }
    for (j=0;j<n;j++)
    {
      for (i=0;i<n;i++)
      {
        if (a[i][j]=='X') continue;
        if ((i==0) || (a[i-1][j]=='X'))
        {
          shu++;
          col[i][j]=shu;
        }
        else
          col[i][j]=shu;
        map[row[i][j]][col[i][j]]=true;
      }
    }
    s^=s;
    for (i=1;i<=heng;i++)
    {
      memset(cover,false,sizeof(cover));
      if (find(i))
        s++;
    }
    printf("%d\n",s);
    scanf("%d",&n);
  }
  return 0;
}