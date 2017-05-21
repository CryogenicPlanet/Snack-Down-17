/*
 ============================================================================
 Name        : SameSnake.c
 Author      : Dhruv
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int debug = 1;

int main(void) {
	int testcases, condition = 0;
	long long xh1,yh1,xt1,yt1;// X & Y coordinates of Head1(h1) && Tail1(t1)
	long long xh2,yh2,xt2,yt2;// X & Y coordinates of Head2(h2) && Tail2(t2)
	int pos1, pos2;// 0 = vertical 1 = horizontal
	scanf("%d", &testcases);
	for(int a = 0; a < testcases; a++)
	{
		condition = 0;
		scanf("%lld %lld %lld %lld", &xh1, &yh1, &xt1, &yt1);
		if (debug) printf("First: %lld %lld %lld %lld\n", xh1, yh1, xt1, yt1);
		scanf("%lld %lld %lld %lld", &xh2, &yh2, &xt2, &yt2);
		if (debug) printf("Second: %lld %lld %lld %lld\n", xh2, yh2, xt2, yt2);

		// which direction do the snakes move
		if(xh1 != xt1) pos1 = 0;
		else if(xh1 == xt1 && yh1 == yt1) pos1 = 2;
		else pos1 = 1;


		if(xh2 != xt2) pos2 = 0;// moves vertically
		else if(xh1 == xt1 && yh1 == yt1) pos1 = 2;
				else pos2 = 1;//  moves horizontally
		if(pos1 == pos2)
		{
			//all you need to make sure is that the points intersect. Since they move in same direction.
			if(xh1 == xh2)// if the snakes meet on x axis.
			{
				if(yh2 >= yt1 && yh2 <= yh1){// if head of snake2 is between tail & head of other snake.
					if (debug) printf ("YT1H2H1\n");
					condition = 1;
				}
				else if(yh1 >= yt2 && yh1 <= yh2){// if head of snake is between tail & head of other snake.
					if (debug) printf ("YT2H1H2\n");
					condition = 1;
				}
				else if(yt2 >= yt1 && yt2 <= yh1){// if tail of snake 2 is between tail & head of other snake.
					if (debug) printf ("YT1T2H1\n");
					condition = 1;
				}
				else if(yt1 >= yt2 && yt1 <= yh2){// if tail of snake is between tail & head of other snake.
					if (debug) printf ("YT2T1H2\n");
					condition = 1;
				}

				else if(yh2 <= yt1 && yh2 >= yh1){
					if (debug) printf ("YH1H2T1\n");
					condition = 1;
				}
				else if(yh1 <= yt2 && yh1 >= yh2){
					if (debug) printf ("YH2H1T2\n");
					condition = 1;
				}
				else if(yt2 <= yt1 && yt2 >= yh1){
					if (debug) printf ("YH1T2T1\n");
					condition = 1;
				}
				else if(yt1 <= yt2 && yt1 >= yh2){
					if (debug) printf ("YH2T1T2\n");
					condition = 1;
				}

			}
			else if(yh1 == yh2)// if the snakes are meeting on y axis.
			{
				if(xh2 >= xt1 && xh2 <= xh1) {
					if (debug) printf ("XT1H2H1\n");
					condition = 1;// if head of snake 2 is between tail & head of other snake.
				}
				else if(xt2 >= xt1 && xt2 <= xh1) {
					if (debug) printf ("XT1T2H1\n");
					condition = 1;// if tail of snake 2 is between tail & head of other snake.
				}
				else if(xh1 >= xt2 && xh1 <= xh2) {
					if (debug) printf ("XT2H1H2\n");
					condition = 1;// if head of snake is between tail & head of other snake.
				}
				else if(xt1 >= xt2 && xt1 <= xh2) {
					if (debug) printf ("XT2T1H2\n");
					condition = 1;// if tail of snake is between tail & head of other snake.

				}
				else if(xh2 <= xt1 && xh2 >= xh1) {
					if (debug) printf ("XH1H2T1\n");
					condition = 1;//
				}
				else if(xt2 <= xt1 && xt2 >= xh1) {
					if (debug) printf ("XH1T2T1\n");
					condition = 1;//
				}
				else if(xh1 <= xt2 && xh1 >= xh2) {
					if (debug) printf ("XH2H1T2\n");
					condition = 1;//
				}
				else if(xt1 <= xt2 && xt1 >= xh2) {
					if (debug) printf ("XH2T1T2\n");
					condition = 1;//
				}
			}
		}
		else if(pos1 != pos2)
		{
			//there should only be one intersection at edges. Since they are at 90 degrees.
			if(xh1 == xh2 && yh1 == yh2)
			{
				if (debug) printf ("H1H2\n");
				condition = 1;
			}
			else if(xh1 == xt2 && yh1 == yt2)
			{
				if (debug) printf ("H1T2\n");
				condition = 1;
			}
			else if(xt1 == xh2 && yt1 == yh2)
			{
				if (debug) printf ("T1H2\n");
				condition = 1;
			}
			else if(xt1 == xt2 && yt1 == yt2)
			{
				if (debug) printf ("T1T2\n");
				condition = 1;
			}
			else condition = 0;
		}
		if(condition == 1)
			printf("yes\n");
		else
			printf("no\n");
	}
	return EXIT_SUCCESS;
}
