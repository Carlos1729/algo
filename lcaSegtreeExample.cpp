#include<bits/stdc++.h>
/*	#include <boost/math/common_factor.hpp>  boost::math::lcm(10,20) ---> use it to find lcm. fill_n(&an[0][0],n*m,0); typedef long long ll;*/
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
const int MAXN = 1e5+3;
const int inf = 2e9;
int max(int a,int b){	if(a > b)return a; else return b; }
int min(int a, int b){	if(a < b)return a; else return b; }
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
bool cmp(PI p1,PI p2){
	if(p1.ff < p2.ff)return true;	// You should not be writing p1.ss <= p2.ss !!!
	else if(p1.ff == p2.ff){ if(p1.ss < p2.ss)return true; return false; }
	return false;
}

/*
	Codechef : https://www.codechef.com/COW42020/problems/COW3D
	Date : 04-29-2020.
*/

struct LCA{
	vector<int> height, euler, firstOcc, segtree;
	vector<bool> visited;
	int n;
	
	LCA(vector<int> *adj, int N, int root = 0){	// beware !!! root can be 1 in most of the cases.
		n = N;
		height.resize(n);
		firstOcc.resize(n);
		euler.resize(n * 2);
		visited.assign(n , false);
		dfs(adj, root);
		int m = euler.size(); // n*2 
		segtree.resize(m*4);	// this segtree is for euler array
		build(1,0,m-1); 		// root of segtree is 1, as always.
	}
	
	void dfs(vector<int> *adj, int node, int h = 0){
		visited[node] = true;
		height[node] = h;
		firstOcc[node] = euler.size();
		euler.push_back(node);
		for(auto to : adj[node]){
			if(!visited[to]){
				dfs(adj, to, h+1);
				euler.push_back(node);			// this is newly added thing in dfs, to get the euler path.
			}
		}
	}
	
	void build(int node, int tl, int tr){
		if(tl == tr){
			segtree[node] = euler[tl];
		}else{
			int mid = (tl+tr)/2;
			build(node<<1,tl,mid);
			build(node<<1 | 1,mid+1,tr);
			int l = segtree[node<<1] ;
			int r = segtree[node<<1 | 1];
			segtree[node] = (height[l] < height[r]) ? l : r;
		}
	}
	
	int query(int node, int tl, int tr, int L, int R){
		if(tl > R or tr < L)return -1;
		if(tl>=L and tr<=R)return segtree[node];
		
		int mid = (tl+tr) >> 1;
		
		int left = query(node<<1 , tl, mid, L , R);
		int right = query(node<<1 | 1, mid+1,tr,L,R);
		if(left == -1)return right;
		if(right == -1)return left;
		return (height[left] < height[right]) ? left : right;
	}
		
	int lca(int u,int v){
		int left = firstOcc[u], right = firstOcc[v];
		if(left > right)swap(left,right);
		return query(1,0,euler.size()-1,left,right);
	}
};

void solve(){
	int n;
	cin >> n;
	int qe;
	cin >> qe;
	
	vector<int> adj[n+1];
	int u,v;
	FO(i,1,n){
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	LCA sl(adj,n+1,1);
	int k;
	while(qe--){
		cin >> k;
		int b[k];
		set<int> st;
		FO(i,0,k){
			cin >> b[i];
			st.insert(b[i]);
		}
		if(k == 1){
			cout << b[0] << endl;
			continue;
		}
		
		int ans = sl.lca(b[0],b[1]);
		
		FO(i,2,k){
			ans = sl.lca(ans,b[i]);
		}
		
		if(st.find(ans) != st.end()){
			cout << ans << endl;
		}else cout << -1 << endl;
		
	}
}
/* When you have to multiply many things , do it in different (multiple) lines, not in a single line .*/
int32_t main(){
	IO;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif // ONLINE_JUDGE
	// std::cout << std::setprecision(15); std::cout << std::fixed;
	int t; t = 1;
	//cin >> t;
	FE(i,1,t)
		solve();
	return 0;
}

