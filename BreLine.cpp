#include <stdio.h>
#include <graphics.h>

void drawLineBresenham(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1, dy = y2 - y1, p = 2 * dy - dx;
    int x = x1, y = y1;
    
    putpixel(x, y, WHITE);
    while (x < x2) {
        x++;
        if (p < 0) {
            p += 2 * dy;
        } else {
            y++;
            p += 2 * (dy - dx);
        }
        putpixel(x, y, WHITE);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    drawLineBresenham(50,50,200,200);
    getch();
    closegraph();
    return 0;
}
