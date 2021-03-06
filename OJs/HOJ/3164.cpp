/*This Code is Submitted by Timer for Problem 3164 at 2013-12-15 20:56:20*/
/*
题意：在第K天之前都没有人杀狗，而在第K天杀了S只狗，求S.
（题目保证存在病狗）

分析：
当只有1只病狗时，除了病狗主人，其余人都知道当前已经存在一只非自己的病狗，
所以他们不会杀自己的狗，而病狗主人发现当前不存在病狗，就知道自己的狗肯定是病狗，
于是杀自己的狗，这在第1天就会杀这1只狗；
当有2只病狗时，第一天，所有人都能观察到病狗，其中，非病狗主人能看到两只病狗，
病狗主人只能看到1只病狗，这时没有人会杀狗；到第二天，病狗主人发现观察到的那一个病狗主人并没杀狗，
于是判断当前肯定还存在一只病狗，于是那个主人才不会杀自己的狗，而又因为自己只观察到1只病狗，
所以他判断还有一直病狗就是自己的狗，同理，另一个病狗主人也是这么想的，于是，在第二天会有2只狗死；
……
以此类推，第K天之前都没杀狗，在第K天杀了狗，那么第K天肯定杀了K只狗
*/

#include <cstdio>

int main()
{
  int n,k;
  while (scanf("%d%d",&n,&k)==2)
  {
    if (k<=n)
      printf("%d\n",k);
    else
      puts("0");
  }
  return 0;
}