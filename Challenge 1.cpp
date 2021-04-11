#include <stdio.h>
#include <iostream>

enum STATE {START, N, NA, NAN, NANO};
enum STATE state = START;

enum STATE Start(int c);
enum STATE n(int c);
enum STATE Na(int c);
enum STATE Nan(int c);
enum STATE Nano(int c);

using namespace std;

int main(){
	int c;
	enum STATE state = START;
	
	while ((c = getchar())!= EOF){
		if (state == START){
			state = Start(c);
		}
		else if (state == N){
			state = n(c);
		}
		else if (state == NA){
			state = Na(c);
		}
		else if (state == NAN){
			state = Nan(c);
		}
		else if (state == NANO){
			state = Na(c);
			fprintf(stdout, "string found\n");
			state = START;
		}
	}
	return 0;
}

enum STATE Start (int c){
	enum STATE state;
	
	if((char)c == 'n')
	state = N;
	else state = START;
	return state;
}

enum STATE n (int c){
	enum STATE state = N;
	
	if((char) c == 'n')
	state = N;
	else if ((char) c == 'a')
	state = NA;
	else state = START;
	return state;
}

enum STATE Na (int c){
	enum STATE state = NA;
	
	if((char) c == 'n')
	state = NAN;
	else state = START;
	return state;
}

enum STATE Nan (int c){
	enum STATE state = NAN;
	
	if((char) c == 'o')
	state = NANO;
	else if ((char) c == 'n')
	state = N;
	else if ((char)c == 'a')
	state = NA;
	return state;
}

enum STATE Nano (int c){
	enum STATE state = START;
	return state;
}
