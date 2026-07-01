#include <stdio.h>

#define MAX_ROUNDS 5

struct player {
	char moves[MAX_ROUNDS];
	int t, r, p, s;	
	int score;
};

void move(int round, struct player *player);
void score(int round, struct player *player_a, struct player *player_b);
void flush_stdin();

int main(void)
{
	struct player player_a = {};
	struct player player_b = {};
	for (int round = 0; round < MAX_ROUNDS; round++) {
		move(round, &player_a);
		move(round, &player_b);
		score(round, &player_a, &player_b);		
		printf("\nround: %d, player_a: %c, player_b: %c\n", 
		        round, player_a.moves[round], player_b.moves[round]);
		printf("score player_a: %d, score player_b: %d\n\n",
		        player_a.score, player_b.score);
	}
	printf("player_a:");
	for (int round = 0; round < MAX_ROUNDS; round++) {
		printf(" [%c]", player_a.moves[round]);
	}
	printf("\nplayer_b:");
	for (int round = 0; round < MAX_ROUNDS; round++) {
		printf(" [%c]", player_b.moves[round]);
	}
	printf("\nplayer_a T: %d R: %d P: %d S: %d\n", 
	        player_a.t, player_a.r, player_a.p, player_a.s);
	printf("player_b T: %d R: %d P: %d S: %d\n", 
	        player_b.t, player_b.r, player_b.p, player_b.s);
	
	return 0;
}

void flush_stdin() 
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

void move(int round, struct player *player)
{
	char input = 0;
	while(input != 'c' && input != 'd') {
		printf("(c)ooperate or (d)efect\n");
		if (scanf(" %c", &input) != 1) {
			printf("failed to read input\n");
		}
		flush_stdin();
	}
	player->moves[round] = input;
}

void score(int round, struct player *player_a, struct player *player_b)
{
	if (player_a->moves[round] == 'c' && player_b->moves[round] == 'c') {
		player_a->r += 1;
		player_b->r += 1;
		player_a->score += 3;
		player_b->score += 3;
	} else if (player_a->moves[round] == 'c' && 
	           player_b->moves[round] == 'd') {
		player_a->s += 1;
		player_b->t += 1;
		player_a->score += 0;
		player_b->score += 5;
	} else if (player_a->moves[round] == 'd' && 
	           player_b->moves[round] == 'c') {
		player_a->t += 1;
		player_b->s += 1;
		player_a->score += 5;
		player_b->score += 0;
	} else if (player_a->moves[round] == 'd' && 
	           player_b->moves[round] == 'd') {
		player_a->p += 1;
		player_b->p += 1;
		player_a->score += 1;
		player_b->score += 1;
	} else {
		printf("not a valid round\n");
	}
}
