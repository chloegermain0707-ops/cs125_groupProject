#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int attempts = 0;
char answer[5] = {};

void wordSelection(int x){
	char wordList [100][6] = {"apple", "bread", "chair", "dream", "earth", "flame", "grace", "heart", "ideal", "joker", "knife", "lemon", "magic", "night", "ocean", "peace", "queen", "river", "stone", "tiger", "unity", "voice", "water", "youth", "zebra", "angry", "brave", "cloud", "dance", "eagle", "faith", "giant", "house", "image", "juice", "karma", "light", "money", "nurse", "olive", "plant", "quick", "rough", "sweet", "train", "under", "vivid", "world", "xenia", "yield", "zesty", "blaze", "crane", "drift", "envyx", "frost", "gloom", "honey", "ivory", "jolly", "kneel", "loyal", "maple", "novel", "orbit", "prize", "quiet", "radar", "sunny", "trust", "urban", "value", "whale", "xenon", "young", "zonal", "amber", "basil", "cedar", "dried", "ember", "fairy", "glove", "haven", "inlet", "joint", "latch", "metal", "nerve", "ounce", "pilot", "rinse", "scale", "thorn", "usher", "voter", "witty", "yummy", "zilch", "bloom"};
	int i;
	for(i = 0; i < 5; i++) {
		answer[i] = wordList[x][i];
	}
	}

void checker() {
	char guess[1][6] = {};
	char checkList[1][5] = {};
	int i;
	int change;
	while (attempts < 7) {
		
		printf("%d attempts remaining\n", 6 - attempts);
		printf("Guess a 5 letter word: ");
		scanf(" %s", &guess);
		for (i=0; i<5; i++) {
			guess[0][i] = tolower(guess[0][i]);
		}
		attempts++;
		for (i = 0; i < 5; i++) {
			checkList[0][i] = guess[0][i];
			if (answer[i] == guess[0][i]) {
				printf("\e[1;32m%c\e[0;37m ", guess[0][i]);
				checkList[0][i] = (guess[0][i] + '1');
				}
			else if ((answer[0] == guess[0][i]) || (answer[1] == guess[0][i]) || (answer[2] == guess[0][i]) || (answer[3] == guess[0][i]) || (answer[4] == guess[0][i])) {
				if ((checkList[0][0] == (guess[0][i] + '1')) || (checkList[0][1] == (guess[0][i] + '1')) || (checkList[0][2] == (guess[0][i] + '1')) || (checkList[0][3] == (guess[0][i] + '1')) || (checkList[0][4] == (guess[0][i] + '1'))){
                                        printf("%c ", guess[0][i]);
                                        }
				else {
					printf("\e[0;93m%c\e[0;37m ", guess[0][i]);
					}
				}
			else {
				printf("%c ", guess[0][i]);
				}
			}
		if ((answer[0] == guess[0][0]) && (answer[1] == guess[0][1]) && (answer[2] == guess[0][2]) && (answer[3] == guess[0][3]) && (answer[4] == guess[0][4])) {
			printf("\n you got the correct answer!\n");
			break;
			}
		else {
			
			printf("\n\n%s", checkList);


			printf("\n\n");
			continue;
			}
		}
		if (((answer[0] != guess[0][0]) || (answer[1] != guess[0][1]) || (answer[2] != guess[0][2]) || (answer[3] != guess[0][3]) || (answer[4] != guess[0][4])) && (attempts == 6)) {
			change = 1;
			}
		if (change == 1) {
			printf("\nYou were not able to guess the word in 6 tries. The correct word was %c\n", answer[i]);
			}
			
	}




int main() {
	srand(time(NULL));
	wordSelection(rand() %99);
	printf("%s \n", answer);
	checker();
	return 0;
	}
