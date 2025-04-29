#include <iostream>
#include <vector> 
using nmaespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int,int> map;
       for(int i=0; i<nums.size();i++){
            int find_num = target - nums[i];
            if ( map.find(find_num) == map.end()){
                map[nums[i]] = i;
            }
            else{
                return vector<int>{map[find_num],i};
            }
       }
       return {}; 
    }
};