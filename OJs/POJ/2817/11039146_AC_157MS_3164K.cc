/*This Code is Submitted by Timer for Problem 2188 at 2012-07-28 01:43:13*/
#include <cstdio>
#include <cstring>

using namespace std;

int f[13][1<<10][13][2];
int p[13][1<<10][13][2];
int n;
char word[13][35];
int s[13];
int v[13][10000];

inline int cal(int x)
{
  int t;
  t=0;
  while (x>0)
  {  
    t=t+(x&1);
    x=x>>1;
  }
  return t;
}

void init()
{
  int t,i;
  memset(s,0,sizeof(s));
  for (i=1;i<(1<<10);i++)
  {
    t=cal(i);
    s[t]++;
    v[t][s[t]]=i;
  }
}

inline int clhs(int x,int y,int i,int j,int l1,int l2)
{
  int t;
  t=0;
  while ( (i<l1) && (j<l2) ) 
  {
    if (word[x][i]==word[y][j]) t++;
    i++;
    j++;
  }
  return t;
}

int cyr(int x,int y)
{
  int i,j,l1,l2;
  int max,temp;
  max=0;
  l1=strlen(word[x]);
  l2=strlen(word[y]);
  j=0;
  i=l1-1;
  while (i>=0)
  {
    temp=clhs(x,y,i,j,l1,l2);
    if (temp>max) max=temp;
    i--;
  }
  i=0;
  j=1;
  while (j<l2)
  {
    temp=clhs(x,y,i,j,l1,l2);
    if (temp>max) max=temp;
    j++;
  }
  return max;
}

void sub()
{
  int i,j,k,r,jj,temp1,temp2,max1,max2;
  int rr1,rr2,flag1,flag2;
  memset(f,0,sizeof(f));
  memset(p,0,sizeof(p));
  for (k=1;k<=n;k++)
  {
    p[1][1<<(k-1)][k][0]=k;
    p[1][1<<(k-1)][k][1]=k;
  }
  for (i=2;i<=n;i++)
    for (jj=1;jj<=s[i];jj++)
    {
      j=v[i][jj];
      for (k=1;k<=n;k++)
        if ( j & (1<<(k-1)) )
        {
          max1=0;
          max2=0;
          rr1=0;
          rr2=0;
          for (r=1;r<=n;r++)
            if ( (r!=k) && ( j & (1<<(r-1)) ) )
            {
              temp1=f[i-1][j-(1<<(k-1))][r][0]+cyr(r,k);
              temp2=f[i-1][j-(1<<(k-1))][r][1]+cyr(p[i-1][j-(1<<(k-1))][r][1],k);
              if (temp1>temp2)
              {
                if (temp1>max1)
                {
                  max1=temp1;
                  rr1=r;
                  flag1=1;
                }
              }
              else
              {
                if (temp2>max1)
                {
                  max1=temp2;
                  rr1=r;
                  flag1=2;
                }
              }
              //---------------------------------------------------
              temp1=f[i-1][j-(1<<(k-1))][r][0]+cyr(p[i-1][j-(1<<(k-1))][r][0],k);
              temp2=f[i-1][j-(1<<(k-1))][r][1]+cyr(r,k);
              if (temp1>temp2)
              {
                if (temp1>max2)
                {
                  max2=temp1;
                  rr2=r;
                  flag2=1;
                }
              }
              else
              {
                if (temp2>max2)
                {
                  max2=temp2;
                  rr2=r;
                  flag2=2;
                }
              }
            }
          //============================
          f[i][j][k][0]=max1;
          if (flag1==1)
            p[i][j][k][0]=p[i-1][j-(1<<(k-1))][rr1][0];
          else 
            p[i][j][k][0]=rr1;
          //---------------------
          f[i][j][k][1]=max2;
          if (flag2==1)
            p[i][j][k][1]=rr2;
          else
            p[i][j][k][1]=p[i-1][j-(1<<(k-1))][rr2][1];
        }
    }
}

int main()
{
  int k,max,i;
  init();
  scanf("%d",&n);
  while (n>0)
  {
    memset(word,0,sizeof(word));
    for (i=1;i<=n;i++)
      scanf("%s",word[i]);
    sub();
    max=0;
    for (k=1;k<=n;k++)
    {
      if (f[n][(1<<n)-1][k][0] > max)
        max=f[n][(1<<n)-1][k][0];
      if (f[n][(1<<n)-1][k][1] > max)
        max=f[n][(1<<n)-1][k][1];
    }
    printf("%d\n",max);
    scanf("%d",&n);
  }
  return 0;
}