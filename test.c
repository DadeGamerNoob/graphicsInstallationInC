// Bresenham's Line Drawing Algorithm (BSA) code in C
#include <graphics.h>

int main(int argc, char *argv[]) {
  int gd = DETECT, gm;

  int x1, x2, y1, y2;
  printf("Enter initial points :");
  scanf("%d%d", &x1, &y1);
  printf("Enter end points :");
  scanf("%d%d", &x2, &y2);

  float deltaX, deltaY;
  deltaX = abs(x2 - x1);
  deltaY = abs(y2 - y1);

  int P = 2 * deltaY - deltaX;

  float x, y, xEnd;
  if (x2 > x1) {
    x = x1;
    y = y1;
    xEnd = x2;
  } else {
    x = x2;
    y = y2;
    xEnd = x1;
  }

  initgraph(&gd, &gm, "");
  putpixel(x, y, WHITE);

  while (x < xEnd) {
    x++;

    if (P < 0)
      P += 2 * deltaY;
    else {
      y++;
      P += 2 * deltaY - 2 * deltaX;
    }
    putpixel(x, y, WHITE);
  }

  outtextxy(150, 50, "Bresenham's Line Drawing Algorithm (BSA) USING C");
  outtextxy(x1 + 5, y1 - 10, "(x1,y1)");
  outtextxy(x2 + 5, y2 + 5, "(x2,y2)");

  getch();
  closegraph();

  return 0;
}