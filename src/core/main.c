/*
** EPITECH PROJECT, 2025
** main.c
** File description:
** main
*/
#include "../../include/my_radar.h"
#include <math.h>

void handle_events(radar_t *radar)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(radar->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(radar->window);
        if (event.type != sfEvtKeyPressed)
            continue;
        if (event.key.code == sfKeyEscape)
            sfRenderWindow_close(radar->window);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyL)
            radar->show_hitbox = !radar->show_hitbox;
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyS)
            radar->show_sprite = !radar->show_sprite;
    }
}

void destroy_radar(radar_t *radar)
{
    sfSprite_destroy(radar->background);
    sfTexture_destroy(radar->bg_texture);
    sfText_destroy(radar->timer_text);
    sfFont_destroy(radar->font);
    sfClock_destroy(radar->timer_clock);
    sfClock_destroy(radar->clock);
    sfRenderWindow_destroy(radar->window);
}

int main(int argc, char **argv)
{
    radar_t radar;

    if (argc != 2) {
        write(2, "retry with -h\n", 14);
        return 84;
    }
    if (h_dash(argc, argv))
        return 0;
    if (init_radar(&radar, argv[1]) == 84)
        return 84;
    while (sfRenderWindow_isOpen(radar.window)) {
        handle_events(&radar);
        update_aircrafts(&radar);
        handle_collision(&radar);
        render(&radar);
        if (all_aircrafts_done(radar.aircraft))
            sfRenderWindow_close(radar.window);
    }
    destroy_radar(&radar);
    return 0;
}
