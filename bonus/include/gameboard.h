/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** gameboard
*/

#ifndef GAMEBOARD_H_
#define GAMEBOARD_H_

void generate_gameboard(int *game_board, int nb_lines);

void display_gameboard(int *game_board, int nb_lines);

void game_action_msg(char *player, int line, int rm_matches);

#endif /* !GAMEBOARD_H_ */
