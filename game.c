//
// Created by mzxtx on 4/24/22.
//
#include <SDL2/SDL.h>
#include <stdio.h>

#include "game.h"
#include "sdl.h"
struct Game game;
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
    int al = 0;
    game.lin = 0;
    game.col = 0;
    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '0' || ch == '1') {
            al++;
        }
        if (ch == '\n') {
            game.lin++;
        }
    }
    fclose(fp);
    game.lin++;
    game.col = al / game.lin;
    //printf("%d,%d\n",col,lin);
    int i, j;
    for (i = 0; i < game.lin; i++) {
        for (j = 0; j < game.col; j++) {
            fscanf(f, "%c", &game.game[i][j]);
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
    int al = 0;
    game.lin = 0;
    game.col = 0;
    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '0' || ch == '1') {
            al++;
        }
        if (ch == '\n') {
            game.lin++;
        }
    }
    fclose(fp);
    game.lin++;
    game.col = al / game.lin;
    //printf("%d,%d\n",col,lin);
    int i, j;
    for (i = 0; i < game.lin; i++) {
        for (j = 0; j < game.col; j++) {
            fscanf(f, "%c", &game.game[i][j]);
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
        getchar();
        if (c == 'Y' || c == 'y') {
            printf("Please enter the number of game steps:");
            int i;
            scanf("%d", &i);
            if (i == 0 || i > 10000) {
                setbuf(stdin, NULL);
                printf("Invalid input, please re-enter.\n");
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

void play_step(){
    for(game.time=0;game.time<game.step;game.time++){
        for(int i=0;i<game.lin;i++){
            for(int j=0;j<game.col;j++){
                char num[8]={game.game[i-1][j-1],game.game[i-1][j],game.game[i-1][j+1],game.game[i][j-1],game.game[i][j+1],game.game[i+1][j-1],game.game[i+1][j],game.game[i+1][j+1]};
                if(i==0&&j==0){
                    num[0]='0';
                    num[1]='0';
                    num[2]='0';
                    num[3]='0';
                    num[5]='0';
                }
                if(i==0&&j!=0&&j!=game.col-1){
                    num[0]='0';
                    num[1]='0';
                    num[2]='0';
                }
                if(i==0&&j==game.col-1){
                    num[0]='0';
                    num[1]='0';
                    num[2]='0';
                    num[4]='0';
                    num[7]='0';
                }
                if(i!=0&&i!=game.col-1&&j==0){
                    num[0]='0';
                    num[3]='0';
                    num[5]='0';
                }
                if(i!=0&&i!=game.col-1&&j==game.col-1){
                    num[2]='0';
                    num[4]='0';
                    num[7]='0';
                }
                if(i==game.lin-1&&j==0){
                    num[0]='0';
                    num[3]='0';
                    num[5]='0';
                    num[6]='0';
                    num[7]='0';
                }
                if(i==game.lin-1&&j!=0&&j!=game.col-1){
                    num[5]='0';
                    num[6]='0';
                    num[7]='0';
                }
                if(i==game.lin-1&&j==game.col-1){
                    num[2]='0';
                    num[4]='0';
                    num[5]='0';
                    num[6]='0';
                    num[7]='0';
                }
                for(int in=0;in<8;in++){

                }
            }
        }
    }
}

//Run the game
void Run() {
    N_L();
    //Get_Step();
    printf("%d",Get_Step());
    //sdl();
}