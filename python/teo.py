import random

def print_board(board):
    for row in board:
        print("|".join(row))
    print()

def check_winner(board, player):
    # Check rows, columns, and diagonals
    for i in range(3):
        if all([cell == player for cell in board[i]]):  # Rows
            return True
        if all([board[j][i] == player for j in range(3)]):  # Columns
            return True
    if all([board[i][i] == player for i in range(3)]) or all([board[i][2 - i] == player for i in range(3)]):  # Diagonals
        return True
    return False

def get_empty_cells(board):
    return [(i, j) for i in range(3) for j in range(3) if board[i][j] == " "]

def minimax(board, depth, is_maximizing):
    empty_cells = get_empty_cells(board)
    if check_winner(board, "O"):  # AI win
        return 10 - depth
    if check_winner(board, "X"):  # Player win
        return depth - 10
    if not empty_cells:  # Draw
        return 0

    if is_maximizing:
        best_score = float("-inf")
        for cell in empty_cells:
            board[cell[0]][cell[1]] = "O"
            score = minimax(board, depth + 1, False)
            board[cell[0]][cell[1]] = " "
            best_score = max(score, best_score)
        return best_score
    else:
        best_score = float("inf")
        for cell in empty_cells:
            board[cell[0]][cell[1]] = "X"
            score = minimax(board, depth + 1, True)
            board[cell[0]][cell[1]] = " "
            best_score = min(score, best_score)
        return best_score

def get_best_move(board):
    best_score = float("-inf")
    best_move = None
    for cell in get_empty_cells(board):
        board[cell[0]][cell[1]] = "O"
        score = minimax(board, 0, False)
        board[cell[0]][cell[1]] = " "
        if score > best_score:
            best_score = score
            best_move = cell
    return best_move

def tic_tac_toe():
    board = [[" " for _ in range(3)] for _ in range(3)]
    print("Welcome to Tic-Tac-Toe!")
    print_board(board)

    while True:
        # Player's turn
        try:
            row, col = map(int, input("Enter your move (row and column: 0-2): ").split())
            if board[row][col] != " ":
                print("Cell already taken. Try again.")
                continue
            board[row][col] = "X"
        except:
            print("Invalid input. Enter row and column separated by space (e.g., '1 1').")
            continue

        print_board(board)
        if check_winner(board, "X"):
            print("Congratulations! You win!")
            break

        if not get_empty_cells(board):
            print("It's a draw!")
            break

        # AI's turn
        print("AI is making its move...")
        move = get_best_move(board)
        board[move[0]][move[1]] = "O"
        print_board(board)

        if check_winner(board, "O"):
            print("AI wins! Better luck next time!")
            break

        if not get_empty_cells(board):
            print("It's a draw!")
            break

tic_tac_toe()
