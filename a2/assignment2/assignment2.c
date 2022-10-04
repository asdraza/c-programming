#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define B_MARK    "  B  "
#define W_MARK    "  W  "
#define POSSIBLE_MOVE_MARK "  .  "
#define EMPTY_MARK    "     "
#define W    0
#define B    1
#define EMPTY    2
#define PLAYABLE 3
#define FALSE 0
#define TRUE  1
const char *row = "01234567";
const char *column= "01234567";


char size_of_board[8][8];
int play_direction[8][8][8];
int Present_player;
int game_over = FALSE;
int turnSkip = FALSE;
int invalid_move = FALSE;
int valid_move = FALSE;
int score[2];



void start_game( )
{
    memset(size_of_board, EMPTY, sizeof( size_of_board ) );
    score[W] = 2;
    score[B] = 2;
    size_of_board[3][3] = B;
    size_of_board[3][4] = W;
    size_of_board[4][4] = B;
    size_of_board[4][3] = W;
    Present_player = B;
}

int valid_position( int i, int j )
{
    if ( i < 0 || i >= 8 || j < 0 || j >= 8 ) return FALSE;
    return TRUE;
}

int distance( int i1, int j1, int i2, int j2 )
{
    int di = abs( i1 - i2 );
    int dj = abs( j1 - j2 );
    if ( di > 0 )
        return di;
    return dj;
}


int play( int i, int j )
{
    memset( play_direction[i][j], 0, 8 );
    if ( !valid_position( i, j ) )
        return FALSE;
    if ( size_of_board[i][j] != EMPTY )
        return FALSE;

    int playable = FALSE;

    int opponent_player = ( Present_player + 1 ) % 2;

    // Tests UL diagonal
    int a = i-1, b = j-1;
    while ( valid_position( a, b ) && size_of_board[a][b] == opponent_player )
    {
        a -= 1;
        b -= 1;
    }
    if ( valid_position( a, b ) && distance( i, j, a, b ) > 1 && size_of_board[a][b] == Present_player )
    {
        play_direction[i][j][0] = 1;
        playable = TRUE;
    }

    // Tests UP path
    a = i-1, b = j;
    while ( valid_position( a, b ) && size_of_board[a][b] == opponent_player )
        a -= 1;

    if ( valid_position( a, b ) && distance( i, j, a, b ) > 1 && size_of_board[a][b] == Present_player )
    {
        play_direction[i][j][1] = 1;
        playable = TRUE;
    }

    // Tests UR diagonal
    a = i-1, b = j+1;
    while ( valid_position(a,b) && size_of_board[a][b] == opponent_player )
    {
        a -= 1;
        b += 1;
    }
    if (valid_position( a, b ) && distance( i, j, a, b ) > 1 && size_of_board[a][b] == Present_player )
    {
        play_direction[i][j][2] = 1;
        playable = TRUE;
    }

    // Tests LEFT path
    a = i, b = j-1;
    while ( valid_position( a, b ) && size_of_board[a][b] == opponent_player )
        b -= 1;

    if ( valid_position( a, b ) && distance( i, j, a, b ) > 1 && size_of_board[a][b] == Present_player )
    {
        play_direction[i][j][3] = 1;
        playable = TRUE;
    }

    // Tests the RIGHT path
    a = i, b = j+1;
    while ( valid_position( a, b ) && size_of_board[a][b] == opponent_player )
        b += 1;

    if ( valid_position( a, b ) && distance( i, j, a, b ) > 1 && size_of_board[a][b] == Present_player )
    {
        play_direction[i][j][4] = 1;
        playable = TRUE;
    }

    // Tests the DL diagonal
    a = i+1, b = j-1;
    while ( valid_position( a, b ) && size_of_board[a][b] == opponent_player )
    {
        a += 1;
        b -= 1;
    }
    if ( valid_position( a, b ) && distance( i, j, a, b ) > 1 && size_of_board[a][b] == Present_player )
    {
        play_direction[i][j][5] = 1;
        playable = TRUE;
    }

    // Tests the DOWN path
    a = i+1, b = j;
    while ( valid_position( a, b ) && size_of_board[a][b] == opponent_player )
        a += 1;

    if ( valid_position( a, b ) && distance( i, j, a, b ) > 1 && size_of_board[a][b] == Present_player )
    {
        play_direction[i][j][6] = 1;
        playable = TRUE;
    }

    // Tests the DR diagonal
    a = i+1, b = j+1;
    while ( valid_position( a, b ) && size_of_board[a][b] == opponent_player )
    {
        a += 1;
        b += 1;
    }
    if ( valid_position( a, b ) && distance( i, j, a, b ) > 1 && size_of_board[a][b] == Present_player )
    {
        play_direction[i][j][7] = 1;
        playable = TRUE;
    }
    return playable;
}

void possible_next_move( )
{
    valid_move = FALSE;
    for ( int i=0; i<8; ++i )
    {
        for ( int j=0; j<8; ++j )
        {
            if ( size_of_board[i][j] == PLAYABLE )
                size_of_board[i][j] = EMPTY;
            if ( play( i, j ) )
            {
                size_of_board[i][j] = PLAYABLE;
                valid_move = TRUE;
            }
        }
    }
}

void draw_board( )
{
    printf( "     %c     %c     %c     %c     %c     %c     %c     %c\n", column[0], column[1], column[2], column[3], column[4], column[5], column[6], column[7] );
    printf( "   _____ _____ _____ _____ _____ _____ _____ _____\n" );
    for ( int i=0; i<8; ++i )
    {
        printf( "  |     |     |     |     |     |     |     |     |\n" );
        printf( "%c |", row[i] );
        for ( int j=0; j<8; ++j )
        {
            if ( size_of_board[i][j] == W )
            {
                printf( "%s", W_MARK );
            } else if ( size_of_board[i][j] == B )
            {
                printf( "%s", B_MARK );
            } else if ( size_of_board[i][j] == PLAYABLE )
            {
                printf( "%s", POSSIBLE_MOVE_MARK  );
            } else
            {
                printf( "%s", EMPTY_MARK );
            }
            printf("|");
        }
        printf( "\n" );
        printf( "  |_____|_____|_____|_____|_____|_____|_____|_____|\n" );
    }
    printf( "\n" );
}

void show_invalid_move( )
{
    if ( invalid_move )
    {
        printf( "You entered an invalid move!\n" );
        invalid_move = FALSE;
    }
}

void display_Present_player( )
{
    printf( "Current player:" );
    printf("%s", Present_player == W ? W_MARK : B_MARK);
    printf( "\n" );
}

void change_Present_player( )
{
    Present_player = ( Present_player + 1 ) % 2;
}

void prompt_move( int *p_row, int *p_column )
{
    printf( "Enter row [0-7] and column [0-7] separated by a single space (eg.: 2 4).\n" );
    scanf( "%d %d", p_row, p_column );
}

void capture_pieces( int i, int j )
{
    int opponent_player = ( Present_player + 1 ) % 2;
    int a, b;

    // Capture UL diagonal
    if ( play_direction[i][j][0] )
    {
        a = i-1, b = j-1;
        while ( size_of_board[a][b] == opponent_player )
        {
            size_of_board[a][b] = Present_player;
            score[Present_player]++;
            score[opponent_player]--;
            a -= 1;
            b -= 1;
        }
    }

    // Capture UP path
    if ( play_direction[i][j][1] )
    {
        a = i-1, b = j;
        while ( size_of_board[a][b] == opponent_player )
        {
            size_of_board[a][b] = Present_player;
            score[Present_player]++;
            score[opponent_player]--;
            a -= 1;
        }
    }

    // Captures UR diagonal
    if ( play_direction[i][j][2] )
    {
        a = i-1, b = j+1;
        while ( size_of_board[a][b] == opponent_player )
        {
            size_of_board[a][b] = Present_player;
            score[Present_player]++;
            score[opponent_player]--;
            a -= 1;
            b += 1;
        }
    }

    // Capture LEFT path
    if ( play_direction[i][j][3] )
    {
        a = i, b = j-1;
        while ( size_of_board[a][b] == opponent_player )
        {
            size_of_board[a][b] = Present_player;
            score[Present_player]++;
            score[opponent_player]--;
            b -= 1;
        }
    }

    // Capture RIGHT path
    if ( play_direction[i][j][4] )
    {
        a = i, b = j+1;
        while ( size_of_board[a][b] == opponent_player )
        {
            size_of_board[a][b] = Present_player;
            score[Present_player]++;
            score[opponent_player]--;
            b += 1;
        }
    }

    // Capture DL diagonal
    if ( play_direction[i][j][5] )
    {
        a = i+1, b = j-1;
        while ( size_of_board[a][b] == opponent_player )
        {
            size_of_board[a][b] = Present_player;
            score[Present_player]++;
            score[opponent_player]--;
            a += 1;
            b -= 1;
        }
    }

    // Capture DOWN path
    if ( play_direction[i][j][6] )
    {
        a = i+1, b = j;
        while ( size_of_board[a][b] == opponent_player )
        {
            size_of_board[a][b] = Present_player;
            score[Present_player]++;
            score[opponent_player]--;
            a += 1;
        }
    }

    // Capture DR diagonal
    if ( play_direction[i][j][7] )
    {
        a = i+1, b = j+1;
        while ( size_of_board[a][b] == opponent_player )
        {
            size_of_board[a][b] = Present_player;
            score[Present_player]++;
            score[opponent_player]--;
            a += 1;
            b += 1;
        }
    }
}

void next_move( )
{
    int row, column;
    prompt_move( &row, &column );
    if ( valid_position( row, column ) && size_of_board[row][column] == PLAYABLE )
    {
        size_of_board[row][column] = Present_player;
        score[Present_player]++;
        capture_pieces( row, column );
        change_Present_player(  );
    }
    else invalid_move = TRUE;
}

void winner( )
{
    printf( "Final score:\n%s: %d %s: %d\n", W_MARK, score[W], B_MARK, score[B] );
    if ( score[W] > score[B] )
        printf( "%s wins.\n", W_MARK );
    else if ( score[W] < score[B] )
        printf( "%s wins.\n", B_MARK );
    else
        printf( "Draw game.\n" );
}

void display_score( )
{
    printf( "%s: %d %s: %d\n", W_MARK, score[W], B_MARK, score[B] );
}

int main( )
{
    printf("*** Welcome to Othello! ***\n");
    start_game();

    while ( !game_over )
    {
        if ( !invalid_move )
            possible_next_move( );
        if ( !valid_move )
        {
            if ( turnSkip )
            {
                game_over = 1;
                draw_board( );
                continue;
            }
            turnSkip = 1;
            change_Present_player( );
            continue;
        }
        turnSkip = 0;
        draw_board( );
        display_score( );
        display_Present_player( );
        show_invalid_move( );
        next_move( );
    }
    
    winner( );
}
