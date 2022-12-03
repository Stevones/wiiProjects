/*===========================================
        GRRLIB (GX Version)
        - Template Code -
        Minimum Code To Use GRRLIB
============================================*/
#include <grrlib.h>
#include "marioKartFont.h"
#include "marioKartFont.c"
#include "colors.h"
#include <stdlib.h>
#include <wiiuse/wpad.h>
#include <wiiuse/wiiuse.h>


int main(int argc, char **argv) {
    // Initialise the Graphics & Video subsystem
    GRRLIB_Init();

    // Initialise the Wiimotes
    WPAD_Init();


 GRRLIB_ttfFont* font = GRRLIB_LoadTTF(marioKartFont, marioKartFont_size);	

    // Loop forever
    while(1) {

        WPAD_ScanPads();  // Scan the Wiimotes

        // If [HOME] was pressed on the first Wiimote, break out of the loop
        if (WPAD_ButtonsDown(0) & WIIMOTE_BUTTON_HOME) {
			break;
			}
			
			if (WPAD_ButtonsUp(0) & WIIMOTE_BUTTON_A) {
				GRRLIB_PrintfTTF(90, 300, font, "A was pressed.", 25, GRRLIB_WHITE);
			}
			

        // ---------------------------------------------------------------------
        
		GRRLIB_PrintfTTF(90, 110, font, "Hello World", 50, GRRLIB_WHITE);
        // ---------------------------------------------------------------------
		
        GRRLIB_Render();  // Render the frame buffer to the TV
    }

    GRRLIB_Exit(); // Be a good boy, clear the memory allocated by GRRLIB

    exit(0);  // Use exit() to exit a program, do not use 'return' from main()
}