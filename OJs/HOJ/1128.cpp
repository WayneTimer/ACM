/*This Code is Submitted by Timer for Problem 1128 at 2012-04-26 00:32:30*/
#include <cstdio>
#include <cstring>

using namespace std;

int v[101];

int main()
{
  int i,s,a,b,c,d;
  memset(v,0,sizeof(v));
  v[1]=1;
  for (i=2;i<=100;i++)
  {
    v[i]=i*i*i;
  }
  for (a=6;a<=100;a++)
  {
    for (b=2;b<a;b++)
    {
      for (c=b+1;c<a;c++)
      {
        if (b==c) continue;
        for (d=c+1;d<a;d++)
        {
          if ((b==d)||(c==d)) continue;
          s=v[b]+v[c]+v[d];
          if (s>v[a]) break;
          if (s==v[a]) 
          {
            printf("Cube = %d, Triple = (%d,%d,%d)\n",a,b,c,d);
            break;
          }
        }
      }
    }
  }
  return 0;
}