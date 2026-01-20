/*
** EPITECH PROJECT, 2025
** display.c
** File description:
** display
*/

#include "../../include/my_radar.h"

static void draw_timer(radar_t *radar)
{
    sfTime time = sfClock_getElapsedTime(radar->timer_clock);
    int seconds = (int)sfTime_asSeconds(time);
    char number[16];
    char buffer [32];
    sfFloatRect bounds;

    my_int_to_str(seconds, number);
    buffer[0] = '\0';
    my_strcat(buffer, number);
    my_strcat(buffer, " s");
    sfText_setString(radar->timer_text, buffer);
    bounds = sfText_getGlobalBounds(radar->timer_text);
    sfText_setPosition(radar->timer_text
        , (sfVector2f){1920 - bounds.width - 20, 10});
    sfRenderWindow_drawText(radar->window, radar->timer_text, NULL);
}

static void render_towers(radar_t *radar)
{
    tower_t *t = radar->towers;

    while (t) {
        if (radar->show_sprite && t->sprite)
            sfRenderWindow_drawSprite(radar->window, t->sprite, NULL);
        if (radar->show_hitbox && t->area)
            sfRenderWindow_drawCircleShape(radar->window, t->area, NULL);
        t = t->next;
    }
}

static void render_aircrafts(radar_t *radar)
{
    aircraft_t *a = radar->aircraft;

    while (a) {
        if (a->destroyed || a->landed) {
            a = a->next;
            continue;
        }
        if (radar->show_sprite && a->sprite)
            sfRenderWindow_drawSprite(radar->window
                , a->sprite, NULL);
        if (radar->show_hitbox && a->hitbox)
            sfRenderWindow_drawRectangleShape(radar->window
                , a->hitbox, NULL);
        a = a->next;
    }
}

void render(radar_t *radar)
{
    sfRenderWindow_clear(radar->window, sfBlack);
    if (radar->background)
        sfRenderWindow_drawSprite(radar->window, radar->background, NULL);
    render_towers(radar);
    render_aircrafts(radar);
    draw_timer(radar);
    sfRenderWindow_display(radar->window);
}
