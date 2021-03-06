#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {

  screen s;
  color c;

  c.red = 0;
  c.green = MAX_COLOR;
  c.blue = 0;

  clear_screen(s);
  draw_line(0,0, 250, 250,s,c);
  draw_line(0,250,500,0,s,c);
  draw_line(0,250,500,250,s,c);
  draw_line(250,0,250,250,s,c);
  draw_line(120, 500, 270,0,s,c);
  draw_line(0,200,500,320,s,c);
  draw_line(0,100,130, 500,s,c);
  draw_line(500, 0, 0, 120, s, c);
  draw_line(500, 220, 0, 0, s, c); 
  draw_line(420, 500, 0, 0, s, c);
  draw_line(0, 420, 120, 0, s, c); 
  draw_line(0, 430, 470, 350, s, c);
	    
  display(s);
  save_extension(s, "lines.png");
}
