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
    vector<int>vc;
    vc.pb(0);
    vector<int>con;
    con.pb(0);
    string s;
    cin>>s;
    f(i,0,s.length())
    {
        if(s[i]=='a')
        {
            vc.pb(0);
            con.pb(1);
        }
        else
        {
            vc.pb(1);
            con.pb(0);
        }
    }
    //f(i,1,vc.size()) cout<<vc[i]<<" ";
    //cout<<endl<<endl<<endl;

    f(i,1,vc.size())
    {
        vc[i]= vc[i]+vc[i-1];
        con[i]=con[i]+con[i-1];
    }
    //cout<<endl<<endl;
    //f(i,1,con.size()) cout<<con[i]<<" ";

    int l=1,r=1;
    int mx1=0;
    while(1)
    {
        if(l==n+1 || r==n+1) break;
        if(con[r]-con[l-1]<=k)
        {
            mx1= max(mx1,(r-l+1));
            r++;
        }
        else l++;
    }
    l=1,r=1;
    int mx2=0;
    while(1)
    {
        if(l==n+1 || r==n+1) break;
        if(vc[r]-vc[l-1]<=k)
        {
            mx2= max(mx2,(r-l+1));
            r++;
        }
        else l++;
    }

    cout<<max(mx1,mx2)<<endl;

}


