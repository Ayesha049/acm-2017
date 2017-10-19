
#include<bits/stdc++.h>
using namespace std;
map < int , int > parent;
void make_parent1(int n)
{
    for (int i=1; i<=n; i++)
    {
        parent[i]=i;
    }
}

void make_parent2(int n)
{
    for (int i=1; i<=n; i++)
    {
        parent[i]=-1;
    }
}


int Find(int node)
{
    if(parent[node]==-1) return node;
    parent[node]=Find(parent[node]);
    return parent[node];
}

void Union(int node1, int node2)
{
    int a= Find(node1);
    int b= Find(node2);
    if(a==b) return;
    parent[b]=a;
}

int main()
{
    int n,m;
    cin>>n>>m;
    make_parent2(n);
    int a,b;
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d", &a,&b);
        Union(a,b);

    }
    //number of connected components
    int cnt=0;
    map < int, int > :: iterator it;
    for(it=parent.begin();it != parent.end();it++)
    {
        //cout<<(*it).second<<endl;
        if((*it).second == -1) cnt++;
    }
    if(cnt==1 && n==m) cout<<"FHTAGN!"<<endl;
    else cout<<"NO"<<endl;


}



