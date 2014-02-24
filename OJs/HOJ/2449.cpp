/*This Code is Submitted by Timer for Problem 2449 at 2012-07-21 16:58:22*/
#include <cstdio>
#include <cstring>

using namespace std;

char e[110];
int l;

void ctoj()
{
  int i;
  bool cyr;
  cyr=false;
  for (i=0;i<l;i++)
  {
    if (cyr) 
    {
      printf("%c",e[i]-'a'+'A');
      cyr=false;
      continue;
    }
    if (e[i]=='_')
    {
      cyr=true;
      continue;
    }
    printf("%c",e[i]);
  }
  printf("\n");
}

void jtoc()
{
  int i;
  for (i=0;i<l;i++)
  {
    if ((e[i]>='A')&&(e[i]<='Z'))
      printf("_%c",e[i]-'A'+'a');
    else printf("%c",e[i]);
  }
  printf("\n");
}
  
int main()
{
  int i;
  bool fc,fj;
  while (gets(e))
  {
  fc=false;
  fj=false;
  l=strlen(e);
  if (!((e[0]>='a')&&(e[0]<='z')))
  {
    printf("Error!\n");
    continue;
  }
  if (e[l-1]=='_') 
  {
    printf("Error!\n");
    continue;
  }
  for (i=0;i<l;i++)
  {
    if ((e[i]>='A')&&(e[i]<='Z'))
    {
      fj=true;
      continue;
    }
    if (e[i]=='_') 
    {
      if (e[i+1]=='_') 
      {
        fc=true;
        fj=true;
        break;
      }
      fc=true;
      continue;
    }
    if (!((e[i]>='a')&&(e[i]<='z')))
    {
      fc=true;
      fj=true;
      break;
    }
  }
  if ((fc)&&(fj)) printf("Error!\n");
    else if (fc) ctoj();
      else if (fj) jtoc();
        else printf("%s\n",e);
  }
  return 0;
}