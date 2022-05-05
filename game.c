//
// Created by mzxtx on 4/24/22.
//
#include <SDL2/SDL.h>
#include <stdio.h>

#include "game.h"
#include "sdl.h"
struct Game game;
struct Gameof game1;
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
            scanf("%d", &game.step);
            if (game.step == 0 || game.step > 10000) {
                setbuf(stdin, NULL);
                printf("Invalid input, please re-enter.\n");
                continue;
            }
            setbuf(stdin, NULL);
            return game.step;
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

void play_game(){
    game1.i=0;game1.j=0;game1.x=0;game1.y=0;
    game.time=0;

}


void game_odd(){
    for(game1.i=0;game1.i<game.lin;game1.i++){
        for(game1.j=0;game1.j<game.col;game1.j++){
            int count=0;
            for(game1.x=(game1.i-1);game1.x<=(game1.i+1);game1.x++){
                for(game1.y=(game1.j-1);game1.y<=(game1.j+1);game1.y++){
                    if(game.game[game1.x][game1.y]=='1') {
                        count = count + 1;
                    }
                }
            }
            if(game.game[game1.i][game1.j]=='1'){
                if(count==2||count==3){
                    game.game1[game1.i][game1.j]='1';
                } else{
                    game.game1[game1.i][game1.j]='0';
                }
                printf("%c",game.game1[game1.i][game1.j]);
            }
            if(game.game[game1.i][game1.j]=='0'){
                if(count==3){
                    game.game1[game1.i][game1.j]='1';
                } else{
                    game.game1[game1.i][game1.j]='0';
                }
                printf("%c",game.game1[game1.i][game1.j]);
            }
        }
        printf("\n");
        game.time++;
    }
    printf("\n");
}

void game_even(){
    for(game1.i=0;game1.i<game.lin;game1.i++){
        for(game1.j=0;game1.j<game.col;game1.j++){
            int count=0;
            for(game1.x=(game1.i-1);game1.x<=(game1.i+1);game1.x++){
                for(game1.y=(game1.j-1);game1.y<=(game1.j+1);game1.y++){
                    if(game.game[game1.x][game1.y]=='1') {
                        count = count + 1;
                    }
                }
            }
            if(game.game1[game1.i][game1.j]=='1'){
                if(count==2||count==3){
                    game.game[game1.i][game1.j]='1';
                } else{
                    game.game[game1.i][game1.j]='0';
                }
                printf("%c",game.game[game1.i][game1.j]);
            }
            if(game.game1[game1.i][game1.j]=='0'){
                if(count==3){
                    game.game[game1.i][game1.j]='1';
                } else{
                    game.game[game1.i][game1.j]='0';
                }
                printf("%c",game.game[game1.i][game1.j]);
            }
        }
        printf("\n");
        game.time++;
    }
    printf("\n");
}

int exam(){
    for(game1.i=0;game1.i<game.lin;game1.i++) {
        for (game1.j = 0; game1.j < game.col; game1.j++) {
            if(game.game[game1.i][game1.j]=='1'){

            }
        }
    }
}

//Run the game
void Run() {
    N_L();
    Get_Step();
    play_game();
    //printf("%d",Get_Step());
    //sdl();
}