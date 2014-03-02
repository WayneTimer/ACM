#include <cstdio>

#define EPS 1e-6

const double G=9.81;
const double PV2=100.0;

inline bool equ(double x,double y)
{
  double t;
  t=x-y;
  if (t<EPS && t>-EPS) return true;
  return false;
}

int main()
{
  double k,l,s,w;
  double v2;
  while (scanf("%lf%lf%lf%lf",&k,&l,&s,&w)==4)
  {
    if (equ(k,0)) break;
    if (l>s || equ(l,s))
      v2=2.0*G*s;
    else
      v2=2.0*G*s-k*(s-l)*(s-l)/w;
    if (v2<-EPS) puts("Stuck in the air.");
    else if (v2<PV2 || equ(v2,PV2)) puts("James Bond survives.");
    else puts("Killed by the impact.");
  }
  return 0;
}
