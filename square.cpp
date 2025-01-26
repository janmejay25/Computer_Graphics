#include <graphics.h>
#include <conio.h>

int main() {
    // Initialize graphics mode
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Coordinates for the square
    int left = 100, top = 100;
    int right = 200, bottom = 200;

    // Draw the square
    rectangle(left, top, right, bottom);

    // Pause to view the output
    getch();

    // Close the graphics mode
    closegraph();
    return 0;
}
