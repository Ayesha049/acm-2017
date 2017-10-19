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

vector<ll>power;

map<ll,int>mpp;

int main()
{
    int n;
    ll k;
    cin>>n>>k;
    ll base=1;
    power.pb(base);
    if(k==-1) power.pb(k);
    else if(abs(k)>1)
    {
        while(abs(base)<=1000000000000000)
        {
            base*=k;
            power.pb(base);
        }
    }
    vector<ll>v;
    v.pb(0);
    ll a;
    f(i,1,n+1)
    {
        cin>>a;
        v.pb(a);
        v[i]=v[i]+v[i-1];
    }
    ll cnt=0;
    for(int i=n; i>0; --i)
    {

        mpp[v[i]]++;

        for(int j=0; j<power.size(); ++j)
        {
            cnt += mpp[power[j]+v[i-1]];
        }

    }
    cout<<cnt<<endl;
}
