#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pr;



void print(int wt[],int n)
{
    cout<<"Shortest distance between:-"<<endl;
    for(int i=1;i<n;i++)
    {
        cout<<"0--->"<<i<<"\t"<<wt[i]<<endl;
    }
}

//BELLMANFORD

void bellmanford(vector<pr> vt[],int n,int e)
{
   int wt[n];
   for(int i=0;i<n;i++)
   {
       wt[i]=INT_MAX;
   }

    wt[0]=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<vt[j].size();k++)
            {
                int w=vt[j][k].first;
                int v2=vt[j][k].second;
                if(wt[j]!=INT_MAX && (wt[j]+w)<wt[v2])
                wt[v2]=wt[j]+w;
               // cout<<wt[v2]<<" ";
            }
        }
        
    }

    //check for -ve cycle
    int s=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<vt[i].size();j++)
        {
            int w=vt[i][j].first;
            int v2=vt[i][j].second;
            if(wt[i]!=INT_MAX && (wt[i]+w)<wt[v2])
            {
                s=1;
                break;
            }
        }
        if(s==1)
        break;
    }

    if(s==1)
    cout<<"Cycle is present"<<endl;
    else
    print(wt,n);

} 


void dijkstra(vector<pr> vt[],int n)
{
    priority_queue<pr,vector<pr>,greater<pr> > pq;
    bool visit[n];
    int dist[n];
    for(int i=0;i<n;i++)
    {
        visit[i]=false;
        dist[i]=INT_MAX;
    }
    dist[0]=0;

    pq.push(make_pair(0,0));
    while(!pq.empty())
    {
        pr p=pq.top();
        pq.pop();
        int v=p.second,w=p.first;
        if(visit[v])
        continue;

        visit[v]=true;
        for(int i=0;i<vt[v].size();i++)
        {
            int v2=vt[v][i].second;
            int w=vt[v][i].first;
            if(!visit[v2] && dist[v]!=INT_MAX && (dist[v]+w)<dist[v2])
            {
                dist[v2]=dist[v]+w;
                pq.push(make_pair(dist[v]+w,v2));
            }
        }

    }

    print(dist,n);

}
