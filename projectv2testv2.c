#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include "wordleStats.h"

#define STATS_FILE "WordleStats.txt"
Gamestats load_statistics();
int save_stats(Gamestats *s);
int attempts = 0;
char answer[5] = {};
Gamestats stats;
int choice = 1;

void wordSelection(int x){
	char wordList [100][6] = {"apple", "bread", "chair", "dream", "earth", "flame", "grace", "heart", "ideal", "joker", "knife", "lemon", "magic", "night", "ocean", "peace", "queen", "river", "stone", "tiger", "unity", "voice", "water", "youth", "zebra", "angry", "brave", "cloud", "dance", "eagle", "faith", "giant", "house", "image", "juice", "karma", "light", "money", "nurse", "olive", "plant", "quick", "rough", "sweet", "train", "under", "vivid", "world", "xenia", "yield", "zesty", "blaze", "crane", "drift", "envyx", "frost", "gloom", "honey", "ivory", "jolly", "kneel", "loyal", "maple", "novel", "orbit", "prize", "quiet", "radar", "sunny", "trust", "urban", "value", "whale", "xenon", "young", "zonal", "amber", "basil", "cedar", "dried", "ember", "fairy", "glove", "haven", "inlet", "joint", "latch", "metal", "nerve", "ounce", "pilot", "rinse", "scale", "thorn", "usher", "voter", "witty", "yummy", "zilch", "bloom"};
	int i;
	for(i = 0; i < 5; i++) {
		answer[i] = wordList[x][i];
	}
}

void print_stats(){

        printf("\n.・。.・゜✭・.・✫・゜・。..・。.・゜✭・.・✫・゜・。.\n\n");
	printf("    Game Statistics:    \n\n");
        printf("Games won: %d\n", stats.win);
        printf("Games lost: %d\n", stats.lose);
        printf("Total games played: %d\n", stats.totalGames);
        printf("Win percentage: %.2lf%%\n", stats.winPercent);
	printf("\n.・。.・゜✭・.・✫・゜・。..・。.・゜✭・.・✫・゜・。.\n\n");

}

void checker() {

	stats = load_statistics();
	attempts = 0;
	char guess[1][6] = {};
	int i;
	int change;
 	char checkList[5] = {};
	int guessCheck = 0;
    for (i = 0; i < 5; i++){
            checkList[i] = answer[i];
    }
    while (attempts < 7) {

        printf("\n");
	printf("%d attempt(s) remaining\n", 6 - attempts);
        printf("Guess a 5 letter word: ");
        scanf(" %s", &guess);
        for (i=0; i<5; i++) {
            guess[0][i] = tolower(guess[0][i]);
        }
        attempts++;
        


	/**************Make statement to detect guess not 5 letters long***********/	

	if ((strlen(guess[0])) != 5) {
		printf("\nYour word was not 5 letters. Try again.\n");
		attempts--;
		continue;
	}

	/**********************************************************/

	/*************Make statement to detect guess with symbol or number***********/
	for (i = 0; i < 5; i++){
		guessCheck = 0;
		if (isalpha(guess[0][i])){
			continue;
		}
		else {
			guessCheck = 1;
			break;
		}
	}
	
	if (guessCheck == 1){
		printf("\nYour input included a number/symbol. Try again.\n");
		attempts--;
		continue;
	}
	/**********************************************************/	
	int result[5] = {0,0,0,0,0};
    	int used[5] = {0,0,0,0,0};
	

	for (i = 0; i < 5; i++){
            if (guess[0][i] == answer[i]) {
                    result[i] = 2;
                    used[i] = 1;
            }
        }

        for (i = 0; i < 5; i++) {
                if (result[i] == 0) {
                        for (change = 0; change < 5; change ++){
                                if (!used[change] && guess[0][i] == answer[change]){
                                            result[i] = 1;
                                            used[change] = 1;
                                            break;
                                }
                        }
                }
        }
        for (i = 0; i < 5; i++) {
                if (result[i] == 2) {
                        printf("\e[1;32m%c\e[0;37m ", guess[0][i]);
                }

                else if (result[i] == 1) {
                        printf("\e[0;93m%c\e[0;37m ", guess[0][i]);
                }

                else {
                        printf("%c ", guess[0][i]);
                }
        }

		if ((answer[0] == guess[0][0]) && (answer[1] == guess[0][1]) && (answer[2] == guess[0][2]) && (answer[3] == guess[0][3]) && (answer[4] == guess[0][4])) {
			printf("\n\n.・。.・゜✭・.・✫・゜・。..・。.・゜✭・.・✫・゜・。.\n");
			printf("\n   	You got the correct answer!!!\n");
			stats.win++;
			break;
			}
		else {
			printf("\n\n");
			continue;
			}
		}
		if (((answer[0] != guess[0][0]) || (answer[1] != guess[0][1]) || (answer[2] != guess[0][2]) || (answer[3] != guess[0][3]) || (answer[4] != guess[0][4])) && (attempts == 7)) {
			change += 1;
			printf("\n   You were not able to guess the word in 7 tries.\n");
                        stats.lose++;

			}
		stats.totalGames++;
		stats.winPercent = ((double)stats.win / stats.totalGames) *100;
		save_stats(&stats);

		printf("Would you like to play again or view stats?\n\n(1- View stats and play again, 2- View stats and quit):  ");
		scanf("%d", &choice);
		printf("\n\n\n");

		print_stats();
		
		/* add play again, not play again => veiw stats yes or no => yes run statistics function */
	
	
	}

Gamestats load_statistics(){ 

	FILE *file = fopen(STATS_FILE, "rb");
	if (file != NULL){
		fread(&stats, sizeof(Gamestats), 1, file); /* Figure out sizeof(stats) */
		fclose(file);
	}
	return stats;
}

int save_stats(Gamestats *s){

	FILE *file = fopen(STATS_FILE, "wb");
	if (file == NULL){
		printf("Error opening file\n");
		return 1;
	}
	fwrite(s, sizeof(Gamestats), 1, file);
	fclose(file);
	return 0;
}
	

int main() {
	printf("\n  ✧･ﾟ: *✧･ﾟ:* ✧･ﾟ: *✧･ﾟ:*   Welcome to Wordle  ✧･ﾟ: *✧･ﾟ:* ✧･ﾟ: *✧･ﾟ:* \n\n");
	while (choice == 1){
		srand(time(NULL));
		wordSelection(rand() %99);
		 /* This line to check word during testing */
		checker();
	}
	return 0;
	}
