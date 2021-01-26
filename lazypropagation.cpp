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
 * Codeforces problem : https://codeforces.com/contest/295/problem/A 
 */

struct point{
	int li,ri,di;
};

int t[4*mxN], lazy[4*mxN];

void build(int a[], int v, int tl, int tr){
	if(tl == tr){
		t[v] = a[tl];
	}else{
		int tm = (tl + tr)/2;
		build(a, v*2, tl, tm);
		build(a, v*2 + 1, tm + 1, tr);
		t[v] = t[v*2] + t[v*2 + 1];
	}
}
// increments each element in a[i...j] by val (i.e., += val)
void lazyupdate(int v, int tl, int tr, int i, int j, int val){
	if(lazy[v] != 0){
		t[v] += (tr - tl +1) * lazy[v];
		if(tr != tl){
			lazy[2*v] += lazy[v];
			lazy[2*v + 1] += lazy[v];
		}
		lazy[v] = 0;
	}
	
	if(tl > tr  or j < tl or i > tr)return;
	
	if(i <= tl and tr <= j){ 	// current part of seg tree is fully inside the req the region [i...j]
		t[v] += (tr - tl + 1) * val;
		if(tr != tl){
			lazy[2*v] += val;
			lazy[2*v + 1] += val;
		}
		return;
	}
	
	int tm = (tl + tr)/2;
	lazyupdate(v*2, tl, tm, i, j, val);
	lazyupdate(v*2 + 1, tm + 1, tr, i, j, val);
	
	t[v] = t[v*2] + t[2*v + 1];
}
	
int lazyquery(int v, int tl, int tr, int i, int j){
	if(tl > j or i > tr)return 0;
	if(lazy[v] != 0){
		t[v] += (tr - tl + 1) * lazy[v];
		if(tr != tl){
			lazy[2*v] += lazy[v];
			lazy[2*v + 1] += lazy[v];
		}
		lazy[v] = 0;
	}
	if(i <= tl and tr <= j){
		return t[v];
	}
	
	int tm = (tl + tr)/2;
	if(i > tm)return lazyquery(v*2 + 1, tm + 1, tr, i, j);
	else if(j <= tm) return lazyquery(v*2, tl, tm, i, j);
	
	int left = lazyquery(v*2, tl, tm, i, tm);
	int right = lazyquery(v*2 + 1, tm + 1, tr, tm + 1, j);
	
	return left + right;
}

void solve(){
	int n,m,k;
	cin >> n >> m >> k;
	int a[n];
	for(int i = 0; i < n; ++i)cin >> a[i];
	point b[m];
	for(int i = 0; i < m; ++i){
		cin >> b[i].li >> b[i].ri >> b[i].di;
		b[i].li--;
		b[i].ri--;
	}
	vector<int> pref(m+1,0);
	int xi, yi;
	while(k--){
		cin >> xi >> yi;
		xi--;
		pref[xi]++;
		pref[yi]--;
	}
	for(int i = 1; i <= m; ++i){
		pref[i] += pref[i-1];
	}
	for(int i = 0; i < m; ++i){
		b[i].di *= pref[i];
	}
	build(a,1, 0, n -1);
	for(int i = 0; i < m; ++i){
		if(b[i].di != 0)lazyupdate(1,0,n-1,b[i].li,b[i].ri,b[i].di);
	}
	for(int i = 0; i < n; ++i){
		int tt = lazyquery(1,0,n-1, i,i);
		cout << tt << " ";
	}
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
