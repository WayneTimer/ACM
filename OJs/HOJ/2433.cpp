/*This Code is Submitted by Timer for Problem 2433 at 2013-03-13 17:38:42*/
#include <cstdio>

int v[11];

int main()
{
  int i,x,y;
  v[0]=0;
  for (i=1;i<=10;i++)
    v[i]=30*i/5.5;
  while (scanf("%d:%d",&x,&y)==2)
  {
    if (x==11 || (x==10 && y>v[10]))
    {
      puts("00:00\n00:05");
      continue;
    }
    for (i=0;i<10;i++)
      if (x==i || (x==i+1 && y<=v[i+1]))
      {
        printf("%02d:%02d\n",i+1,5*(i+1));
        printf("%02d:%02d\n",i+1,5*(i+2));
        break;
      }
  }
  return 0;
}