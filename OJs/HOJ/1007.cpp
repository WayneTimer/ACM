/*This Code is Submitted by Timer for Problem 1007 at 2012-04-08 13:49:24*/
 #include<cstdio>
 #include<cstring>
 #define N 1050

using namespace std;
 int w[N][N];
 int n;
 int m;
 int time;
 int dis[N];
 int low[N];
 int tag[N];
 void dfs(int v,int prt)
 {
    time++;
     dis[v]=low[v]=time;
     int child=0;
     int i;
    for(i=m;i<=n;++i)
     {
         if(w[v][i]==0) continue;
         if(i!=prt&&dis[i]>0)
         {
             if(dis[i]<low[v])
                 low[v]=dis[i];
         }else if(dis[i]==0)
         {
             child++;
             dfs(i,v);
             if(low[i]<low[v])
                 low[v]=low[i];
             if((v!=m&&dis[v]<=low[i])||(child>=2&&v==m))
                 tag[v]++;
         }
    }
 }
 void input()
 {
     int a,b;
     int cur=0;
     while(scanf("%d",&a)&&a!=0)
     {
         scanf("%d",&b);
         n=0;
         m=1005;
         memset(w,0,sizeof(w));
         w[a][b]=w[b][a]=1;
         if(a>n) n=a;
         if(b>n) n=b;
         if(a<m) m=a;
         if(b<m) m=b;
         while(scanf("%d",&a)&&a!=0)
         {
             scanf("%d",&b);
             w[a][b]=w[b][a]=1;
             if(a>n) n=a;
             if(b>n) n=b;
             if(a<m) m=a;
             if(b<m) m=b;
         }
         memset(tag,0,sizeof(tag));
         memset(dis,0,sizeof(dis));
         memset(low,0,sizeof(low));
         time=0;
         dfs(m,0);
         int i,j,bb;
         bb=0;
         if (cur>0) printf("\n");
         printf("Network #%d\n",++cur);
 
         for(i=m;i<=n;++i)
         {
             if(tag[i])
             {
                 bb=1;
                printf("  SPF node %d leaves %d subnets\n",i,tag[i]+1);

             }
         }
        if(!bb) printf("  No SPF nodes\n");
    }
}

int main()
{
     input();
     return 0;
}