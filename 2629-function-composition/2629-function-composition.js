/**
 * @param {Function[]} functions
 * @return {Function}
 */
var findVal = (functions, pos, x) => {
    if(pos == -1)
        return x;
    
    return findVal(functions, pos - 1, functions[pos](x));
}

var compose = function(functions) {
	return function(x) {
        return findVal(functions, functions.length - 1, x);
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */