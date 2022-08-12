/******************************************************************************
260. Single Number III
Given an integer array nums, in which exactly two elements appear 
only once and all the other elements appear exactly twice. Find the two 
elements that appear only once. You can return the answer in any order.

You must write an algorithm that runs in linear runtime complexity and 
uses only constant extra space.

 

Example 1:

Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.
Example 2:

Input: nums = [-1,0]
Output: [-1,0]
Example 3:

Input: nums = [0,1]
Output: [1,0]
*******************************************************************************/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int>ans;
        int st=0;
        int nd=0;
        int xori=0;
        
        for(int i=0;i<nums.size();i++){
            xori = xori ^ nums[i];
        }
        
       int count=0;
       while(xori){
           if(xori & 1){
                 break;
           }
           
           count++;
           xori=xori>>1;
           
       }
       
        for(int i=0;i<nums.size();i++){
            if(nums[i] & (1<<count)){
                st=st ^ nums[i];
            }
            else
                nd=nd ^ nums[i];
        }
        
       ans.push_back(st);
       ans.push_back(nd);
        return ans;
        
    }
};