/*
** EPITECH PROJECT, 2025
** init_radar.c
** File description:
** init_radar
*/

#include "../../include/my_radar.h"

int radar_ressources(radar_t *radar)
{
    radar->window = create_window();
    radar->clock = sfClock_create();
    radar->aircraft = NULL;
    radar->towers = NULL;
    radar->show_hitbox = 1;
    radar->show_sprite = 1;
    radar->aircraft_texture = sfTexture_createFromFile("assets/plane.png"
        , NULL);
    radar->tower_texture = sfTexture_createFromFile("assets/tower.png", NULL);
    radar->timer_clock = sfClock_create();
    radar->font = sfFont_createFromFile("assets/fonts/font.ttf");
    radar->timer_text = sfText_create();
    if (!radar->aircraft_texture || !radar->tower_texture
        || !radar->font || !radar->timer_text)
        return 84;
    return 0;
}

int init_radar(radar_t *radar, const char *file_path)
{
    if (radar_ressources(radar) != 0)
        return 84;
    background(radar);
    if (parse_file(file_path, radar) != 0) {
        sfRenderWindow_destroy(radar->window);
        return 84;
    }
    sfText_setFont(radar->timer_text, radar->font);
    sfText_setCharacterSize(radar->timer_text, 20);
    sfText_setFillColor(radar->timer_text, sfWhite);
    return 0;
}
