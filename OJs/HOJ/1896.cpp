//有可能出现-0.00
#include <cstdio>

char a[100];

int calc(int h,int m,int s)
{
  int ret;
  ret=h*60+m;
  ret=ret*60+s;
  return ret;
}

int main()
{
  int h,m,s,x,s1,s2;
  bool first;
  double sum,y,t;
  first=true;
  sum=0;
  while (gets(a))
  {
    if (sscanf(a,"%d:%d:%d %d",&h,&m,&s,&x)==4)
    {
      s2=calc(h,m,s);
      t=x*10.0/36;
      if (first)
      {
	s1=s2;
	y=t;
	first=false;
	continue;
      }
      sum+=(s2-s1)*y;
      y=t;
      s1=s2;
    }
    else
    {
      s2=calc(h,m,s);
      sum+=(s2-s1)*y;
      t=sum/1000.0;
      if (t<0) t=0;
      printf("%02d:%02d:%02d %.2lf km\n",h,m,s,t);
      s1=s2;
    }
  }
  return 0;
}
