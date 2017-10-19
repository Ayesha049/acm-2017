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

vector<int>edge[100009];

int main()
{
    int n,m,k;
    siii(n,m,k);
    map<pair<int,int>,int>len;
    int a,b,l;
    f(i,0,m)
    {
        siii(a,b,l);

        if(len[mp(a,b)]==0 && len[mp(b,a)]==0)
        {
            len[mp(a,b)]=l;
            len[mp(b,a)]=l;
            edge[a].pb(b);
            edge[b].pb(a);
        }
        else
        {
            len[mp(a,b)]= min(l,len[mp(a,b)]);
            len[mp(b,a)]= len[mp(a,b)];
        }
    }
    int flag=-1;
    int ans=(int) INFINITY;
    f(i,0,k)
    {
        int a;
        si(a);
        if(edge[a].size()!=0)
        {
            int mn= (int)INFINITY;
            f(j,0,edge[a].size())
            {
                mn= min(mn,len[mp(a,edge[a][j])]);
            }
            ans=min(ans,mn);
            flag=ans;
        }
    }
    cout<<flag<<endl;
}


