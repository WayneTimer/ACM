#include <cstdio>
#include <cstring>

typedef unsigned long long ull;

int n,w,back_flag;
char a[20],b[20];
char sa[20],sb[20];
char ansa[20],ansb[20];
ull mind,mina,minb;
bool first;

int find_diff_digit()
{
    for (int i=0;i<n;i++)
        if (a[i]!='?' && b[i]!='?')
            if (a[i]!=b[i])
                return i;
    return n;
}

void update_ans()
{
    for (int i=w;i<n;i++)
    {
        if (back_flag==-1) // make back a<b
        {
            if (a[i]=='?' && b[i]=='?')
            {
                sa[i]='0';
                sb[i]='9';
            }
            else if (a[i]=='?' && b[i]!='?')
            {
                sa[i]='0';
                sb[i]=b[i];
            }
            else if (a[i]!='?' && b[i]=='?')
            {
                sa[i]=a[i];
                sb[i]='9';
            }
            else
            {
                sa[i]=a[i];
                sb[i]=b[i];
            }
        }
        else // make back a>b
        {
            if (a[i]=='?' && b[i]=='?')
            {
                sa[i]='9';
                sb[i]='0';
            }
            else if (a[i]=='?' && b[i]!='?')
            {
                sa[i]='9';
                sb[i]=b[i];
            }
            else if (a[i]!='?' && b[i]=='?')
            {
                sa[i]=a[i];
                sb[i]='0';
            }
            else
            {
                sa[i]=a[i];
                sb[i]=b[i];
            }
        }
    }

    ull t1,t2,t;
    t1=t2=0;
    for (int i=0;i<n;i++)
    {
        t1 = t1*10 + (sa[i]-'0');
        t2 = t2*10 + (sb[i]-'0');
    }
    if (t1>t2) t=t1-t2;
    else t=t2-t1;

    if (first || t<=mind)
        if (first || t<mind || t1<=mina)
            if (first || t<mind || t1<mina || t2<minb)
            {
                first=false;
                mind=t;
                mina=t1;
                minb=t2;
                strcpy(ansa,sa);
                strcpy(ansb,sb);
            }
}

// flag: -1: a<b,  0: a==b,  1: a>b
bool fill(int flag,int p)
{
    if (p<0)
    {
        update_ans();
        return true;
    }

    if (flag==0)
    {
        if (a[p]=='?' && b[p]=='?')
            sa[p]=sb[p]='0';
        else if (a[p]!='?' && b[p]=='?')
            sa[p]=sb[p]=a[p];
        else if (a[p]=='?' && b[p]!='?')
            sa[p]=sb[p]=b[p];
        else
        {
            sa[p]=a[p];
            sb[p]=b[p];
        }
        fill(flag,p-1);
    }
    else if (flag==-1) // make a<b
    {
        if (a[p]=='?' && b[p]=='?')
        {
            sa[p]='0';
            sb[p]='1';
            fill(0,p-1);
            sa[p]='9';
            sb[p]='0';
            fill(-1,p-1);
        }
        else if (a[p]=='?' && b[p]!='?')
        {
            sb[p]=b[p];
            if (b[p]!='0')
            {
                sa[p]=b[p]-1;
                fill(0,p-1);
            }
            else
            {
                sa[p]='9';
                fill(-1,p-1);
            }
        }
        else if (a[p]!='?' && b[p]=='?')
        {
            sa[p]=a[p];
            if (a[p]!='9')
            {
                sb[p]=a[p]+1;
                fill(0,p-1);
            }
            else
            {
                sb[p]='0';
                fill(-1,p-1);
            }
        }
        else
        {
            sa[p]=a[p];
            sb[p]=b[p];
            fill(flag,p-1);
        }
    }
    else // make a>b
    {
        if (a[p]=='?' && b[p]=='?')
        {
            sa[p]='1';
            sb[p]='0';
            fill(0,p-1);
            sa[p]='0';
            sb[p]='9';
            fill(1,p-1);
        }
        else if (a[p]=='?' && b[p]!='?')
        {
            sb[p]=b[p];
            if (b[p]!='9')
            {
                sa[p]=b[p]+1;
                fill(0,p-1);
            }
            else
            {
                sa[p]='0';
                fill(1,p-1);
            }
        }
        else if (a[p]!='?' && b[p]=='?')
        {
            sa[p]=a[p];
            if (a[p]!='0')
            {
                sb[p]=a[p]-1;
                fill(0,p-1);
            }
            else
            {
                sb[p]='9';
                fill(1,p-1);
            }
        }
        else
        {
            sa[p]=a[p];
            sb[p]=b[p];
            fill(flag,p-1);
        }
    }
    return false;
}

int main()
{
    int o,T;
    scanf("%d",&T);
    for (int o=1;o<=T;o++)
    {
        scanf("%s %s",a,b);
        n=strlen(a);

        w = find_diff_digit();

        memset(sa,0,sizeof(sa));
        memset(sb,0,sizeof(sb));
        first = true;
        if (w==n) // 1. can be equ
            fill(0,n-1);
        else if (a[w]>b[w])
        {
            back_flag = -1;
            fill(0,w-1);
            back_flag = 1;
            fill(-1,w-1);
        }
        else if (a[w]<b[w])
        {
            back_flag = 1;
            fill(0,w-1);
            back_flag = -1;
            fill(1,w-1);
        }

        printf("Case #%d: %s %s\n",o,ansa,ansb);
    }
    return 0;
}
