#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pr;
typedef pair<int,pr> PPR;


//PRIM'S
int prims(vector<pair<int,int> > vt[],int n)
{
   priority_queue<pr,vector<pr>,greater<pr> > pq;
   bool visit[n];
   memset(visit,false,sizeof(visit));
   pq.push(make_pair(0,0));
   int minsum=0;
   pr p;
   while(!pq.empty())
   {
       p=pq.top();
       pq.pop();
       int v=p.second,w=p.first;
       if(visit[v])
       continue;

       minsum+=w;
       visit[v]=true;
       for(int i=0;i<vt[v].size();i++)
       {
           if(!visit[vt[v][i].second])
           pq.push(vt[v][i]);
       }
   }

    return minsum;
}


//KRUSKAL

int root(int set[],int x)
{
    while(x!=set[x])
    {
        x=set[x];
    }
    return x;
}

void unin(int set[],int v1,int v2)
{
    set[v1]=v2;
}


int kruskal(vector<pr> vt[],int n,int e)
{
    PPR adj[e];
    int k=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<vt[i].size();j++)
        {
            int v2=vt[i][j].second;
            int w=vt[i][j].first;
            adj[k++]=make_pair(w,make_pair(i,v2));
        }
    }

    sort(adj,e+adj);
    int minsum=0;

    //set
    int set[n];
    for(int i=0;i<n;i++)
    {
        set[i]=i;
    }

    for(int i=0;i<e;i++)
    {
        int w=adj[i].first;
        pr p=adj[i].second;
        int v1=p.first;
        int v2=p.second;

        int root1=root(set,v1);
        int root2=root(set,v2);
        if(root1!=root2)
        {
            minsum+=w;
            unin(set,root1,root2);
        }
    }
return minsum; 
}