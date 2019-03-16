CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
	gcc -o randomtestadventurer randomtestadventurer.c dominion.o rngs.o $(CFLAGS)

randomtestcard1: randomtestcard1.c dominion.o rngs.o
	gcc -o randomtestcard1 -g randomtestcard1.c dominion.o rngs.o $(CFLAGS)


randomtestcard2: randomtestcard2.c dominion.o rngs.o
	gcc -o randomtestcard2 -g randomtestcard2.c dominion.o rngs.o $(CFLAGS)

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

testadventurer: randomtestadventurer
	./randomtestadventurer &> randomtestadventurerresult.out
	gcov randomtestadventurer.c >> randomtestadventurerresult.out
	cat randomtestadventurer.c.gcov >> randomtestadventurerresult.out

randomtest1: randomtestcard1
	./randomtestcard1 &> randomtestcard1result.out
	gcov randomtestcard1.c >> randomtestcard1result.out
	cat randomtestcard1.c.gcov >> randomtestcard1result.out


randomtest2: randomtestcard2
	./randomtestcard2 &> randomtestcard2result.out
	gcov randomtestcard2.c >> randomtestcard2result.out
	cat randomtestcard2.c.gcov >> randomtestcard2result.out

unittest1: unittest1.c dominion.o rngs.o
	gcc -o unittest1 -g unittest1.c dominion.o rngs.o $(CFLAGS)

unittest2: unittest2.c dominion.o rngs.o
	gcc -o unittest2 -g unittest2.c dominion.o rngs.o $(CFLAGS)

unittest3: unittest3.c dominion.o rngs.o
	gcc -o unittest3 -g unittest3.c dominion.o rngs.o $(CFLAGS)

unittest4: unittest4.c dominion.o rngs.o
	gcc -o unittest4 -g unittest4.c dominion.o rngs.o $(CFLAGS)

allrandomtests: randomtestadventurer randomtestcard1 randomtestcard2
	./randomtestadventurer > randomtestadventurerresult.out
	gcov randomtestadventurer.c >> randomtestadventurerresult.out
	cat randomtestadventurer.c.gcov >> randomtestadventurerresult.out
	./randomtestcard1 > randomtestcard1result.out
	gcov randomtestcard1.c >> randomtestcard1result.out
	cat randomtestcard1.c.gcov >> randomtestcard1result.out
	./randomtestcard2 > randomtestcard2result.out
	gcov randomtestcard2.c >> randomtestcard2result.out
	cat randomtestcard2.c.gcov >> randomtestcard2result.out

allunittests: unittest1 unittest2 unittest3 unittest4
	./unittest1 > unittestresult.out
	gcov -b unittest1.c >> unittestresult.out
	cat unittest1.c.gcov >> unittestresult.out
	./unittest2 >> unittestresult.out
	gcov -b unittest2.c >> unittestresult.out
	cat unittest2.c.gcov >> unittestresult.out
	./unittest3 >> unittestresult.out
	gcov -b unittest3.c >> unittestresult.out
	cat unittest3.c.gcov >> unittestresult.out
	./unittest4 >> unittestresult.out
	gcov -b unittest4.c >> unittestresult.out
	cat unittest4.c.gcov >> unittestresult.out

all: playdom player 

clean:
	rm -f *.o playdom.exe randomtestadventurer randomtestcard1 randomtestcard2 unittest1 unittest2 unittest3 unittest4 *.gcov *.gcda *.gcno *.so *.out
