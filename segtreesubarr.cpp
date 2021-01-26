/*
 * SPOJ : https://www.spoj.com/problems/GSS1/
 * Not Yet Completed , Doubt : when ans is neg. whether '0' has to be printed or that neg value has to be printed.
*/
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
const int MAXN = 2e5+3;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
#define print(x) cerr << #x << " is " << x << endl;
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
bool cmp(PI p1,PI p2){
	if(p1.ff < p2.ff)return true;	// You should not be writing p1.ss <= p2.ss !!!
	else if(p1.ff == p2.ff){ if(p1.ss < p2.ss)return true; return false; }
	return false;
}



/* one common thing is while calling all these fuctions from main() put v= 1, tl = 0, tr = n-1. */

struct data{
	int sum, pref, suff, ans;
};
typedef struct data Data;
int n;
Data t[4*MAXN];

Data combine(Data l, Data r){
	Data res;
	res.sum = l.sum + r.sum;
	res.pref = max(l.pref , l.sum + r.pref);
	res.suff = max(r.suff, l.suff + r.sum);
	res.ans = max( max(l.ans, r.ans) , l.suff + r.pref);
	
	return res;
}

Data make_data(int val){
	Data res;
	res.sum = val;
	res.pref = res.suff = res.ans = val;
	return res;
}

void build(int a[], int v, int tl, int tr){
	if(tl == tr){
		t[v] = make_data(a[tl]);
	}else{
		int tm = (tr + tl)/2;
		build(a,v*2,tl, tm);
		build(a,v*2 + 1,tm + 1,tr);
		t[v] = combine(t[v*2] , t[v*2 + 1]);
	}
}

void update(int v, int tl, int tr, int pos, int new_val){
	if(tl == tr){
		t[v] = make_data(new_val);
	}else {
		int tm = (tl + tr)/2;
		if(pos <= tm)update(v*2, tl, tm,pos, new_val);
		else update(v*2 +1,tm+1 ,tr,pos,new_val);
		
		t[v] = combine(t[v*2] , t[v*2 + 1]);
	}
}


Data query(int v, int tl, int tr, int l, int r){
	if(l > r)return make_data(0);
	
	if(l==tl and r==tr)return t[v];
	int tm = (tl + tr)/2;
	return combine(query(v*2, tl, tm,l, min(r,tm)) , query(v*2 + 1, tm+1,tr, max(l,tm+1),r));
}

void solve(){
	cin >> n;		// n is global variable.
	int a[n];
	FO(i,0,n)cin >> a[i];
	build(a,1,0,n-1);
	int q;
	cin >> q;
	int x,y;
	while(q--){
		cin >> x >> y;
		//cout << x << y << endl;
		x--,y--;
		Data fin = query(1,0,n-1,x,y);
		cout << fin.ans << endl;//" " << fin.sum << " " << fin.pref << " " << fin.suff << endl;
	}
}

int32_t main(){
	IO;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif // ONLINE_JUDGE
	// std::cout << std::setprecision(15); std::cout << std::fixed;
	int nT = 1;
	//cin >> nT;
	FE(i,1,nT)
		solve();
	return 0;
}
