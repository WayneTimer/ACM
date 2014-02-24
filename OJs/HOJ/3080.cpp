/*This Code is Submitted by Timer for Problem 3080 at 2011-12-25 15:07:26*/
#include <stdio.h>
#include <string.h>

int main()
{
    int f,T,Q,N,j,i,k,l1,l2;
    char a[1000][1000];
    char e[1000];
    while (scanf("%d",&T)==1)
    {
        for (i=1;i<=T;i++)
        {
            memset(a,0,sizeof(a));
            memset(e,0,sizeof(e));
            scanf("%d",&N);
            getchar();
            for (j=1;j<=N;j++)
              gets(a[j]);
            scanf("%d",&Q);
            getchar();
            for (j=1;j<=Q;j++)
            {
              gets(e);
              f=0;
              for (k=1;k<=N;k++)
              {
                  l1=strlen(a[k]);
                  l2=strlen(e);
                  if (l2>l1) continue;
                  if (strstr(a[k],e)!=NULL)
                  {
                      if (l2==l1)
                      {
                        f=1;
                        break;
                      }
                  }
              }
              if (f) printf("YES\n");
                else printf("NO\n");
            }
            printf("\n");
        }
    }
    return 0;
}
 