//
// Created by mzxtx on 4/24/22.
//
#ifndef C_2_2_CWK2_GAME_H
#define C_2_2_CWK2_GAME_H

#endif //C_2_2_CWK2_GAME_H
struct Game{
    int lin;
    int col;
    char game[50][50];
    int time;
    int step;
    int exam;
    int exam1;
    char game1[50][50];
};

struct Gameof{
    int i;
    int j;
    int x;
    int y;
};
void N_L();
void Read_Last();
void Read_New();
void Write_File();
void if_Step();
int Get_Step();
void game_odd();
void game_even();
void Run();