
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
    int n,i,j,k,l,x,cnt=0;
    cin>>n;
    make_parent2(n);
    for(i=1;i<=n;i++)
    {
        scanf("%d", &x);
        Union(i,x);

    }
    map < int, int > :: iterator it;
    for(it=parent.begin();it != parent.end();it++)
    {
        //cout<<(*it).second<<endl;
        if((*it).second == -1) cnt++;
    }
    cout<<cnt<<endl;

}


