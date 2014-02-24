/*This Code is Submitted by Timer for Problem 1337 at 2012-07-24 09:42:28*/
#include <cstdio>
#include <cstring>

using namespace std;

struct cyr
{
  char v[210];
  cyr *head;
  cyr *next;
};

cyr *p,*t;

int main()
{
  char a[210];
  char b[210];
  scanf("%s",a);
  p=new cyr;
  strcpy(p->v,"http://www.acm.org/");
  p->head=NULL;
  p->next=NULL;
  while (a[0]!='Q')
  {
    if (a[0]=='V')
    {
      scanf("%s",b);
      t=new cyr;
      strcpy(t->v,b);
      t->head=p;
      t->next=NULL;
      p->next=t;
      p=t;
      printf("%s\n",p->v);
    }
    if (a[0]=='B')
    {
      if (p->head!=NULL)
      {
        p=p->head;
        printf("%s\n",p->v);
      }
      else printf("Ignored\n");
    }
    if (a[0]=='F')
    {
      if (p->next!=NULL)
      {
        p=p->next;
        printf("%s\n",p->v);
      }
      else printf("Ignored\n");
    }
    scanf("%s",a);
  }
  return 0;
}