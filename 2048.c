#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define size 4

int board[size][size];

void initialize_board();
void print_board();
void merge_left();
void merge_right();
void merge_up();
void merge_down();
void get_rand_numbers();
int check_moves();
void process_input();
int check_extra_move();


int main()
{

    initialize_board();
    do
    {
        get_rand_numbers();
        print_board();
        char ch = getch();

        process_input(ch);
    }while(check_moves());
    system("CLS");
    printf("\nGame Over\n");
    return 0;
}


void initialize_board()
{
    int i,j;
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            board[i][j]=0;
        }
    }
}

void print_board()
{
    int i,j;
    system("CLS");
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            printf("%d\t",board[i][j]);
        }
        printf("\n");
    }
    printf("\nPress 'W' for up\nPress 'S' for down\nPress 'A' for left\nPress 'D' for right\nPress 'Q' to Quit the game");
}

void merge_left()
{
    int stop_i=-1,stop_j=-1;
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            for(int k=j-1; k>=0; k--)
            {

                if((stop_i!=i || stop_j!=k) && board[i][k]==board[i][j])
                {
                    board[i][k]+=board[i][j];
                    board[i][j]=0;
                    stop_i=i;
                    stop_j=k;
                }


                else if(board[i][k]>0)
                    break;
            }
        }
        for(int j=0; j<size; j++)
        {
            for(int k=0; k<j; k++)
            {
                if(board[i][k]==0)
                {
                    board[i][k]= board[i][j];
                    board[i][j]=0;
                }

            }
        }
    }
}



void merge_right()
{
    int stop_i=-1,stop_j=-1;
    for(int i=0; i<size; i++)
    {
        for(int j=size-1; j>=0; j--)
        {
            for(int k=j+1; k<size; k++)
            {

                if((stop_i!=i || stop_j!=k) && board[i][k]==board[i][j])
                {
                    board[i][k]+=board[i][j];
                    board[i][j]=0;
                    stop_i=i;
                    stop_j=k;
                }


                else if(board[i][k]>0)
                    break;
            }
        }
        for(int j=size-1; j>=0; j--)
        {
            for(int k=size-1; k>j; k--)
            {
                if(board[i][k]==0)
                {
                    board[i][k]= board[i][j];
                    board[i][j]=0;
                }

            }
        }
    }
}

void merge_up()
{
    int stop_i=-1,stop_j=-1;
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            for(int k=j-1; k>=0; k--)
            {

                if((stop_i!=i || stop_j!=k) && board[k][i]==board[j][i])
                {
                    board[k][i]+=board[j][i];
                    board[j][i]=0;
                    stop_i=i;
                    stop_j=k;
                }


                else if(board[k][i]>0)
                    break;
            }
        }
        for(int j=0; j<size; j++)
        {
            for(int k=0; k<j; k++)
            {
                if(board[k][i]==0)
                {
                    board[k][i]= board[j][i];
                    board[j][i]=0;
                }

            }
        }
    }
}

void merge_down()
{
    int stop_i=-1,stop_j=-1;
    for(int i=0; i<size; i++)
    {
        for(int j=size-1; j>=0; j--)
        {
            for(int k=j+1; k<size; k++)
            {

                if((stop_i!=i || stop_j!=k) && board[k][i]==board[j][i])
                {
                    board[k][i]+=board[j][i];
                    board[j][i]=0;
                    stop_i=i;
                    stop_j=k;
                }


                else if(board[i][k]>0)
                    break;
            }
        }
        for(int j=size-1; j>=0; j--)
        {
            for(int k=size-1; k>j; k--)
            {
                if(board[k][i]==0)
                {
                    board[k][i]= board[j][i];
                    board[j][i]=0;
                }

            }
        }
    }
}


void get_rand_numbers()
{
    int i,j;
    i=rand()%size;
    j=rand()%size;

    while(board[i][j] != 0)
    {
        i=rand()%size;
        j=rand()%size;
    }

    board[i][j] = 2;
}

int check_moves()
{
    int i,j,count=0;
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            if(board[i][j] == 0)
                count++;
        }
    }
    if(count == 0)
        return check_extra_move();
    else
        return 1;
}

void process_input(int ch)
{
    switch(ch)
    {
        case 'w' : merge_up();
                    break;
        case 's' : merge_down();
                    break;
        case 'a' : merge_left();
                    break;
        case 'd' : merge_right();
                    break;
        case 'q' : exit(0);
        default : printf("\n Invalid Input Try again\nPress any key to continue: ");
                    getch();
    }
}



int check_extra_move()
{
    int i,j,count=0;
    for(i=0;i<size;i++)
    {
        for(j=1;j<size;j++)
        {
            if(board[i][j]==board[i][j-1])
                count++;
        }
    }

    for(i=0;i<size;i++)
    {
        for(j=size-2;j>=0;j--)
        {
            if(board[i][j]==board[i][j+1])
                count++;
        }
    }
    for(i=0;i<size;i++)
    {
        for(j=1;j<size;j++)
        {
            if(board[j][i]==board[j][i-1])
                count++;
        }
    }

    for(i=0;i<size;i++)
    {
        for(j=size-2;j>=0;j--)
        {
            if(board[j][i]==board[j][i+1])
                count++;
        }
    }
    if(count==0)
        return 0;
    else
        return 1;
}
