/*
	Implementing dijkstra's using flood fill --> Hackerearth practice problem 'Grid'
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
/*		1. Take all the inputs
		4. Whenever you do multiplication and division in the same line, beware.
*/

char a[1003][1003];
bool vis[1003][1003];
int dis[1003][1003];
int sx,sy;

void dijkstra(int n,int m){
	memset(vis,false,sizeof vis);
	FO(i,0,1003){
		FO(j,0,1003){
			dis[i][j] = 1e9;
		}
	}
	priority_queue<pair<int,PI > , vector<pair<int,PI > > , greater<pair<int,PI > > >pq;
	pq.push(mpr(0,mpr(sx,sy)));
	dis[sx][sy] = 0;
	//vis[sx][sy] = true;
	while(!pq.empty()){
		pair<int,PI > tp = pq.top();
		pq.pop();
		
		if(vis[tp.ss.ff][tp.ss.ss] == true)continue;
		vis[tp.ss.ff][tp.ss.ss] = true;
		//int wei = tp.ff;
		
		FO(i,0,4){
			int u = tp.ss.ff + dx[i];
			int v = tp.ss.ss + dy[i];
			if(u<0 || u>=n || v<0 || v>=m)continue;
			if(a[u][v] == 'O'){
				if(dis[u][v] > dis[tp.ss.ff][tp.ss.ss] + 1){
					dis[u][v] = dis[tp.ss.ff][tp.ss.ss] + 1;
					pq.push(mpr(dis[u][v],mpr(u,v)));
				}
			}
		}
	}
}

void solve(){
	// int main  or  int32_t main ...
	int n,m,q;
	cin >> n >> m >> q;
	string s;
	
	FO(i,0,n){
		cin >> s;
		FO(j,0,m){
			a[i][j] = s[j];
			//cout << a[i][j];
		}
		//cout << endl;
	}
	cin >> sx >> sy;
	sx--;sy--;	// 0-indexing.
	dijkstra(n,m);
	int fx,fy;
	while(q--){
		cin >> fx >> fy;
		fx--;fy--;
		if(dis[fx][fy] == 1e9)cout << -1 << endl;
		else cout << dis[fx][fy] << endl;
	}
}
/*	memset() can be used to set all values as 0 or -1 for integer data types.*/

int main(){
	IO;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif // ONLINE_JUDGE
	// std::cout << std::setprecision(15); std::cout << std::fixed;
	int t; t = 1;
	// cin >> t;
	while(t--){ solve(); }
	return 0;
}

