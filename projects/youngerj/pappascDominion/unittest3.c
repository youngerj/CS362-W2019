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
	
	int r = initializeGame(2, k, 1, &G);

	printf("TESTING: supplyCount() with 2 cards (adventurer and smithy)\n");

#if (NOISY_TEST == 1)
	printf("Testing supplyCount of adventurer: \n");
#endif
  G.supplyCount[0] = 5;
	if(supplyCount(0,&G) == 5){
		printf("test passed! \n");
	}
	else{
		printf("test failed! \n");
	}

#if (NOISY_TEST == 1)
	printf("Testing supplyCount of smithy: \n");
#endif
  G.supplyCount[6] = 5;
	if(supplyCount(6,&G) == 5){
		printf("test passed! \n");
	}
	else{
		printf("test failed! \n");
	}

#if (NOISY_TEST == 1)
	printf("Testing supplyCount of non-exisistant card: \n");
#endif	
	if(supplyCount(-5,&G) == -1){
		printf("test passed! \n");
	}
	else{
		printf("test failed! \n");
	}

	printf("Testing complete! \n");


	return 0;
}
