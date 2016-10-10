#include <cstdio>
#include <cstring>

using namespace std;

struct cy
{
  int x;
  int y;
};

cy b[601][601];

int f[601][601];
char x[500];

int cyrmin(int q,int w,int u,int &ff)
{
  if (q<=w) return q;
  ff=u;
  return w;
}

void out(int i,int j)
{
  int op;
  if (b[i][j].x!=7)
  {
    if (b[i][j].x==1)
    {
      printf("(");
      if (i==j) printf("%c",x[i]);
      else
      out(i+1,j-1);
      printf(")");
      return;
    }
    if (b[i][j].x==2)
    {
      printf("[");
      if (i==j) printf("%c",x[i]);
      else
      out(i+1,j-1);
      printf("]");
      return;
    }
    if (b[i][j].x==3)
    {
      printf("%c",x[i]);
      if (i<j) out(i+1,j);
      printf(")");
      return;
    }
    if (b[i][j].x==4)
    {
      printf("%c",x[i]);
      if (i<j) out(i+1,j);
      printf("]");
      return;
    }
    if (b[i][j].x==5)
    {
      printf("(");
      if (i<j) out(i,j-1);
      printf("%c",x[j]);
      return;
    }
    if (b[i][j].x==6)
    {
      printf("[");
      if (i<j) out(i,j-1);
      printf("%c",x[j]);
      return;
    }
  }
  else
  {
    out(i,b[i][j].y);
    out(b[i][j].y+1,j);
  }
  return;
}

void cal(int n)
{
  int i,j,p;
  int flag;
  int ans;
  for (i=1;i<=n;i++) f[i][i-1]=0;
  for (i=1;i<=n;i++)
  {
    f[i][i]=1;
    if (x[i]=='(')
      b[i][i].x=3;
    else
    if (x[i]==')')
      b[i][i].x=5;
    if (x[i]=='[')
      b[i][i].x=4;
    else
    if (x[i]==']')
      b[i][i].x=6;
  }
  for (p=1;p<n;p++)
    for (i=1;i<=(n-p);i++)
  {
      j=i+p;
  ans=99999999;
  flag=0;
  if ((x[i]=='(') && (x[j]==')'))
    ans=cyrmin(ans,f[i+1][j-1],1,flag);
  if ((x[i]=='[') && (x[j]==']'))
    ans=cyrmin(ans,f[i+1][j-1],2,flag);
  if (x[i]=='(')
    ans=cyrmin(ans,f[i+1][j]+1,3,flag);
  if (x[i]=='[')
    ans=cyrmin(ans,f[i+1][j]+1,4,flag);
  if (x[j]==')')
    ans=cyrmin(ans,f[i][j-1]+1,5,flag);
  if (x[j]==']')
    ans=cyrmin(ans,f[i][j-1]+1,6,flag);
  int k;
  int wokao,nima;
  wokao=0;
  for (k=i;k<=(j-1);k++)
  {
    nima=1;
    ans=cyrmin(ans,f[i][k]+f[k+1][j],0,nima);
    if (nima==0) 
      wokao=k;
  }
  if (wokao!=0) flag=7;
  f[i][j]=ans;
  b[i][j].x=flag;
  if (flag==7) b[i][j].y=wokao;
  }
}

int main()
{
  int l;
  while (gets(x))
  {
    char tt[300];
    memset(f,0,sizeof(f));
    memset(b,0,sizeof(b));
    l=strlen(x);
    if (l<=0) 
    {
      printf("\n");
      continue;
    }
    tt[0]=' ';
    tt[1]='\0';
    strcat(tt,x);
    strcpy(x,tt);
    cal(l);
    out(1,l);
    printf("\n");
  }
  return 0;
}