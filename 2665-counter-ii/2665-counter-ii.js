/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let orignalInit = init;
    return {
        increment : () => {
            init+=1;
            return init;
        },
        decrement : () => {
            init-=1;
            return init;
        },
        reset : () =>{
            init = orignalInit;
            return init;
        }
    }
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */