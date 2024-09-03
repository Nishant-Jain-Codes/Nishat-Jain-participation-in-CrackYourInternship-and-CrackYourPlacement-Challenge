/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
    let k = n;
    return function() {
        k+=1;
        return k-1;
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */