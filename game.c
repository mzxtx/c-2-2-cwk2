//
// Created by mzxtx on 4/24/22.
//
#include <SDL2/SDL.h>
#include <stdio.h>

#include "game.h"
#include "sdl.h"

//Ask users to start a new game or continue with the last one.
void N_L() {
    while (1) {
        printf("New Game(N) / Last Game(L):");
        char c;
        scanf("%c", &c);
        if (c == 'N' || c == 'n') {
            Read_New();
            break;
        } else {
            if (c == 'L' || c == 'l') {
                Read_Last();
                break;
            }
        }
        printf("Invalid input, please re-enter.\n");
        setbuf(stdin, NULL);
    }
}

//Reads the initial state of the world from a file
void Read_New() {
    FILE *fp;
    FILE *f;
    fp = fopen("../newgame.txt", "r");
    f = fopen("../newgame.txt", "r");
    if (fp == NULL) {
        printf("File reading error.\n");
    }
    /*
    if(fp!=NULL){
        printf("new\n");
    }
     */

    /*
    if(fp!=NULL){
        printf("last");
    }
     */

    char ch;
    int al = 0, lin = 0, col = 0;
    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '0' || ch == '1') {
            al++;
        }
        if (ch == '\n') {
            lin++;
        }
    }
    fclose(fp);
    lin++;
    col = al / lin;
    //printf("%d,%d\n",col,lin);
    int i, j;
    char game[lin][col];
    for (i = 0; i < lin; i++) {
        for (j = 0; j < col; j++) {
            fscanf(f, "%c", &game[i][j]);
        }
        fscanf(f, "\n");
    }

    fclose(f);

    setbuf(stdin, NULL);
    /*
    for(i=0;i<lin;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%c",game[i][j]);
        }
        printf("\n");
    }
     */
}

void Read_Last() {
    FILE *fp;
    FILE *f;
    fp = fopen("../lastgame.txt", "r");
    f = fopen("../lastgame.txt", "r");
    if (fp == NULL) {
        setbuf(stdin, NULL);
        printf("Game log file not found, you can start a new game.\n");
        N_L();
    }
    /*
    if(fp!=NULL){
        printf("last");
    }
     */

    char ch;
    int al = 0, lin = 0, col = 0;
    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '0' || ch == '1') {
            al++;
        }
        if (ch == '\n') {
            lin++;
        }
    }
    fclose(fp);
    lin++;
    col = al / lin;
//printf("%d,%d\n",col,lin);
    int i, j;
    char game[lin][col];
    for (i = 0; i < lin; i++) {
        for (j = 0; j < col; j++) {
            fscanf(f, "%c", &game[i][j]);
        }
        fscanf(f, "\n");
    }

    fclose(f);

    setbuf(stdin, NULL);
/*
for(i=0;i<lin;i++)
{
    for(j=0;j<col;j++)
    {
        printf("%c",game[i][j]);
    }
    printf("\n");
}
 */
}

//Outputs the final state of the world to a file
void Write_File() {

}

//Get the number of steps from the user
int Get_Step() {
    while (1) {
        printf("Do you want to set the number of steps (if you don't, the game will continue until the end)? (Y / N):");
        char c;
        scanf("%c", &c);
        if (c == 'Y' || c == 'y') {
            printf("Please enter the number of game steps:");
            int i;
            scanf("%d", &i);
            if (i == 0 || i > 10000) {
                printf("Invalid input, please re-enter.\n");
                setbuf(stdin, NULL);
                continue;
            }
            setbuf(stdin, NULL);
            return i;
        } else {
            if (c == 'N' || c == 'n') {
                setbuf(stdin, NULL);
                return 1;
            }
        }
        setbuf(stdin, NULL);
        printf("Invalid input, please re-enter.\n");
    }
}

//Run the game
void Run() {
    //N_L();
    N_L();
    setbuf(stdin, NULL);
    //Get_Step();
    printf("%d",Get_Step());
    //sdl();
}