//
// Created by mzxtx on 4/24/22.
//
#include <SDL2/SDL.h>
#include <stdio.h>

#include "game.h"
#include "sdl.h"

struct Game game;
struct Gameof game1;
int N_Y, n_l;

//Ask users to start a new game or continue with the last one.
void N_L() {
    printf("Please select the game type:\n");
    printf("1.New Game\n");
    printf("2.Last Game\n");
    printf("3.Exit\n");
    scanf("%d", &n_l);
    if (n_l == 1) {
        Read_New();
    }
    if (n_l == 2) {
        Read_Last();
    }
    if (n_l == 3) {
        exit(0);
    }
    if (n_l != 1 && n_l != 2 && n_l != 3) {
        printf("Invalid input, please re-enter.\n");
        setbuf(stdin, NULL);
        N_L();
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
    game.col = al / game.lin;
    //printf("%d,%d\n",game.col,game.lin);
    int i, j;
    for (i = 0; i < game.lin; i++) {
        for (j = 0; j < game.col; j++) {
            fscanf(f, "%c", &game.game[i][j]);
        }
        fscanf(f, "\n");
    }
    fclose(f);
    setbuf(stdin, NULL);
    game.exam=0;
    for (game1.i = 0; game1.i < game.lin; game1.i++) {
        for (game1.j = 0; game1.j < game.col; game1.j++) {
            if (game.game[game1.i][game1.j] == '1' ) {
                game.exam=1;
            }
        }
    }
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
    char c = fgetc(fp);
    if (fp == NULL || c == EOF) {
        setbuf(stdin, NULL);
        printf("Sorry, game data not found, you can start a new game. \n");
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
    game.col = al / game.lin;
    game.col++;
    //printf("%d,%d\n",game.col,game.lin);
    int i, j;
    for (i = 0; i < game.lin; i++) {
        for (j = 0; j < game.col; j++) {
            fscanf(f, "%c", &game.game[i][j]);
        }
        fscanf(f, "\n");
    }
    fclose(f);
    setbuf(stdin, NULL);
    game.exam=0;
    for (game1.i = 0; game1.i < game.lin; game1.i++) {
        for (game1.j = 0; game1.j < game.col; game1.j++) {
            if (game.game[game1.i][game1.j] == '1' ) {
                game.exam=1;
            }
        }
    }
/*
    for (i = 0; i < game.lin; i++) {
        for (j = 0; j < game.col; j++) {
            printf("%c", game.game[i][j]);
        }
        printf("\n");
    }*/

}

//Outputs the final state of the world to a file
void Write_File() {
    FILE *fp;
    fp = fopen("../lastgame.txt", "w");
    if (game.exam != 0) {
        if (game.time % 2 == 1) {
            for (game1.i = 0; game1.i < game.lin; game1.i++) {
                for (game1.j = 0; game1.j < game.col; game1.j++) {
                    fprintf(fp, "%c", game.game1[game1.i][game1.j]);
                }
                fprintf(fp, "\n");
            }
        }
        if (game.time % 2 == 0) {
            for (game1.i = 0; game1.i < game.lin; game1.i++) {
                for (game1.j = 0; game1.j < game.col; game1.j++) {
                    fprintf(fp, "%c", game.game[game1.i][game1.j]);
                }
                fprintf(fp, "\n");
            }
        }
    }
    if (game.exam == 0) {
        fprintf(fp, "");
    }
    fclose(fp);
}


//Get the number of steps from the user
void if_Step() {
    if (n_l == 1 || n_l == 2) {
        printf("Do you want to set the number of steps (if you don't, the game will continue until the end)?\n");
        printf("1.Yes\n");
        printf("2.No\n");
        printf("3.Return back\n");
        printf("4.Exit\n");
        scanf("%d", &N_Y);
        //getchar();
        if (N_Y != 1 && N_Y != 2 && N_Y != 3 && N_Y != 4) {
            printf("Invalid input, please re-enter.\n");
            setbuf(stdin, NULL);
            if_Step();
        }
    }
    if (N_Y == 3) {
        N_L();
    }
    if (N_Y == 4) {
        exit(0);
    }
}

int Get_step() {
    if (N_Y == 1) {
        printf("Please enter the number of game steps:");
        scanf("%d", &game.step);
        if (game.step <= 0) {
            setbuf(stdin, NULL);
            printf("Invalid input, please re-enter.\n");
            Get_step();
        }
    }
    if (N_Y == 2) {
        setbuf(stdin, NULL);
        game.step = 1000;
    }
    return game.step;
}

void game_odd() {
    for (game1.i = 0; game1.i < game.lin; game1.i++) {
        for (game1.j = 0; game1.j < game.col; game1.j++) {
            int count = 0;
            for (game1.x = (game1.i - 1); game1.x <= (game1.i + 1); game1.x++) {
                for (game1.y = (game1.j - 1); game1.y <= (game1.j + 1); game1.y++) {
                    if (game.game[game1.x][game1.y] == '1') {
                        count = count + 1;
                    }
                }
            }
            if (game.game[game1.i][game1.j] == '1') {
                if (count == 3 || count == 4) {
                    game.game1[game1.i][game1.j] = '1';
                } else {
                    game.game1[game1.i][game1.j] = '0';
                }
                printf("%c", game.game1[game1.i][game1.j]);

            }
            if (game.game[game1.i][game1.j] == '0') {
                if (count == 3) {
                    game.game1[game1.i][game1.j] = '1';
                } else {
                    game.game1[game1.i][game1.j] = '0';
                }
                printf("%c", game.game1[game1.i][game1.j]);

            }
        }
        printf("\n");
    }
    game.time++;
    game.exam=0;
    for (game1.i = 0; game1.i < game.lin; game1.i++) {
        for (game1.j = 0; game1.j < game.col; game1.j++) {
            if (game.game1[game1.i][game1.j] == '1' ) {
                game.exam=1;
            }
        }
    }
    printf("%d\n", game.time);
    //printf("exam=%d", game.exam);
    printf("\n");
}

void game_even() {
    for (game1.i = 0; game1.i < game.lin; game1.i++) {
        for (game1.j = 0; game1.j < game.col; game1.j++) {
            int count = 0;
            for (game1.x = (game1.i - 1); game1.x <= (game1.i + 1); game1.x++) {
                for (game1.y = (game1.j - 1); game1.y <= (game1.j + 1); game1.y++) {
                    if (game.game[game1.x][game1.y] == '1') {
                        count = count + 1;
                    }
                }
            }
            if (game.game1[game1.i][game1.j] == '1') {
                if (count == 3 || count == 4) {
                    game.game[game1.i][game1.j] = '1';
                } else {
                    game.game[game1.i][game1.j] = '0';
                }
                printf("%c", game.game[game1.i][game1.j]);

            }
            if (game.game1[game1.i][game1.j] == '0') {
                if (count == 3) {
                    game.game[game1.i][game1.j] = '1';
                } else {
                    game.game[game1.i][game1.j] = '0';
                }
                printf("%c", game.game[game1.i][game1.j]);

            }
        }
        printf("\n");
    }
    game.time++;
    game.exam=0;
    for (game1.i = 0; game1.i < game.lin; game1.i++) {
        for (game1.j = 0; game1.j < game.col; game1.j++) {
            if (game.game[game1.i][game1.j] == '1' ) {
                game.exam=1;
            }
        }
    }
    printf("%d\n", game.time);
    //printf("exam=%d", game.exam);
    printf("\n");
}


//Run the game
void Run() {
    N_L();
    if_Step();
    Get_step();
    //play_game();
    //printf("%d", Get_step());
    //sdl();
}