import java.util.Objects;
import java.util.Scanner;

public class Connect4 
{
    String[][] board;
    int winnerPlayer;
    boolean draw;
    int playerTurn;

    public Connect4() 
    {
        winnerPlayer = 0;
        draw = false;
        playerTurn = 1;
        board = new String[6][7];
        newBoard();
        displayBoard();
    }

    // Building a better looking board in the console
    private void newBoard()
    {
        for (int i = 0; i < 6; i++) 
        {
            for (int j = 0; j < 7; j++) 
            {
                board[i][j] = "-";
            }
        }
    }
     
    //Displaying the board
    private void displayBoard() 
    {
        System.out.println(" ");
        System.out.println(" *** Connect 4 ***");
        System.out.println("");
        for (int i = 0; i < 6; i++) 
        {
            for (int j = 0; j < 7; j++) 
            {
                System.out.print(board[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println();
    }

    //Input Validation
    private boolean validInput(String input) 
    {
        return (Objects.equals(input, "1") ||
                Objects.equals(input, "2") ||
                Objects.equals(input, "3") ||
                Objects.equals(input, "4") ||
                Objects.equals(input, "5") ||
                Objects.equals(input, "6") ||
                Objects.equals(input, "7"));
    }

    private boolean isColumnFull(int column) 
    {
        return board[0][column - 1].equals("X") || board[0][column - 1].equals("0");
    }

    //Getting next available slot
    private int getNextAvailableSlot(int column) 
    {
        int position = 5;
        boolean found = false;
        while (position >= 0 && !found) 
        {
            if (!board[position][column ].equals("X") && !board[position][column].equals("0")) 
            {
                return position; //when the available slot is found
            } 
            else 
            {
                position--;
            }
        }
        return -1; // if the column is full
    }

    //Swapping the players for thier turn
    private void swapPlayerTurn() 
    {
        if (playerTurn == 1) 
        {
            playerTurn = 2;
        } else 
        {
            playerTurn = 1;
        }
    }

    private void placePiece()
     {
        Scanner sc = new Scanner(System.in);
        System.out.println("Player " + playerTurn + " - Please select which column to place your piece (1-7):");
        String input = sc.nextLine();

        while (!validInput(input) || isColumnFull(Integer.parseInt(input))) 
        {
            while (!validInput(input)) 
            {
                System.out.println("Invalid input - please select a column from 1-7");
                input = sc.nextLine();
            }
            while (isColumnFull(Integer.parseInt(input))) 
            {
                System.out.println("Column full, choose another column");
                input = sc.nextLine();
                if (!validInput(input)) 
                {
                    break;
                }
            }
        }
        int columnChoice = Integer.parseInt(input) - 1;
        int position = getNextAvailableSlot(columnChoice);
        if (position != -1) 
        {
            System.out.println("Next available row in column: " + position);
            String pieceToPlace = (playerTurn == 1) ? "X" : "0";
            board[position][columnChoice] = pieceToPlace;
            displayBoard();
            swapPlayerTurn();
        }
        else 
        {
            System.out.println("Column is full. Please choose another column.");
        }
    }

    //Checking whether the board is full or not
    private boolean isBoardFull() 
    {
        boolean full = true;
        for (int i = 0; i < 6; i++) 
        {
            for (int j = 0; j < 7; j++) 
            {
                if (!board[i][j].equals("X") && !board[i][j].equals("0")) 
                {
                    full = false;
                    break;
                }
            }
        }
        return full;
    }

    //Vertical win check
    private String checkVerticalWinner() 
    {
        String symbol = null;
        for (int i = 0; i < 3; i++) 
        {
            for (int j = 0; j < 7; j++) 
            {
                if (Objects.equals(board[i][j], board[i + 1][j]) && Objects.equals(board[i][j], board[i + 2][j]) &&
                    Objects.equals(board[i+3][j], board[i][j])) 
                {
                    if (Objects.equals(board[i][j], "X") || Objects.equals(board[i][j], "0")) 
                    {
                        symbol = board[i][j];
                    }
                }
            }
        }
        return symbol;
    }

    //Horizontal win check
    private String checkHorizontalWinner() 
    {
        String symbol = null;
        for (int i = 0; i < 6; i++) 
        {
            for (int j = 0; j < 4; j++) 
            {
                if (Objects.equals(board[i][j], board[i][j + 1]) && Objects.equals(board[i][j], board[i][j + 2]) &&
                    Objects.equals(board[i][j], board[i][j + 3])) 
                {
                    if (Objects.equals(board[i][j], "X") || Objects.equals(board[i][j], "0")) 
                    {
                        symbol = board[i][j];
                    }
                }
            }
        }
        return symbol;
    }

    //Left diagonal win check
    private String checkLeftDiagonalWinner() 
    {
        String symbol = null;
        for (int i = 0; i < 3; i++) 
        {
            for (int j = 0; j < 4; j++) 
            {
                if (Objects.equals(board[i][j], board[i + 1][j + 1]) && Objects.equals(board[i][j], board[i + 2][j + 2]) &&
                    Objects.equals(board[i][j], board[i + 3][j + 3])) 
                {
                    if (Objects.equals(board[i][j], "X") || Objects.equals(board[i][j], "0")) 
                    {
                        symbol = board[i][j];
                    }
                }
            }
        }
        return symbol;
    }

    //Right diagonal win check
    private String checkRightDiagonalWinner() 
    {
        String symbol = null;
        for (int i = 0; i < 3; i++) 
        {
            for (int j = 3; j < 7; j++) 
            {
                if (Objects.equals(board[i][j], board[i + 1][j - 1]) && Objects.equals(board[i][j], board[i + 2][j - 2]) &&
                    Objects.equals(board[i][j], board[i + 3][j - 3])) 
                {
                    if (Objects.equals(board[i][j], "X") || Objects.equals(board[i][j], "0")) 
                    {
                        symbol = board[i][j];
                    }
                }
            }
        }
        return symbol;
    }

    //Checking who is the winner
    private int checkForWinner()
    {
        int winner = 0;
        String symbol = " ";
        if (Objects.equals(checkVerticalWinner(), "X") || Objects.equals(checkVerticalWinner(), "0")) 
        {
            symbol = checkVerticalWinner();
        }
        else if (Objects.equals(checkHorizontalWinner(), "X") || Objects.equals(checkHorizontalWinner(), "0")) 
        {
            symbol = checkHorizontalWinner();
        } 
        else if (Objects.equals(checkLeftDiagonalWinner(), "X") || Objects.equals(checkLeftDiagonalWinner(), "0")) 
        {
            symbol = checkLeftDiagonalWinner();
        }
        else if (Objects.equals(checkRightDiagonalWinner(), "X") || Objects.equals(checkRightDiagonalWinner(), "0")) 
        {
            symbol = checkRightDiagonalWinner();
        }

        if (Objects.equals(symbol, "X")) 
        {
            winner = 1;
        }
        else if (Objects.equals(symbol, "0")) 
        {
            winner = 2;
        }
        return winner;
    }

    //Ckecking whether it is draw or not
    private boolean checkForDraw() 
    {
        return isBoardFull()==true && checkForWinner() == 0;
    }

    // Declaring the winner the the game
    private void showWinner() 
    {
        System.out.println(" ");
        System.out.println("*******************");
        System.out.println("                    ");
        System.out.println("    *   *   *       *   *   *        ");
        System.out.println("  *    *  *   *    *  *   *");
        System.out.println("    Player " + winnerPlayer + " Wins!!!");
        System.out.println("    *   *   *       *   *   *        ");
        System.out.println("  *    *  *   *    *  *   *");
         System.out.println("                    ");
         System.out.println("*******************");
    }

    //Round of Connect 4 game
    public void playGame() 
    {
        while (winnerPlayer == 0)
        {
            winnerPlayer = checkForWinner();
            draw = checkForDraw();
            if (winnerPlayer == 1 || winnerPlayer == 2) 
            {
                showWinner();
                break;
            }
            else if (draw==true)
            {
                System.out.println("It's a draw");
                break;
            }
            placePiece();
        }
    }

    //Main method
    public static void main(String[] args) 
    {
        Connect4 c4 = new Connect4();
        c4.playGame();
    }
}
