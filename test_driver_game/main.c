
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#include <unistd.h>
#include "sprite.h"
#include "board.h"
#include "constants.h"
#include "keypadMatrix.h"

int checkIfPlayerHit();
void checkShield(char);

extern SpritePlayer player;
extern Sprite projectile;
extern Sprite shield;
extern int shield_timer;

int main(void) 
{
   srand(time(NULL));
   setupBoard();


   while(checkIfPlayerHit())
   {
    system("clear");
    printBoard();
    fflush(stdout);
	  
    char buttonPressed = get_key();
    movePlayer(buttonPressed);
    moveProjectile();
    checkShield(buttonPressed);

   usleep(200000);
      
   }
   system("clear");
   printf("\n\n\n\n\t\t" GREEN "GAME OVER" RESET);
   
   printf("\n");

   return 0;
}

void checkShield(char buttonPressed) 
{
   if (player.numOfShields > 0 && buttonPressed == '*')
   {
      player.numOfShields--;
      player.shieldTimeLeft = 200;
   }
   
   if (player.shieldTimeLeft > 0) {
       player.shieldTimeLeft--;
    }
    
    /*************************************/
    if (player.x == shield.x && player.y == shield.y) 
    { 
	 player.numOfShields++;
	 shield.x = 19;
	 shield.y = 19;
	 shield.displaySign = ' ';
   }
   
   if (player.numOfShields < MAX_SHIELDS && shield.displaySign == ' ') 
   {
	    if (shield_timer > 0) 
	    {
	       shield_timer--;
	       
	    } else 
	    {
	       shield_timer = 20;
	       shield.x = 1 + rand()%16;
	       shield.y = 1 + rand()%16;
	       shield.displaySign = 'x';
	    }
   }
}

int checkIfPlayerHit() {
   
   if (player.x == projectile.x && player.y == projectile.y) 
   {
	    if (player.shieldTimeLeft > 0)  
	    {
	       projectile.x = 1 + rand()%16;
	       projectile.y = BORDER_RIGHT - 1;
	       player.shieldTimeLeft = 0;
	    } 
	    else 
	    {	    
	       return 0;
	    }
    }
    
    return 1;
   
}
