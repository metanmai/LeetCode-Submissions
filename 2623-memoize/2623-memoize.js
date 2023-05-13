/**
 * @param {Function} fn
 */
function memoize(fn) {
     hash = {}
    
    return function(...args) {
        var key = JSON.stringify(args);
        
        if(key in hash)
        return hash[key];

        return hash[key] = fn(...args);
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */