
#include "constants.h"
#include "sprite.h"
#include <stdlib.h>

SpritePlayer player;
Sprite projectile;
Sprite shield;

extern int shield_timer;

int movePlayer(char buttonPressed) 
{
	
	if(buttonPressed == '2')
	  {
	    if(player.x > 0)
	    {
	       player.x--;
	       return 2;
	    }
	  } 
	  else if (buttonPressed == '6')
	  {
	    if(player.y < BORDER_RIGHT - 2)
	    {
	       player.y++;
	       return 6;
	    }
	  } 
	  else if (buttonPressed == '8')
	  {
	    if(player.x < BORDER_DOWN - 1)
	    {
	       player.x++;
	       return 8;
	    }
	  }
	  else if(buttonPressed == '4')
	  {
	    if (player.y  > 0)
	    {
	       player.y--;
	       return 4;
	    }
	  }
	  
	  return -1;
}

int moveProjectile() {
     
     if (projectile.y > 0) 
     {
      projectile.y--;
     } 
     else 
     {
      projectile.y = 15;
      projectile.x = rand() % 16;
     }
}
