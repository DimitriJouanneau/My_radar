/*
** EPITECH PROJECT, 2025
** h_dash.c
** File description:
** h dash
*/

#include "../../include/my_radar.h"

int h_dash(int argc, char **argv)
{
    if (argc == 2 && my_strcmp(argv[1], "-h") == 0) {
        write(1,
            "Air traffic simulation.\nUSAGE\n./my_radar [FILE]\n"
            "FILE\tThe path to the script file.\n"
            "OPTIONS\n-h\tExplain how to use the system.\n"
            "USER INTERACTIONS\n'L'\tEnable/disable hitboxes and area.\n"
            "'S'\tEnable/disable sprites.\n", 208);
        return 1;
    }
    return 0;
}
