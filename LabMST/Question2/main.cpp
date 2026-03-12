class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long mod=1e9+7;

        vector<long long>bit(32,0);

        for(int x:nums){
            for(int b=0;b<32;b++){
                if(x & (1<<b)){
                    bit[b]++;
                }
            }
        }
        long long ans=0;

        for(int i=0;i<k;i++){
            long long val=0;
            for(int b=0;b<32;b++){
                if(bit[b]>0){
                    val|=(1LL << b);
                    bit[b]--;
                }
            }
            ans=(ans+(val*val)%mod)%mod;
        }
        return ans;
    }
};