class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        mapa = {}
        for i in range(9):
            for j in range(9):
                if board[i][j] == '.':
                    continue
                else:
                    if board[i][j] in mapa:
                        for el in mapa[board[i][j]]:
                            if el[0] == i or el[1] == j:

                                return False
                            if(int(el[0] / 3) == int(i / 3) and int(el[1] / 3) == int(j / 3)):
                                return False
                        mapa[board[i][j]].append([i, j])
                    else:
                        mapa[board[i][j]] = [[i, j]]
        return True
