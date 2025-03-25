#include <graphics.h>
#include <conio.h>
#include <dos.h>

// Function to draw a car at position (x, y)
void drawCar(int x, int y) {
    setcolor(WHITE);
    rectangle(x, y, x + 100, y + 40); // Car body
    rectangle(x + 20, y - 20, x + 80, y); // Car top
    circle(x + 25, y + 40, 10); // Wheel 1
    circle(x + 75, y + 40, 10); // Wheel 2
}

// Function to draw a bouncing ball at (x, y)
void drawBall(int x, int y) {
    setcolor(YELLOW);
    circle(x, y, 15); // Ball shape
    floodfill(x, y, YELLOW);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    int carX = 50, carY = 300, ballX = 200, ballY = 100;
    int ballDirY = 1, ballSpeedY = 5, carSpeedX = 5;
    
    while (!kbhit()) { // Loop until key press
        cleardevice();

        // Moving Car Animation
        drawCar(carX, carY);
        carX += carSpeedX;
        if (carX > getmaxx()) carX = -100; // Reset car position

        // Bouncing Ball Animation
        drawBall(ballX, ballY);
        ballY += ballDirY * ballSpeedY;

        // Bounce logic
        if (ballY >= getmaxy() - 15 || ballY <= 15) ballDirY *= -1;

        delay(50);
    }

    closegraph();
    return 0;
}
