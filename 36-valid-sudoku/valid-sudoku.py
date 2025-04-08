class Solution:
    def isValidSudoku(self, board):
        # Check 3x3 boxes
        for i in range(3):
            for j in range(3):
                seen = set()
                for k in range(3):
                    for l in range(3):
                        num = board[i * 3 + k][j * 3 + l]
                        if num == '.':
                            continue
                        if num in seen:
                            return False
                        seen.add(num)
        
        # Check rows
        for i in range(9):
            seen = set()
            for j in range(9):
                num = board[i][j]
                if num == '.':
                    continue
                if num in seen:
                    return False
                seen.add(num)
        
        # Check columns
        for i in range(9):
            seen = set()
            for j in range(9):
                num = board[j][i]
                if num == '.':
                    continue
                if num in seen:
                    return False
                seen.add(num)
        
        return True
