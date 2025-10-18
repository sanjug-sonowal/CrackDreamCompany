// Last updated: 18/10/2025, 09:01:38
/**
 * @param {number[][]} customers
 * @return {number}
 */
var averageWaitingTime = function(customers) {
    let wait = 0;
    let curr = 0;

    for (let c of customers) {
        curr = Math.max(curr, 1.0 * c[0]) + c[1];
        wait += curr - c[0];
    }

    return 1.0 * wait / customers.length;
};
