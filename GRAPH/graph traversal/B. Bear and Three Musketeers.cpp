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

vector<int> edge[4009];
int visited[4009];

int main()
{
    int n,m;
    sii(n,m);
    int a,b;
    f(i,0,m)
    {
        sii(a,b);
        edge[a].pb(b);
        edge[b].pb(a);
    }
    int mn = (int) INFINITY;
    int flag=-1;
    f(i,1,n+1)
    {
        int node1=i;
        f(j,0,edge[i].size())
        {
            int node2 = edge[i][j];
            f(k,0,edge[node2].size())
            {
                int node3= edge[node2][k];
                if(node3!=node1 && visited[node3]==0)
                {
                    if(find(edge[node3].begin(),edge[node3].end(),node1)!=edge[node3].end())
                    {
                        int cnt= edge[node1].size()+edge[node2].size()+ edge[node3].size() -6;
                        mn= min(mn,cnt);
                        flag=mn;
                        //cout<<node1<<" "<<node2<<" "<<node3<<"cost "<<cnt<<endl;
                    }
                }
            }
        }
        visited[i]=1;
    }
    cout<<flag<<endl;
}


