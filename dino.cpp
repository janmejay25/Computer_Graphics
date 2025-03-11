#include <stdio.h>
#include <stdlib.h>
#include <conio.h>   // For _kbhit() and _getch() (Windows only)
#include <unistd.h>  // For usleep()

#define SCREEN_WIDTH 50
#define SCREEN_HEIGHT 10
#define GROUND_Y (SCREEN_HEIGHT - 2)

// Dinosaur structure
typedef struct {
    int x, y;
    int isJumping;
} Dinosaur;

// Function to clear screen (cross-platform)
void clearScreen() {
#ifdef _WIN32
    system("cls");  // Windows
#else
    system("clear");  // Linux/macOS
#endif
}

// Function to draw the screen
void drawScreen(Dinosaur *dino, int obstacleX) {
    clearScreen();

    // Draw top border
    for (int i = 0; i < SCREEN_WIDTH; i++) printf("-");
    printf("\n");

    // Draw game area
    for (int i = 1; i < SCREEN_HEIGHT - 1; i++) {
        for (int j = 0; j < SCREEN_WIDTH; j++) {
            if (i == GROUND_Y) {
                // Draw ground and obstacles
                if (j == obstacleX) {
                    printf("X");  // Obstacle
                } else {
                    printf("_");  // Ground
                }
            } else {
                if (i == dino->y && j == dino->x) {
                    printf("D");  // Draw dinosaur
                } else {
                    printf(" ");  // Empty space
                }
            }
        }
        printf("\n");
    }

    // Draw bottom border
    for (int i = 0; i < SCREEN_WIDTH; i++) printf("-");
    printf("\n");

    usleep(100000);  // Delay for smooth gameplay
}

// Function to handle jumping
void jump(Dinosaur *dino) {
    if (!dino->isJumping) {
        dino->isJumping = 1;

        // Jump up
        for (int i = 0; i < 3; i++) {
            if (dino->y > 1) {
                dino->y--;
                drawScreen(dino, SCREEN_WIDTH - 5);
            }
            usleep(100000);
        }

        // Fall down
        while (dino->y < GROUND_Y) {
            dino->y++;
            drawScreen(dino, SCREEN_WIDTH - 5);
            usleep(100000);
        }

        dino->isJumping = 0;
    }
}

// Main game loop
int main() {
    Dinosaur dino = {5, GROUND_Y, 0};  // Starting position
    int obstacleX = SCREEN_WIDTH - 5;  // Initial obstacle position
    int score = 0;

    while (1) {
        if (_kbhit()) {
            char ch = _getch();  // Get key press
            if (ch == ' ') {
                jump(&dino);  // Jump when spacebar is pressed
            }
        }

        drawScreen(&dino, obstacleX);




        
        // Move the obstacle left
        obstacleX--;
        if (obstacleX < 0) {
            obstacleX = SCREEN_WIDTH - 5; 
            
            score++;
        }

        // Check collision
        if (dino.x == obstacleX && dino.y == GROUND_Y) {
            printf("Game Over! Your score: %d\n", score);
            break;
        }

        usleep(150000);  // Control game speed
    }

    return 0;
}
