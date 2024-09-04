/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    // return arr.filter(fn);
    let _arr = []
    arr.forEach((item,i)=>{
        if(fn(item,i))
            _arr.push(item);
    });
    return _arr;  
};