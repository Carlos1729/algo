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

template<class T>
void merge(vector<T> &v,int p,int q,int r){
	int size1 = q-p+1;
	int size2 = r-q;
	vector<T> L(size1);
	vector<T> R(size2);
	FO(i,0,size1) L[i] = v[p+i];
	FO(i,0,size2) R[i] = v[i+q+1];
	
	int i=0,j=0;
	int k = p;		// starting point of L
	while(i<size1 && j<size2){
		if(L[i] <= R[j]){
			v[k] = L[i];
			i++,k++;
		}else{
			v[k] = R[j];
			k++,j++;
		}
	}
	while(i<size1){
		v[k] = L[i];
		k++,i++;
	}
	while(j<size2){
		v[k] = R[j];
		k++,j++;
	}
}

template<class T>
void merge_sort(vector<T> &v,int p,int r){
	if(p < r){
		int q = (p+r)/2;
		merge_sort(v,p,q);
		merge_sort(v,q+1,r);
		merge(v,p,q,r);
	}
}

void solve(){
	
}

int32_t main(){
	IO;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif // ONLINE_JUDGE
	// std::cout << std::setprecision(15); std::cout << std::fixed;
	int t; t = 1;
	// cin >> t;
	FE(i,1,t)
		solve();
	return 0;
}

