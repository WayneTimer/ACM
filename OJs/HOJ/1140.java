/*This Code is Submitted by Timer for Problem 1140 at 2012-09-02 12:50:38*/
//HOJ 1140
import java.util.*;

class cyr
{
  int x,y;
  int v;
  cyr(int xx,int yy,int vv)
  {
    x=xx;
    y=yy;
    v=vv;
  }
}

public class Main
{
  public static int BFS(int sx,int sy,int dx,int dy,String[] a,int n,int m)
  {
    boolean[][] f=new boolean[80][80];
    cyr[] c=new cyr[7000];
    int head,tail;
    int i,j,x,y;
    int[][] way=new int[4][2];
    int[][] r=new int[80][80];
    for (i=0;i<=n+1;i++)
      for (j=0;j<=m+1;j++)
      {
        f[i][j]=false;
        r[i][j]=7000;
      }
    way[0][0]=-1;
    way[0][1]=0;
    way[1][0]=0;
    way[1][1]=1;
    way[2][0]=1;
    way[2][1]=0;
    way[3][0]=0;
    way[3][1]=-1;
    head=0;
    tail=1;
    c[1]=new cyr(sx,sy,0);
    f[sx][sy]=true;
    r[sx][sy]=0;
    do
    {
      head++;
      for (i=0;i<4;i++)
      {
        j=1;
        while (true)
        {
        x=c[head].x+j*way[i][0];
        y=c[head].y+j*way[i][1];
        if (x<0) break;
        if (x>n+1) break;
        if (y<0) break;
        if (y>m+1) break;
        if (f[x][y]) 
          if (c[head].v>=r[x][y]) 
            break;
        if ((x==dx) && (y==dy))
          return c[head].v+1;
        if ((x>=1) && (x<=n) && (y>=1) && (y<=m))
          if (a[x].charAt(y-1)=='X') break;
        tail++;
        c[tail]=new cyr(x,y,c[head].v+1);
        f[x][y]=true;
        r[x][y]=c[tail].v;
        j++;
        }
      }
    } while (head<tail);
    return -1;
  }

  public static void main(String[] args)
  {
    Scanner cin=new Scanner(System.in);
    int n,m,i,T=0;
    int sx,sy,dx,dy;
    String[] a=new String[80];
    m=cin.nextInt();
    n=cin.nextInt();
    while (!((n==0) && (m==0)))
    {
      T++;
      a[0]=cin.nextLine();
      for (i=1;i<=n;i++)
        a[i]=cin.nextLine();
      sy=cin.nextInt();
      sx=cin.nextInt();
      dy=cin.nextInt();
      dx=cin.nextInt();
      System.out.println("Board #"+T+":");
      int U=0;
      while (!((sx==0) && (sy==0) && (dx==0) && (dy==0)))
      {
        int ans;
        U++;
        ans=BFS(sx,sy,dx,dy,a,n,m);
        if (ans>=0)
        {
          System.out.println("Pair "+U+": "+ans+" segments.");
        }
        else System.out.println("Pair "+U+": impossible.");
        sy=cin.nextInt();
        sx=cin.nextInt();
        dy=cin.nextInt();
        dx=cin.nextInt();
      }
      System.out.println();
      m=cin.nextInt();
      n=cin.nextInt();
    }
  }
}
 