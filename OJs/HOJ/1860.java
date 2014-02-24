/*This Code is Submitted by Timer for Problem 1860 at 2013-01-09 02:31:57*/
/*
关键词：线段树、离散化

这题和HOJ 1119 / HDU 1542 / POJ 1151 Atlantis那题基本一样，甚至更简单（因为数据是整数而不是浮点数了），

具体解题思路详见：
HOJ 1119 / HDU 1542 / POJ 1151 Atlantis

*/
//HOJ 1860
import java.util.*;

class cyr
{
  int y1,y2;
  long area;
  cyr()
  {
    y1=-1;
    y2=-1;
    area=0;
  }
}

class rect
{
  int x1,y1,x2,y2;
  rect(int q1,int w1,int q2,int w2)
  {
    x1=q1;
    y1=w1;
    x2=q2;
    y2=w2;
  }
}

public class Main
{
  static int n,cnt,x,y,g,h;
  static long[] width=new long[20010];
  static cyr[] a=new cyr[100100];
  static rect[] b=new rect[10010];
  static int[] thex=new int[20010];

  public static void thexsort(int l,int r)
  {
    int i,j,mid,t;
    i=l;
    j=r;
    mid=thex[(l+r)>>1];
    do
    {
      while (thex[i]<mid) i++;
      while (thex[j]>mid) j--;
      if (i<=j)
      {
        t=thex[i];
        thex[i]=thex[j];
        thex[j]=t;
        i++;
        j--;
      }
    } while (i<=j);
    if (l<j) thexsort(l,j);
    if (i<r) thexsort(i,r);
  }

  public static void build(int l,int r,int now)
  {
    if (l==r)
    {
      a[now]=new cyr();
      return;
    }
    int mid;
    mid=(l+r)>>1;
    build(l,mid,now<<1);
    build(mid+1,r,now<<1|1);
    a[now]=new cyr();
    return;
  }

  public static void insert(int l,int r,int now)
  {
    if (l==r)
    {
      if ((a[now].y1==-1) && (a[now].y2==-1))
      {
        a[now].y1=g;
        a[now].y2=h;
      }
      else
      {
        if (g>a[now].y2)
        {
          long q,w;
          q=a[now].y1;
          w=a[now].y2;
          a[now].area=a[now].area+width[l]*(w-q);
          a[now].y1=g;
          a[now].y2=h;
        }
        else
          if (h>a[now].y2)
            a[now].y2=h;
      }
      return;
    }
    int mid;
    mid=(l+r)>>1;
    if (x<=mid) insert(l,mid,now<<1);
    if (y>mid) insert(mid+1,r,now<<1|1);
    return;
  }

  public static long cal(int l,int r,int now)
  {
    if (l==r)
    {
      if ((a[now].y1==-1) && (a[now].y2==-1))
        return 0;
      return (a[now].area+(a[now].y2-a[now].y1)*width[l]);
    }
    int mid;
    mid=(l+r)>>1;
    long q=cal(l,mid,now<<1);
    long w=cal(mid+1,r,now<<1|1);
    return (q+w);
  }

  public static void mysort(int l,int r)
  {
    int i,j,mid;
    rect t;
    i=l;
    j=r;
    mid=b[(l+r)>>1].y1;
    do
    {
      while (b[i].y1<mid) i++;
      while (b[j].y1>mid) j--;
      if (i<=j)
      {
        t=b[i];
        b[i]=b[j];
        b[j]=t;
        i++;
        j--;
      }
    } while (i<=j);
    if (l<j) mysort(l,j);
    if (i<r) mysort(i,r);
  }

  public static int findx(int u)
  {
    int i;
    for (i=1;i<=cnt+1;i++)
      if (thex[i]==u) return i;
    return -1;
  }

  public static void main(String[] args)
  {
    Scanner cin=new Scanner(System.in);
    int i,x1,y1,x2,y2;
    while (cin.hasNextInt())
    {
      n=cin.nextInt();
      for (i=1;i<=n;i++)
      {
        x1=cin.nextInt();
        y1=cin.nextInt();
        x2=cin.nextInt();
        y2=cin.nextInt();
        b[i]=new rect(x1,y1,x2,y2);
        thex[((i-1)<<1)+1]=x1;
        thex[i<<1]=x2;
      }
      thexsort(1,n<<1);
      cnt=1;
      for (i=2;i<=n<<1;i++)
      {
        if (thex[i]!=thex[i-1])
        {
          width[cnt]=thex[i]-thex[i-1];
          cnt++;
          thex[cnt]=thex[i];
        }
      }
      cnt--;
      mysort(1,n);
      build(1,cnt,1);
      for (i=1;i<=n;i++)
      {
        x=findx(b[i].x1);
        y=findx(b[i].x2)-1;
        g=b[i].y1;
        h=b[i].y2;
        insert(1,cnt,1);
      }
      long sum=0;
      sum=cal(1,cnt,1);
      System.out.println(sum);
    }
  }
}
 