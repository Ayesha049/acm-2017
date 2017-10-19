#include<bits/stdc++.h>


#define X  first
#define Y  second
typedef long long ll;

#define FOR(i,a,b) for(ll i = a;i<=b;i++)
#define FOD(i,a,b) for(ll i = a;i>=b;i--)
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair<ll,ll>ii;
typedef priority_queue<ll,vector<ll>,greater<ll> > heap_min;
const ll maxN = 1e6+5;
const ll inf = 1e10;
const ll mod = 1e9+7;
ll n,k,a[200000],b[200000],need=0,res=0;

ll check(ll x)
{
	need=0;
	FOR(i,1,n)
	{
		if (a[i]*x>b[i]) need+=a[i]*x-b[i];
		if (need>k) return 0;
	}
	if (need<=k) return 1;
	else return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
	cin>>n>>k;
	FOR(i,1,n) cin>>a[i];
	FOR(i,1,n) cin>>b[i];
	ll l=0,r=2000000000;
	while (l<=r)
	{
		ll mid=(l+r)/2;
		if (check(mid))
		{
			res=mid;
//			cout<<res<<endl;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<res;
	return 0;
}
