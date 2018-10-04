#include<stdio.h>
#define size 4

int board[size][size]= {2,0,0,0,2,0,0,0,4,0,0,0,4,0,0,0};
void merge_left();
void merge_right();
void merge_up();
void merge_down();
int main()
{
    merge_down();
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            printf("%d\t",board[i][j] );
        }
        printf("\n" );
    }
    printf("\n");
    return 0;
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
