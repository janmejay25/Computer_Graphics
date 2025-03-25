#include <graphics.h>
#include <stdlib.h>
#include <unistd.h>  // For sleep()

// Function to draw a stickman at position (x, y)
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

// Function to draw a face with blinking eyes at fixed position
void drawFace(int blink) {
    // Draw face outline
    circle(400, 200, 100);

    // Draw eyes (blinking effect)
    if (blink == 0) {
        circle(360, 170, 10);  // Left eye open
        circle(440, 170, 10);  // Right eye open
    } else {
        line(350, 170, 370, 170);  // Left eye closed
        line(430, 170, 450, 170);  // Right eye closed
    }

    // Draw mouth (smiling)
    arc(400, 230, 200, 340, 30);
}

int main() { 
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x = 50, y = 300;  // Initial position for the stick figure

    // Animation loop
    for (int i = 0; i < 40; i++) {
        cleardevice();  // Clear the screen for smooth animation

        drawStickMan(x, y);            // Draw the moving stick figure
        drawFace(i % 2);               // Draw the blinking face (alternates eyes every loop)
        x += 10;                       // Move stickman horizontally
        delay(200);                    // Delay to control animation speed
    }

    closegraph();
    return 0;
}
