/*This Code is Submitted by Timer for Problem 1138 at 2012-07-25 10:50:36*/
#include <cstdio>
#include <cstring>

using namespace std;

int s,p;
char a[50][150];
char word[30];

void cyr(char w)
{
  int end,i,j,mid,last;
  end=p+s+1;
  mid=(2*s+3)>>1;
  last=2*s+2;
  for (i=0;i<=last;i++)
    for (j=p;j<=(end+1);j++)
      a[i][j]=' ';
  if (w=='1')
  {
    for (i=1;i<mid;i++)
      a[i][end]='|';
    for (i=mid+1;i<last;i++)
      a[i][end]='|';
  }
  if (w=='2')
  {
    for (j=p+1;j<end;j++)
    {
      a[0][j]='-';
      a[mid][j]='-';
      a[last][j]='-';
    }
    for (i=1;i<mid;i++)
      a[i][end]='|';
    for (i=mid+1;i<last;i++)
      a[i][p]='|';
  }
  if (w=='3')
  {
    for (j=p+1;j<end;j++)
    {
      a[0][j]='-';
      a[mid][j]='-';
      a[last][j]='-';
    }
    for (i=1;i<mid;i++)
      a[i][end]='|';
    for (i=mid+1;i<last;i++)
      a[i][end]='|';
  }
  if (w=='4')
  {
    for (i=1;i<mid;i++)
      a[i][end]='|';
    for (i=mid+1;i<last;i++)
      a[i][end]='|';
    for (j=p+1;j<end;j++)
      a[mid][j]='-';
    for (i=1;i<mid;i++)
      a[i][p]='|';
  }
  if (w=='5')
  {
    for (j=p+1;j<end;j++)
    {
      a[0][j]='-';
      a[mid][j]='-';
      a[last][j]='-';
    }
    for (i=1;i<mid;i++)
      a[i][p]='|';
    for (i=mid+1;i<last;i++)
      a[i][end]='|';
  }
  if (w=='6')
  {
    for (j=p+1;j<end;j++)
    {
      a[0][j]='-';
      a[mid][j]='-';
      a[last][j]='-';
    }
    for (i=1;i<mid;i++)
      a[i][p]='|';
    for (i=mid+1;i<last;i++)
      a[i][end]='|';
    for (i=mid+1;i<last;i++)
      a[i][p]='|';
  }
  if (w=='7')
  {
    for (i=1;i<mid;i++)
      a[i][end]='|';
    for (i=mid+1;i<last;i++)
      a[i][end]='|';
    for (j=p+1;j<end;j++)
      a[0][j]='-';
  }
  if (w=='8')
  {
    for (j=p+1;j<end;j++)
    {
      a[0][j]='-';
      a[mid][j]='-';
      a[last][j]='-';
    }
    for (i=1;i<mid;i++)
      a[i][end]='|';
    for (i=mid+1;i<last;i++)
      a[i][end]='|';
    for (i=1;i<mid;i++)
      a[i][p]='|';
    for (i=mid+1;i<last;i++)
      a[i][p]='|';
  }
  if (w=='9')
  {
    for (j=p+1;j<end;j++)
    {
      a[0][j]='-';
      a[mid][j]='-';
      a[last][j]='-';
    }
    for (i=1;i<mid;i++)
      a[i][end]='|';
    for (i=mid+1;i<last;i++)
      a[i][end]='|';
    for (i=1;i<mid;i++)
      a[i][p]='|';
  }
  if (w=='0')
  {
    for (j=p+1;j<end;j++)
    {
      a[0][j]='-';
      a[last][j]='-';
    }
    for (i=1;i<mid;i++)
    {
      a[i][p]='|';
      a[i][end]='|';
    }
    for (i=mid+1;i<last;i++)
    {
      a[i][p]='|';
      a[i][end]='|';
    }
  }
  p=end+2;
}
 
int main()
{
  int i,l;
  scanf("%d %s",&s,word);
  while (s)
  {
    memset(a,0,sizeof(a));
    l=strlen(word);
    p=0;
    for (i=0;i<l;i++)
      cyr(word[i]);
    p--;
    for (i=0;i<=(2*s+2);i++)
    {
      a[i][p]='\0';
      printf("%s\n",a[i]);
    }
    printf("\n");
    scanf("%d %s",&s,word);
  }
  return 0;
}