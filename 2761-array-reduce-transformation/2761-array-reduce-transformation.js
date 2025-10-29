/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    for(const i in nums)
    {
        init=(fn(init,nums[i] ));
    }
return init;
};