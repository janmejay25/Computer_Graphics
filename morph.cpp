#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <math.h>

void drawMorphingImage(int alpha) {
    int x = 200, y = 200;
    cleardevice();
    setcolor(WHITE);

    if (alpha < 50) {
        circle(x, y, 50 + alpha);  // Expanding circle
    } else {
        rectangle(x - 50, y - 50, x + 50, y + 50);  // Rectangle appears
    }
}

void displayRenderedAnimation() {
    int x = 300, y = 300, halfSize = 50;
    static int angle = 0;

    cleardevice();
    setcolor(YELLOW);
    
    float radians = angle * 3.14159 / 180;

    int x1 = x + halfSize * cos(radians);
    int y1 = y + halfSize * sin(radians);
    int x2 = x + halfSize * cos(radians + 3.14159 / 2);
    int y2 = y + halfSize * sin(radians + 3.14159 / 2);
    int x3 = x + halfSize * cos(radians + 3.14159);
    int y3 = y + halfSize * sin(radians + 3.14159);
    int x4 = x + halfSize * cos(radians + 3 * 3.14159 / 2);
    int y4 = y + halfSize * sin(radians + 3 * 3.14159 / 2);

    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x4, y4);
    line(x4, y4, x1, y1);

    angle += 5;
    if (angle >= 360) angle = 0;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Morphing Animation
    for (int alpha = 0; alpha <= 100; alpha++) {
        drawMorphingImage(alpha);
        delay(30);
    }

    // Rendered Animation (Rotating Square)
    while (!kbhit()) {
        displayRenderedAnimation();
        delay(30);
    }

    getch();
    closegraph();
    return 0;
}
