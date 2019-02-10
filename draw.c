#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  if(x0 == x1){
    int y = 0;
    while(y <= y1){
      plot(s,c,x0,y);
      y++;
    }
  }
  else if(y0 == y1){
    int x = 0;
    while(x <= x1){
      plot(s,c,x,y0);
      x++;
    }
  }

  else{
    
    if(x0 > x1){
      int temp = x1;
      x1 = x0;
      x0 = temp;
      temp = y1;
      y1 = y0;
      y0 = temp;
    }

    
    int x = x0;
    int y = y0;
    int A = y1 - y0;
    int B = -(x1-x0);
    int d = 2*A + B;
    //Positive
    
    if(A > 0){
      //I
      if(A < -B){
	d = 2*A + B;
	
	while(x <= x1){
	  plot(s,c,x,y);
	  if(d > 0){
	    y++;
	    d+= 2*B;
	  }
	  x++;
	  d+= 2*A;
	}
      }
      //II
      else{
	d = A + 2*B;
	while(y <= y1){
	  plot(s,c,x,y);
	  if(d < 0){
	    x++;
	    d+= 2*A;
	  }
	  y++;
	  d+= 2*B;
	}
      }
    }
    //Negative
    else{
      if(A<B){
	//VII
	d = 2*B - A;
	while(y >= y1){
	  plot(s,c,x,y);
	  if(d < 0){
	    x++;
	    d -= 2*A;
	  }
	  y--;
	  d+= 2*B;
	}
      }

      else{
	d = B -2 *A;
	while(x <= x1){
	  plot(s,c,x,y);
	  if(d > 0){
	    y--;
	    d+= 2*B;
	  }
	  x++;
	  d -= 2*A;
	}
      }
    }
  }
}
