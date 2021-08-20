#pragma once

void clear(int x[6][6], int y[6][6], int z[5][5]);

void map1(void);                    

void printMap(int map[6][6], int soton[6][6], int m[5][5], int e, int x, int y, int turn);

bool checkBounded(int e, int x, int y, int map[6][6], int soton[6][6]);

void restart(int map[6][6], int soton[6][6], int m[5][5]);

void winner(int emtiazA, int emtiazB);

void circlecolor(int i);                        /* header haye bazi! */