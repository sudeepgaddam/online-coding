class NumArray {
    private:
        vector<int> arr;
        vector<int> tree;
        int size;

public:

/**
 * Build and init tree
 */
void build_tree(int node, int a, int b) {
  	if(a > b) return; // Out of range
  	
  	if(a == b) { // Leaf node
    	tree[node] = arr[a]; // Init value
		return;
	}
	
	build_tree(node*2, a, (a+b)/2); // Init left child
	build_tree(node*2+1, 1+(a+b)/2, b); // Init right child
	
	tree[node] = (tree[node*2] +  tree[node*2+1]); // Init root value


}
/**
 * Query tree to get max element value within range [i, j]
 */
int query_tree(int node, int a, int b, int i, int j) {
	
	if(a > b || a > j || b < i) return 0; // Out of range

	if(a >= i && b <= j) // Current segment is totally within range [i, j]
		return tree[node];

	int q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
	int q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child

	int res = (q1+ q2); // Return final result

	return res;
}

    NumArray(vector<int> &nums) {
        arr = nums;
        size = nums.size();
        cout<<"Size"<<size<<endl;
        tree.resize(3*size+100);
        build_tree(1,0,size-1);
    }
	~NumArray(){
		
	}
    int sumRange(int i, int j) {
        //return 1;
        return query_tree(1,0,size-1,i,j);
    }
};
