class Solution(object):
    def gameOfLife(self, board):
        n = len(board)
        m = len(board[0])
        
        counter = 0
        for i in range(n):
            for j in range(m):
                if(i > 0 and j > 0):
                    if(board[i-1][j-1] > 0.5):
                        counter += 1
                if(i > 0):
                    if(board[i-1][j] > 0.5):
                        counter += 1
                if(i > 0 and j < m-1):
                    if(board[i-1][j+1] > 0.5):
                        counter += 1
                if(j > 0):
                    if(board[i][j-1] > 0.5):
                        counter += 1
                if(j < m-1):
                    if(board[i][j+1] > 0.5):
                        counter += 1
                if(i < n-1 and j > 0):
                    if(board[i+1][j-1] > 0.5):
                        counter += 1
                if(i < n-1):
                    if(board[i+1][j] > 0.5):
                        counter += 1
                if(i < n-1 and j < m-1):
                    if(board[i+1][j+1] > 0.5):
                        counter += 1
                
                if(counter < 2 and board[i][j] == 1):
                    board[i][j] = 0.8
                    
                if(counter > 3 and board[i][j] == 1):
                    board[i][j] = 0.8

                if(counter == 3 and board[i][j] == 0):
                    board[i][j] = 0.2
                
                counter = 0
        for i in range(n):
            for j in range(m):
                if board[i][j] == 0.8:
                    board[i][j]  = 0
                elif board[i][j] == 0.2:
                    board[i][j]  = 1

        