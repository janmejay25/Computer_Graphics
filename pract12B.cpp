#include <graphics.h>
#include <unistd.h>  // For sleep()

void drawFace(int blink) {
    // Draw face outline
    circle(300, 200, 100);  

    // Draw eyes
    if (blink == 0) {
        circle(260, 170, 10);  // Left eye open
        circle(340, 170, 10);  // Right eye open
    } else {
        line(250, 170, 270, 170);  // Left eye closed
        line(330, 170, 350, 170);  // Right eye closed
    }

    // Draw mouth (smiling)
    arc(300, 230, 200, 340, 30);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    for (int i = 0; i < 10; i++) {
        cleardevice();
        drawFace(i % 2);  // Alternate between open and closed eyes (blink)
        delay(500);  // Delay between frames
    }

    closegraph();
    return 0;
}
