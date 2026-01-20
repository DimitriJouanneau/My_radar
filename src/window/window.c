/*
** EPITECH PROJECT, 2025
** window.c
** File description:
** window
*/

#include "../../include/my_radar.h"

sfRenderWindow *create_window(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *w = sfRenderWindow_create(mode, "my_radar", sfClose, NULL);

    sfRenderWindow_setFramerateLimit(w, 60);
    return w;
}
