#include <graphics.h>
#include <stdio.h>

void floodFill4(int x, int y, int fillColor, int oldColor) {
    if (getpixel(x, y) == oldColor) {
        putpixel(x, y, fillColor);
        floodFill4(x + 1, y, fillColor, oldColor);
        floodFill4(x - 1, y, fillColor, oldColor);
        floodFill4(x, y + 1, fillColor, oldColor);
        floodFill4(x, y - 1, fillColor, oldColor);
    }
}

void floodFill8(int x, int y, int fillColor, int oldColor) {
    if (getpixel(x, y) == oldColor) {
        putpixel(x, y, fillColor);
        floodFill8(x + 1, y, fillColor, oldColor);
        floodFill8(x - 1, y, fillColor, oldColor);
        floodFill8(x, y + 1, fillColor, oldColor);
        floodFill8(x, y - 1, fillColor, oldColor);
        floodFill8(x + 1, y + 1, fillColor, oldColor);
        floodFill8(x - 1, y - 1, fillColor, oldColor);
        floodFill8(x + 1, y - 1, fillColor, oldColor);
        floodFill8(x - 1, y + 1, fillColor, oldColor);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Draw a circle as the area to fill
    circle(200, 200, 50);
    
    // Choose one algorithm to fill (uncomment as needed)
    floodFill4(200, 200, RED, BLACK);
    // floodFill8(200, 200, BLUE, BLACK);

    getch();
    closegraph();
    return 0;
}
