//https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/
// Time:: O(N) Space:: O(N)

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans=0,n=nums.size();

        vector <int> zeros;
        for(int i=0;i<n;i++)
            if(nums[i]==0)
                zeros.push_back(i);

        int z=zeros.size();
        if(z==0)
            return n-1;

        if(z==n)
            return 0;

        zeros.insert(zeros.begin(),-1);
        zeros.push_back(n);
        z=z+2;

        for(int i=1;i<z-1;i++){
            int l=zeros[i]-zeros[i-1]-1;
            int r=zeros[i+1]-zeros[i]-1;

            ans = max(ans,l+r);
        }

        return ans;
    }
};