#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

const int rows = 5;
const int cols = 15;

void fillMatrix(char** matrix, const char charset[]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = charset[std::rand() % (sizeof(charset) - 1)];
        }
    }
}

void printMatrix(char** matrix) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << "\033[32m" << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

void clearMatrix(char** matrix) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = ' ';
        }
    }
}

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    char** matrix = new char* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new char[cols];
    }

    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    std::cout << "Start\n";
    Sleep(1000);
    Beep(440, 500);
    for (int shift = 1; shift <= cols; ++shift) {
        Beep(247, 500); Beep(417, 500); Beep(417, 500); Beep(370, 500); Beep(417, 500); Beep(329, 500); Beep(247, 500); Beep(247, 500); Beep(247, 500); Beep(417, 500); Beep(417, 500); Beep(370, 500); Beep(417, 500); Beep(497, 500);

        fillMatrix(matrix, charset);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < shift - 1; ++j) {
                matrix[i][j] = ' ';
            }
        }

        printMatrix(matrix);

        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        system("cls");
    }
    Sleep(500);
    Beep(497, 500); Beep(277, 500); Beep(277, 500); Beep(440, 500); Beep(440, 500); Beep(417, 500); Beep(370, 500); Beep(329, 500); Beep(247, 500); Beep(417, 500); Beep(417, 500); Beep(370, 500); Beep(417, 500); Beep(329, 500);

    clearMatrix(matrix);

    std::cout << "End\n";
    system("cls");

    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}