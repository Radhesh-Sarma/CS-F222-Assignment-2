#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> adj[26];
bool visited[26];
string answer;

void dfs(int s)
{
    if(visited[s])
    {
        return;
    }
    visited[s] = true;
    char ch = s + 'A';
    answer.push_back(ch);
    for(auto i : adj[s])
    {
        if(!visited[i])
        {
            dfs(i);
        }
    }
}
int32_t main()
{


    int n, m;
    cin >> n >> m;


    for(int i = 1; i <= m; i++)
    {
        char x, y;
        cin >> x >> y;

        adj[x - 'A'].push_back(y - 'A');
        adj[y - 'A'].push_back(x - 'A');
    }

    vector<string> ans;

    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            dfs(i);
            ans.push_back(answer);
            answer = "";
        }

    }

    cout << ans.size() << endl;
    for(auto i : ans)
    {
        sort(i.begin(), i.end());
        cout << i << endl;
    }

    return 0;


}