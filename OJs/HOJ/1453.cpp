/*This Code is Submitted by Timer for Problem 1453 at 2012-07-25 09:49:25*/
#include <cstdio>
#include <cstring>

using namespace std;

double P,U,I;
char e[510];
int l,j;
bool fp,fu,fi;

double getans()
{
  double g,i,ans;
  g=1.0;
  ans=0.0;
  while ((e[j]>='0')&&(e[j]<='9'))
  {
    ans=ans*10;
    ans+=e[j]-'0';
    j++;
  }
  if (e[j]=='.')
  {
    g=0.1;
    j++;
    while ((e[j]>='0')&&(e[j]<='9'))
    {
      ans+=(e[j]-'0')*g;
      g=g/10.0;
      j++;
    }
  }
  if (e[j]=='m') ans=ans/1000.0;
  if (e[j]=='k') ans=ans*1000.0;
  if (e[j]=='M') ans=ans*1000000.0;
  return ans;
}

void cyr()
{
  if (fp)
  {
    P=U*I;
    printf("P=%.2lfW\n",P);
  }
  if (fu)
  {
    U=P/I;
    printf("U=%.2lfV\n",U);
  }
  if (fi)
  {
    I=P/U;
    printf("I=%.2lfA\n",I);
  }
  printf("\n");
}

int main()
{
  int test,o,u;
  double x,y;
  scanf("%d",&test);
  getchar();
  o=0;
  while (test--)
  {
    o++;
    printf("Problem #%d\n",o);
    gets(e);
    l=strlen(e);
    j=0;
    while (e[j]!='=') j++;
    u=j-1;
    j++;
    x=getans();
    fp=true;
    fu=true;
    fi=true;
    P=-1;
    U=-1;
    I=-1;
    if (e[u]=='P')
    {
      fp=false;
      P=x;
    }
    else
    if (e[u]=='U')
    {
      fu=false;
      U=x;
    }
    else
    if (e[u]=='I')
    {
      fi=false;
      I=x;
    }
    while (e[j]!='=') j++;
    u=j-1;
    j++;
    x=getans();
    if (e[u]=='P')
    {
      fp=false;
      P=x;
    }
    else
    if (e[u]=='U')
    {
      fu=false;
      U=x;
    }
    else
    if (e[u]=='I')
    {
      fi=false;
      I=x;
    }
    cyr();
  }
  return 0;
}