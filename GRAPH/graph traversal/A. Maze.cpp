#include <bits/stdc++.h>
#define ll             long long
#define f(i,a,b)       for(int i=(a);i<(b);i++)
#define fd(i,a,b)      for(ll i=(a);i>(b);i--)
#define x              first
#define y              second
#define si(a)          scanf("%d",&a)
#define sii(a,b)       scanf("%d %d",&a,&b)
#define siii(a,b,c)    scanf("%d %d %d",&a,&b,&c)
#define sl(a)          scanf("%I64d",&a)
#define sll(a,b)       scanf("%I64d %I64d",&a,&b)
#define slll(a,b,c)    scanf("%I64d %I64d %I64d",&a,&b,&c);
#define pfci(n,ans)    printf("Case %I64d: %d\n",n,ans)
#define pfcl(n,ans)    printf("Case %I64d: %I64d\n",n,ans)
#define pfcd(n,ans)    printf("Case %I64d: %lf\n",n,ans)
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define MOD 1000000009
#define ld long double
#define mp make_pair
using namespace std;
#define INF 1e12
#define EPS 1e-12
//#define double long double
#define PI 3.141592653589

char s[509][509];
int n,m,k;

const int DX[] = {0,1,0,-1};
const int DY[] = {1,0,-1,0};

map<pair<int,int>,int> visited;

bool checkCell(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
        return false;
    return s[x][y] == '.';
}


void bfs(pair<int,int> src)
{
    visited[src]=1;
    queue<pair<int,int> > q;
    q.push(src);
    while(!q.empty())
    {
        int xx= q.front().first;
        int yy= q.front().second;
        q.pop();
        int flag=0;
        for (int i = 0; i < 4; i++)
        {
            int xxx = xx + DX[i];
            int yyy = yy + DY[i];
            if(checkCell(xxx,yyy))
            {
                if(s[xxx][yyy]=='.')
                {
                    if(visited[mp(xxx,yyy)]==0)
                    {
                        flag=1;
                        visited[mp(xxx,yyy)]=1;
                        q.push(mp(xxx,yyy));
                    }
                }

            }
        }
        if(flag==0)
        {
            if(k==0) return;
            k--;
            s[xx][yy]='X';
            if(k==0) return;
        }
    }
    return;
}


void dfs(pair<int,int> src)
{
    visited[src]=1;
    int xc = src.x;
    int yc = src.y;
    for (int d = 0; d < 4; d++)
    {
        int xx = xc + DX[d];
        int yy = yc + DY[d];
        if (!checkCell(xx, yy))
            continue;
        if (visited[mp(xx,yy)])
            continue;
        dfs(mp(xx, yy));
    }
    if(k==0) return;
    k--;
    s[xc][yc]='X';
    return;
}


int main()
{
    siii(n,m,k);
    pair<int,int> sc;
    int ff=0;
    f(i,0,n)
    {
        f(j,0,m)
        {
            cin>>s[i][j];
            if(ff==0 && s[i][j]=='.')
            {
                sc = mp(i,j);
                ff=1;
            }
        }
    }
    dfs(sc);
    f(i,0,n)
    {
        f(j,0,m)
        {
            cout<<s[i][j];
        }
        cout<<endl;
    }

}


