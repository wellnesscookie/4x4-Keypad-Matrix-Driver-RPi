#include "keypadMatrix.h"

char get_key()
{
   char pressedKey[1] = "\0";
   
   FILE* file_desc;
   file_desc = (FILE*) fopen("/dev/gpio_driver","r");
   
   if (file_desc == NULL)
   {
     printf("Error, 'dummy' not opened\n");
     return -1;
   }
   
   fscanf(file_desc, "%s", pressedKey);
   
   
   fclose(file_desc);

   return pressedKey[0];
}
