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
    int k;
    string s;
    cin>>k>>s;
    int cnt1=0;
    vector<int>vc;
    vc.pb(0);
    f(i,0,s.length())
    {
        if(s[i]=='1')
        {
            vc.pb(vc[i]+1);
            cnt1++;
        }
        else vc.pb(vc[i]);
    }


    int l=0,r=1;
    int cnt=0;
    int n= s.length();
    f(i,0,n+1) cout<<vc[i]<<" ";
    cout<<endl;
    while(1)
    {
        if(l==n+1 || r==n+1)
        {
            /*if(l<=(n))
            {
                while(1)
                {
                    if(l==(n+1)) break;
                    if(vc[r-1]-vc[l]==k) cnt++;
                    l++;
                }
            }*/
            break;
        }
        if( vc[r]-vc[l]<k)
        {
            r++;
        }
        else if(vc[r]-vc[l]>k)
        {
            l++;
        }
        else
        {
            int xx=l;
            int yy=r;
            while(vc[yy]-vc[xx]==k)
            {
                cnt++;
                xx++;
            }
            l=xx;
            xx=l;
            while(vc[yy]-vc[xx]==k)
            {
                cnt++;
                yy++;
            }
            r=yy;
            cnt++;
            //r++;

        }

    }
    if(k==0) cnt-=cnt1;
    cout<<cnt<<endl;
}
