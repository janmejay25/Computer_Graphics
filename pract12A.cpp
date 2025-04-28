#include <graphics.h>
#include <stdlib.h>
#include <unistd.h>  // For sleep()

void drawStickMan(int x, int y) {
    // Draw head
    circle(x, y - 40, 20);  
    // Draw body
    line(x, y - 20, x, y + 30);  
    // Draw arms
    line(x, y, x - 20, y + 10);  
    line(x, y, x + 20, y + 10);  
    // Draw legs
    line(x, y + 30, x - 20, y + 60);  
    line(x, y + 30, x + 20, y + 60);  
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x = 50, y = 200;  // Initial position of the stick figure
    while (x < 600) {
        cleardevice();  // Clear screen
        drawStickMan(x, y);  // Draw the stick figure
        x += 10;  // Move right
        delay(100);  // Delay to control speed
    }

    closegraph();
    return 0;
}
