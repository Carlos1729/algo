/*
	Codeforces - 500B
*/
#include<bits/stdc++.h>
/*	#include <boost/math/common_factor.hpp>  boost::math::lcm(10,20) ---> use it to find lcm.*/
using namespace std;
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long ll;
// #define int long long 
#define PI pair<int , int >
#define mpr make_pair
#define ff first
#define ss second
#define endl "\n"
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define debug() cout << "Hi" << endl	// write debug(); in main()
const int MOD = 1e9+7;
const int MAXN = 1e5+3;
const int inf = 2e9;
int max(int a,int b){	if(a > b)return a; else return b; }
int min(int a, int b){	if(a < b)return a; else return b; }
/*		0. Go to main function first.
		1. Take all the inputs................................................
		2. Check Once whether the graph given is directed or undirected.......
		3. Tree can also be undirected.
		4. Whenever you do multiplication and division in the same line, beware.
*/

int parent[303];

void make_set(int n){
	for(int i = 0;i <= n;++i)parent[i] = i;
}

int find_set(int v){
	if(v == parent[v])return v;
	return parent[v] = find_set(parent[v]);
}

void union_sets(int a,int b){
	a = find_set(a);
	b = find_set(b);
	if(a != b)parent[b] = a;
}

void solve(){
	//debug();
	// int main  or  int32_t main ...
	int n;
	cin >> n;
	int a[n];
	for(int i = 0;i < n;++i){
		cin >> a[i];
		//cout << a[i] << " ";
	}
	//cout << endl;
	make_set(n);
	int ok[n][n] = {0};
	for(int ii = 0;ii < n;++ii){
		string s;cin >> s;
		for(int jj = 0;jj < n;++jj){
			//cin >> ok[ii][jj];
			if(s[jj] == '1')ok[ii][jj] = 1;
			else ok[ii][jj] = 0;
			//cout << ok[ii][jj] << " ";
			if(ok[ii][jj] == 1)union_sets(a[ii],a[jj]);	// merge the p_ii and p_jj , but not ii and jj;
		}
		//cout << endl;
	}
	
	vector< set<int> > comp(n+1);
	for(int j = 0;j < n;++j){
		comp[find_set(a[j])].insert(a[j]);		// pushing a[j] into resp. components
	}
	
	for(int k = 0;k < n;++k){
		auto it = comp[find_set(a[k])].begin();		// least element in the set.
		cout << /*find_set(a[k]) << " " <<*/ *it << " ";
		comp[find_set(a[k])].erase(it);			// erasing the printed element of the set.
	}
	cout << endl;
}
/*	memset() can be used to set all values as 0 or -1 for integer data types.*/

int main(){
	IO;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#endif // ONLINE_JUDGE
	// std::cout << std::setprecision(12); std::cout << std::fixed;
	int t;
	// cin >> t;
	t = 1;
	while(t--){
		solve();
	}
	return 0;
}

