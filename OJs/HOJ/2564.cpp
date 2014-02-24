/*This Code is Submitted by Timer for Problem 2564 at 2012-04-18 13:08:42*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct team
{
  char name[51];
  int num;
  long long time;
  long long pro[10];
};

struct team a[101];

int chenyunran(char x[],char y[])
{
  int i,l1,l2;
  char e1,e2;
  l1=strlen(x);
  l2=strlen(y);
  i=0;
  while ((i<l1)&&(i<l2))
  {
    e1=x[i];
    e2=y[i];
    if (isupper(e1)!=0) e1=tolower(e1);
    if (isupper(e2)!=0) e2=tolower(e2);
    if (e1>e2) return 1;
    if (e1<e2) return -1;
    i++;
  }
  if (l1==l2) return 0;
  if (i==l1) return -1;
  if (i==l2) return 1;
}   

void sort(int n)
{
  int f,i,j,u;
  long long t;
  char e[51];
  for (i=1;i<n;i++)
  {
    f=1;
    for (j=n;j>i;j--)
    {
      if (a[j].num>a[j-1].num)
      {
        f=0;
        u=a[j].num;
        a[j].num=a[j-1].num;
        a[j-1].num=u;
        t=a[j].time;
        a[j].time=a[j-1].time;
        a[j-1].time=t;
        strcpy(e,a[j].name);
        strcpy(a[j].name,a[j-1].name);
        strcpy(a[j-1].name,e);
      }
      if (a[j].num==a[j-1].num)
        {
        if (a[j].time<a[j-1].time)
        {
        f=0;
        u=a[j].num;
        a[j].num=a[j-1].num;
        a[j-1].num=u;
        t=a[j].time;
        a[j].time=a[j-1].time;
        a[j-1].time=t;
        strcpy(e,a[j].name);
        strcpy(a[j].name,a[j-1].name);
        strcpy(a[j-1].name,e);
        }
        if (a[j].time==a[j-1].time)
        if (chenyunran(a[j-1].name,a[j].name)>0)
        {
        f=0;
        u=a[j].num;
        a[j].num=a[j-1].num;
        a[j-1].num=u;
        t=a[j].time;
        a[j].time=a[j-1].time;
        a[j-1].time=t;
        strcpy(e,a[j].name);
        strcpy(a[j].name,a[j-1].name);
        strcpy(a[j-1].name,e);
        }
        }
    }
    if (f) break;
  }
}

int main()
{
  int l,n,m,t,w,p,i,j;
  char e[501],cyr[51];
  long long ti,ran;
  while (scanf("%d%d",&n,&m)==2)
  {
    memset(a,0,sizeof(a));
    getchar();
    for (i=1;i<=n;i++)
      gets(a[i].name);
    for (i=1;i<=m;i++)
    {
      gets(e);
      t=e[0]-'A'+1;
      if (e[11]=='A')
      {
        j=14;
        l=strlen(e);
        p=0;
        while (j<l)
        {
          cyr[p]=e[j];
          j++;
          p++;
        }
        cyr[p]='\0';
        l=strlen(cyr);
        for (p=1;p<=n;p++)
          if (strlen(a[p].name)==l)
            if (strcmp(a[p].name,cyr)==0)
            { 
              w=p;
              break;
            }
        if (a[w].pro[t]==-1) continue;
        ti=0;
        if (e[2]!='0') ti=ti+(e[2]-'0')*10;
        ti=ti+(e[3]-'0');
        ti=(ti-9)*60*60;
        ran=0;
        if (e[5]!='0') ran=ran+(e[5]-'0')*10;
        ran=ran+(e[6]-'0');
        ti=ti+ran*60;
        ran=0;
        if (e[8]!='0') ran=ran+(e[8]-'0')*10;
        ran=ran+(e[9]-'0');
        ti=ti+ran;
        a[w].time=a[w].time+ti+a[w].pro[t]*20*60;
        a[w].pro[t]=-1;
        a[w].num++;
      }
      else
      {
        j=14;
        if ((e[11]=='T')||(e[11]=='M')) j++;
        l=strlen(e);
        p=0;
        while (j<l)
        {
          cyr[p]=e[j];
          j++;
          p++;
        }
        cyr[p]='\0';
        l=strlen(cyr);
        for (p=1;p<=n;p++)
          if (strlen(a[p].name)==l)
            if (strcmp(a[p].name,cyr)==0)
            { 
              w=p;
              break;
            }
        if (a[w].pro[t]==-1) continue;
        a[w].pro[t]++;
      }
    }
    sort(n);
    for (i=1;i<=n;i++)
      printf("%s\n",a[i].name);
    printf("\n");
  }
  return 0;
}