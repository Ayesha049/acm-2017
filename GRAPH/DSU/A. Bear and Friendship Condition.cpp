
#include<bits/stdc++.h>
using namespace std;
map < int , int > parent;
map < int , long long > node;
void make_parent(int n)
{
    for (int i=1; i<=n; i++)
    {
        parent[i]=i;
        node[i]=1;
    }
}
int Find(int node)
{
    if(parent[node]==node) return node;
    parent[node]=Find(parent[node]);
    return parent[node];
}

int main()
{
    int a,b,n, m,i,j,k,l;
    map < int, long long > edge;
    scanf("%d %d",&n,&m);
    make_parent(n);
    for(i = 1; i<=m; i++)
    {
        scanf("%d %d",&a,&b);
        int p1=Find(a);
        int p2=Find(b);
        if(p1==p2)
        {
            edge[p1]++;

        }
        else
        {
            edge[p1]+=edge[p2]+1;
            edge[p2]=0;
            node[p1]+=node[p2];
            node[p2]=0;
            parent[p2]=p1;
        }

    }
    map < int, long long > :: iterator it;
    for(it = edge.begin(); it!=edge.end(); it++)
    {
        if((*it).second !=0)
        {
            int pr=(*it).first;
            long long nd=node[pr];
            long long ed=((*it).second);
            //cout<<"pr "<<pr<<" ed "<<ed<<" nd "<<nd<<endl;
            if(!(ed == (nd * (nd -1)/2)))
            {
                printf("NO\n");
                return 0;
            }
        }

    }
    printf("YES\n");
    return 0;
}
