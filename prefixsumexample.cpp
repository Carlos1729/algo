#include<bits/stdc++.h>
/*	#include <boost/math/common_factor.hpp>  boost::math::lcm(10,20) ---> use it to find lcm.*/
using namespace std;
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
//typedef long long ll;
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
bool cmp(PI p1,PI p2){
	if(p1.ff < p2.ff)return true;	// You should not be writing p1.ss <= p2.ss !!!
	else if(p1.ff == p2.ff){ if(p1.ss < p2.ss)return true; return false; }
	return false;
}
/*		1. Take all the inputs
		4. Whenever you do multiplication and division in the same line, beware.
*/
void solve(){
	// int main  or  int32_t main ...
	int n;
	cin >> n;
	int a[n];
	FO(i,0,n)cin >> a[i];
	int sum[n+1];
	sum[0] = 0;
	FO(i,1,n+1){
		sum[i] = sum[i-1] + a[i-1];
	}
	map<int,int> mp;
	
	int ans = 0;
	int minR = 0;
	mp[0] = 0;		// this is extra 0 , added in front of array a[] ... which is already part of sum[]
	for(int j=1;j<=n;j++){			// go through all the elements of sum array
		if(mp.find(sum[j]) != mp.end()){		// if already present in map
			minR = max(minR,mp[sum[j]]+1);				// change minR value
			/*
			 * The Reason for writing max above is the following test case:
			 * 4
			 * 1 1 0 -1
			 * Correct Answer : 4
			 * Answer when max() is not used : 7
			 */
			
			//	minR = mp[sum[j] + 1];
		}
		ans += (j - minR);
		
		mp[sum[j]] = j;				// update with the recent value
	}
	cout << ans << endl;
}
/*	memset() can be used to set all values as 0 or -1 for integer data types.*/

int32_t main(){
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

