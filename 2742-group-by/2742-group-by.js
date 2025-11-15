/**
 * @param {Function} fn
 * @return {Object}
 */
Array.prototype.groupBy = function(fn) {
    const result = {};
    
    for (const item of this) {
        const key = fn(item);   // apply selector function
        if (!result[key]) {
            result[key] = [];   // initialize array if key not present
        }
        result[key].push(item); // push item into the correct group
    }
    
    return result;
};


/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */