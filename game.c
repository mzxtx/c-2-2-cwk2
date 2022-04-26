//
// Created by mzxtx on 4/24/22.
//
#include <SDL2/SDL.h>

#include "game.h"
#include "sdl.h"
//Ask users to start a new game or continue with the last one.
int N_L(){
    printf("New Game(N) / Last Game(L):");
    char c;
    scanf("%c",&c);
    if(c=='N'||c=='n'){
        return 1;
    }
    if(c=='L'||c=='l'){
        return 2;
    }
    if(c!='N'&&c!='n'&&c!='l'&&c!='L'){
        printf("Invalid input, please re-enter.\n");
        N_L();
    }
}
//Reads the initial state of the world from a file
void Read_File(){
    char filename;
    FILE *fp;
    FILE *f;
    if(N_L()==1){
        fp= fopen("../newgame.txt","r");
        f= fopen("../newgame.txt","r");
        if(fp==NULL){
            printf("File reading error.\n");
        }
        if(fp!=NULL){
            printf("new\n");
        }
    } else{
    if(N_L()==2) {
        fp= fopen("../lastgame.txt","r");
        f= fopen("../lastgame.txt","r");
        if(fp==NULL){
            printf("Game log file not found, you can start a new game.");
            N_L();
        }
    }}
    char ch;
    int al=0,lin=0,col=0;
    while((ch=fgetc(fp)) != EOF) {
        if (ch == '0' || ch== '1') {
            al++;
        }
        if (ch == '\n') {
            lin++;
        }
    }
    fclose(fp);
    lin++;
    col = al/lin;
    printf("%d,%d\n",col,lin);
    int i,j;
    char game[lin][col];
    for(i=0;i<lin;i++)
    {
        for(j=0;j<col;j++)
        {
            fscanf(f,"%c",&game[i][j]);
        }
        fscanf(f,"\n");
    }

    fclose(f);

    for(i=0;i<lin;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%c",game[i][j]);
        }
        printf("\n");
    }
}
//Outputs the final state of the world to a file
void Write_File(){

}
//Ask the user if the number of steps needs to be set
char Y_N(){

}
//Get the number of steps from the user
int Get_Step(){

}

//Run the game
void Run(){
    Read_File();
    //sdl();
}