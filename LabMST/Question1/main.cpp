class Solution {
public:
    long long solve(int x,vector<int>& nums){
        long long op=0;
        for(int i=0;i<nums.size();i++){
            op+=(nums[i]-1)/x;
        }
        return op;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int  low=1;
        int high=*max_element(nums.begin(),nums.end());
        int ans=high;

        while(low<=high){
            int mid=(low+high)/2;
            long long op=solve(mid,nums);

            if(op<=maxOperations){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};