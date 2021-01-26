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
const double EPS = 1e-9;

vector<int> g[mxN];
int in[mxN], out[mxN];

void dfs1(int u, int p){
	for(int i : g[u]){
		if(i != p){
			dfs1(i, u);
			in[u] = max(in[u], 1ll + in[i]);
		}
	}
}

void dfs2(int u, int p){
	int mx1 = -1, mx2 = -1;
	for(int i : g[u]){
		if(i != p){
			if(in[i] >= mx1){
				mx2 = mx1;
				mx1 = in[i];
			}else if(in[i] > mx2)mx2 = in[i];
		}
	}
	
	for(int i : g[u]){
		if(i != p){
			int use = mx1;
			if(in[i] == mx1)use = mx2;
			out[i] = max(1ll + out[u], 2ll + use);
			dfs2(i, u);
		}
	}
}

void solve(){
	int n;
	cin >> n;
	int u, v;
	for(int i = 1; i < n; ++i){
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs1(1, 0);
	dfs2(1, 0);
	for(int i = 1; i <= n; ++i)cout << max(in[i], out[i]) << " ";
	cout << endl;
}

int32_t main(){
	IO;
	
	int nT = 1;
	//cin >> nT;
	for(int i = 1; i <= nT; ++i)
		solve();
	return 0;
}
