/**
 * @param {string} word1
 * @param {string} word2
 * @return {string}
 */
var mergeAlternately = function(word1, word2) {
    var mergedStr = "";

    for (let i = 0, j = 0; i < word1.length || j < word2.length;) {
        if (i < word1.length) {
            mergedStr += word1[i++];
        }
        if (j < word2.length) {
            mergedStr += word2[j++];
        }
        console.log(i, j)
    }

    return mergedStr;
};