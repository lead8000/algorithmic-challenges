/**
 * @param {number[]} flowerbed
 * @param {number} n
 * @return {boolean}
 */
var canPlaceFlowers = function(flowerbed, n) {
    const N = flowerbed.length;

    if (n === 0)
        return true;

    for (let i = 0; i < N; i++) {
        if (flowerbed[i] === 1)
            continue;
    
        const emptyLeftPlot  = i !== 0 ? flowerbed[i-1] === 0 : true;
        const emptyRightPlot = i !== N-1 ? flowerbed[i+1] === 0 : true;

        if (emptyLeftPlot && emptyRightPlot) {
            flowerbed[i] = 1;
            n--;

            if (n === 0)
                return true;
        }
    }
    return false;
};

console.log(canPlaceFlowers([0,0,0,0,0,1,0,0], 0))