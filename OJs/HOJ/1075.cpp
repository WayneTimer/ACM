/*This Code is Submitted by Timer for Problem 1075 at 2012-03-09 19:27:03*/
#include <cstdio>
#include <cstring>
#define maxn 50

using namespace std;

int m,n,s;
int way[5];
bool a[2501][5];
bool b[2501][2501];
int c[2501],w[2501];
bool kuo[2501];

void init()
{
  int i,j,e,q;
  memset(w,0,sizeof(w));
  memset(a,0,sizeof(a));
  memset(b,false,sizeof(b));
  memset(c,0,sizeof(c));
  memset(kuo,false,sizeof(kuo));
  q=0;
  for (i=1;i<=n;i++)
  {
      for (j=1;j<=m;j++)
      {
            scanf("%d",&e);
            q=(i-1)*m+j;
            switch (e)
            {
              case 1:{a[q][1]=true;break;}
              case 2:{a[q][2]=true;break;}
              case 3:{a[q][1]=true;a[q][2]=true;break;}
              case 4:{a[q][3]=true;break;}
              case 5:{a[q][1]=true;a[q][3]=true;break;}
              case 6:{a[q][2]=true;a[q][3]=true;break;}
              case 7:{a[q][1]=true;a[q][2]=true;a[q][3]=true;break;}
              case 8:{a[q][4]=true;break;}
              case 9:{a[q][1]=true;a[q][4]=true;break;}
              case 10:{a[q][2]=true;a[q][4]=true;break;}
              case 11:{a[q][1]=true;a[q][2]=true;a[q][4]=true;break;}
              case 12:{a[q][3]=true;a[q][4]=true;break;}
              case 13:{a[q][1]=true;a[q][3]=true;a[q][4]=true;break;}
              case 14:{a[q][2]=true;a[q][3]=true;a[q][4]=true;break;}
              case 15:{a[q][1]=true;a[q][2]=true;a[q][3]=true;a[q][4]=true;break;}
            };
      }
  }
  way[1]=1;
  way[2]=m;
  way[3]=-1;
  way[4]=-m;
}

int main()
{
  int i,j,x,y,yy,jj;
  long u,uu,h,maxh;
  char fang;
  bool ff;
  while (scanf("%d%d",&m,&n)==2)
  {
  init();
  s=n*m;
  for (i=1;i<=s;i++)
  {
        if ((i%m)!=1)
          if (!a[i][1]) b[i][i-1]=true;
        if ((i/m)>0)
          if (!a[i][2]) b[i][i-m]=true;
        if ((i%m)!=0)
          if (!a[i][3]) b[i][i+1]=true;
        if ((i+m)<=s)
          if (!a[i][4]) b[i][i+m]=true;
  }
  u=0;
  uu=0;
  maxh=0;
  while (u<s)
  {
        i=1;
        while (c[i]!=0) i++;
        c[i]=i;
        w[c[i]]=1;
        u++;
        uu++;
        h=1;
        ff=true;
        while (ff)
        {
            for (j=1;j<=4;j++)
            {
                jj=way[j]+i;
                if ((jj>=1)&&(jj<=s))
              if ((b[i][jj])&&(c[jj]==0))
                {
                  w[c[i]]++;
                  c[jj]=c[i];
                  u++;
                  h++;
                }
            }
            if (h>maxh) maxh=h;
            kuo[i]=true;
            ff=false;
            for (i=1;i<=s;i++)
              if (c[i]!=0)
                if (!kuo[i])
                {
                    ff=true;
                    break;
                }
          }
      }
    printf("%ld\n",uu);
    printf("%ld\n",maxh);
    maxh=0;
    y=0;
    yy=0;
    h=0;
    fang='E';
    for (j=2;j<=m;j++)
      for (i=n;i>=1;i--)
        {
          x=(i-1)*m+j;
          if ((!b[x-1][x])&&(c[x-1]!=c[x]))
            {
              h=w[c[x-1]]+w[c[x]];
              if (h>maxh)
                {
                  maxh=h;
                  y=i;
                  yy=j-1;
                }
            }
        }
    for (j=1;j<=m;j++)
      for (i=n;i>=2;i--)
        {
          x=(i-1)*m+j;
          if ((!b[x-m][x])&&(c[x-m]!=c[x]))
            {
              h=w[c[x-m]]+w[c[x]];
              if (h>maxh)
                {
                  maxh=h;
                  y=i;
                  yy=j;
                  fang='N';
                }
              if (h==maxh)
                if ((j<yy)||((j==yy)&&(i>=y)))
                  {
                    maxh=h;
                    y=i;
                    yy=j;
                    fang='N';
                  }
            }
        }
    printf("%ld\n",maxh);
    printf("%d %d %c\n",y,yy,fang);
    printf("\n");
  }
  return 0;
}