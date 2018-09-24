#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

void draw_board();
char take_input();
void process_input(char ch);
void go_left();
void go_up();
void go_down();
void go_right();
void clear_board();
void swap(int x1, int y1, int x2, int y2);
int check_win();

// Initial board , change the values and zero indexes for various boards
int board[4][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 0, 13, 14, 15};
int correct_board[4][4] = {1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9 ,10 ,11 ,12 ,13 ,14 ,15 ,0};
// Initially zero positions, first and second indexes, if 0 is at (1,3) first index will be 1 and second will be 3
int zero_pos_first_index = 3;
int zero_pos_seond_index = 0;

// Initial move count
int move_count = 0;

int main() {
    // Initially draw the board
	draw_board();
    // Loop till check_win is not equal to 1
	while(check_win()) {
		char ch = take_input();
		process_input(ch);
		move_count++;
		
		draw_board();
		
	}
        // Take input and store in ch
        // Process input (ch)
        // Clear the board
        // Draw the board again
        // Increase move count
	printf("You have won in %d moves",move_count);
    // End Loop
    // Print You have won with ___ Moves
    return 0;
}

void draw_board() {
/*
    Print the current board like
     1  2  3  4
     5  6  7  8
     9 10 11 12
    13 14  0 15

    ----------[W] UP --- [S] Down --- [A] LEFT --- [D] Right--------------
*/
	clear_board();
	int i,j;
	for(i=0;i<4;i++) {
		for(j=0;j<4;j++) {
			printf("%d\t",board[i][j]);
		}
		printf("\n");
	}

}

void clear_board() {
    // Clear the board
	
	system("CLS");
}

char take_input() {
/*
    Take input and return it, Use fflush() if scanf() is being used
*/
	char ch;
	ch = getch();
	return ch;
}

void process_input(char ch) {
/*
    Handle the input char ch, which is either w, a, s, d, for up, left, down and right
    Use a switch case and call go_left(), go_right() etc respectively
*/	
	switch(ch) {
		case 'w' : go_up();
				   break;
		case 'a' : go_left();
					break;
		case 's' : go_down();
					break;
		case 'd' : go_right();
					break;
		default : printf("Invalid input try again\n");
	}
}

void go_left() {
// Move 0 tile left
	if(zero_pos_seond_index!=0) {
		swap(zero_pos_first_index,zero_pos_seond_index,zero_pos_first_index,zero_pos_seond_index-1);
		zero_pos_seond_index--;
	}
	else {
		printf("Invalid input\nPress ant key to continue");
		getch();
	}
}

void go_right() {
// Move 0 tile right
	if(zero_pos_seond_index!=3) {
		swap(zero_pos_first_index,zero_pos_seond_index,zero_pos_first_index,zero_pos_seond_index+1);
		zero_pos_seond_index++;
	}
	else {
		printf("Invalid input\nPress ant key to continue");
		getch();
	}
}

void go_up() {
// Move 0 tile up
	if(zero_pos_first_index!=0) {
		swap(zero_pos_first_index,zero_pos_seond_index,zero_pos_first_index-1,zero_pos_seond_index);
		zero_pos_first_index--;
	}
	else {
		printf("Invalid input\nPress ant key to continue");
		getch();
	}
}

void go_down() {
// Move 0 tile down
	if(zero_pos_first_index!=3) {
		swap(zero_pos_first_index,zero_pos_seond_index,zero_pos_first_index+1,zero_pos_seond_index);
		zero_pos_first_index++;
	}
	else {
		printf("Invalid input\nPress ant key to continue");
		getch();
	}
}

void swap(int x1, int y1, int x2, int y2) {
// Swap board[x1][y1] and board[x2][y2];
	int temp;
	temp = board[x1][y1];
	board[x1][y1] = board[x2][y2];
	board[x2][y2] = temp;
}

int check_win() {
// Return 1 , if current board has all tiles perfectly places ,or 0 otherwise
	int i,j;
	for(i=0;i<4;i++) {
		for(j=0;j<4;j++) {
			if(board[i][j]!=correct_board[i][j])
				return 1;
		}
	}
	return 0;
}
