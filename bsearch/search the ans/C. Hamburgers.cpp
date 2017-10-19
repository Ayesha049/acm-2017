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

ll b=0,s=0,c=0,nb,nc,ns,pb,ps,pc,r;

int check(ll n)
{
    ll xb=n*b;
    ll xs=n*s;
    ll xc=n*c;
    ll need=0;
    if(xb>nb) need+=((xb-nb)*pb);
    if(xc>nc) need+=((xc-nc)*pc);
    if(xs>ns) need+=((xs-ns)*ps);
    if(need>r) return 0;
    //cout<<need<<" "<<r<<"                 ";
    return 1;

}


int main()
{
    string ss;
    cin>>ss;
    cin>>nb>>ns>>nc>>pb>>ps>>pc>>r;
    for(int i=0;i<ss.length();i++)
    {
        if(ss[i]=='S') s++;
        else if(ss[i]=='B') b++;
        else c++;
    }
    ll l=0;
    ll h=100000000000000;
    ll ans=0;
    while(l<=h)
    {
        ll mid= (l+h)/2;
        if(check(mid)==1)
        {
            ans=mid;
            //cout<<ans<<"     ";
            l=mid+1;
        }
        else h=mid-1;
    }
    cout<<ans<<endl;
}


