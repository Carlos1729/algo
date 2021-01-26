#include<bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long 
#define endl "\n"
#define all(x) (x).begin(),(x).end()
const int MOD = 1e9+7;
const int mxN = 2e5+3;

void radix_sort(vector<pair<pair<int,int> , int>> &v){
	int n = (int)v.size();
	//cout << n << endl;
	vector<int> cnt1(n,0);
	for(int i = 0; i < n; ++i){
		//cout << v[i].first.second << endl;
		cnt1[v[i].first.second]++;
	}
	vector<pair< pair<int,int> ,int> > tmp(n);
	//wonderful trick is coming below
	vector<int> pos(n);
	pos[0] = 0;
	for(int i = 1; i < n; ++i){
		pos[i] = pos[i-1] + cnt1[i - 1];
	}
	for(auto x : v){
		int i = x.first.second;
		tmp[pos[i]] = x;
		pos[i]++;
	}
	// here pos is like a use-and-throw array, the value in pos array are useless after the 'tmp' vector is filled
	
	vector<int> cnt2(n,0);
	for(int i = 0; i < n; ++i)cnt2[tmp[i].first.first]++;
	
	vector<int> pos2(n);
	pos2[0] = 0;
	for(int i = 1; i < n; ++i)pos2[i] = pos2[i - 1] + cnt2[i - 1];
	for(auto x : tmp){
		int i = x.first.first;
		v[pos2[i]] = x;
		pos2[i]++;
	}
	
}

bool isSubstring(vector<string> tp, string pat){
	int n = (int)tp.size();
	int i = 0, j = n - 1;
	while(i <= j){
		int md = (i + j)/2;
		if(tp[md] == pat)return true;
		if(tp[md] < pat)i = md + 1;
		else j = md - 1;
	}
	return false;
}

void solve(){
	string s;
	cin >> s;
	s += '$';
	int n = (int)s.length();
	vector<int> p(n), c(n);
	// p -> ordering of the strings, permutation
	// c -> equivalent class , a number may occur many times
	
	// k = 0;
	vector<pair<char, int> > a(n);
	for(int i = 0; i < n; ++i)a[i] = make_pair(s[i], i);
	sort(a.begin(), a.end());
	// Now we are ready to make our first p and c arrays
	for(int i = 0; i < n; ++i)p[i] = a[i].second;
	
	c[p[0]] = 0;
	for(int i = 1; i < n; ++i){
		if(a[i].first == a[i-1].first)c[p[i]] = c[p[i-1]];
		else c[p[i]] = c[p[i-1]] + 1;
	}
	
	int k = 0;
	while((1 << k) < n){
		vector<pair<pair<int, int>, int> > v(n);
		for(int i = 0; i < n; ++i)v[i] = make_pair(make_pair(c[i], c[(i + (1 << k)) %n]) , i);
		
		//sort(v.begin(), v.end());
		radix_sort(v);
		
		// now p 
		for(int i = 0; i < n; ++i)p[i] = v[i].second;
		// c now
		c[p[0]] = 0;
		for(int i = 1; i < n; ++i){
			if(v[i].first == v[i-1].first)c[p[i]] = c[p[i-1]];
			else c[p[i]] = c[p[i-1]] + 1;
		}
		k++;
	}
	
	//for(int i = 0; i < n; ++i)cout << p[i] << " ";
	//cout << endl;
	string sn = s + s;
	int times;
	cin >> times;
	
	auto binSearch = [n,sn,p](bool flag, int sz, string pat){
		int result = -1;
		int j = 0, en = n - 1;
		while(j <= en){
			int md = (j + en)/2;
			if(sn.substr(p[md], sz) == pat){
				result = md;
				if(flag)en = md - 1;
				else j = md + 1;
			}else if(sn.substr(p[md], sz) > pat)en = md - 1;
			else j = md + 1;
		}
		return result;
	};
	
	for(int i = 0; i < times; ++i){
		string pat;
		cin >> pat;
		int sz = (int)pat.size();
		int lowerInd = binSearch(true,sz, pat);
		if(lowerInd == -1)cout << 0 << endl;
		else{
			int higherInd = binSearch(false, sz, pat);
			int ans = higherInd - lowerInd + 1;
			cout << ans << endl;
		}
	}
}

int32_t main(){
	IO;
	
	int nT = 1;
	//cin >> nT;
	for(int i = 1; i <= nT; ++i)
		solve();
	return 0;
}

