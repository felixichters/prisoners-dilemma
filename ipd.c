#include <stdio.h>

struct state {
	int T, R, P, S;
	float w;
};

void move(struct state *state);


int main(void)
{
	return 0;
}

void move(struct state *state) 
{
	char input_a;
	scanf("%c", &input_a);

	if (input_a != 'c' || input_a != 'd') {
		printf("choose either (c)ooperate or (d)efect");
	}
	
	char input_b;
	scanf("%c", &input_b);

	if (input_a == 'c') {

	} else if (input_a == 'd') {
		
	} else {
		printf("choose either (c)ooperate or (d)efect");
	}
}
