/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    // let hasbeencalled = false
    let value = {};
    return function(...args) {
        // console.log(args,value)
        let val = JSON.stringify(arguments)
        if(value[val] !== undefined){
            // hasbeencalled=true;
            return value[val];
        }
        else
           {
            // console.log("new val found" , val , )
            value[val] = fn(...args)
            return value[val];
           }
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */