#ifndef __SPRITE__
#define __SPRITE__

typedef struct SpritePlayer {
	
	char displaySign;
	int x;
	int y;
	int numOfShields;
	int shieldTimeLeft;
	
} SpritePlayer;

typedef struct Sprite {
	
	char displaySign;
	int x;
	int y;
} Sprite;

int movePlayer(char buttonPressed);
int moveProjectile();

#endif
