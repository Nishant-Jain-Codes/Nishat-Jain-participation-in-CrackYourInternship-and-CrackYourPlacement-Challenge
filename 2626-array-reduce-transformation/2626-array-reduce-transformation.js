/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    // if(nums.length == 0)
        // return init
    let red = init;
    nums.forEach((item , i)=>{
        red = fn(red,item);
    })
    return red;
};