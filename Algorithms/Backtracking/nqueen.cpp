/*  The following program is a solution to the n queen
    problem, that is placing n queens on a n*n chessboard
    such that all of the queens are safe.
    In this approach, queens are placed one by one in every
    column on each of the safe blocks. If there's no safe
    block present in that column, then we go back to the
    previous column (here, 3 spaces back) and place that queen
    in another safe position. This is called backtracking,
    going back to the correct part of the solution.
    This is done till all of the queens are placed safely.

    To make the implementation simpler, the board is stored
    as a 1D array. So, if n = 5 for example, the board will
    look like this (The numbers represent the indices of the
    1D array) :

    0  1  2  3  4
    5  6  7  8  9
    10 11 12 13 14
    15 16 17 18 19
    20 21 22 23 24

    Reader will probably need a pen and paper to understand the
    equations for each of the conditions in the isSafe function.

    The time complexity of this approach is O(n^2), since there's
    a loop that runs n times and the function recurs another n times.

*/

#include <iostream>

/* Modified queen can only attack if another queen is
   within 5 blocks diagonally, 4 blocks horizontally
   and three blocks vertically. */

using namespace std;

bool isSafe( int n, int curr, int *board){
/*  Now, the board has one horizontal start and one end limit,
    one vertical start and one end limit, one diagonal start
    and one end limit for '\' and the same for '/'.

    It is important to define these since we've used a 1D array
    for the board.
*/

    int hstart = ( curr/n ) * n;
    int hend = ( curr/n + 1 ) * n - 1;

    int vstart = curr % n ;
    int vend = (curr % n) + n * ( n-1 );

    //d1 is '\'
    int d1start = 0;
    int d1end = n*n - 1;

    //d2 is '/'
    int d2start = 1;
    int d2end = n*n - 1;

    int i;
    for(i = 1; i <= 4; i ++){
        if( board[curr + i] && curr + i <= hend ){
            //To check if queen is placed within 4 blocks horizontally
            //and so that block is within the board
            return false;
        }

        if( board[curr - i] && curr - i >= hstart ){
            return false;
        }
    }

    for(i = 1; i <= 3; i ++){
        if( board[curr + n*i] && curr + n*i <= vend ){
            //To check if queen is placed within 3 blocks vertically
            //and so that block is within the board
            return false;
        }

        if(board[curr - n*i] && curr - n*i >= vstart){
            return false;
        }
    }

/*  The following loops check upper and lower side of each diagonal
    with respect to the current position of the queen. The first
    if condition in very loop ensures that the diagonal stays in
    one line and doesn't wrap around the board.

*/

    for(i = 1; i <= 5; i ++){
        if( (curr + i*(n + 1)) % n == 0 )
            break;
        if( board[curr + i*(n + 1)] && curr + i*(n + 1) <= d1end )
            return false;
    }

    for(i = 1; i <= 5; i ++){
        if( (curr - i*(n + 1)) % n == n-1 )
            break;
        if( board[curr - i*(n + 1)] && curr - i*(n + 1) >= d1start )
            return false;
    }

    for(i = 1; i <= 5; i ++){
        if( (curr + i*(n - 1)) % n == n-1 )
            break;
        if( board[curr + i*(n - 1)] && curr + i*(n - 1) <= d2end  )
            return false;
    }

    for(i = 1; i <= 5; i ++){
        if( (curr - i*(n - 1)) % n == 0 )
            break;
        if( board[curr - i*(n - 1)] && curr - i*(n - 1) >= d2start  )
            return false;
    }
    return true;
}

bool nQueen( int n, int curr, int *board){

    if( curr == n )
        return true;
        //Base case, all queens placed

    else{
        int i;
        for(i = curr; i < n*n; i = i + n){
            //One more condition here idk what.
            //Loop to place all n queens

            if(isSafe(n, i, board)){
                board[i] = 1;


            if(nQueen( n, curr + 1, board))
                return true;

            board[i] = 0;
            //Backtrack if no solution

            }
        }
    }
    return false;
}

int main(){
    cout << "Enter number of queens" << endl;
    int n;
    cin >> n;

    int board[n*n];
    //Store the blocks in a single contiguous array

    int i, j;
    for(i = 0; i < n*n; i ++){
        board[i] = 0;
    }
    //Clear the board

    int curr = 0;
    //The current position of the queen

    nQueen(n, curr, board);

    for(i = 0; i < n*n; i ++){
        cout<<board[i];
        if( (i+1)%n == 0)
            cout<<endl;
    }

    return 0;
}
