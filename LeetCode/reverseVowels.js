/**
 * @param {string} s
 * @return {string}
 */
var reverseVowels = function(s) {
    const N = s.length;
    const reversed = new Array(N).fill('');
    const vowers = new Set([97, 101, 105, 111, 117, 65, 69, 73, 79, 85]);
    let stack = [];

    for (let i = 0; i < N; i++) {
        if (!vowers.has(s.charCodeAt(i))) {
            reversed[i] = s.charAt(i);
        }
        else 
            stack.push(s.charAt(i));
    }
    let ss = "";
    for (let i = 0; i < N; i++) {
        if (reversed[i] === '')
            ss += stack.pop();
        else 
            ss += reversed[i];
    }

    return ss;
};

console.log(reverseVowels("hello"))