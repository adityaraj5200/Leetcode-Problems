class NumArray {
public:
    vector<int> seg_tree;
    int n;
    
    void build(vector<int>& nums,int l,int r,int st_idx){
        if(l==r){
            seg_tree[st_idx] = nums[l];
            return;
        }
        
        int mid = (l+r)>>1;
        build(nums,l,mid,st_idx*2+1);
        build(nums,mid+1,r,st_idx*2+2);
        
        seg_tree[st_idx] = seg_tree[st_idx*2+1] + seg_tree[st_idx*2+2];
    }
    
    NumArray(vector<int>& nums) {
        n = nums.size();
        seg_tree = vector<int>(4*n);
        build(nums,0,n-1,0);
    }
    
    void update(int index,int val,int l,int r,int st_idx){
        if(l==r){
            seg_tree[st_idx] = val;
            return;
        }
        
        int mid = (l+r)>>1;
        if(index<=mid)
            update(index,val,l,mid,st_idx*2+1);
        else
            update(index,val,mid+1,r,st_idx*2+2);
        
        seg_tree[st_idx] = seg_tree[st_idx*2+1] + seg_tree[st_idx*2+2];
    }
    
    int sumRange(int qleft,int qright,int currleft,int currright,int st_idx) {
        if(qright<currleft || qleft>currright)
            return 0;
        
        if(currleft>=qleft && currright<=qright) return seg_tree[st_idx];
        
        int mid = (currleft+currright)>>1;
        int left = sumRange(qleft,qright,currleft,mid,st_idx*2+1);
        int right = sumRange(qleft,qright,mid+1,currright,st_idx*2+2);
        
        return left+right;
    }
    
    
    void update(int index, int val) {
        update(index,val,0,n-1,0);
    }
    
    int sumRange(int left, int right) {
        return sumRange(left,right,0,n-1,0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
