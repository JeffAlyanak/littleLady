/*                      Little Lady
    --------------------------------------------------------
   | A first attempt at Game Boy Programming in C.          |
   | Compiled with lcc/GBDK v2.94                           |
   |--------------------------------------------------------|
   |            jeffalyanak@gmail.com                       |
    --------------------------------------------------------     */


#include <gb/gb.h>
#include <gb/drawing.h>
#include "sprite_littleLady.h"

void
main ()
{

  void spriteInitialize ();
  void theOnlyLevelSoFar ();

  spriteInitialize ();
  theOnlyLevelSoFar ();
}

void
theOnlyLevelSoFar ()
{
  int sprLeft, sprRight, sprFeet, x, y, oldLeft, oldRight;




  sprLeft = 0;				/* sprite numbers to start with */
  sprRight = 3;
  sprFeet = 6;

  x = 15;				/* x cordinate to start at */
  y = 75;				/* y cordinate to start at */
  oldLeft = 0;				/* the last sprite displayed */
  oldRight = 0;

  move_sprite (sprLeft, 14, 75);	/* puts the first sprite on screen */
  move_sprite (sprRight, 22, 75);	/*  puts the right side in place */
  move_sprite (sprFeet, 18, 91);

  SHOW_SPRITES;


  while (!0)				/* this is an infinite loop, for now */
    {

      if (joypad () == J_RIGHT)			/* move sprite right */
	{
	  x++;
	  move_sprite (oldLeft, 200, 200);	/* Move the old sprites away */
	  move_sprite (oldRight, 200, 200);
	  move_sprite (sprLeft, x, y);		/* Move the new sprites into place */
	  move_sprite (sprRight, (x + 8), y);
	  move_sprite (sprFeet, (x + 4), (y + 16));
	  delay (75);
	  oldLeft = sprLeft;			/* Cycle to new sprite */
	  oldRight = sprRight;
	  sprLeft++;
	  sprRight++;
	  if (sprLeft == 3)
	    sprLeft = 0;
	  if (sprRight == 5)
	    sprRight = 3;
	}

      if (joypad () == J_LEFT)	/* see above */
	{
	  x--;
	  move_sprite (oldLeft, 200, 200);	/* Move the old sprites away */
	  move_sprite (oldRight, 200, 200);
	  move_sprite (sprLeft, x, y);		/* Move the new sprites into place */
	  move_sprite (sprRight, (x + 8), y);
	  move_sprite (sprFeet, (x + 4), (y + 16));
	  delay (75);
	  oldLeft = sprLeft;			/* Cycle to new sprite */
	  oldRight = sprRight;
	  sprLeft++;
	  sprRight++;
	  if (sprLeft == 3)
	    sprLeft = 0;
	  if (sprRight == 5)
	    sprRight = 3;
	}

      if (joypad () == J_UP)			/* see above */
	{
	  y--;
	  move_sprite (oldLeft, 200, 200);	/* Move the old sprites away */
	  move_sprite (oldRight, 200, 200);
	  move_sprite (sprLeft, x, y);		/* Move the new sprites into place */
	  move_sprite (sprRight, (x + 8), y);
	  move_sprite (sprFeet, (x + 4), (y + 16));
	  delay (75);
	  oldLeft = sprLeft;			/* Cycle to new sprite */
	  oldRight = sprRight;
	  sprLeft++;
	  sprRight++;
	  if (sprLeft == 3)
	    sprLeft = 0;
	  if (sprRight == 5)
	    sprRight = 3;
	}

      if (joypad () == J_DOWN)			/* see above */
	{
	  y++;
	  move_sprite (oldLeft, 200, 200);	/* Move the old sprites away */
	  move_sprite (oldRight, 200, 200);
	  move_sprite (sprLeft, x, y);		/* Move the new sprites into place */
	  move_sprite (sprRight, (x + 8), y);
	  move_sprite (sprFeet, (x + 4), (y + 16));
	  delay (75);
	  oldLeft = sprLeft;			/* Cycle to new sprite */
	  oldRight = sprRight;
	  sprLeft++;
	  sprRight++;
	  if (sprLeft == 3)
	    sprLeft = 0;
	  if (sprRight == 5)
	    sprRight = 3;
	}

    }

}

void
spriteInitialize ()
{

  SPRITES_8x16;				/* set sprite mode to 8x16 */

  set_sprite_data (0, 13, littleLady);	/* define sprite data */

  set_sprite_tile (0, 0);		/* defines the tiles data for left side of body */
  set_sprite_tile (1, 4);
  set_sprite_tile (2, 8);

  set_sprite_tile (3, 2);		/* Right side of body */
  set_sprite_tile (4, 6);
  set_sprite_tile (5, 10);

  set_sprite_tile (6, 12);		/* Feet */

}
