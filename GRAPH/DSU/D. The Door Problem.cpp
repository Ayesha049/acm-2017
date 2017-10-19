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
    int n,m;
    cin>>n>>m;
    int a;
    map<int,int>mpp;
    f(i,0,n)
    {
        si(a);
        mpp[i+1]=a;
    }
    vector< vector< int > > vc;
    f(i,0,m)
    {
        si(a);
        int flag=0;
        int xx;
        vector<int>vv;
        f(j,0,a)
        {
            si(xx);
            if(mpp[xx]!=0) flag=1;
            vv.pb(xx);
        }
        if(flag==0)
        {
            vc.pb(vv);
        }
    }
    f(i,0,vc.size())
    {

        //cout<<i<<endl;
        f(j,0,vc[i].size()) mpp[vc[i][j]]=1;

    }
    int flag=0;
    f(i,1,n+1)
    {
        if(mpp[i]==0)
        {

            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;

}


