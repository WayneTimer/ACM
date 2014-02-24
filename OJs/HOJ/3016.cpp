/*This Code is Submitted by Timer for Problem 3016 at 2013-07-31 22:07:47*/
/*
将中缀表达式转换成后缀表达式

对中缀表达式从左至右依次扫描，
由于操作数的顺序保持不变，
当遇到操作数时直接输出；
为调整运算顺序，设立一个栈用以保存操作符，
扫描到操作符时，将操作符压入栈中，
进栈的原则是保持栈顶操作符的优先级要高于栈中上一个操作符的优先级
（或是上一个操作符是"(" ），
否则，将栈顶操作符依次退栈并输出，直到满足要求为止。

特殊：遇到“(”进栈，当遇到“)”时，退栈输出直到“(”为止
*/
#include <cstdio>

char a[300];
int b[300];
int w[100];
char e[6];

inline void work()
{
  int i,j;
  i^=i;
  j^=j;
  while (a[i])
  {
    if (a[i]>='a' && a[i]<='z')
      printf("%c",a[i]);
    else if (a[i]=='(')
      b[++j]=-1;
    else if (a[i]==')')
    {
      while (b[j]!=-1)
      {
        printf("%c",e[b[j]]);
        j--;
      }
      j--;
    }
    else
    {
      while (b[j]>=w[a[i]])
      {
        printf("%c",e[b[j]]);
        j--;
      }
      b[++j]=w[a[i]];
    }
    i++;
  }
  while (j>0)
  {
    printf("%c",e[b[j]]);
    j--;
  }
  puts("");
}

int main()
{
  int n;
  w['+']=1;
  w['-']=2;
  w['*']=3;
  w['/']=4;
  w['^']=5;
  e[1]='+';
  e[2]='-';
  e[3]='*';
  e[4]='/';
  e[5]='^';
  b[0]=0;
  while (scanf("%d",&n)==1)
  {
    while (n--)
    {
      scanf("%s",a);
      work();
    }
  }
  return 0;
}