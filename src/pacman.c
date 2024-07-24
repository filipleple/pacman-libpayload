/*
** Pacman - In curses
*/
#include <ctype.h>
#include "pacman.h"
#include "render.h"
#include "gameloop.h"
#include "libpayload.h"

// void GetMarqueeText(GAME_STATE *ptr) {
// 	FILE *fp = fopen("pactext", "r");
// 	int i;
// 	char *pc;

// 	ptr->pMarquee = 0;
// 	if (fp)	{
// 		fseek(fp, 0, SEEK_END);
// 		ptr->iMarqueeSize = ftell(fp);
// 		if ((ptr->pMarquee = malloc(ptr->iMarqueeSize))){
// 			fseek(fp,0,SEEK_SET);
// 			fread(ptr->pMarquee, 1, ptr->iMarqueeSize, fp);
// 			pc = ptr->pMarquee;
// 			for(i=0;i<ptr->iMarqueeSize;i++,pc++)
// 				if (isalnum(*pc) || ispunct(*pc))
// 					;/*empty*/
// 				else
// 					*pc = ' ';
// 		}
// 		fclose(fp);
// 	}
// }







void GetMarqueeText(GAME_STATE *ptr)
{
    // Hardcoded marquee text (replace this with the actual text if known)
    const char *marqueeText = "Pac-Man: Insert Coin to Start! Use Arrow Keys to Move. Eat All Dots to Win!";

    ptr->iMarqueeSize = strlen(marqueeText);
    ptr->pMarquee = (char *)malloc(ptr->iMarqueeSize + 1); // Allocate memory for the text plus null terminator

    if (ptr->pMarquee) {
        strcpy(ptr->pMarquee, marqueeText); // Copy the hardcoded text to the allocated memory

        // Process the text
        char *pc = ptr->pMarquee;
        for (int i = 0; i < ptr->iMarqueeSize; i++, pc++) {
            if (isalnum(*pc) || ispunct(*pc)) {
                ; // Keep alphanumeric and punctuation characters as they are
            } else {
                *pc = ' '; // Replace other characters with a space
            }
        }
    }
}











int main(int argc, char **argv) {
	GAME_STATE game;
	void *pRender;

	game.iHighScore = 9710;
	GetMarqueeText(&game);
	pRender = Pac_InitRender();
	do {
		Pac_MainGame(pRender, &game);
		Pac_DrawEndGame(pRender, &game);
	} while (Pac_AnotherGame(pRender));
	Pac_CloseRender(pRender);

	return 0;
}

