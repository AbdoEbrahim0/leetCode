/**
 * @param {Function} fn
 * @param {number} t milliseconds
 * @return {Function}
 */
var debounce = function(fn, t) {
    let timerId = null;

    return function(...args) {
        if (timerId) {
            clearTimeout(timerId); // cancel previous scheduled call
        }

        timerId = setTimeout(() => {
            fn(...args); // execute with latest arguments
        }, t);
    };
};

/**
 * const log = debounce(console.log, 100);
 * log('Hello'); // cancelled
 * log('Hello'); // cancelled
 * log('Hello'); // Logged at t=100ms
 */