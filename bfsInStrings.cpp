/*
 * Codeforces 653 B -- Bfs used in processing strings , constructive algorithms question.
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
	if(p1.ff < p2.ff)return true;	// You should not be writing p1.ss <= p2.ss !!!
	else if(p1.ff == p2.ff){ if(p1.ss < p2.ss)return true; return false; }
	return false;
}
/*		1. Take all the inputs
		4. Whenever you do multiplication and division in the same line, beware.
*/
void solve(){
	// int main  or  int32_t main ...
	int n,q;
	cin >> n >> q;
	pair<string , char > cp[q];
	FO(i,0,q){
		cin >> cp[i].ff >> cp[i].ss;
	}
	int ans = 0;
	string fin = "a";
	queue<string> qu;
	qu.push(fin);
	
	while(!qu.empty()){
		string tp = qu.front();
		qu.pop();
		// check the first character of tp with all characters(second) of cp
		FO(i,0,q){
			if(tp[0] == cp[i].ss){
				string tmp = cp[i].ff;
				for(int j=1;j<(int)tp.length();++j){
					tmp.pb(tp[j]);
				}
				qu.push(tmp);
			}
		}
		// Now that we have pushed lots of new strings , check whether we have any string of length n
		// if so , remove it... increament answer.
		while((int)qu.front().length() == n){
			ans++;
			qu.pop();
		}
	}
	cout << ans << endl;
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

