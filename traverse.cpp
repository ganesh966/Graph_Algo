#include <bits/stdc++.h>
using namespace std;

//BFS
void bfs(vector<pair<int,int> > vt[],int n)
{
    queue<int> qu;
    qu.push(0);
    bool visit[n];
    memset(visit,false,sizeof(visit));
    visit[0]=true;
    while(!qu.empty())
    {
        int v=qu.front();
        qu.pop();
        cout<<v<<" ";
        for(int i=0;i<vt[v].size();i++)
        {
            if(!visit[vt[v][i].second])
            {
                qu.push(vt[v][i].second);
                visit[vt[v][i].second]=true;
            }
        }
    }
    cout<<endl;
}


//DFS
void dfs(vector<pair<int,int> > vt[],int n)
{
    stack<int> st;
    st.push(0);
    int visit[n];
    memset(visit,0,sizeof(visit));
    visit[0]=1;
    while(!st.empty())
    {
        int v=st.top();
        cout<<v<<" ";
        st.pop();
        for(int i=0;i<vt[v].size();i++)
        {
            if(visit[vt[v][i].second]==0)
            {
            st.push(vt[v][i].second);
            visit[vt[v][i].second]=1;
            }
        }
    }
    cout<<endl;
}