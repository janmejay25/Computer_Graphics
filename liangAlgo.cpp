#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>

float xmin = 100, ymin = 100, xmax = 400, ymax = 300;  // Clipping window dimensions

// Liang-Barsky Line Clipping Algorithm
void liangBarsky(float x1, float y1, float x2, float y2) {
    float p[4], q[4], t1 = 0, t2 = 1;
    float dx = x2 - x1, dy = y2 - y1;

    p[0] = -dx; q[0] = x1 - xmin;
    p[1] = dx;  q[1] = xmax - x1;
    p[2] = -dy; q[2] = y1 - ymin;
    p[3] = dy;  q[3] = ymax - y1;

    for (int i = 0; i < 4; i++) {
        if (p[i] == 0 && q[i] < 0) return;  // Line completely outside
        float t = q[i] / p[i];
        if (p[i] < 0) t1 = (t > t1) ? t : t1;  // Entering
        else if (p[i] > 0) t2 = (t < t2) ? t : t2;  // Leaving
        if (t1 > t2) return;  // Line completely outside
    }

    float nx1 = x1 + t1 * dx, ny1 = y1 + t1 * dy;
    float nx2 = x1 + t2 * dx, ny2 = y1 + t2 * dy;

    setcolor(GREEN);
    line(nx1, ny1, nx2, ny2);  // Draw clipped line
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);  // Initialize graphics mode

    float x1 = 50, y1 = 150, x2 = 450, y2 = 250;  // Line to be clipped

    // Draw the clipping window
    setcolor(RED);
    rectangle(xmin, ymin, xmax, ymax);

    // Draw the original line before clipping
    setcolor(WHITE);
    line(x1, y1, x2, y2);
    getch();

    // Clear the screen and draw the window again
    cleardevice();
    setcolor(RED);
    rectangle(xmin, ymin, xmax, ymax);

    // Perform Liang-Barsky line clipping and draw the clipped line
    liangBarsky(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}
