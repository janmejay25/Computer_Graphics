#include <stdio.h>
#include <graphics.h>

void drawLineDDA(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1, dy = y2 - y1, steps;
    float Xinc, Yinc, x = x1, y = y1;
    
    steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);
    Xinc = dx / (float)steps;
    Yinc = dy / (float)steps;
    
    for (int i = 0; i <= steps; i++) {
        putpixel(x, y, WHITE);
        x += Xinc;
        y += Yinc;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    drawLineDDA(50, 50, 200, 200);
    getch();
    closegraph();
    return 0;
}
