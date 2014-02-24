/*This Code is Submitted by Timer for Problem 1084 at 2012-04-26 01:04:08*/
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
  int i,s,n,j;
  int f1[105],f2[105],b1[105],b2[105];
  scanf("%d",&n);
  while (n!=0)
  {
    s=n/4;
    if ((n%4)!=0) s++;
    memset(f1,0,sizeof(f1));
    memset(f2,0,sizeof(f2));
    memset(b1,0,sizeof(b1));
    memset(b2,0,sizeof(b2));
    i=0;
    j=0;
    while (j<s)
    {
      j++;
      i++;
      if (i>n) break;
      f2[j]=i;
      i++;
      if (i>n) break;
      b1[j]=i;
    }
    j++;
    while (j>0)
    {
      j--;
      i++;
      if (i>n) break;
      b2[j]=i;
      i++;
      if (i>n) break;
      f1[j]=i;
    }
    printf("Printing order for %d pages:\n",n);
    for (i=1;i<=s;i++)
    {
      printf("Sheet %d, front: ",i);
      if (f1[i]==0) printf("Blank, ");
        else printf("%d, ",f1[i]);
      if (f2[i]==0) printf("Blank\n");
        else printf("%d\n",f2[i]);
      if ((b1[i]==0)&&(b2[i]==0)) continue;
      printf("Sheet %d, back : ",i);
      if (b1[i]==0) printf("Blank, ");
        else printf("%d, ",b1[i]);
      if (b2[i]==0) printf("Blank\n");
        else printf("%d\n",b2[i]);
    }
    scanf("%d",&n);
  }
  return 0;
}