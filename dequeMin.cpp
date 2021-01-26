/*
 * Completed.
 * Finding minimum with Deque.
 * CF 1290A 
*/
#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
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
 * Something like window of length of m-k , seems interesting .. So starting with possibility that all k people are 
 * 			asked to take the last one.
 * Finding minimum is to take worst case in to account.****
*/
void solve(){
	int n,m,k;
	cin >> n >> m >> k;
	int a[n];
	FO(i,0,n)cin >> a[i];
	
	k = min(k,m-1);
	
	vector<int> v;
	for(int i=0;i<m;i++){
		v.push_back(max(a[i],a[n-m+i]));
	}
	
	int ans = 0;
	deque<int> qi;
	int i;
	// window of length of m-k
	for(i = 0;i < m-k; ++i){
		while(!qi.empty() and v[i] <= v[qi.back()])
			qi.pop_back();
		qi.push_back(i);
	}
	for(;i<m;i++){
		ans = max( ans , v[qi.front()]);		// k-times
		while(!qi.empty() and qi.front() <= i-(m-k))
			qi.pop_front();
		while(!qi.empty() and v[i] <= v[qi.back()])
			qi.pop_back();
		qi.push_back(i);
	}
	ans = max( ans, v[qi.front()]);		// (k+1)-th time
	/* So, the answer seems to be like the (k+1)-th minimum in the vector v, because I can have control on
	 * only k people */
	cout << ans << endl;
}
/* When you have to multiply many things , do it in different (multiple) lines, not in a single line .*/
int32_t main(){
	IO;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif // ONLINE_JUDGE
	// std::cout << std::setprecision(15); std::cout << std::fixed;
	int nT = 1;
	cin >> nT;
	FE(i,1,nT)
		solve();
	return 0;
}

