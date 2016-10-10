#include <queue>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int move[8][2] = {
    {-2,1},{-1,2},{1,2},{2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}
};
typedef struct point {
    int x,y,step;
} point;

int main()
{
    char str[10];
    while(gets(str)) {
        int map[8][8];
        memset(map,-1,sizeof(map));
        int r1,c1,r2,c2;
        r1 = str[0] - 'a';
        c1 = str[1] - '1';
        r2 = str[3] - 'a';
        c2 = str[4] - '1';
        if(r1==r2&&c1==c2) {
            printf("To get from %c%c to %c%c takes %d knight moves.\n",str[0],str[1],str[3],str[4],0);
            continue;
        }
        map[r1][c1] = 0;
        queue<point> q;
        point p0 = {r1,c1,0};
        q.push(p0);
        int ctn = 0;
        while(!q.empty()) {
            point p = q.front();
            q.pop();
            for(int i=0; i<8; i++) {
                int tx = p.x + move[i][0];
                int ty = p.y + move[i][1];
                if(tx>=0 && tx<8 && ty>=0 && ty<8 && map[tx][ty]<0) {
                 if(tx==r2 && ty==c2) {
                        printf("To get from %c%c to %c%c takes %d knight moves.\n",str[0],str[1],str[3],str[4],p.step+1);
                        ctn = 1;
                        break;
                    }
                    point tmp = {tx, ty, p.step+1};
                    q.push(tmp);
                    map[tx][ty] = tmp.step;
                }
            }
            if(ctn) break;
        }
    }
    return 0;
}