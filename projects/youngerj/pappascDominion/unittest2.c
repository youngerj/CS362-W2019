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

	printf("TESTING: buyCard()\n");

#if (NOISY_TEST == 1)
	printf("Testing buyCard with no money: \n");
#endif
  G.numBuys = 1;
  G.coins = 0;

	if(buyCard(1, &G) == -1){
		printf("test passed! \n");
   }
	else{
		printf("test failed! \n");
  }
  
#if (NOISY_TEST == 1)
	printf("Testing buyCard with no buys left: \n");
#endif
  G.numBuys = 0;
  G.coins = 6;

	if(buyCard(2, &G) == -1){
		printf("test passed! \n");
   }
	else{
		printf("test failed! \n");
  }
    
#if (NOISY_TEST == 1)
	printf("Testing buyCard on good card: \n");
#endif	

  G.numBuys = 1;
  G.coins = 10;

  if(buyCard(2, &G) == 0){
		printf("test passed! \n");	
	}
	else{
		printf("test failed! \n");
	}

	printf("Testing complete! \n");
 
  return 0;

}
