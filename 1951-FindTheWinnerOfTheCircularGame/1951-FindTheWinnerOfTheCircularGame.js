// Last updated: 18/10/2025, 09:01:25
/**
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var findTheWinner = function(n, k) {
    // friends[i] := true if i-th friend is left
    let friends = new Array(n).fill(false);

    let friendCount = n;
    let fp = 0;  // friends' index

    while (friendCount > 1) {
        for (let i = 0; i < k; ++i, ++fp)
            while (friends[fp % n])  // The friend is not there.
                ++fp;                // Point to the next one.
        friends[(fp - 1) % n] = true;
        --friendCount;
    }

    const winnerIndex = friends.findIndex(friend => !friend);
    return winnerIndex + 1;
};