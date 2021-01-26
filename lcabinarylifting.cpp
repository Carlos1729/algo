#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long 
#define PI pair<int , int >
#define mpr make_pair
#define ff first
#define ss second
#define endl "\n"
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define FO(i,a,b) for(int i = (int)a;i < (int)b;++i)
#define FE(i,a,b) for(int i = (int)a;i <= (int)b;++i)
const int MOD = 1e9+7;
const int mxN = 2e5+3;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};

/*
	similar question : https://www.codechef.com/LRNDSA08/problems/ENOC1
	* slight modifications are required in dfs1 function and while answering queries.
*/

vector<int> g[mxN];
const int mxL = log2(mxN);
int up[mxN][mxL+1];
int level[mxN];

int n;
int v[mxN];
int sum[mxN]; // or something else depending on the ques, xr[mxN];

void dfs(int u, int p){
	up[u][0] = p;
	for(auto ii : g[u]){
		if(ii != p){
			level[ii] = level[u] + 1;
			dfs(ii,u);
		}
	}
}

void dfs1(int u, int p, int vl){
	sum[u] = vl + v[u];
	for(auto ii : g[u]){
		if(ii != p){
			dfs1(ii , u, sum[u]);
		}
	}
}

void init(){
	for(int j = 1; j<= mxL; ++j){
		for(int i = 1; i<=n; ++i){
			if(up[i][j-1] != -1){
				int par = up[i][j-1];
				up[i][j] = up[par][j-1]; 		// (2^j) parent of i;
			}
		}
	}
}

int lca(int a, int b){
	if(level[a] > level[b])swap(a,b);
	int d = level[b] - level[a];
	
	while(d > 0){
		int i = log2(d);
		b = up[b][i];
		d -= (1 << i);
	}
	
	if(a == b)return a;
	
	for(int i = mxL; i>=0; --i){
		if(up[a][i] != -1 and (up[a][i] != up[b][i])){
			a = up[a][i];
			b = up[b][i];
		}
	}
	return up[a][0];
}

void solve(){
	memset(up,-1,sizeof up);
	cin >> n;
	int q;
	cin >> q;
	FE(i,0,n)g[i].clear();
	
	FE(i,1,n)cin >> v[i];
	int u,w;
	FO(i,1,n){
		cin >> u >> w;
		g[u].pb(w);
		g[w].pb(u);
	}
	
	level[1] = 0;
	dfs(1,-1);
	dfs1(1,-1,0);
	init();
	
	while(q--){
		cin >> u >> w;
		int lc = lca(u,w);
		int ans = sum[u] + sum[w] - (2*sum[lc]) + v[lc];
		cout << ans << endl;
	}
}

int32_t main(){
	IO;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif // ONLINE_JUDGE
	// std::cout << std::setprecision(15); std::cout << std::fixed;
	int nT = 1;
	cin >> nT;
	FE(i,1,nT)
		solve();
	return 0;
}
