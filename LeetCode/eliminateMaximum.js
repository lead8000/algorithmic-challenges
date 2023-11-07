/**
 * @param {number[]} dist
 * @param {number[]} speed
 * @return {number}
 */
var eliminateMaximum = function(dist, speed) {
    const N = dist.length;
    const rounds = new Array(N).fill(0);

    for (let i = 0; i < N; i++) {
        rounds[i] = Math.ceil(dist[i] / speed[i]);
    }

    rounds.sort((x,y) => x-y)

    for (let i = 0; i < N; i++) {
        if (rounds[i] < i+1)
            return i;
    }

    return N;
};

console.log(eliminateMaximum(
    [3,2,4],
    [5,3,2]
))