/**
 * @param {number} sx
 * @param {number} sy
 * @param {number} fx
 * @param {number} fy
 * @param {number} t
 * @return {boolean}
*/
var isReachableAtTime = function(sx, sy, fx, fy, t) {
    if (sx === fx && sy === fy)
        return t !== 1;

    if (Math.abs(sx-fx) < Math.abs(sy-fy)) {
        sx = sy;
        fx = fy;
    }
    return Math.abs(sx-fx) <= t;
};

// inefficient
var isReachableAtTime2 = function(sx, sy, fx, fy, t) {
    if (sx === fx && sy === fy)
        return t !== 1;
    const crypto = require('crypto');

    const mask = new Set();
    mask.add(
        crypto.createHash('sha256')
            .update(JSON.stringify([sx,sy]))
            .digest()
            .toString('hex')
    );

    var queue = [[sx,sy,0]];
    const vX = [-1,  0,  1, 1, 1, 0, -1, -1];
    const vY = [-1, -1, -1, 0, 1, 1,  1,  0];

    while (true) {
        let item = queue.shift();

        if (item[0] === fx && item[1] === fy) {
            return item[2] <= t;
        } 

        for (let i = 0; i < 8; i++) {
            const xx = item[0] + vX[i];
            const yy = item[1] + vY[i];
            const hash = crypto.createHash('sha256')
                .update(JSON.stringify([xx,yy]))
                .digest()
                .toString('hex');
            
            if (!mask.has(hash)) {
                mask.add(hash);
                queue.push([xx,yy,item[2]+1]);
            }
        }
    }
};
