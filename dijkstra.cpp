#include<bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long ll;
#define PI pair<int , int >
#define mpr make_pair
#define ff first
#define ss second
#define endl "\n"
#define pb push_back
const int MOD = 1e9+7;
const int MAXN = 1e5+3;
const int inf = 1e9;

/************ Use when precision need to set to some value **************/
// std::cout << std::setprecision(12);
// std::cout << std::fixed;
/*******************************************/
int max(int a,int b){
	if(a > b)return a;
	else return b;
}

int min(int a, int b){
	if(a < b)return a;
	else return b;
}
/*
		Take all the inputs............................................
*/

vector<PI > v[MAXN];
int dist[MAXN];
bool vis[MAXN];

void dijkstra(){		// 1-based indexing.
	memset(vis, false, sizeof vis);
	// memset(dist, 100000000, sizeof dist);
	
	dist[1] = 0;
	multiset<PI > s;	// multiset do the job as a min-priority queue.
	s.insert(mpr(0,1));
	PI p;
	while(!s.empty()){
		
		// unique way of using begin().....
		p = *s.begin();	
		s.erase(s.begin());
		int x = p.ss;
		int wei = p.ff;
		if(vis[x] == true)
			continue;
		vis[x] = true;
		
		for(int i=0;i<v[x].size();i++){
			
		/*
			The pair in vector v is of the form (other vertex, weight).
		*/
			int e = v[x][i].ff;
			int w = v[x][i].ss;
			
			if((dist[x]+w) < dist[e]){
				
				dist[e] = (dist[x]+w);
				/*
				Insert this adjacent vertex with its updated weight.
				*/
				s.insert(mpr(dist[e],e));
				
			}
		}	
	}
}

void solve(){
	int n,m;
	cin >> n >> m;
	int x,y,weight;
	for(int i=0;i<m;i++){
		cin >> x >> y >> weight;
		
		v[x].pb(mpr(y,weight));
		v[y].pb(mpr(x,weight));
	}
	/*
		source vertex is 1 here.
	*/

	for(int k=0;k<(n+2);k++){
		dist[k] = inf;
	}
	dijkstra();	
	for(int j=2;j<=n;j++){
		cout << dist[j] << " ";
	}
}

int main(){
	IO;

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#endif // ONLINE_JUDGE

	int t;
	// cin >> t;
	t = 1;
	while(t--){
		solve();
	}
	return 0;
}
