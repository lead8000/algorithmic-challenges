/**
 * @param {string} str1
 * @param {string} str2
 * @return {string}
 */
var gcdOfStrings = function(str1, str2) {
    if (str2.length > str1.length) {
        var tmp = str1
        str1 = str2
        str2 = tmp
    }

    while (str1.length > 0 && str2.length > 0) {
        var [times, rest] = divide(str1, str2)
        if (times === 0) {
            return ""
        }
        str1 = str2
        str2 = rest
    }

    return str1
};

/**
 * @param {string} str1
 * @param {string} str2
 * @return {[number, string]}
 */
var divide = function(str1, str2) {
    var times = 0

    for (let i = 0, n = str2.length; i < str1.length; i++) {
        if (str1[i] != str2[i % n])
            return [0, str1]
        
        if ((i+1) % n === 0) 
            times++
    }

    return [times, str1.slice(str2.length * times)]
}