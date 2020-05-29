#include <stdio.h>
#define array_size 100
#define gen_count 50

void swap_arrays(int *current_state, int *next_state, int size);
void print_state(int *state , int state_length);
void initialize_array(int *array_to_initialize, int state_length);
void calculate_next_state(int *current_state, int *next_state, int state_length);
int get_rule(int a,int b,int c);


void main(){
	// initializing current and next state arrays
	int cur[array_size] = {0};
	int next[array_size] = {0};
	initialize_array(cur, array_size);
	
	int i; // performing operations in number of generation count
	for(i = 0; i < gen_count; i++){
		calculate_next_state(cur, next, array_size);
		print_state(cur, array_size);
		printf("\n");
		swap_arrays(cur, next, array_size);
	}
	
}



void print_state(int *state , int state_length){
	int i;
	// because arrays contain zeros and ones converting
	// them to underscore and hashtag for a better look
	for(i = 0; i < state_length; i++){
			if(state[i] == 0){
				printf("_ "); 
			}
			else if(state[i] == 1){
				printf("# ");
			}

	}
	
}

void initialize_array(int *array_to_initialize, int state_length){
	// setting the middle point of the array
	int midpoint = (state_length / 2) - 1;
	array_to_initialize[midpoint] = 1;
}

void swap_arrays(int *current_state, int *next_state, int size){
	
	int i;
	// transfering all the elements of the next_state array to current_state array
	for(i = 0; i < size; i++){
		current_state[i] = next_state[i];
	}
	
}

void calculate_next_state(int *current_state, int *next_state, int state_length){
	
	int left, middle, right, i;
	// sending 3 neighbors to get_rule function to get 
	// the return of rule 30
	for(i = 1; i < state_length - 1; i++){
		left = current_state[i-1];
		middle = current_state[i];
		right = current_state[i+1];
		next_state[i] = get_rule(left, middle, right);
	}
	
}


int get_rule(int l,int m,int r){
	int num;
	// converting 3 binary variables to decimals
	// to easily calculate the corresponding value by the rule 30
	l *= 100;
	m *= 10;
	num = l+m+r;
	if(num > 0 && num < 101){
		return 1;
	}
	else{
		return 0;
	}
}
