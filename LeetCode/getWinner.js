/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number}
 */
var getWinner = function(arr, K) {
    let max = arr[0], k = 0;
    
    for (let i = 1; i < arr.length; i++) {
        if (arr[i] > max) {
            max = arr[i];
            k = 1;
        }
        else {
            k++;
        }
        if (k == K)
            break;
    }

    return max;
};
