#include<iostream>
#include<vector>

/***
 class Solution {
	 
	public :int[] TwoSum(int[] nums, int target) 
	{
		Dictionary<int, int> numberIndexPairs = new Dictionary<int, int>();
		for (int i = 0; i < nums.Length; i++)
		{
			if (numberIndexPairs.ContainsKey(target - nums[i]))
			{
				return new int[] { i, numberIndexPairs[target - nums[i]] };
			}
			numberIndexPairs[nums[i]] = i;
		}
		return new int[] { };
	}
	
 }
 */

