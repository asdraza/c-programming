#include <stdio.h>

void Go(int steps);

int main(void)
{
 int sx, sy, dx, dy;
 int diff_x, diff_y;


 scanf("%d %d %d %d",&sx,&sy,&dx,&dy);
 diff_x = dx - sx;
 diff_y = dy - sy;

 if (diff_x>0 && diff_y > 0)
 {
   printf("R R ");
   Go(diff_y);
   printf("L ");
   Go(diff_x);
 }
 if (diff_x>0 && diff_y < 0)
 {
   printf("L ");
   Go(diff_y);
   printf("R ");
   Go(-diff_x);
 }

 if (diff_x<0 && diff_y > 0)
 {
   printf("L L ");
   Go(-diff_y);
   printf("R ");
   Go(diff_x);
 }

 if (diff_x<0 && diff_y < 0)
 {
   Go(-diff_y);
   printf("L ");
   Go(-diff_x);
 }

 printf("\n");
 return 0;
}
void Go(int steps)
{
 int i;
 for (i=0;i<steps;i++)
   {
     printf("W ");
   }
}
