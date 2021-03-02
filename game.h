#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define row 3
#define col 3
//ÉùÃ÷
void Initboard(char board[row][col], int r, int c);

void DisplayBoard(char board[row][col],int r,int c);

void playermove(char board[row][col], int r, int c);

void computermove(char board[row][col],int r,int c);

char iswin(char board[row][col], int r, int c);
int isfull(char board[row][col], int r, int c);

