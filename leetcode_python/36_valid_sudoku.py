class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        def isValidRow(ind):
            st = set()
            for i in range(0,9):
                if board[ind][i].isdigit():
                    if board[ind][i] not in st:
                        st.add(board[ind][i])
                    else:
                        return False
            return True
        def isValidCol(ind):
            st = set()
            for i in range(0,9):
                if board[i][ind].isdigit():
                    if board[i][ind] not in st:
                        st.add(board[i][ind])
                    else:
                        return False
            return True
        def isGridValid(ind):
            row = 3 * (ind / 3)
            col = 3 * (ind%3)
            st = set()
            # print(row,col)
            for i in range(row,row+3):
                for j in range(col, col + 3):
                    # print(board[i][j])
                    if board[i][j].isdigit():
                        if board[i][j] not in st:
                            st.add(board[i][j])
                        else:
                            return False
            return True
        for i in range(0,9):
            if not isGridValid(i) or not isValidRow(i) or not isValidCol(i):
                return False
        return True
