#include <graphics.h>
#include <conio.h>

int main() {
    // Initialize the graphics mode and driver
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Set the color and draw the circle
    setcolor(WHITE);
    circle(200, 200, 100); // Center (200,200) and radius 100

    // Add text to indicate the circle
    outtextxy(180, 320, "This is a circle");

    // Hold the output screen until keypress
    getch();

    // Close the graphics mode
    closegraph();

    return 0;
}
