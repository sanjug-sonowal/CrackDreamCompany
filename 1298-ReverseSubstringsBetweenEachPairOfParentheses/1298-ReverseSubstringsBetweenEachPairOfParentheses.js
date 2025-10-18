// Last updated: 18/10/2025, 09:03:22
/**
 * @param {string} s
 * @return {string}
 */
var reverseParentheses = function(s) {
 let stack = [];
    let ans = "";

    for (const c of s) {
        if (c === '(') {
            stack.push(ans.length);
        } else if (c === ')') {
            const j = stack.pop();
            const toReverse = ans.slice(j).split('').reverse().join('');
            ans = ans.slice(0, j) + toReverse;
        } else {
            ans += c;
        }
    }

    return ans;
};