#include "board.h"
#include "sprite.h"
#include "constants.h"
#include <stdlib.h>
#include <stdio.h>

extern SpritePlayer player;
extern Sprite projectile;
extern Sprite shield;
int shield_timer = 20;

void printBoard() {
	
	for(int i = 0; i < BORDER_DOWN; i++) 
	{
		for(int j = 0; j < BORDER_RIGHT; j++) 
		{
		   
		  if(j == BORDER_LEFT)
		  {
		     printf("|");
		  }
		  if (j == BORDER_RIGHT - 1)
		  {
		     printf("*|");
		  }

		  if (player.x == i && player.y == j) 
		  {
		     printf(CYAN "%c" RESET, player.displaySign);
		  }
		  else if (projectile.x == i && projectile.y == j)
		  {
		     printf(RED "%c" RESET, projectile.displaySign);
		  }
		  else if (shield.x == i && shield.y == j)
		  {
		     printf("%c", shield.displaySign);
		  }
		  else 
		  {
		     putchar(' ');
		  }
		  
		  
	       }
	       putchar('\n');
	}
	
      printf(YELLOW "Shields: %d" RESET, player.numOfShields);
	
}

void setupBoard() {
   player.x = 0;
   player.y = 0;
   player.displaySign = 'i';
   player.numOfShields = 0;
   
   projectile.x = 0;
   projectile.y = 16;
   projectile.displaySign = '<';
   
   //na pocetku se pojavljuje uvek 1 shield
   shield.x = 1+rand() % 16;
   shield.y = 1+rand() % 16;
   shield.displaySign = 'x';
   
}
