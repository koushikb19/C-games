#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define size 4

int board[size][size];

void initialize_board();
void print_board();
void go_left();
void rotate_clock();
void add_left();
void add_up();
void add_down();
void add_right();
void get_rand_numbers();
int board_empty();
void process_input();

int main()
{

    initialize_board();
    do
    {
        print_board();
        char ch = getch();
        get_rand_numbers();
        process_input(ch);
    }while(board_empty());
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
    printf("\nPress 'W' for up\nPress 'S' for down\nPress 'A' for left\nPress 'D' for right");
}

void go_left()
{
    int i,j,k;
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            for(k=0;k<j;k++)
            {
                if(board[i][k]==0)
                {
                    board[i][k]=board[i][j];
                    board[i][j]=0;
                }
            }
        }
    }
}

void rotate_clock()
{
      int temp;

  for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            temp = board[i][j];
            board[i][j] = board[j][i];
            board[j][i] = temp;
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size / 2; j++)
        {
            temp = board[i][j];
            board[i][j] = board[i][size - 1 - j];
            board[i][size - 1 - j] = temp;
        }
      }
}

void add_left()
{
    int i,j,k,stop_i=-1,stop_j=-1;
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            for(k=j-1; k>=0; k--)
            {
                if(stop_i!=i || stop_j!=k)
                {
                    if(board[i][k]==board[i][j])
                    {
                        board[i][k]+=board[i][j];
                        board[i][j]=0;

                    }
                }
            }
        }
    }
    go_left();
}

void add_up()
{
    rotate_clock();
    rotate_clock();
    rotate_clock();
    add_left();
    rotate_clock();
}

void add_down()
{
    rotate_clock();
    add_left();
    rotate_clock();
    rotate_clock();
    rotate_clock();
}

void add_right()
{
    rotate_clock();
    rotate_clock();
    add_left();
    rotate_clock();
    rotate_clock();
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

int board_empty()
{
    int i,j;
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            if(board[i][j] != 0)
                return 1;
        }
    }
    return 0;
}

void process_input(int ch)
{
    switch(ch)
    {
        case 'w' : add_up();
                    break;
        case 's' : add_down();
                    break;
        case 'a' : add_left();
                    break;
        case 'd' : add_right();
                    break;
        default : printf("\n Invalid Input Try again\nPress any key to continue: ");
                    getch();
    }
}
