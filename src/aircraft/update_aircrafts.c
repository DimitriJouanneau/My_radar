/*
** EPITECH PROJECT, 2025
** update_aircrafts.c
** File description:
** update aircrafts
*/

#include "../../include/my_radar.h"

static void aircraft_active(aircraft_t *a, float dt)
{
    if (a->active)
        return;
    a->delay -= dt;
    if (a->delay <= 0)
        a->active = 1;
}

static int reached_destination(aircraft_t *a, float dt)
{
    float dx = a->end.x - a->pos.x;
    float dy = a->end.y - a->pos.y;
    float dist = dx * dx + dy * dy;
    float move_dist = a->speed * dt;

    return dist <= move_dist * move_dist;
}

static void move_aircraft(aircraft_t *a, float dt)
{
    if (a->destroyed || !a->active)
        return;
    a->pos.x += a->velocity.x * dt;
    a->pos.y += a->velocity.y * dt;
    if (reached_destination(a, dt)) {
        a->pos = a->end;
        a->landed = 1;
        return;
    }
    sfRectangleShape_setPosition(a->hitbox, a->pos);
    sfSprite_setPosition(a->sprite, a->pos);
}

void update_aircrafts(radar_t *radar)
{
    aircraft_t *a = radar->aircraft;
    float dt = sfTime_asSeconds(sfClock_restart(radar->clock));

    while (a) {
        aircraft_active(a, dt);
        move_aircraft(a, dt);
        a = a->next;
    }
}
