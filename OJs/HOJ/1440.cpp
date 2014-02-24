/*This Code is Submitted by Timer for Problem 1440 at 2011-11-22 19:01:57*/
#include <stdio.h>
#include <string.h>

int main()
{
  char e[10];
  int a[9][9];
  int way[8][2]={{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
  int f,i,x,y,xx,yy,head,tail;
  int b[100][2];
  int s[100];
  while (gets(e)!=NULL)
  {
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(s,0,sizeof(s));
    x=e[0]-'a'+1;
    y=e[1]-'0';
    a[x][y]=1;
    xx=e[3]-'a'+1;
    yy=e[4]-'0';
    if (a[xx][yy]) 
    {
      printf("To get from %c%c",e[0],e[1]);
      printf(" to %c%c takes",e[3],e[4]);
      printf(" 0 knight moves.\n");
      continue;
    }
    a[xx][yy]=2;
    head=-1;
    tail=0;
    b[0][0]=x;
    b[0][1]=y;
    do
    {
      head++;
      x=b[head][0];
      y=b[head][1];
      f=0;
      for (i=0;i<=7;i++)
      {
        xx=x+way[i][0];
        yy=y+way[i][1];
        if (xx<=0) continue;
        if (yy<=0) continue;
        if (xx>8) continue;
        if (yy>8) continue;
        if (a[xx][yy]==2) 
        {
          printf("To get from %c%c",e[0],e[1]);
          printf(" to %c%c takes",e[3],e[4]);
          printf(" %d knight moves.\n",s[head]+1);
          f=1;
        }
        if (f) break;
        if (a[xx][yy]) continue;
        tail++;
        a[xx][yy]=1;
        b[tail][0]=xx;
        b[tail][1]=yy;
        s[tail]=s[head]+1;
      }
      if (f) break;
    } while (head<tail);
  }
  return 0;
}