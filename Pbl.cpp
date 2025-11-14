#include <graphics.h>  // Or <winbgim.h> if you have WinBGI installed
#include <conio.h>
#include <dos.h>  // Or <windows.h> for Sleep() if needed

void drawBackground() {
    // Simplified creative background: Solid light blue sky
    setcolor(LIGHTBLUE);
    setfillstyle(SOLID_FILL, LIGHTBLUE);
    bar(0, 0, getmaxx(), getmaxy());  // Fill the entire screen
    
    // Add fluffy clouds (white filled circles/ellipses)
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    ellipse(100, 100, 0, 360, 50, 30);  // Cloud 1
    floodfill(100, 100, WHITE);
    ellipse(150, 120, 0, 360, 40, 25);
    floodfill(150, 120, WHITE);
    
    ellipse(500, 80, 0, 360, 60, 35);  // Cloud 2
    floodfill(500, 80, WHITE);
    ellipse(550, 100, 0, 360, 45, 28);
    floodfill(550, 100, WHITE);
}

void happyFace() {
    setcolor(YELLOW);
    circle(300, 200, 100); // Face
    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(300, 200, YELLOW);

    setcolor(BLACK);
    circle(260, 170, 10);  // Left eye
    circle(340, 170, 10);  // Right eye
    setfillstyle(SOLID_FILL, BLACK);
    floodfill(260, 170, BLACK);
    floodfill(340, 170, BLACK);

    arc(300, 220, 200, 340, 40); // Happy mouth

    // Add light red cheeks above the smile (moved up from y=230 to y=200)
    setcolor(LIGHTRED);
    setfillstyle(SOLID_FILL, LIGHTRED);
    circle(250, 200, 15);  // Left cheek (above smile)
    floodfill(250, 200, LIGHTRED);
    circle(350, 200, 15);  // Right cheek (above smile)
    floodfill(350, 200, LIGHTRED);
}

void sadFace() {
    setcolor(YELLOW);
    circle(300, 200, 100); // Face
    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(300, 200, YELLOW);

    setcolor(BLACK);
    circle(260, 170, 10);  // Left eye
    circle(340, 170, 10);  // Right eye
    setfillstyle(SOLID_FILL, BLACK);
    floodfill(260, 170, BLACK);
    floodfill(340, 170, BLACK);

    arc(300, 250, 20, 160, 40); // Sad mouth

    // No red cheeks for sad face (removed as requested)
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    for (int i = 0; i < 5; i++) {
        cleardevice();
        drawBackground();  // Draw the simplified creative background each time
        happyFace();
        delay(1000);
        cleardevice();
        drawBackground();  // Redraw background
        sadFace();
        delay(1000);
    }

    getch();
    closegraph();
    return 0;
}
