class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> pmap; // prefix sum -> frequency
        int sum = 0, c = 0;

        pmap[0] = 1; // base case: sum=0 occurs once

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            // if (sum - k) exists, add its frequency
            if(pmap.find(sum - k) != pmap.end()) {
                c += pmap[sum - k];
            }

            // store/update frequency of current sum
            pmap[sum]++;
        }
        return c;
    }
};
