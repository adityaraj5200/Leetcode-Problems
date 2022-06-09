class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0,j=numbers.size()-1;
        while(i<j){
            int sum = numbers[i]+numbers[j];
            if(i!=0 && numbers[i]==numbers[i-1]) i++;
            else if(sum < target) i++;
            else if(sum > target) j--;
            else return {i+1,j+1};
        }
        return {};
    }
};