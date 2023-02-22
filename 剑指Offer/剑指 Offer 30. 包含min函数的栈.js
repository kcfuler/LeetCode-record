/**
 * initialize your data structure here.
 */
var MinStack = function() {
    this.stack = [];
    this.minStack = [Infinity] // 注意初始值
};

/** 
 * @param {number} x
 * @return {void}
 */
MinStack.prototype.push = function(x) {
    this.stack.push(x);
    let minVal = this.minStack[this.minStack.length - 1]
    this.minStack.push(Math.min(minVal, x));
};

/**
 * @return {void}
 */
MinStack.prototype.pop = function() {
    this.minStack.pop();
    this.stack.pop();
};

/**
 * @return {number}
 */
MinStack.prototype.top = function() {
    return this.stack[this.stack.length - 1];
};

/**
 * @return {number}
 */
MinStack.prototype.min = function() {
    let minVal = this.minStack[this.minStack.length - 1];
    return minVal;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * var obj = new MinStack()
 * obj.push(x)
 * obj.pop()
 * var param_3 = obj.top()
 * var param_4 = obj.min()
 */