#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> adj[505];
bool visited[505];
int color[505];

bool dfs(int s)
{
    if(visited[s])
    {
        return true;
    }

    visited[s] = true;

    if(color[s] == 0)
    {
        color[s] = 1;
    }

    for(auto i : adj[s])
    {
        if(color[i] == 0)
        {
            if(color[s] == 1)
            {
                color[i] = 2;
            }
            else
            {
                color[i] = 1;
            }
        }
        else
        {
            if(color[i] == color[s])
            {
                return false;
            }
        }
    }

    bool answer = true;
    for(auto i : adj[s])
    {
        if(!visited[i])
        {
            answer &= dfs(i);
        }
    }
    return answer;

}

int32_t main()
{

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int ans = true;

    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            ans &= dfs(i);
        }
    }

    if(ans)
    {
        cout << "YES" << endl;
        for(int i = 1; i <= n; i++)
        {
            if(color[i] == 1)
            {
                cout << "R";
            }
            else
            {
                cout << "B";
            }
        }
    }
    else
    {
        cout << "NO";
    }
    return 0;


}