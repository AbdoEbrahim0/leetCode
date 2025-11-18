/**
 * @param {Array} arr
 * @param {number} depth
 * @return {Array}
 */
var flat = function (arr, n) {
    const result = [];

    const helper = (current, depth) => {
        for (const item of current) {
            if (Array.isArray(item) && depth < n) {
                helper(item, depth + 1); // recurse deeper
            } else {
                result.push(item); // push value directly
            }
        }
    };

    helper(arr, 0); // start at depth 0
    return result;
};
