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
const int MAXN = 1e5+3;
const int inf = 2e9;
int max(int a,int b){	if(a > b)return a; else return b; }
int min(int a, int b){	if(a < b)return a; else return b; }
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};

int n,t[4*MAXN];		// root is at index '1', n is input array size , t[] is segment tree.

/* one common thing is while calling all these fuctions from main() put v= 1, tl = 0, tr = n-1. */

void build(int a[], int v, int tl, int tr){		// a is input array, v is index of current vertex(in seg tree), tl,tr -> boundaries of current segment.  
	if(tl == tr){
		t[v] = a[tl];
	}else{
		int tm = (tl+tr)/2;
		build(a,v*2,tl,tm);
		build(a,v*2+1,tm+1,tr);
		t[v] = t[2*v] + t[2*v+1];
	}
}

int sum(int v, int tl, int tr, int l, int r){		// l and r are query boundaries ( mostly 0-based indices only)
	if(l > r)return 0;
	if(l == tl and r == tr)return t[v];
	
	int tm = (tl+tr)/2;
	return sum(v*2,tl,tm,l,min(tm,r)) + sum(v*2+1,tm+1,tr,max(tm+1,l),r);
}

// a[pos] = new_val ...... here pos is mostly (almost) 0-indexed only because a[] itself is 0-indexed.
void update(int v, int tl, int tr, int pos, int new_val){
	if(tl == tr){
		t[v] = new_val;
	}else{
		int tm = (tl+tr)/2;
		if(pos <= tm)update(v*2, tl, tm,pos,new_val);
		else update(v*2+1,tm+1,tr,pos,new_val);
		
		t[v] = t[v*2] + t[v*2+1] ;
	}
}

void solve(){
	
}

int32_t main(){
	IO;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif // ONLINE_JUDGE
	// std::cout << std::setprecision(15); std::cout << std::fixed;
	int nT = 1;
	// cin >> nT;
	FE(i,1,nT)
		solve();
	return 0;
}

