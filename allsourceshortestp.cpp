#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> PR;

void warshall(vector<PR> vt[],int n)
{

    //INITIALIZATION
    int dist[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            dist[i][j]=0;
            else
            dist[i][j]=999;
        }
    }


    for(int i=0;i<n;i++)
    {
        for(int j=0;j<vt[i].size();j++)
        {
            int v=vt[i][j].second;
            int w=vt[i][j].first;
            dist[i][v]=w;
        }
    }


    //ALGO
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                dist[i][j]=min(dist[i][k]+dist[k][j],dist[i][j]);
            }
        }
    }


    //PRINT
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(dist[i][j]==999)
            cout<<"~"<<"  ";
            else
            cout<<dist[i][j]<<"  ";
        }
        cout<<endl;
    }


}