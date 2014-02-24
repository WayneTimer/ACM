/*This Code is Submitted by Timer for Problem 2576 at 2012-08-31 19:44:24*/
//HOJ 2576
//数论-容斥原理
import java.util.*;

public class Main
{
  public static void mysort(int l,int r,int[] a)
  {
    int i,j,mid,t;
    i=l;
    j=r;
    mid=a[(l+r)>>1];
    do
    {
      while (a[i]<mid) i++;
      while (a[j]>mid) j--;
      if (i<=j)
      {
        t=a[i];
        a[i]=a[j];
        a[j]=t;
        i++;
        j--;
      }
    } while (i<=j);
    if (l<j) mysort(l,j,a);
    if (i<r) mysort(i,r,a);
  }

  public static long gcd(long a,long b)
  {
    long temp;
    while (b!=0)
    {
      temp=b;
      b=a%b;
      a=temp;
    }
    return a;
  }

  public static void main(String[] args)
  {
    Scanner cin=new Scanner(System.in);
    int T=cin.nextInt();
    int[] a=new int[110];
    int n;
    long m;
    while (T>0)
    {
      T--;
      n=cin.nextInt();
      m=cin.nextLong();
      for (int i=1;i<=n;i++)
        a[i]=cin.nextInt();
      mysort(1,n,a);
      int u=1;
      for (int i=2;i<=n;i++)
      {
        if (a[i]!=a[u])
        {
          u++;
          a[u]=a[i];
        }
      }
      n=u;
      u=1<<n;
      int s=0;
      long sum=0;
      long t1=0,d,t2=0;
      for (int i=1;i<u;i++)
      {
        s^=s;
        d=1;
        for (int j=0;j<n;j++)
        {
          int t=1<<j;
          if ((i&t)>0)
          {
            s++;
            t1=gcd(a[j+1],d);
            d=d*a[j+1]/t1;
          }
        }
        if ((s&1)>0)
          sum=sum+m/d;
        else
          sum=sum-m/d;
      }
      System.out.println(sum);
    }
  }
}
 