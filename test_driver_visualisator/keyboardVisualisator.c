#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#include <unistd.h>

#define RED "\033[1;31m"
#define RESET "\033[0m"

char pressedKeys[16] = "\0";

// cat /dev/gpio_drivec
char* get_key()
{
   
   FILE* file_desc;
   file_desc = (FILE*) fopen("/dev/gpio_driver","r");
   
   if (file_desc == NULL)
   {
     printf("Error, 'dummy' not opened\n");
     return NULL;
   }
   
   fscanf(file_desc, "%s", pressedKeys);
   
   fclose(file_desc);

   return &pressedKeys[0];
}

char keys[4][4] = {
   {'1', '2', '3', 'A'},
   {'4', '5', '6', 'B'},
   {'7', '8', '9', 'C'},
   {'*', '0', '#', 'D'} 
};

int main() {
	
	int i, j, k;
	while(1) 
	{
		system("clear");
		
		char* pressedKeys;
		pressedKeys = get_key();
		
		for(i = 0; i < 4; i++)
		{
			for(j = 0; j < 4; j++)
			{
				int found = 0;
				
				for(k = 0; k < 16; k++) 
				{
					if (pressedKeys[k] == keys[i][j]) 
					{
						found = 1;
						break;
					}			
				}
				
				if (found)
					printf(RED "%c " RESET, keys[i][j]);
				else
					printf("%c ", keys[i][j]);
				
				
				fflush(stdout);
			}
			putchar('\n');
		}
		
		for (i = 0; i < 16; i++) 
		{
			pressedKeys[i] = '\0';
		}
		usleep(200000);
	}
	
	return 0;
}

