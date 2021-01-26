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
bool cmp(PI p1,PI p2){
	if(p1.ff < p2.ff)return true;	// You should not be writing p1.ss <= p2.ss !!!
	else if(p1.ff == p2.ff){ if(p1.ss < p2.ss)return true; return false; }
	return false;
}
/*		1. Take all the inputs
		4. Whenever you do multiplication and division in the same line, beware.
*/

#define inf 5000003
bitset<inf> pr;
vector<int> divisor(inf+1,1);		// divisor[j] have biggest prime divisor of j.
vector<int> factor(inf+1,0);		// factor[j] has the no of prime factor of j i.e., 12 has 2,2,3 --> 3, so factor[12] = 3;
vector<int> sumoffactor(inf+1,0);	// This is used only when there need for no. of. factors of n! --> n factorial , which is sum of all factor[k] where 1<= k <= n.

void seive(){
	pr[0] = pr[1] = 1;
	for(int i = 2; i*i <= inf; ++i){
		if(!pr[i]){
			for(int j = 2*i;j <= inf; j += i){
				pr[j] = i;
				divisor[j] = i;		// divisor[j] have biggest prime divisor of j.
				
			}
		}
	}
	
}

void counting(){
	for(int i=2;i <= inf;++i){
		if(!pr[i]){
			factor[i] = 1;
		
		}else{
			factor[i] = factor[i/divisor[i]] + 1;
			//cout << "factor["<< i <<"] is " << factor[i] << endl;
		}
		sumoffactor[i] = sumoffactor[i-1] + factor[i];
	}
	//FO(j,0,inf+1)cout << "divisor["<<j<<"] is " << divisor[j] << " " << "factor["<<j<<"] is " << factor[j] << " " << "sumoffactor["<<j<<"] is " << sumoffactor[j] << endl;
}

void solve(){
	// int main  or  int32_t main ...
	int a,b;
	cin >> a >> b;
	cout << sumoffactor[a] - sumoffactor[b] << endl;
}
/*	memset() can be used to set all values as 0 or -1 for integer data types.*/

int32_t main(){
	IO;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif // ONLINE_JUDGE
	// std::cout << std::setprecision(15); std::cout << std::fixed;
	int t; t = 1;
	seive();
	counting();
	cin >> t;
	while(t--){ solve(); }
	return 0;
}

