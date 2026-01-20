/*
** EPITECH PROJECT, 2025
** background.c
** File description:
** background
*/

#include "../../include/my_radar.h"

void background(radar_t *radar)
{
    radar->background = sfSprite_create();
    radar->bg_texture = sfTexture_createFromFile("assets/bg/back.jpg", NULL);
    if (!radar->bg_texture || !radar->background)
        return;
    sfSprite_setTexture(radar->background, radar->bg_texture, sfTrue);
}
