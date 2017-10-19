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
#define EPS 1e-15
//#define double long double
#define PI acos(-1.0)

vector<int> vc[1001];

int memo[1001][1001];

int dp(int i, int j,int N)
{

    if(i==0) return memo[0][0];
    if(i>N)
    {
        if(memo[i-1][j]==-1)
        {
            memo[i-1][j]=dp(i-1,j,N);
        }

        if(memo[i-1][j+1]==-1)
        {
            memo[i-1][j+1]=dp(i-1,j+1,N);
        }

        return vc[i][j]+max(memo[i-1][j],memo[i-1][j+1]);
    }
    else
    {
        if(j==vc[i].size()-1)
        {
            if(memo[i-1][j-1]==-1)
            {
                memo[i-1][j-1]=dp(i-1,j-1,N);
            }

            return vc[i][j]+memo[i-1][j-1];
        }
        if(j==0)
        {
            if(memo[i-1][j]==-1)
            {
                memo[i-1][j]=dp(i-1,j,N);
            }
            return vc[i][j]+memo[i-1][j];
        }
        else
        {
            if(memo[i-1][j]==-1)
            {
                memo[i-1][j]=dp(i-1,j,N);
            }
            if(memo[i-1][j-1]==-1)
            {
                memo[i-1][j-1]=dp(i-1,j-1,N);
            }
            return vc[i][j]+max(memo[i-1][j],memo[i-1][j-1]);
        }
    }
    //cout<<dp(i,j,N)<<endl;

}

void solve()
{
    int N;
    si(N);

    int n= 2*N -1;
    f(i,0,n+1)
    {
        vc[i].clear();
    }
    f(i,0,N)
    {
        int a;
        f(j,0,i+1)
        {
            si(a);
            vc[i].pb(a);
        }
    }
    f(i,N,n)
    {
        int a;
        f(j,0,n-i)
        {
            si(a);
            vc[i].pb(a);
        }

    }

    f(i,0,n)
    {
        memset(memo[i],-1,sizeof(memo[i]));
    }
    memo[0][0]= vc[0][0];
    int ans = dp(n-1,0,N-1);
    cout<<ans<<endl;


}

int main()
{
    int tc;
    si(tc);
    for (int i = 0; i < tc; ++i)
    {
        printf("Case %d: ", i + 1);
        solve();
    }
    return 0;
}



