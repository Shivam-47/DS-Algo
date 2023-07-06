//https://leetcode.com/problems/minimum-size-subarray-sum/description/
// Time:: O(NLogN) Space:: O(1)

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        vector <int> lsum;
        lsum.push_back(0);
        int preSum=0,ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            preSum += nums[i];
            lsum.push_back(preSum);
            if(preSum>=target && lower_bound(lsum.begin(),lsum.end(),preSum-target) != lsum.end()){
                int j= lower_bound(lsum.begin(),lsum.end(),preSum-target)-lsum.begin();
                while(j>0 && lsum[j]>preSum-target)
                    j--;
                if(i>=0)
                    ans = min(ans,i-j+1);
            }
        }

        return (ans==INT_MAX)?0:ans;
    }
};