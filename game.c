//
// Created by mzxtx on 4/24/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#include "game.h"
#include "sdl.h"

//Reads the initial state of the world from a file
void Read_File(){
    printf("New Game(N) / Last Game(L):");
    char c;
    scanf("%c",&c);
    if(c == 'N'||c=='n'){
        //printf("new\n");
        FILE *fp= fopen("../newgame.txt","r");
        if(fp==NULL){
            printf("Not found the file.\n");
        }
        /*
        if(fp!=NULL){
            printf("success\n");
        }
         */
        int al,lin,col;
        char ch;
        while ((ch= fgetc(fp))!=EOF){
            if(ch=='0'||ch=='1'){
                al++;
            }
            if(ch=='\n'){
                lin++;
            }
            //printf("%c",ch);
        }
        lin++;
        //printf("\n%d\n",lin);
        col=al/lin;
        //printf("%d\n",col);
        fclose(fp);
        FILE *fp1= fopen("../newgame.txt","r");
        int game[50][50];
        int i,j;
        for(i=0;i<lin;i++){
            for(j=0;j<col;j++){
                fscanf(fp1,"%d ",&game[i][j]);
            }
        }
        fclose(fp1);
        for(i=0;i<lin;i++){
            for(j=0;j<lin;j++){
                printf("%d",game[i][j]);
            }
            printf("\n");
        }

    }
    if(c == 'L'||c=='l'){
        printf("last");
        FILE *fp= fopen("../lastgame.txt","r");
        if(fp==NULL){
            printf("Game log file not found, please start a new game.\n");
            Read_File();
        }
        if(fp!=NULL){
            printf("success\n");
        }
        int al,lin,col;
        char ch;
        while ((ch= fgetc(fp))!=EOF){
            if(ch=='0'||ch=='1'){
                al++;
            }
            if(ch=='\n'){
                lin++;
            }
            //printf("%c",ch);
        }
        lin++;
        //printf("\n%d\n",lin);
        col=al/lin;
        //printf("%d\n",col);
        fclose(fp);
        FILE *fp1= fopen("../lastgame.txt","r");
        int game[50][50];
        int i,j;
        for(i=0;i<lin;i++){
            for(j=0;j<col;j++){
                fscanf(fp1,"%d ",&game[i][j]);
            }
        }
        fclose(fp1);
        for(i=0;i<lin;i++){
            for(j=0;j<lin;j++){
                printf("%d",game[i][j]);
            }
            printf("\n");
        }
        /*
        for(i=0;i<9;i++){
            for(j=0;j<9;j++){
                printf("%d",game[i][j]);
            }
            printf("\n");
        }
         */
    }
    if(c!='N'&c!='n'&c!='l'&c!='L'){
        printf("Invalid input, please re-enter.\n");
        Read_File();
    }

}
//Outputs the final state of the world to a file
void Write_File(){

}

//Get the number of steps from the user
void Get_Step(){
    printf("Do you want to set the number of steps (if not, the game will continue until the end)? (Y / N):");
    char c;
    scanf("%c",&c);
    if(c=='y'||c=='Y'){
        printf("Please enter the number of game steps:");
        int i;
        scanf("%d",&i);
    }
    if(c=='N'||c=='n'){

    }
    if(c!='N'&c!='n'&c!='y'&c!='Y'){
        printf("\nInvalid input, please re-enter.\n");
        Get_Step();
    }
}

//Run the game
void Run(){
    //Read_File();
    Get_Step();
}