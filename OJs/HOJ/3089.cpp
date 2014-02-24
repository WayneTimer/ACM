/*This Code is Submitted by Timer for Problem 3089 at 2011-12-25 15:10:15*/
#include <stdio.h>
#include <string.h>

int main()
{
    int l,i,k,j;
    char a[1010];
    while (gets(a)!=NULL)
    {
        l=strlen(a);
        i=0;
        while ((i<l)&&(a[i]!='"')) i++;
        if (i==l)
        {
            printf("%s\n",a);
            continue;
        }
        j=l-1;
        while ((j>i)&&(a[j]!='"')) j--;
        for (k=0;k<=i;k++)
          printf("%c",a[k]);
        for (k=i+1;k<=(j-1);k++)
          if (a[k]==' ') printf("*");
            else printf("%c",a[k]);
        for (k=j;k<l;k++)
          printf("%c",a[k]);
        printf("\n");
    }
    return 0;
}
 