#include <cstdio>

int m;

int main()
{
  int x,y,lx,ly,sx,sy;
  while (scanf("%d",&m)==1 && m)
  {
    lx=0;
    ly=0;
    sx=0;
    sy=0;
    while (scanf("%d%d",&x,&y)==2)
    {
      if (x==-1 && y==-1) break;
      if (lx+x<=m)
      {
	lx+=x;
	if (y>ly) ly=y;
      }
      else
      {
	if (lx>sx) sx=lx;
	sy+=ly;
	lx=x;
	ly=y;
      }
    }
    if (lx>sx) sx=lx;
    printf("%d x %d\n",sx,sy+ly);
  }
  return 0;
}
