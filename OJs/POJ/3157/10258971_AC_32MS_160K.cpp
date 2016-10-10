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
  gets(e);
  fc=false;
  fj=false;
  l=strlen(e);
  if (!((e[0]>='a')&&(e[0]<='z')))
  {
    printf("Error!\n");
    return 0;
  }
  if (e[l-1]=='_') 
  {
    printf("Error!\n");
    return 0;
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
        printf("Error!\n");
        return 0;
      }
      fc=true;
      continue;
    }
    if (!((e[i]>='a')&&(e[i]<='z')))
    {
      printf("Error!\n");
      return 0;
    }
  }
  if ((fc)&&(fj)) printf("Error!\n");
    else if (fc) ctoj();
      else if (fj) jtoc();
        else printf("%s\n",e);
  return 0;
}