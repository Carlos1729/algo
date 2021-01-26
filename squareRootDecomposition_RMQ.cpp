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

/*
	Problem link : https://www.spoj.com/problems/RMQSQ/
	Youtube video link : https://www.youtube.com/watch?v=o7278rPg_9I
	Dt: 04 May '20
*/
void solve(){
	int n;
	cin >> n;
	int a[n];
	FO(i,0,n)cin >> a[i];
	
	int F[400]; // square-root decomposition array
	int sq = sqrtl(n);
	int blocks = n/sq;
	
	for(int i=0;i<blocks;i++){
		F[i] = LLONG_MAX;
		int start = sq*i;
		for(int j = 0;j<sq;j++){
			if(start+j < n){
				F[i] = min(F[i], a[start+j]);
			}else break;
		}
	}
	
	int q;
	cin >> q;
	int l,r;
	while(q--){
		cin >> l >> r;
		
		int LB = l/sq;
		int RB = r/sq;
		//cout << LB << " " << RB << endl;
		///*
		int ans = LLONG_MAX;
		if(LB == RB){
			for(int i = l;i <= r;i++){
				ans = min(ans, a[i]);
			}
		}else{
			for(int i=l;i<sq*(LB+1);i++){
				ans = min(ans, a[i]);
			}
			
			for(int i = LB+1;i < RB;i++){
				ans = min(ans, F[i]);
			}
			
			for(int i = sq*(RB); i<=r;i++){
				ans = min(ans, a[i]);
			}
		}
		cout << ans << endl;
		//*/
	}
	
}
/* When you have to multiply many things , do it in different (multiple) lines, not in a single line .*/
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

