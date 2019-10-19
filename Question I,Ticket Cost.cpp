#include<bits/stdc++.h>
using namespace std;

const int N = 12;
vector<int> g[N];
int d[N][N];
int n,m,p,q,ans = 2e9;
const int INF = 1e9;
set<int> s;
bool flag = false;
vector<int> pr;

void dfs(int node, int weight)
{
	s.insert(node);
	if(node == q)
		ans = min(ans,weight);
	for(auto it : g[node])
	{
		if(s.find(it) == s.end())
		{
		 	dfs(it,weight+d[it][node]);
	 	}
 	}
 	s.erase(node);
}

void dfs1(int node, int weight)
{
	s.insert(node);
 	if(node == q and weight == ans)
 	{
 	 	pr.push_back(q);
 	 	flag = true;
 	 	return;
 	}
 	for(auto it : g[node])
 	{
 	 	if(s.find(it) == s.end())
 	 	{
 	 	 	dfs1(it,weight+d[it][node]);
 	 	}
 	 	if(flag)
 	 	{
 	 	 	pr.push_back(node);
 	 	 	return;
 	 	}
 	}
 	if(flag)
 	{
 	 	pr.push_back(node);
 	}
 	s.erase(node);
}

int main()
{
	
	cin >> n >> m >> p >> q;
	for(int i = 1; i <= n; i++)	
		for(int j = 1; j <= n; j++)
			d[i][j] = INF;
	for(int i = 0; i < m; i++)
	{
	 	int a,b,c;
	 	cin >> a >> b >> c;
	 	d[a][b] = c;
	 	d[b][a] = c;
	 	g[a].push_back(b);
	 	g[b].push_back(a);
	}
	dfs(p,0);
	s.clear();
	dfs1(p,0);
	cout << ans <<endl;
	reverse(pr.begin(),pr.end());
	for(auto it : pr)
		cout << it << " ";
}
