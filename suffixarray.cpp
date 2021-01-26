#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long 
#define endl "\n"
#define all(x) (x).begin(),(x).end()
const int MOD = 1e9+7;
const int mxN = 2e5+3;

void solve(){
	string s;
	cin >> s;
	s += '$';
	int n = (int)s.size();
	vector<int> p(n), c(n);
	//  p will contain orderings of the strings
	//  c will contain equivalent classes
	
	// k = 0;
	vector<pair<char, int>> a(n);
	for(int i = 0; i < n; ++i){
		a[i] = make_pair(s[i], i);
	}
	sort(a.begin(), a.end());
	
	// Now from this array , we create the initial array P
	for(int i = 0; i < n; ++i)p[i] = a[i].second;
	
	// Now from the P array, we can create the initial array C
	c[p[0]] = 0;
	for(int i = 1; i < n; ++i){
		if(a[i].first == a[i-1].first){
			c[p[i]] = c[p[i - 1]];
		}else{
			c[p[i]] = c[p[i-1]] + 1;
		}
	}
	
	// now we are ready to make the transitions
	int k = 0;
	while((1 << k) < n){
		// k -> (k + 1)
		vector<pair<pair<int, int> , int>> v(n);
		for(int i = 0; i < n; ++i){
			v[i] = make_pair(make_pair(c[i], c[(i + (1 << k)) %n]), i);
		}
		// above left part -> a pair which contais the equivalence classes of left half and right half of the current string
		// right part -> an integer to store the STARTING index of that particular string which we will lose once once the vector is sorted , if it is not stored
		
		sort(v.begin(), v.end());
		
		// once the vector is sorted , we can make our P array , which will have the order of suffixes
		for(int i = 0; i < n; ++i)p[i] = v[i].second;
		
		// now make the equi classes array C for the next iteration
		
		c[p[0]] = 0;
		for(int i = 1; i < n; ++i){
			if(v[i].first == v[i-1].first){				// v[i].first is a pair Here !!!
				c[p[i]] = c[p[i-1]];
			}else{
				c[p[i]] = c[p[i-1]] + 1;
			}
		}
		k++; 			// k increment
	}
	for(int i = 0; i < n; ++i){
		cout << p[i] << " ";
		cout << s.substr(p[i], n - p[i]) << endl;
	}
	cout << endl;
}

int32_t main(){
	IO;
	
	int nT = 1;
	//cin >> nT;
	for(int i = 1; i <= nT; ++i)
		solve();
	return 0;
}
