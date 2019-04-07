#include<bits/stdc++.h>
#include "traverse.cpp"
#include "msp.cpp"
#include "shortestpath.cpp"
#include "allsourceshortestp.cpp"
#include "articulation_point.cpp"
using namespace std;

vector<pair<int,int> > adj[1000];
int n,e; 

//Insert
void insert()
{
    cout<<"Enter no. of vertices and edge"<<endl;
    cin>>n>>e;
    cout<<"Enter v1,v2and weight"<<endl;
    for(int i=0;i<e;i++)
    {
        int v1,v2,w;
        cin>>v1>>v2>>w;
        adj[v1].push_back(make_pair(w,v2));
    }
cout<<"Data inserted sucessfully"<<endl;
} 


int main()
{
    l:
    cout<<"*****************MENU*****************"<<endl;
    cout<<"PRESS 1.INSERT"<<endl;
    cout<<"PRESS 2.BFS"<<endl;
    cout<<"PRESS 3.DFS"<<endl;
    cout<<"PRESS 4.MINIMUM SPANNING TREEE"<<endl;
    cout<<"PRESS 5.SINGLE SOURCE SHORTEST PATH"<<endl;
    cout<<"PRESS 6.ALL SOURCE SHORTEST PATH(WARSHALL ALGO)"<<endl;
    cout<<"PRESS 7.ARTICULATION POINT"<<endl;
    cout<<"Enter ur choice.."<<endl;
    int ch;
    cin>>ch;
    switch(ch)
    {
        case 1:
        {
            insert();
            break;
        }
        case 2:
        {
            bfs(adj,n);
            break;
        }
        case 3:
        {
            dfs(adj,n);
            break;
        }
        case 4:
        {
            cout<<"1.PRIM'S ALGO"<<endl;
            cout<<"2.KRUSKAL ALGO"<<endl;
            cout<<"Enter ur choice.."<<endl;
            int ch1;
            cin>>ch1;
            switch(ch1)
            {
                case 1:
                {
                    int res=prims(adj,n);
                    cout<<"Minmum Spaning tree weight:"<<res<<endl;
                    break;
                }
                case 2:
                {
                    int res=kruskal(adj,n,e);
                    cout<<"Minimum Spanning Tree weight:"<<res<<endl;
                    break;
                }
            }
            break;
        }
        case 5:
        {
            cout<<"1.BELLMAN FORD'S ALGO"<<endl;
            cout<<"2.DIJKSTRA ALGO"<<endl;
            int ch;
            cin>>ch;
            switch(ch)
            {
                case 1:
                {
                    bellmanford(adj,n,e);
                    break;
                }
                case 2:
                {
                    dijkstra(adj,n);
                    break;
                }
            }
            break;
            
        }
        case 6:
        {
            warshall(adj,n);
            break;
        }
        case 7:
        {
            cout<<"Articulation points are.."<<endl;
            atpoint(adj,n);
            break;
        }
        default:
        break;
    }
    goto l;
    return 0;

}

