#include <bits/stdc++.h>
#define MAXN 30000000
using namespace std;
int c[300000];
int d[300000];
int n;

int B_search (int m) {
    int score = m;
    for (int i = 0; i < n; i++) {
        if (score<1900&&d[i]==1) return 1;
        if (score>=1900&&d[i]==2) return 2;
            score += c[i];
    }
    return score;
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) scanf("%d%d",&c[i],&d[i]);
    int sum = 0;
    for (int i = 0; i < n; i++) sum+=d[i];
    if(sum==n) {
        puts("Infinity");
        return 0;
    }
    int l = -MAXN, r = MAXN;
    int ans = 0;
    while (l <= r) {
        int mid = (l+r)>>1;
        int t = B_search(mid);
        if (t == 1) l = mid+1;
        else if (t == 2) r = mid -1;
        else {
            ans = t;
            l = mid + 1;
        }
    }
    if (!ans) puts("Impossible");
    else cout << ans << endl;
    return 0;
}
