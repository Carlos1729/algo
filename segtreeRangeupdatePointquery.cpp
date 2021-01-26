#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int MOD = 1e9 + 7;
const int mxN = 1e5 + 3;

struct point{
	int li,ri,di;
};

int t[4*mxN];

void build(int a[], int v, int tl, int tr){
	if(tl == tr){
		t[v] = a[tl];
	}else{
		int tm = (tl + tr)/2;
		build(a, v*2, tl, tm);
		build(a, v*2 + 1, tm + 1, tr);
		t[v] = 0;
	}
}

void update(int v, int tl, int tr, int l, int r, int add){
	if(l > r)return;
	if(l == tl and r == tr)t[v] += add;
	else{
		int tm = (tl + tr)/2;
		update(v*2, tl, tm, l, min(tm,r), add);
		update(v*2 + 1, tm + 1, tr, max(l,tm + 1), r, add);
	}
}

int query(int v, int tl, int tr, int pos){
	if(tl == tr)return t[v];
	int tm = (tl + tr)/2;
	if(pos <= tm)return t[v] + query(v*2, tl, tm, pos);
	else return t[v] + query(v*2 + 1, tm + 1, tr, pos);
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
		if(b[i].di != 0)update(1,0,n-1,b[i].li,b[i].ri,b[i].di);
	}
	for(int i = 0; i < n; ++i){
		int tt = query(1,0,n-1, i);
		cout << tt << " ";
	}
	cout << endl;
}

int32_t main(){
	int nt = 1;
	//cin >> t;
	for(int i = 1; i <= nt; ++i){
		solve();
	}
	return 0;
}
