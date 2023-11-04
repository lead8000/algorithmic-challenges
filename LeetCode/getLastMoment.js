/**
 * @param {number} n
 * @param {number[]} left
 * @param {number[]} right
 * @return {number}
 */
var getLastMoment = function(n, left, right) {  
    var max = -1;
    left.forEach(item => {
        max = Math.max(max, item)
    });

    var min = n;
    right.forEach(item => {
        min = Math.min(min, item)
    })

    var lastTime = 0

    if (left.length > 0)
        lastTime = Math.max(lastTime, max)

    if (right.length > 0)
        lastTime = Math.max(lastTime, n-min)

    return lastTime
};