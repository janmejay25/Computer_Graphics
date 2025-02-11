#include <stdio.h>
#include <graphics.h>

void drawEllipse(int xc, int yc, int rx, int ry) {
    int x = 0, y = ry;
    int p1 = ry * ry - rx * rx * ry + 0.25 * rx * rx;
    int dx = 2 * ry * ry * x, dy = 2 * rx * rx * y;
    
    while (dx < dy) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        x++;
        dx += 2 * ry * ry;
        if (p1 < 0) {
            p1 += dx + ry * ry;
        } else {
            y--;
            dy -= 2 * rx * rx;
            p1 += dx - dy + ry * ry;
        }
    }

    int p2 = ry * ry * (x + 0.5) * (x + 0.5) + rx * rx * (y - 1) * (y - 1) - rx * rx * ry * ry;
    while (y >= 0) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        y--;
        dy -= 2 * rx * rx;
        if (p2 > 0) {
            p2 += rx * rx - dy;
        } else {
            x++;
            dx += 2 * ry * ry;
            p2 += dx - dy + rx * rx;
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    drawEllipse(200, 200, 100, 50);
    getch();
    closegraph();
    return 0;
}
