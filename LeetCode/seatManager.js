/**
 * @param {number} n
 */
var SeatManager = function(n) {
    SeatManager.prototype.n = n;
    SeatManager.prototype.seats = new Array(n).fill(false);
    SeatManager.prototype.lowerEmptySeat = 0;
};

/**
 * @return {number}
 */
SeatManager.prototype.reserve = function() {
    const seats = SeatManager.prototype.seats;
    const lowerEmptySeat = SeatManager.prototype.lowerEmptySeat;

    for (let i = lowerEmptySeat + 1; i < seats.length; i++) {
        if (!seats[i]) {
            SeatManager.prototype.lowerEmptySeat = i;
            break;
        }
        if (i + 1 === seats.length) {
            SeatManager.prototype.lowerEmptySeat = SeatManager.prototype.n;
        }
    }

    SeatManager.prototype.seats[lowerEmptySeat] = true;
    return lowerEmptySeat + 1;
};

/** 
 * @param {number} seatNumber
 * @return {void}
 */
SeatManager.prototype.unreserve = function(seatNumber) {
    SeatManager.prototype.seats[seatNumber-1] = false;

    const lowerEmptySeat = SeatManager.prototype.lowerEmptySeat;

    if (lowerEmptySeat > seatNumber-1) {
        SeatManager.prototype.lowerEmptySeat = seatNumber-1;
    }
};

/** 
 * Your SeatManager object will be instantiated and called as such:
 * var obj = new SeatManager(n)
 * var param_1 = obj.reserve()
 * obj.unreserve(seatNumber)
 */

var seatManager = new SeatManager(5); // Initializes a SeatManager with 5 seats.
console.log(seatManager.reserve());    // All seats are available, so return the lowest numbered seat, which is 1.
console.log(seatManager.reserve());    // The available seats are [2,3,4,5], so return the lowest of them, which is 2.
console.log(seatManager.unreserve(2)); // Unreserve seat 2, so now the available seats are [2,3,4,5].
console.log(seatManager.reserve());    // The available seats are [2,3,4,5], so return the lowest of them, which is 2.
console.log(seatManager.reserve());    // The available seats are [3,4,5], so return the lowest of them, which is 3.
console.log(seatManager.reserve());    // The available seats are [4,5], so return the lowest of them, which is 4.
console.log(seatManager.reserve());    // The only available seat is seat 5, so return 5.
console.log(seatManager.unreserve(5)); // Unreserve seat 5, so now the available seats are [5].