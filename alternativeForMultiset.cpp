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

void solve(){
	int n,k;
	cin >> n >> k;
	PI a[n];
	FO(i,0,n){
		cin >> a[i].ss >> a[i].ff;
	}
	// first one is beauty and second one is length. bcz we want to sort based on beauty.
	sort(a,a+n);
	int ans = 0;
	int sum = 0;
	set<PI > st;
	/*
	 * Using a set<int> will not work here bcz two songs can have same length 
	 * Possible Atlernatives: 1. Use multiset 2. Use set< pair<int,int> > and store the index as second value 
						so that those two songs will get distinguished as counted as two , but not as one.
	 * Here we cannot use  ** map<int,int> **  because the size of map is not equal to no. of elements inserted
			but the sum of values of respective keys is equal to no. of. elements inserted.
	*/
	for(int i = n-1; i>=0 ; --i){
		st.insert(mpr(a[i].ss,i));
		sum += a[i].ss;
		if((int)st.size() > k){
			auto it = st.begin();
			sum -= (it->ff);
			st.erase(it);
		}
		ans = max( ans , sum * (a[i].ff));
	}
	cout << ans << endl;
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

