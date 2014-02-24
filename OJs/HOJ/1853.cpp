/*This Code is Submitted by Timer for Problem 1853 at 2011-11-25 01:03:19*/
#include <stdio.h>
#include <string.h>

int main()
{
  char x;
  char e[501];
  int l,i;
  while (gets(e)!=NULL)
  {
    for (i=0;i<strlen(e);i++)
    {
      x=e[i];
      if (x==' ') {printf(" ");continue;}
      if (x=='1') {printf("`");continue;}
      if ((x>'1')&&(x<='9'))
      {printf("%c",x-1);continue;}
      if (x=='0') {printf("9");continue;}
      if (x=='-') {printf("0");continue;}
      if (x=='=') {printf("-");continue;}
      if (x=='\\') {printf("]");continue;}
      if (x==']') {printf("[");continue;}
      if (x=='[') {printf("P");continue;}
      if (x=='P') {printf("O");continue;}
      if (x=='O') {printf("I");continue;}
      if (x=='I') {printf("U");continue;}
      if (x=='U') {printf("Y");continue;}
      if (x=='Y') {printf("T");continue;}
      if (x=='T') {printf("R");continue;}
      if (x=='R') {printf("E");continue;}
      if (x=='E') {printf("W");continue;}
      if (x=='W') {printf("Q");continue;}
      if (x=='\'') {printf(";");continue;}
      if (x==';') {printf("L");continue;}
      if (x=='L') {printf("K");continue;}
      if (x=='K') {printf("J");continue;}
      if (x=='J') {printf("H");continue;}
      if (x=='H') {printf("G");continue;}
      if (x=='G') {printf("F");continue;}
      if (x=='F') {printf("D");continue;}
      if (x=='D') {printf("S");continue;}
      if (x=='S') {printf("A");continue;}
      if (x=='/') {printf(".");continue;}
      if (x=='.') {printf(",");continue;}
      if (x==',') {printf("M");continue;}
      if (x=='M') {printf("N");continue;}
      if (x=='N') {printf("B");continue;}
      if (x=='B') {printf("V");continue;}
      if (x=='V') {printf("C");continue;}
      if (x=='C') {printf("X");continue;}
      if (x=='X') {printf("Z");continue;}
    }
    printf("\n");
  }
  return 0;
}