/*
 * @lc app=leetcode.cn id=1 lang=javascript
 *
 * [1] 两数之和
 */

// @lc code=start
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
  let map = new Map();
  let ans = [0, 0]
  nums.forEach((n,i) => {
    if( map.get(target - n ) !== undefined){
      let temp = map.get(target - n );
      ans[0] = temp;
      ans[1] = i;
    }
    else {
      map.set(n , i);
    }
  })

  return ans.sort((a, b) => a - b);
};
// @lc code=end
console.log(twoSum([3, 3], 6));

