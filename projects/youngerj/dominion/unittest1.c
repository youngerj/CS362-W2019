#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
 
#define NOISY_TEST 1

int main(){

	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    	struct gameState G;
	
	r = initializeGame(2, k, 1, &G);

	printf("TESTING: getCost() with 2 cards (adventurer and smithy)\n");

#if (NOISY_TEST == 1)
	printf("Testing getCost of adventurer: \n");
#endif
	if(getCost(0) == 6){
		printf("test passed! \n");
	}
	else{
		printf("test failed! \n");
	}

#if (NOISY_TEST == 1)
	printf("Testing getCost of smithy: \n");
#endif
	if(getCost(6) == 4){
		printf("test passed! \n");
	}
	else{
		printf("test failed! \n");
	}
#if (NOISY_TEST == 1)
	printf("Testing getCost of non-exisistant card: \n");
#endif	
	if(getCost(-5) == -1){
		printf("test passed! \n");
	}
	else{
		printf("test failed! \n");
	}

	printf("Testing complete! \n");


	return 0;
}
