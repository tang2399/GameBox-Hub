#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define SIZE 4
#define TARGET 2048

// 游戏面板
int board[SIZE][SIZE] = {0};
int score = 0;

// 函数原型
void initGame();
void drawBoard();
void generateNewNumber();
int moveLeft();
int moveRight();
int moveUp();
int moveDown();
int checkGameOver();
int checkWin();
void clearScreen();

// 主函数
int main() {
    int gameOver = 0;
    int win = 0;
    char key;
    int moved;

    // 初始化随机数种子
    srand((unsigned int)time(NULL));
    
    // 初始化游戏
    initGame();
    
    // 游戏循环
    while (!gameOver && !win) {
        // 绘制面板
        clearScreen();
        drawBoard();
        
        // 获取用户输入
        printf("\nUse arrow keys or WASD to move blocks (ESC to exit)\n");
        key = getch();
        
        // 处理输入
        moved = 0;
        if (key == 27) { // ESC键
            break;
        } else if (key == 0 || key == 224) { // 方向键
            key = getch(); // 获取第二个字节
            
            switch (key) {
                case 75: // 左方向键
                    moved = moveLeft();
                    break;
                case 77: // 右方向键
                    moved = moveRight();
                    break;
                case 72: // 上方向键
                    moved = moveUp();
                    break;
                case 80: // 下方向键
                    moved = moveDown();
                    break;
            }
        } else { // WASD键处理
            switch (key) {
                case 'a': case 'A': // 左
                    moved = moveLeft();
                    break;
                case 'd': case 'D': // 右
                    moved = moveRight();
                    break;
                case 'w': case 'W': // 上
                    moved = moveUp();
                    break;
                case 's': case 'S': // 下
                    moved = moveDown();
                    break;
            }
        }
        
        // 如果移动了，生成新数字
        if (moved) {
            generateNewNumber();
        }
        
        // 检查游戏状态
        win = checkWin();
        gameOver = checkGameOver();
    }
    
    
    // 最终面板状态
    clearScreen();
    drawBoard();
    
    // 游戏结果
    if (win) {
        printf("\nCongratulations! You won!\n");
    } else if (gameOver) {
        printf("\nGame Over! No more moves available.\n");
    }
    
    printf("\nFinal score: %d\n", score);
    printf("Press ESC key to exit...");
    
    // 等待用户按下ESC键退出
    while (1) {
        char exitKey = getch();
        if (exitKey == 27) { // ESC键
            break;
        }
    }
    
    return 0;
}

// 用两个随机数初始化游戏
void initGame() {
    score = 0;
    
    // 清空面板
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = 0;
        }
    }
    
    // 生成两个初始数字
    generateNewNumber();
    generateNewNumber();
}

// 绘制游戏面板
void drawBoard() {
    printf("\n  2048 Game\n");
    printf("  Score: %d\n\n", score);
    
    for (int i = 0; i < SIZE; i++) {
        printf("  +------+------+------+------+\n  ");
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                printf("|      ");
            } else {
                printf("| %4d ", board[i][j]);
            }
        }
        printf("|\n");
    }
    printf("  +------+------+------+------+\n");
}

// 在随机空单元格中生成新数字（2或4）
void generateNewNumber() {
    int emptyCells[SIZE * SIZE][2];
    int count = 0;
    
    // 找出所有空单元格
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                emptyCells[count][0] = i;
                emptyCells[count][1] = j;
                count++;
            }
        }
    }
    
    // 如果有空单元格
    if (count > 0) {
        // 选择一个随机空单元格
        int index = rand() % count;
        int row = emptyCells[index][0];
        int col = emptyCells[index][1];
        
        // 生成2（90%几率）或4（10%几率）
        board[row][col] = (rand() % 10 == 0) ? 4 : 2;
    }
}

// 向左移动方块
int moveLeft() {
    int moved = 0;
    int merged[SIZE][SIZE] = {0}; // 跟踪已合并的单元格
    
    for (int i = 0; i < SIZE; i++) {
        // 将非零元素压缩到左侧
        for (int j = 1; j < SIZE; j++) {
            if (board[i][j] != 0) {
                int col = j;
                while (col > 0 && board[i][col-1] == 0) {
                    board[i][col-1] = board[i][col];
                    board[i][col] = 0;
                    col--;
                    moved = 1;
                }
                
                // 如果可能则合并
                if (col > 0 && board[i][col-1] == board[i][col] && !merged[i][col-1]) {
                    board[i][col-1] *= 2;
                    score += board[i][col-1];
                    board[i][col] = 0;
                    merged[i][col-1] = 1;
                    moved = 1;
                }
            }
        }
    }
    
    return moved;
}

// 向右移动方块
int moveRight() {
    int moved = 0;
    int merged[SIZE][SIZE] = {0}; // 跟踪已合并的单元格
    
    for (int i = 0; i < SIZE; i++) {
        // 将非零元素压缩到右侧
        for (int j = SIZE - 2; j >= 0; j--) {
            if (board[i][j] != 0) {
                int col = j;
                while (col < SIZE - 1 && board[i][col+1] == 0) {
                    board[i][col+1] = board[i][col];
                    board[i][col] = 0;
                    col++;
                    moved = 1;
                }
                
                // 如果可能则合并
                if (col < SIZE - 1 && board[i][col+1] == board[i][col] && !merged[i][col+1]) {
                    board[i][col+1] *= 2;
                    score += board[i][col+1];
                    board[i][col] = 0;
                    merged[i][col+1] = 1;
                    moved = 1;
                }
            }
        }
    }
    
    return moved;
}

// 向上移动方块
int moveUp() {
    int moved = 0;
    int merged[SIZE][SIZE] = {0}; // 跟踪已合并的单元格
    
    for (int j = 0; j < SIZE; j++) {
        // 将非零元素向上压缩
        for (int i = 1; i < SIZE; i++) {
            if (board[i][j] != 0) {
                int row = i;
                while (row > 0 && board[row-1][j] == 0) {
                    board[row-1][j] = board[row][j];
                    board[row][j] = 0;
                    row--;
                    moved = 1;
                }
                
                // 如果可能则合并
                if (row > 0 && board[row-1][j] == board[row][j] && !merged[row-1][j]) {
                    board[row-1][j] *= 2;
                    score += board[row-1][j];
                    board[row][j] = 0;
                    merged[row-1][j] = 1;
                    moved = 1;
                }
            }
        }
    }
    
    return moved;
}

// 向下移动方块
int moveDown() {
    int moved = 0;
    int merged[SIZE][SIZE] = {0}; // 跟踪已合并的单元格
    
    for (int j = 0; j < SIZE; j++) {
        // 将非零元素向下压缩
        for (int i = SIZE - 2; i >= 0; i--) {
            if (board[i][j] != 0) {
                int row = i;
                while (row < SIZE - 1 && board[row+1][j] == 0) {
                    board[row+1][j] = board[row][j];
                    board[row][j] = 0;
                    row++;
                    moved = 1;
                }
                
                // 如果可能则合并
                if (row < SIZE - 1 && board[row+1][j] == board[row][j] && !merged[row+1][j]) {
                    board[row+1][j] *= 2;
                    score += board[row+1][j];
                    board[row][j] = 0;
                    merged[row+1][j] = 1;
                    moved = 1;
                }
            }
        }
    }
    
    return moved;
}

// 检查游戏是否结束（没有可能的移动）
int checkGameOver() {
    // 检查空单元格
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                return 0; // 游戏未结束，找到空单元格
            }
        }
    }
    
    // 检查水平方向可能的合并
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE - 1; j++) {
            if (board[i][j] == board[i][j+1]) {
                return 0; // 游戏未结束，可以水平合并
            }
        }
    }
    
    // 检查垂直方向可能的合并
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == board[i+1][j]) {
                return 0; // 游戏未结束，可以垂直合并
            }
        }
    }
    
    return 1; // 游戏结束，没有可能的移动
}

// 检查玩家是否获胜（达到2048）
int checkWin() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == TARGET) {
                return 1; // 满足获胜条件
            }
        }
    }
    return 0; // 未满足获胜条件
}

// 清空控制台屏幕
void clearScreen() {
    system("cls");
}