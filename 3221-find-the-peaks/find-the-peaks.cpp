class Solution {
public:
    vector<int> findPeaks(vector<int>& nums) {
        vector<int> ans;
        for(int i=1;i<nums.size()-1;i++){
            int prev=nums[i-1];
            int curr=nums[i];
            int next=nums[i+1];
            if(prev < curr && curr > next){
                ans.push_back(i);
            }

        }return ans;
    }
};