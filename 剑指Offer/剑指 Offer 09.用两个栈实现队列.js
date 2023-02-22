/*
 * @lc app=leetcode.cn id=剑指 Offer 09 lang=javascript
 * @lcpr version=21704
 *
 * [剑指 Offer 09] 用两个栈实现队列
 */

// @lc code=start

var CQueue = function() {
  this.outStk = [];
  this.inStk = [];
};

/** 
 * @param {number} value
 * @return {void}
 */
CQueue.prototype.appendTail = function(value) {
  this.inStk.push(value);
};

/**
 * @return {number}
 */
CQueue.prototype.deleteHead = function() {
  if( !this.outStk.length ){
    if( !this.inStk.length ){
      return -1;
    }
    while( this.inStk.length ){
      this.outStk.push(this.inStk.pop());
    }
  }

  return this.outStk.pop();
};

/**
 * Your CQueue object will be instantiated and called as such:
 * var obj = new CQueue()
 * obj.appendTail(value)
 * var param_2 = obj.deleteHead()
 */
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=
// paramTypes= []
// returnType=
// @lcpr-div-debug-arg-end


/*
// @lcpr case=start
// 
// @lcpr case=end

// @lcpr case=start
// 
// @lcpr case=end

 */


