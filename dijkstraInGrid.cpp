#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long 
#define endl "\n"
#define all(x) (x).begin(),(x).end()
const int MOD = 1e9+7;
const int mxN = 2e5+3;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void solve(){
	int n,m;
	cin >> n >> m;
	int a[n][m];
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			cin >> a[i][j];
	
	vector<vector<int>> dist(n,vector<int>(m,1e9));
	vector<vector<bool>> vis(n,vector<bool>(m,0));
	priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>> ,greater<pair<int, pair<int,int>>>> pq;
	pq.push(make_pair(a[0][0], make_pair(0,0)));
	dist[0][0] = a[0][0];
	
	while(!pq.empty()){
		pair<int, pair<int, int>> tp = pq.top();
		pq.pop();
		
		auto x = tp.second;
		if(vis[x.first][x.second])continue;
		vis[x.first][x.second] = true;
		
		for(int i = 0; i < 4; ++i){
			int u = x.first + dx[i];
			int v = x.second + dy[i];
			
			if(u<0 or u>=n or v<0 or v>=m)continue;
			int wei = a[u][v];
			if(dist[x.first][x.second] + wei < dist[u][v]){
				dist[u][v] = dist[x.first][x.second] + wei;
				pq.push(make_pair(dist[u][v], make_pair(u,v)));
			}
		}
	}
	cout << dist[n-1][m-1] << endl;
}

int32_t main(){
	IO;
	
	int nT = 1;
	cin >> nT;
	for(int i = 1; i <= nT; ++i)
		solve();
	return 0;
}

