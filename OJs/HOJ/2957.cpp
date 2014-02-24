/*This Code is Submitted by Timer for Problem 2957 at 2012-07-30 21:13:45*/
#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

struct cyr
{
  int v;
  char s[200];
  int g;
};

map <int,int> b;
map <int,int> step;
cyr f1[100000];
cyr f2[100000];


int sub1(int x)
{
  int ans,t;
  int i;
  ans=0;
  for (i=0;i<8;i++)
  {
    t=x%10;
    ans=ans*10+t;
    x=x/10;
  }
  return ans;
}

int sub2(int x)
{
  int t1,t2,ans,h;
  t1=x/10000;
  t2=x%10000;
  h=t1%10;
  t1=t1/10;
  ans=h*1000+t1;
  ans=ans*10000;
  h=t2/1000;
  t2=t2%1000;
  ans=ans+t2*10+h;
  return ans;
}

int sub3(int x)
{
  int t[10];
  int i,ans;
  ans=x;
  for (i=7;i>=0;i--)
  {
    t[i]=ans%10;
    ans=ans/10;
  }
  ans=t[1];
  t[1]=t[6];
  t[6]=t[5];
  t[5]=t[2];
  t[2]=ans;
  ans=0;
  for (i=0;i<=7;i++)
    ans=ans*10+t[i];
  return ans;
}

int sub4(int x)
{
  int ans;
  int t1,t2,h;
  t1=x/10000;
  t2=x%10000;
  h=t1/1000;
  t1=t1%1000;
  t1=t1*10+h;
  ans=t1*10000;
  h=t2%10;
  t2=t2/10;
  t2=h*1000+t2;
  ans=ans+t2;
  return ans;
}

int sub5(int x)
{
  int t[10];
  int i,ans;
  ans=x;
  for (i=7;i>=0;i--)
  {
    t[i]=ans%10;
    ans=ans/10;
  }
  ans=t[1];
  t[1]=t[2];
  t[2]=t[5];
  t[5]=t[6];
  t[6]=ans;
  ans=0;
  for (i=0;i<=7;i++)
    ans=ans*10+t[i];
  return ans;
}

void BFS()
{
  int t,j;
  char temp[13];
  int head,tail1,tail2;
  int i;  
  t=12345678;
  b[t]=1;
  head=-1;
  tail1=0;
  tail2=0;
  do
  {
    head++;
    for (i=1;i<=3;i++)
    {
      if (i==1)
        t=sub1(f1[head].g);
      if (i==2)
        t=sub2(f1[head].g);
      if (i==3) 
        t=sub3(f1[head].g);
      if (b[t]==0)
      {
        tail1++;
        f1[tail1].v=f1[head].v+1;
        strcpy(f1[tail1].s,f1[head].s);
        temp[0]='A'+i-1;
        temp[1]='\0';
        strcat(f1[tail1].s,temp);
        f1[tail1].g=t;
        b[t]=1;
        step[t]=tail1;
      }
      if (b[t]==2)
      {
        printf("%d\n",f1[head].v+1);
        for (j=0;j<f1[head].v;j++)
          printf("%c",f1[head].s[j]);
        printf("%c",i+'A'-1);
        printf("\n");
        return;
      }
    }
  } while (head<tail1);
}

int main()
{
  int i,x,t;
  char e[15];
  f1[0].v=0;
  f1[0].g=12345678;
  f1[0].s[0]='\0';
  b[f1[0].g]=1;
  while (scanf("%d",&x)==1)
  {
    b.clear();
    t=x;
    for (i=1;i<=7;i++)
    {
      scanf("%d",&x);
      t=t*10+x;
    }
    e[8]='\0';
    f2[0].v=0;
    f2[0].g=t;
    f2[0].s[0]='\0';
    b[f2[0].g]=2;
    if (t==12345678) 
    {
      printf("0\n");
      printf("\n");
      continue;
    }
    BFS();
  }
  return 0;
}