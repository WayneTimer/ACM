#include <cstdio>
#include <cstring>

int a[40][40];
char str[2000];

int main()
{
  int T,i,j,x,y,d,lx,ly;
  scanf("%d",&T);
  for (i=1;i<=T;i++)
  {
    scanf("%d%d",&x,&y);
    scanf("%s",str);
    printf("Bitmap #%d\n",i);
    j=0;
    memset(a,0,sizeof(a));
    while (str[j]!='.')
    {
      if (str[j]=='E')
      {
	lx=x+1;
	ly=y;
	if (y>0)
	  a[x][y-1]=1;
      }
      else if (str[j]=='N')
      {
	lx=x;
	ly=y+1;
	if (x<32)
	  a[x][y]=1;
      }
      else if (str[j]=='W')
      {
	lx=x-1;
	ly=y;
	if (ly<32)
	  a[lx][ly]=1;
      }
      else
      {
	lx=x;
	ly=y-1;
	if (lx>0)
	  a[x-1][ly]=1;
      }
      x=lx;
      y=ly;
      j++;
    }
    for (y=31;y>=0;y--)
    {
      for (x=0;x<32;x++)
	if (a[x][y])
	  putchar('X');
	else
	  putchar('.');
      puts("");
    }
    puts("");
  }
}
