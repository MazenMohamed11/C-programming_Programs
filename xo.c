#include<stdio.h>
#define WINEER_EXIST 10
#define PLAYER1_WIN 15
#define PLAYER2_WIN 20
#define DRAW 30
#define MOVE_POSSIBILITY 1
#define ZERO_MOVE 0

char position[3][3]={{'1','2','3'},
	             {'4','5','6'},
                     {'7','8','9'}};

int move = ZERO_MOVE ; // we can make 9 moves at maximum					 
int available_move = MOVE_POSSIBILITY; // to know if we have move 	
char player_mark;	
char player_one_mark;
char player_two_mark;	

/*Functions declariation*/
void print_board(void);
void game_Init(void);
void game_running(void);
void check_position(char c_pos);
void check_win(char player);

/* function to print the board
*  Input:  Nothing  
*  Return: Nothing 
*/
void print_board(void)
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
		printf("|%c| ",position[i][j]);
		}
		printf("\n");
	}	
}

/* function to initialize the game
*  Input:  Nothing  
*  Return: Nothing 
*/
void game_Init(void)
{
	int flag=1;
    printf("----- Welcome ------\n");
    printf("----- X-O Game -----\n");
	while(flag)
	{
	printf("Player 1,Please choose your mark 'X' or 'O' :");
	scanf(" %c",&player_one_mark);
	if(player_one_mark =='X'|| player_one_mark =='O')
	{	
       flag=0;
	}
    else
    {
		printf("wrong choice,Try again \n");
    }	
	}
	if(player_one_mark == 'O')
	{
		player_two_mark = 'X';
	}
    else
    {
	    player_two_mark = 'O';
    }	
	printf("Player 1 : %c \n",player_one_mark);
	printf("Player 2 : %c \n",player_two_mark);
}
/* function to run the game
*  Input:  Nothing  
*  Return: Nothing 
*/
void game_running(void)
{
	char pos;
	while(available_move<10)
	{
		if(move%2==0)
		{
			player_mark=player_one_mark;
			printf("player 1 , choose a position : ");
		    scanf(" %c",&pos);
			check_position(pos);
			print_board();
			check_win(player_mark);
			   if(available_move==10)
			   {
				  available_move =PLAYER1_WIN;
			   } 
			   else
			   {}
		   
		}
		else
		{
			player_mark=player_two_mark;
			printf("player 2 , choose a position : ");
		    scanf(" %c",&pos);
			check_position(pos);
			print_board();
			check_win(player_mark);
			   if(available_move==10)
			   {
				  available_move =PLAYER2_WIN;
			   }
			   else
			   {}
		}
        if(move == 9)
		{
			printf("Draw");
			available_move=DRAW;
		}
        else
		{}			 
	}
	if(available_move == PLAYER1_WIN)
	{
		printf("Player 1 is the winners\n");
	}
	else if(available_move == PLAYER2_WIN)
	{
		printf("Player 2 is the winners\n");
	}
}

/* function to check if position is free
*  Input:  Choosen position 
*  Return: Nothing 
*/
void check_position(char c_pos)
 {
	 int flag=1;
	 int i,j;
	 while(flag)
	 {  for(i=0;i<3;i++)
	    {
		   for(j=0;j<3;j++)
		   {
		    if(position[i][j]==c_pos)
			{
				position[i][j]=player_mark;
			    flag=0;
				move++;
				break;
			}
			else
		    {
				flag=1;
		    }
		   }
		   if(flag==0)
		   {
			   break;
		   }
       		else
			{}				
	    }
	if(flag==1)
	{
		printf("wrong choice, try again\n");
		game_running();
	}
	else
	{}
	 }	
 }

/* function to check if the whineer
*  Input:  player mark  
*  Return: Nothing 
*/ 
 void check_win(char player)
 {
    int i;    
    for (i = 0; i < 3; i++)
	{
        if ((position[i][0] == player) && //for horizontal check
            (position[i][1] == player) && 
            (position[i][2] == player))
		{
            available_move =WINEER_EXIST;
        }
		else if ((position[0][0] == player) && //for diagonal check
                 (position[1][1] == player) &&
                 (position[2][2] == player))
		{
             available_move =WINEER_EXIST;
        }
        else if ((position[0][i] == player) && //for vertical check
                 (position[1][i] == player) &&
                 (position[2][i] == player))
		{
			available_move =WINEER_EXIST;       
        }
		else
		{}
    }
 }
	 
void main(void)
{
	game_Init();
	print_board();
	game_running();
}
	
