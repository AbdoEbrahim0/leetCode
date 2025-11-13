/**
 * @param {Function} fn
 * @param {number} t
 * @return {Function}
 */
var timeLimit = function(fn, t) {
    return async function(...args) {
        return new Promise((resolve, reject) => {
            // Set up the timeout rejection
            const timer = setTimeout(() => {
                reject("Time Limit Exceeded");
            }, t);

            // Run the original function
            fn(...args)
                .then((res) => {
                    clearTimeout(timer); // Clear timeout if resolved in time
                    resolve(res);
                })
                .catch((err) => {
                    clearTimeout(timer); // Clear timeout if rejected in time
                    reject(err);
                });
        });
    };
};


/**
 * const limited = timeLimit((t) => new Promise(res => setTimeout(res, t)), 100);
 * limited(150).catch(console.log) // "Time Limit Exceeded" at t=100ms
 */