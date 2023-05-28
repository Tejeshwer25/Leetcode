class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int evenSum=0;
        
        for(int i=0; i<nums.size(); i++)
            if(nums[i]%2 == 0) 
                evenSum += nums[i];
        
        for(int i=0; i<queries.size(); i++) {
            int index=queries[i][1];
            int value=queries[i][0];
            int temp=nums[index];
            
            nums[index] = nums[index] + value;
            
            if((temp%2 != 0) && (nums[index]%2 == 0))
                evenSum += nums[index];
            else if((temp%2 == 0) && (nums[index]%2 != 0)) 
                evenSum -= temp;
            else if((temp%2 == 0) && (nums[index]%2 == 0))
                evenSum += (nums[index] - temp);
            
            ans.push_back(evenSum);
        }
        
        return ans;
    }
};
