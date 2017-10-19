#include<bits/stdc++.h>
using namespace std;
int cnt;
bool visited[55][55];
char s[55][55];
int n,m,k;


const int DX[] = {0,1,0,-1};
const int DY[] = {1,0,-1,0};


bool checkCell(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
        return false;
    return s[x][y] == '.';
}

void dfs(int x, int y)
{
    visited[x][y] = 1;
    cnt++;
    for (int d = 0; d < 4; d++)
    {
        int xx = x + DX[d];
        int yy = y + DY[d];
        if (!checkCell(xx, yy))
            continue;
        if (visited[xx][yy])
            continue;
        dfs(xx, yy);
    }
    return;
}

void dfs2(int x, int y)
{
    s[x][y] = '*';
    for (int d = 0; d < 4; d++)
    {
        int xx = x + DX[d];
        int yy = y + DY[d];
        if (!checkCell(xx, yy))
            continue;
        dfs2(xx, yy);
    }
    return;
}


int main()
{

    cin>>n>>m>>k;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) cin>>s[i][j];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(i>0 && i<n-1 && j>0 && j<m-1) continue;
            if(s[i][j]=='*') continue;
            dfs(i,j);
        }
    }
    vector<pair<int,pair<int,int> > > vc;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if (s[i][j] == '*') continue;
            if(visited[i][j]) continue;
            cnt=0;
            dfs(i,j);
            vc.push_back(make_pair(cnt,make_pair(i,j)));
        }
    }
    sort(vc.begin(),vc.end());
    int zz= vc.size();
    int kk= zz-k;
    int sum=0;
    for(int i=0; i<kk; i++)
    {
        sum+=vc[i].first;
        dfs2(vc[i].second.first,vc[i].second.second);
    }
    cout<<sum<<endl;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<s[i][j];
        }
        cout<<endl;
    }
}
