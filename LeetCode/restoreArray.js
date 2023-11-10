/**
 * @param {number[][]} adjacentPairs
 * @return {number[]}
 */
var restoreArray = function(adjacentPairs) {
    const dict = new Map();

    for (let i = 0; i < adjacentPairs.length; i++) {
        const item1 = adjacentPairs[i][0];
        const value1 = dict.get(item1);
        
        if (value1 === undefined) {
            dict.set(item1, [i]);
        }
        else {   
            value1.push(i);
        }
        
        const item2 = adjacentPairs[i][1];
        const value2 = dict.get(item2);

        if (value2 === undefined) {
            dict.set(item2, [i]);
        }
        else {   
            value2.push(i);
        }
    }

    let currPos = -1;
    let currItem = undefined;

    for (const [key, value] of dict.entries()) {
        if (value.length === 1) {
            currItem = key;
            currPos  = value[0];
            break;
        }
    }

    const array = new Array();
    array.push(currItem);

    while (true) {
        const item1 = adjacentPairs[currPos][0];
        const item2 = adjacentPairs[currPos][1];

        if (item1 !== currItem) {
            array.push(item1);

            const pos = dict.get(item1);
            if (pos.length === 1)
                break;
            if (pos[0] !== currPos)
                currPos = pos[0];
            else
                currPos = pos[1];
            currItem = item1;
        }
        else {
            array.push(item2);

            const pos = dict.get(item2);
            if (pos.length === 1)
                break;
            if (pos[0] !== currPos)
                currPos = pos[0];
            else
                currPos = pos[1];
            currItem = item2;
        }
    }    

    return array;
};
