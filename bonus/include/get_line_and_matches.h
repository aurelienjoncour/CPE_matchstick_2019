/*
** EPITECH PROJECT, 2020
** bonus
** File description:
** get_line_and_matches
*/

#ifndef GET_LINE_AND_MATCHES_H_
#define GET_LINE_AND_MATCHES_H_

int get_nbr_line(int *line, int nb_lines);

int get_nbr_matches(void);

int error_nbr_matches(int line, int rm_matches, int max_rm_matches,
                            int *game_board);

#endif /* !GET_LINE_AND_MATCHES_H_ */
