#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <assert.h>

void testCard(){
	int numTests = 1000;
	int numPlayers;
	struct gameState game;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	int testsFailed = 0;


	printf("Smithy Card Test Start\n");

	srand(time(NULL));

	for(int i = 0; i < numTests; i++){
		printf("Test #%d:\n",i+1);

		// Set up test game
		numPlayers = rand() % 3 + 2;
		memset(&game,23,sizeof(struct gameState));
		initializeGame(numPlayers,k,1,&game);
	
		for(int j = 0; j < numPlayers;j++){

			// Set up random numbers of cards
			game.deckCount[j] = rand() % 21 + 5;
			game.handCount[j] = rand() % 8 + 3;
			game.discardCount[j] = rand() % 8 + 2;
		
			// Randomize deck
			for(int l = 0; l < game.deckCount[j];l++){
				if(rand() % 3 == 0){
					game.deck[j][l] = rand() % 3 + 1;
				}
				else{
					game.deck[j][l] = k[rand() % 10];
				}
			}


			// Randomize Hand
			for(int l = 0; l < game.handCount[j];l++){
				if(rand() % 3 == 0){
					game.hand[j][l] = rand() % 3 + 1;
				}
				else{
					game.hand[j][l] = k[rand() % 10];
				}
			}

			// Randomize discard
			for(int l = 0; l < game.discardCount[j]; l++){
				if(rand() % 3 == 0){
					game.discard[j][l] = rand() % 3 + 1;
				}
				else{
					game.discard[j][l] = k[rand() % 10];
				}
			}
		}

		// Put a smithy in a players hand
		game.whoseTurn = 0;
		int smithyCardPos = rand() % (game.handCount[0]);
		game.hand[0][smithyCardPos] = smithy;

		// Store counts before playing the card, for testing purposes	
		int deckCount[4];
		int handCount[4];
		int discardCount[4];
	       	for(int a = 0; a < numPlayers;a++){
			deckCount[a] = game.deckCount[a];
			handCount[a] = game.handCount[a];
			discardCount[a] = game.discardCount[a];
		}	

		int playCard = cardEffect(smithy, 0, 0, 0, &game, 1, 0);

		if(playCard){
			printf("Failed to play smithy card!\n");
			testsFailed = 1;
		}
		else{
			printf("Succesfully played smithy card!\n");
		}

		if(game.handCount[0] != handCount[0] + 3){
			printf("Failed to draw three cards.\n");
			testsFailed = 1;
		}
		else{
			printf("Succesfully drew three cards. \n");
		}

		for(int j = 1; j < numPlayers; j++){
		
			if(game.deckCount[j] != deckCount[j]){
				printf("ERROR: Player %d's deck was changed and it shouldn't have been!\n",j+1);
				testsFailed = 1;
			}
			else{
				printf("Player %d's deck was unchanged.\n",j);
			}

			if(game.handCount[j] != handCount[j]){
				printf("ERROR: Player %d's, hand was changed and it shouldn't have been!\n",j);
				testsFailed = 1;
			}
			else{
				printf("Player %d's hand was unchanged.\n",j);
			}

			if(game.discardCount[j] != discardCount[j]){
				printf("ERROR: Player %d's hand was changed and it shouldn't have been! \n",j);
				testsFailed = 1;
			}
			else{
				printf("Player %d's hand was unchanged.\n",j);
			}
		}
	}	

	if(testsFailed == 0){
		printf("All tests passed!\n");
	}
	else{
		printf("Some tests failed..\n");
	}

}

int main(){
	testCard();

	return 0;
}
