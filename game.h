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
    int count;
};
void N_L();
void Read_Last();
void Read_New();
void Write_File();
int Get_Step();
void play_step();
void Run();