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

	printf("TESTING: numHandCars() with 2 cards (adventurer and smithy)\n");

  for(int i =0; i < 2;i++){
#if (NOISY_TEST == 1)
	  printf("Testing numHandCards of player %d: \n",i);
#endif
    G.handCount[i] = 5;
	  if(G.handCount[i] == 5){
	  	printf("test passed! \n");
	  }
	  else{
	  	printf("test failed! \n");
	  }
     endTurn(&G);
  }

	printf("Testing complete! \n");

	return 0;
}
