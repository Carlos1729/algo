/*
 * Similar to Codejam 2020 Qualification round 3rd problem , but slightly different in handling corner cases. 
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
	if(p1.ss < p2.ss)return true;	// You should not be writing p1.ss <= p2.ss !!!
	else if(p1.ss == p2.ss){ if(p1.ff < p2.ff)return true; return false; }
	return false;
}
/*		1. Take all the inputs
		4. Whenever you do multiplication and division in the same line, beware.
*/
void solve(){
	// int main  or  int32_t main ...
	int n;
	cin >> n;
	PI a[n];
	FO(i,0,n){
		cin >> a[i].ff >> a[i].ss;
	}
	sort(a,a+n,cmp);
	int tv0end = 0;
	int tv1end = 0;
	int recent = 0;
	
	tv0end = a[0].ss;
	bool pr = true;
	FO(i,1,n){
		if(i==1){
			if(a[i].ff > tv0end){
				tv0end = a[i].ss;
			}else{
				recent = 1;
				tv1end = a[i].ss;
			}
			continue;
		}
		if(a[i].ff > tv0end && a[i].ff > tv1end){
			if(recent == 0)tv0end = a[i].ss;
			else tv1end = a[i].ss;
		}else if(a[i].ff > tv0end){
			recent = 0;
			tv0end = a[i].ss;
		}else if(a[i].ff > tv1end){
			recent = 1;
			tv1end = a[i].ss;
		}else{
			pr = false;
			break;
		}
	}
	if(pr)cout << "YES" << endl;
	else cout << "NO" << endl;
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

