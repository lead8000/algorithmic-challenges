/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    var stack = [];

    for (let i = 0; i < s.length; i++) {
        while (i < s.length && s.charAt(i) === ' ') { i++; }
        var word = "";

        while(i < s.length && s.charAt(i) !== ' ') { 
            word+= s.charAt(i);
            i++;
        }

        if (word !== "") {
            stack.push(word);
        }
    }

    var reversed = "";
    while (true) {
        reversed += stack.pop();
        if (stack.length == 0) {
            break;
        } 
        else {
            reversed += " ";
        }
    }

    return reversed;
};

console.log(reverseWords(" .  hello    worlds    d"))