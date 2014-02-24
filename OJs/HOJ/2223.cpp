/*This Code is Submitted by Timer for Problem 2223 at 2013-02-26 17:39:36*/
#include <cstdio>

int n;
char a[50];
char b[50];

int cal(char t[])
{
  int i,ret,p;
  ret^=ret;
  i^=i;
  p=1;
  while (t[i])
  {
    if (t[i]>='2' && t[i]<='9')
      p=t[i]-'0';
    else
    {
      if (t[i]=='m') ret+=p*1000;
      else if (t[i]=='c') ret+=p*100;
      else if (t[i]=='x') ret+=p*10;
      else if (t[i]=='i') ret+=p;
      p=1;
    }
    i++;
  }
  return ret;
}

void output(int x,char c)
{
  if (x==0) return;
  if (c=='i') output(x/10,'x');
  else if (c=='x') output(x/10,'c');
  else if (c=='c') output(x/10,'m');
  int t;
  t=x%10;
  if (t)
  {
    if (t>1) printf("%d",t);
    putchar(c);
  }
}

int main()
{
  int x,y;
  scanf("%d",&n);
  while (n--)
  {
    scanf("%s %s",a,b);
    x=cal(a);
    y=cal(b);
    x+=y;
    output(x,'i');
    puts("");
  }
  return 0;
}