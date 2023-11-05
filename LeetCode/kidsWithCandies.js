/**
 * @param {number[]} candies
 * @param {number} extraCandies
 * @return {boolean[]}
 */
var kidsWithCandies = function(candies, extraCandies) {
    let max = candies[0];
    candies.forEach((v, _, __) => max = Math.max(max, v));

    let mask = new Array(candies.length);

    for (let i = 0; i < candies.length; i++) {
        if (candies[i] + extraCandies >= max) {
            mask[i] = true;
        }
        else {
            mask[i] = false;
        }
    }

    return mask;
};