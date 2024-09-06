/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */
var chunk = function(arr, size) {
    let output = []
    let curChunk = []
    for(let i = 0 ; i<arr.length;i++){
        curChunk.push(arr[i])
        if(curChunk.length==size || i+1 == arr.length)
            {
                output.push(curChunk)
                // console.log(curChunk)
                curChunk = []
            }
    }
    return output
};
