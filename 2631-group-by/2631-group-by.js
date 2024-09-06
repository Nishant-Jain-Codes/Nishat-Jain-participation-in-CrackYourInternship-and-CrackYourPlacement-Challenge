/**
 * @param {Function} fn
 * @return {Object}
 */
Array.prototype.groupBy = function(fn) {
    return this.reduce((acc,item)=>{
        let fnCall = fn(item);
        if(acc[fnCall])
            acc[fnCall].push(item)
        else
            acc[fnCall] = [item]
        return acc;
    },{})
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */