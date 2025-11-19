/**
 * @param {Object|Array} obj
 * @return {Object|Array}
 */
var compactObject = function(obj) {
    if (Array.isArray(obj)) {
        return obj
            .map(compactObject)
            .filter(Boolean); // removes falsy values
    } else if (obj !== null && typeof obj === 'object') {
        const result = {};
        for (const key in obj) {
            const val = compactObject(obj[key]);
            if (Boolean(val)) {
                result[key] = val;
            }
        }
        return result;
    } else {
        return obj;
    }
};
