/*This Code is Submitted by Timer for Problem 3081 at 2011-12-25 15:08:24*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define max 2500001

struct name
{
    char v[8];
    struct name* next;
} NODE;

long N,M;
long a[max];
struct name* s[max];

int main()
{
    long i,x,j;
    char e[8];
    struct name* y;
    struct name* u;
    while (scanf("%ld%ld",&N,&M)==2)
    {
        memset(a,0,sizeof(a));
        memset(s,0,sizeof(s));
        for (i=1;i<=N;i++)
        {
          scanf("%ld",&x);
          scanf("%s",e);
          y=(struct name*)malloc(sizeof(NODE));
          y->next=NULL;
          a[x]++;
          strcpy(y->v,e);
          if (a[x]==1) s[x]=y;
            else
            {
                y->next=s[x];
                s[x]=y;
            }
        }
        for (i=0;i<=M;i++)
          if (a[i]>0)
          {
              u=s[i];
              while  (u->next!=NULL)
              {
                  printf("%ld %s\n",i,u->v);
                  u=u->next;
              }
              printf("%ld %s\n",i,u->v);
          }
    }
    return 0;
}
 
