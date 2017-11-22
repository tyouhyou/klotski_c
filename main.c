/*
 ============================================================================
 Name        : Klotski.c
 Author      : zb
 Version     :
 Copyright   : copyright notice
 Description : Ansi-style
 ============================================================================
 */

#include <sys/time.h>
#include <stdlib.h>
#include "Klotski.h"

int main(void) {
	struct timeval tv1;
	struct timeval tv2;
	int i, cnt, steps = 0;
	Board b = NULL;
	StartBoard	**sb = malloc(sizeof(StartBoard *));

	cnt = getStartBoards(sb);
	b = sb[0]->board;

	if (!b) {
		fprintf(stderr, "failed to retrieve the start board\n");
		return 1;
	}
	gettimeofday(&tv1,NULL);
	start();
	steps = doAnalysis(b);
	gettimeofday(&tv2,NULL);

	if (steps <= 0) {
		fprintf(stderr, "failed to find way out\n");
		return 1;
	}

	while (b!=NULL) {
		printBoard(b);
		b = getNextBoard(b);
	}

	for (i=0;i<cnt;i++) {
		free(sb[i]);
	}
	free(sb);

	end();

	fprintf(stderr, "\nTotal steps %d\n", steps);
	fprintf(stderr, "Time consumption: %ld sec, %ld micro seconds\n", tv2.tv_sec-tv1.tv_sec, tv2.tv_usec-tv1.tv_usec);

	return 0;
}
