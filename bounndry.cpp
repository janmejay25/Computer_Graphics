#include <graphics.h>
#include <stdio.h>

void boundaryFill4(int x, int y, int fillColor, int boundaryColor) {
    int currentColor = getpixel(x, y);
    if (currentColor != boundaryColor && currentColor != fillColor) {
        putpixel(x, y, fillColor);
        boundaryFill4(x + 1, y, fillColor, boundaryColor);
        boundaryFill4(x - 1, y, fillColor, boundaryColor);
        boundaryFill4(x, y + 1, fillColor, boundaryColor);
        boundaryFill4(x, y - 1, fillColor, boundaryColor);
    }
}

void boundaryFill8(int x, int y, int fillColor, int boundaryColor) {
    int currentColor = getpixel(x, y);
    if (currentColor != boundaryColor && currentColor != fillColor) {
        putpixel(x, y, fillColor);
        boundaryFill8(x + 1, y, fillColor, boundaryColor);
        boundaryFill8(x - 1, y, fillColor, boundaryColor);
        boundaryFill8(x, y + 1, fillColor, boundaryColor);
        boundaryFill8(x, y - 1, fillColor, boundaryColor);
        boundaryFill8(x + 1, y + 1, fillColor, boundaryColor);
        boundaryFill8(x - 1, y - 1, fillColor, boundaryColor);
        boundaryFill8(x + 1, y - 1, fillColor, boundaryColor);
        boundaryFill8(x - 1, y + 1, fillColor, boundaryColor);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Draw a rectangle as the boundary
    rectangle(100, 100, 300, 300);
    
    // Choose one algorithm to fill (uncomment as needed)
    boundaryFill4(150, 150, RED, WHITE);
    boundaryFill8(150, 150, BLUE, WHITE);

    getch();
    closegraph();
    return 0;
}
