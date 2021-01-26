#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long 
#define endl "\n"
#define all(x) (x).begin(),(x).end()
const int MOD = 1e9+7;
const int mxN = 1e5+3;

/*
 * SPOJ : https://www.spoj.com/problems/MULTQ3/
 */

void swap(int* a, int* b, int* c){
	int tmp = *c;
	*c = *b;
	*b = *a;
	*a = tmp;
} 

int t[4*mxN][3], lazy[4*mxN];

void build(int v, int tl, int tr){
	if(tl == tr){
		t[v][0] = 1;
	}else{
		int tm = (tl + tr)/2;
		build(v*2, tl, tm);
		build(v*2 + 1, tm + 1, tr);
		t[v][0] = t[v*2][0] + t[v*2 + 1][0];
	}
}

void lazyupdate(int v, int tl, int tr, int i, int j){
	lazy[v] %= 3;
	if(lazy[v] >= 1){
		swap(&t[v][0], &t[v][1], &t[v][2]);
		if(lazy[v] == 2)swap(&t[v][0], &t[v][1], &t[v][2]);
		if(tl != tr){
			lazy[v*2] += lazy[v];
			lazy[v*2 + 1] += lazy[v];
			lazy[v*2] %= 3;
			lazy[v*2 + 1] %= 3;
		}
		lazy[v] = 0;
	}
	
	if(tl > tr or j < tl or i > tr)return;
	if(i <= tl and tr <= j){
		swap(&t[v][0], &t[v][1], &t[v][2]);
		if(tr != tl){
			lazy[v*2]++;
			lazy[v*2 + 1]++;
			lazy[v*2] %= 3;
			lazy[v*2 + 1] %= 3;
		}
		return;
	}
	
	int tm = (tl + tr)/2;
	lazyupdate(v*2, tl, tm, i, j);
	lazyupdate(v*2 + 1, tm + 1, tr, i, j);
	
	t[v][0] = t[v*2][0] + t[v*2 + 1][0];
	t[v][1] = t[v*2][1] + t[v*2 + 1][1];
	t[v][2] = t[v*2][2] + t[v*2 + 1][2];
}

int lazyquery(int v, int tl, int tr, int i, int j){
	if(tl > j or i > tr)return 0;
	lazy[v] %= 3;
	if(lazy[v] >= 1){
		swap(&t[v][0], &t[v][1], &t[v][2]);
		if(lazy[v] == 2)swap(&t[v][0], &t[v][1], &t[v][2]);
		if(tl != tr){
			lazy[v*2] += lazy[v];
			lazy[v*2 + 1] += lazy[v];
			lazy[v*2] %= 3;
			lazy[v*2 + 1] %= 3;
		}
		lazy[v] = 0;
	}
	
	if(i <= tl and tr <= j)return t[v][0];
	
	int tm = (tl + tr)/2;
	if(i > tm)return lazyquery(v*2 + 1, tm + 1, tr, i, j);
	else if(j <= tm)return lazyquery(v*2, tl, tm, i, j);
	
	int left = lazyquery(v*2, tl, tm, i, tm);
	int right = lazyquery(v*2 + 1, tm + 1, tr, tm + 1, j);
	
	return left + right;
}
	
void solve(){
	int n,q;
	cin >> n >> q;
	build(1, 0, n - 1);
	int type, a, b;
	while(q--){
		cin >> type >> a >> b;
		if(type == 0){
			lazyupdate(1, 0, n - 1, a, b);
		}else{
			int tt = lazyquery(1, 0, n - 1, a, b);
			cout << tt << endl;
		}
	}
}

int32_t main(){
	IO;
	
	int nT = 1;
	//cin >> nT;
	for(int i = 1; i <= nT; ++i)
		solve();
	return 0;
}

