#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> adj[2005];
bool visited[2005] = {false};
int parent[2005] = {0};

void bfs(int s)
{
    parent[s] = -1;
    visited[s] = true;
    queue<int> q;
    q.push(s);
    dist[s] = 1;

    while(!q.empty())
    {
        int k = q.front();
        q.pop();

        for(auto i : adj[k])
        {
            if(!visited[i])
            {
                visited[i] = true;
                q.push(i);
                parent[i] = k;
            }
        }
    }
}

int32_t main()
{


#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m ;

    for(int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);

    }

    int source, destination;
    cin >> source >> destination;

    bfs(source);

    if(visited[destination])
    {
        vector<int> ans;
        ans.push_back(destination);
        int s = destination;

        while(parent[s] != -1)
        {
            ans.push_back(parent[s]);
            s = parent[s];
        }

        reverse(ans.begin(), ans.end());

        cout << ans.size() - 1 << endl;

        for(auto i : ans)
        {
            cout << i << " ";
        }
    }
    else
    {
        cout << -1;
    }

    return 0;


}