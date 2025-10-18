# Last updated: 18/10/2025, 09:03:08
class Solution(object):
    def oddCells(self, m, n, indices):
        """
        :type m: int
        :type n: int
        :type indices: List[List[int]]
        :rtype: int
        """
        # Initialize a matrix of m rows and n columns with all 0s
        matrix = [[0 for _ in range(n)] for _ in range(m)]

        # Apply the increment operations
        for r, c in indices:
            # Increment the entire row `r`
            for col in range(n):
                matrix[r][col] += 1
            # Increment the entire column `c`
            for row in range(m):
                matrix[row][c] += 1

        # Count the number of cells with odd values
        count = 0
        for i in range(m):
            for j in range(n):
                if matrix[i][j] % 2 == 1:
                    count += 1

        return count
