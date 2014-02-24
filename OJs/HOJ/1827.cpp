/*This Code is Submitted by Timer for Problem 1827 at 2012-02-09 15:01:59*/
#include <cstdio>
#include <string.h>

const int c[10][10]=
    {{0,0,0,0,0,0,0,0,0,0},
    {0,3,3,3,3,3,2,3,2,0},
    {0,2,3,2,3,2,3,1,0,1},
    {0,3,3,3,2,3,3,0,2,3},
    {0,2,3,1,3,2,0,2,3,1},
    {0,2,3,2,3,1,3,2,3,2},
    {0,1,3,2,0,2,3,1,3,2},
    {0,3,2,0,3,3,2,3,3,3},
    {0,1,0,1,3,2,3,2,3,2},
    {0,0,2,3,2,3,3,3,3,3}};
int t[10];

void init()
{
  int i;
  scanf("%d%d%d",&t[4],&t[5],&t[6]);
  scanf("%d%d%d",&t[7],&t[8],&t[9]);
  for (i=1;i<=9;i++)
  {
    if (t[i]==0) t[i]=4;
    if (t[i]==1) t[i]=1;
    if (t[i]==2) t[i]=2;
    if (t[i]==3) t[i]=3; 
  }
}

void cyr()
{
  int i,k,j;
  int a[10];
  bool flag;
  memset(a,0,sizeof(a));
  for (i=1;i<=9;i++)
    for (k=1;k<=9;k++)
      a[k]=a[k]+c[i][k]*(4-t[i]);
  for (i=1;i<=9;i++)
    a[i]=a[i]%4;
  flag=true;
  for (i=1;i<=9;i++)
    for (j=1;j<=a[i];j++)
    {
      if (flag) 
      {
        printf("%d",i);
        flag=false;
      }
      else
        printf(" %d",i);
  }
  printf("\n");
}

int main()
{
  while (scanf("%d%d%d",&t[1],&t[2],&t[3])==3)
  {
    init();
    cyr();
  }
  return 0;
}