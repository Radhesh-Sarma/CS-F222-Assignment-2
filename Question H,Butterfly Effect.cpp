#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<int> g[N];
bool vis[N];
int n,m,p,q,t;
bool flag = false;
vector<int> ans;

void dfs(int node, int state)
{
	if(node == p)
		state = 1;
	if(state == 1 and node == q)
		return;
	if(node == t)
	{
		flag = true;
		ans.push_back(t);
		return;			 	
	}

	vis[node] = true;
	for(auto it : g[node])
	{
	    if(!vis[it])
	    	dfs(it,state);
	    if(flag)
	    {
	    	ans.push_back(node);
	    	return; 	
	    }
	}
	if(flag)
		return;
}

int main()
{

	cin >> n >> m >> t;
	for(int i = 0; i < m; i++)
	{
	 	int a,b;
	 	cin >> a >> b;
	 	g[a].push_back(b);
	 	g[b].push_back(a);
	}
	cin >> p >> q;
	dfs(1,0);
	if(!flag)
	{
	 	cout <<"NO";
	 	return 0;
	}
	reverse(ans.begin(),ans.end());
	cout <<"YES\n";
	for(auto it : ans)
		cout << it <<" ";
}
