#include<bits/stdc++.h>
using namespace std;

const int N = 5e3+3;
char a[N][N];
int n,len;
set<pair<int,int>> s;
string comp;
int ans;
int dx[] = {1,0,-1,0,1,1,-1,-1};
int dy[] = {0,-1,0,1,-1,1,1,-1};

bool check(int x, int y)
{
 	if(x >= 0 and x < n and y >=0  and y < n)
 		return true;
 	return false;
}

void dfs(int x, int y, int state)
{
	if(state == len-1)
		ans++;
	s.insert({x,y}); 	
	for(int i = 0; i < 8; i++)
	{
	 	int nx = x+dx[i];
	 	int ny = y+dy[i];
	 	if(check(nx,ny) and a[nx][ny] == comp[state+1] and (s.find({nx,ny}) == s.end()))
	 	{
	 		dfs(nx,ny,state+1);			 		
	 	}
	}
	s.erase({x,y});
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> a[i][j];
	cin >> len >> comp;
	for(int i = 0; i < n; i++)
	{
	    for(int j = 0; j < n; j++)
	    {
	     	if(a[i][j] == comp[0])
	     		dfs(i,j,0);
	    }
	}
	cout << ans <<endl;	
}
