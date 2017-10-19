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

string s1, s2;
int ans1;

int lcss[33][33];

/*int LCS(int i,int j)
{
    if(i==0 || j==0)
    {
        if(s1[i]==s2[j])
        {
            memo1[i][j]=1;
            return 1;
        }
        else
        {
            memo1[i][j]=1;
            return 0;
        }
    }
    if(memo1[i][j]==-1)
    {
        if(s1[i]==s2[j]) memo1[i][j]= 1+LCS(i-1,j-1);
        else memo1[i][j]= max(LCS(i-1,j),LCS(i,j-1));
    }
    return memo1[i][j];
}

*/

ll memo[33][33][100];

ll DP(int i,int j,int num)
{
    if(i==s1.length())
    {
        ll xx =  s2.length()-j;
        xx+=num;
        if(xx==ans1) return 1;
        return 0;
    }
    else if(j==s2.length())
    {
        ll xx =  s1.length()-i;
        xx+=num;
        if(xx==ans1) return 1;
        return 0;
    }
    if(memo[i][j][num]==-1)
    {
        if(s1[i]==s2[j]) memo[i][j][num]= DP(i+1,j+1,num+1);
        else memo[i][j][num]= DP(i,j+1,num+1)+DP(i+1,j,num+1);
    }
    return memo[i][j][num];
}


void computeLCSS(int m,int n){
    for(int i = 0; i <= m; i++)
        lcss[i][0] = i;
    for(int i = 0; i <= n; i++)
        lcss[0][i] = i;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++){
            if(s1[i-1] == s2[j-1]) lcss[i][j] = lcss[i-1][j-1];
            else lcss[i][j] = min(lcss[i][j-1], lcss[i-1][j]);
            lcss[i][j]++;
        }
}

void solve()
{
    cin>>s1>>s2;
    /*f(i,0,33)
    {
        f(j,0,33) memo1[i][j]=-1;
    }*/
    computeLCSS(s1.length(),s2.length());
    ans1=lcss[s1.length()][s2.length()];
    //ans1 = (s1.length()+s2.length()) - ans1;
    f(i,0,33)
    {
        f(j,0,33)
        {
            f(k,0,100) memo[i][j][k]=-1;
        }
    }
    ll ans2 = DP(0,0,0);
    printf("%d %lld\n",ans1,ans2);
}

int main()
{
    int tc;
    cin >> tc;
    for (int i = 0; i < tc; ++i)
    {
        printf("Case %d: ", i + 1);
        solve();
    }
    return 0;
}



