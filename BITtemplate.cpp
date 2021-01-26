//		0 - indexing
//		Finding sum in one-dimensional array
struct FenwickTree{
	vector<int> bit;
	int n;

	FenwickTree(int num){
		this->n = num;
		bit.assign(num,0);
	}
	
	FenwickTree(vector<int> a) : FenwickTree(a.size()){
		for(size_t i = 0;i < a.size();++i)
			add(i,a[i]);
	}
	
	int sum(int r){
		int ret = 0;
		for(;r >= 0; r = (r & (r+1)) - 1)
			ret += bit[r];
		return ret;
	}
	
	int sum(int l, int r){
		return sum(r) - sum(l-1);
	}
	
	void add(int idx, int delta){
		for(;idx < n;idx = idx | (idx+1))
			bit[idx] += delta;
	}
};

// 		1 - indexing
// 		Finding sum in one-dimensional array
struct FenwickTreeOne{
	vector<int> bit;
	int n;
	
	FenwickTreeOne(int num){
		this->n = num+1;
		bit.assign(num+1,0);
	}
	
	FenwickTreeOne(vector<int> a) : FenwickTreeOne(a.size()){
		for(size_t i = 0;i < a.size();++i){
			add(i,a[i]);
		}
	}
	
	int sum(int idx){
		int ret = 0;
		for(++idx;idx > 0;idx -= idx & -idx)
			ret += bit[idx];
			
		return ret;
	}
	
	int sum(int l, int r){
		return sum(r) - sum(l-1);
	}
	
	void add(int idx, int delta){
		for(++idx;idx < n;idx += idx & -idx)
			bit[idx] += delta;
	}
	
	/* For Range Update and Point Query */
/* This function is for updating the range by 'val' but not for updating each number in the range.*/	
	void range_add(int l, int r, int val){
		add(l,val);
		add(r+1, -val);
	}
/*
* If you wish to increment a particular value the call range_add(i,i,val) ..
*/
/* point_query is giving the prefix sum i.e., sum of all values of a[] until the and including idx */	
	int point_query(int idx){
		int ret = 0;
		for(++idx;idx > 0;idx -= idx & -idx)
			ret += bit[idx];
		
		return ret;
	}
};
