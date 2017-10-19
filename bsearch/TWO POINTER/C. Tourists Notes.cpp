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

int main()
{
    int n,k;
    cin>>n>>k;
    int mx=0;
    int a=0,b=0;
    cin>>a>>b;
    mx= (b+a-1);
    f(i,0,k-1)
    {
        int c,d;
        cin>>c>>d;
        int dif=c-a;
        if(abs(b-d)>dif)
        {
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
        int m1=max(b,d);
        int m2=min(b,d);
        int xx = m2-m1;
        xx+=dif;
        xx/=2;
        xx+=m1;
        mx=max(mx,xx);
        a=c;
        b=d;
    }
    mx= max(mx,b+(n-a));
    cout<<mx<<endl;
}


