/*This Code is Submitted by Timer for Problem 2098 at 2012-09-10 20:57:54*/
//HOJ 2098
//模拟归并排序
import java.util.*;

public class Main
{
  static int n;
  static long ans;
  static long[] a=new long[500010];
  static long[] b=new long[500010];

  public static void cyr(int l,int mid,int r)
  {
    int i,j,k;
    i=l;
    j=mid+1;
    k=l-1;
    while (i<=mid && j<=r)
    {
      k++;
      if (a[i]<=a[j])
      {
        b[k]=a[i];
        i++;
      }
      else
      {
        b[k]=a[j];
        j++;
        ans=ans+mid-i+1;
      }
    }
    while (i<=mid)
    {
      k++;
      b[k]=a[i];
      i++;
    }
    while (j<=r)
    {
      k++;
      b[k]=a[j];
      j++;
    }
    for (i=l;i<=r;i++)
      a[i]=b[i];
    return;
  }

  public static void mergesort(int l,int r)
  {
    if (l>=r) return;
    int mid;
    mid=(l+r)>>1;
    mergesort(l,mid);
    mergesort(mid+1,r);
    cyr(l,mid,r);
  }

  public static void main(String[] args)
  {
    Scanner cin=new Scanner(System.in);
    int i;
    n=cin.nextInt();
    while (n>0)
    {
      for (i=1;i<=n;i++)
        a[i]=cin.nextLong();
      ans=0;
      mergesort(1,n);
      System.out.println(ans);
      n=cin.nextInt();
    }
  }
}
 