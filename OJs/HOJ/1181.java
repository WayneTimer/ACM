/*This Code is Submitted by Timer for Problem 1181 at 2012-01-28 02:47:52*/
//HOJ 1181
public class Main
{
  public static void main(String[] args)
  {
    long t=1;
    long min=1;
    long[] a=new long[1501];
    int v1=2;
    int v2=1;
    int v3=1;
    int i=1;
    a[1]=2;
    a[2]=3;
    a[3]=4;
    a[4]=5;
    for (i=5;i<1500;i++)
    {
      min=2*a[v1];
      t=3*a[v2];
      if (t<min)
        min=t;
      t=5*a[v3];
      if (t<min)
        min=t;
      if (min==t) v3++;
      t=2*a[v1];
      if (min==t) v1++;
      t=3*a[v2];
      if (min==t) v2++;
      a[i]=min;
    }
    System.out.println("The 1500'th ugly number is "+a[1499]+".");
  }
}