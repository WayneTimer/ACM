/*This Code is Submitted by Timer for Problem 1448 at 2012-02-03 23:35:33*/
#include <stdio.h>
#include <string.h>

struct CYR 
{
  int x;
  int y;
  int z;
};

int l,r,c,i,j,k;
char e;
int map[32][32][32];
struct CYR a[1000001];
int b[32][32][32];
struct CYR way[7];
int father[1000001];
char t[50];

int check(int x,int y,int z)
{
  if (x>l) return 0;
  if (x<1) return 0;
  if (y>r) return 0;
  if (y<1) return 0;
  if (z>c) return 0;
  if (z<1) return 0;
  if (b[x][y][z]==1) return 0;
  if (map[x][y][z]==0) return 0;
  return 1;
}

int main()
{
  int head,tail,p,x,y,z;
  int sum;
  int flag;
  memset(way,0,sizeof(way));
  way[1].z=-1;
  way[2].y=-1;
  way[3].z=1;
  way[4].y=1;
  way[5].x=1;
  way[6].x=-1;
  scanf("%d%d%d",&l,&r,&c);
  while (!((l==0)||(r==0)||(c==0)))
  {
    e=getchar();
    memset(map,0,sizeof(map));
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(father,0,sizeof(father));
    for (i=1;i<=l;i++)
    {
      for (j=1;j<=r;j++)
      {
        for (k=1;k<=c;k++)
        {
          e=getchar();
          if (e=='.') map[i][j][k]=1;
          else
          if (e=='S') 
          {
            map[i][j][k]=2;
            a[1].x=i;
            a[1].y=j;
            a[1].z=k;
            b[i][j][k]=1;
          }
          else 
          if (e=='E') map[i][j][k]=3;
        }
        e=getchar();
      }
      gets(t);
    }
    head=0;
    tail=1;
    flag=1;
    sum=0;
    father[1]=0;
    do
    {
      head++;
      for (p=1;p<=6;p++)
      {
        x=a[head].x+way[p].x;
        y=a[head].y+way[p].y;
        z=a[head].z+way[p].z;
        if (check(x,y,z)) 
        {
          tail++;
          father[tail]=father[head]+1;
          if (map[x][y][z]==3) 
          {
            flag=0;
            printf("Escaped in %d minute(s).\n",father[tail]);
            break;
          }
          a[tail].x=x;
          a[tail].y=y;
          a[tail].z=z;
          b[x][y][z]=1;
        }
      }
    } while ((tail>head)&&(flag));
    if (flag) printf("Trapped!\n");
    scanf("%d%d%d",&l,&r,&c);
  }
  return 0;
}