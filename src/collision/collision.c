/*
** EPITECH PROJECT, 2025
** collision.c
** File description:
** collision
*/

#include "../../include/my_radar.h"

int in_tower(const sfVector2f *pos, tower_t *tower)
{
    float dx = pos->x - tower->pos.x;
    float dy = pos->y - tower->pos.y;
    float dist = sqrt(dx * dx + dy * dy);

    return dist <= tower->radius;
}

int aircrafts_collide(aircraft_t *a1, aircraft_t *a2)
{
    sfFloatRect r1;
    sfFloatRect r2;

    if (a1->destroyed || a2->destroyed || a1->landed || a2->landed)
        return 0;
    r1 = sfRectangleShape_getGlobalBounds(a1->hitbox);
    r2 = sfRectangleShape_getGlobalBounds(a2->hitbox);
    return sfFloatRect_intersects(&r1, &r2, NULL);
}

int aircraft_in_safe_zone(aircraft_t *a, tower_t *towers)
{
    while (towers) {
        if (in_tower(&a->pos, towers))
            return 1;
        towers = towers->next;
    }
    return 0;
}

void collision(aircraft_t *a1, aircraft_t *a2, tower_t *towers)
{
    if (aircraft_in_safe_zone(a1, towers))
        return;
    if (aircraft_in_safe_zone(a2, towers))
        return;
    a1->destroyed = 1;
    a2->destroyed = 1;
}

static void if_collide(aircraft_t *a1, aircraft_t *a2,
    tower_t *towers)
{
    if (!aircrafts_collide(a1, a2))
        return;
    collision(a1, a2, towers);
}

void handle_collision(radar_t *radar)
{
    aircraft_t *a1 = radar->aircraft;
    aircraft_t *a2;

    while (a1) {
        a2 = a1->next;
        while (a2) {
            if_collide(a1, a2, radar->towers);
            a2 = a2->next;
        }
        a1 = a1->next;
    }
}
