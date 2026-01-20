/*
** EPITECH PROJECT, 2025
** parser.c
** File description:
** parser
*/

#include "../../include/my_radar.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int parse_line(char *line, radar_t *radar)
{
    if (line[0] == 'A') {
        parse_aircraft(line, radar);
        return 0;
    }
    if (line[0] == 'T') {
        parse_tower(line, radar);
        return 0;
    }
    return 84;
}

int parse_file(const char *path, radar_t *radar)
{
    FILE *file = fopen(path, "r");
    char *line = NULL;
    size_t len = 0;

    if (!file) {
        write(2, "The file is not correct.\n", 25);
        return 84;
    }
    while (getline(&line, &len, file) != -1) {
        if (parse_line(line, radar) != 0) {
            write(2, "Invalid line in script.\n", 24);
            free(line);
            fclose(file);
            return 84;
        }
    }
    free(line);
    fclose(file);
    return 0;
}
