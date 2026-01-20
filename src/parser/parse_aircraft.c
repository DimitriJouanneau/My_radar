/*
** EPITECH PROJECT, 2025
** parse_aircraft.c
** File description:
** parse aircraft
*/

#include "../../include/my_radar.h"
#include <stdlib.h>

int my_atoi(char *str)
{
    int res = 0;
    int sign = 1;

    if (*str == '-') {
        sign = -1;
        str++;
    }
    while (*str >= '0' && *str <= '9') {
        res = res * 10 + (*str - '0');
        str++;
    }
    return res * sign;
}

char *skip_spaces(char *str)
{
    while (*str == ' ' || *str == '\t')
        str++;
    return str;
}

float parse_value(char **ptr)
{
    float value = my_atoi(*ptr);

    while (**ptr && **ptr != ' ')
        (*ptr)++;
    *ptr = skip_spaces(*ptr);
    return value;
}

static sfVector2f velocity(aircraft_t *a)
{
    float dx = a->end.x - a->start.x;
    float dy = a->end.y - a->start.y;
    float len = sqrt(dx * dx + dy * dy);

    if (len == 0)
        return (sfVector2f){0, 0};
    return (sfVector2f) {dx / len * a->speed, dy / len * a->speed};
}

static void aircraft_hitbox(aircraft_t *a)
{
    a->hitbox = sfRectangleShape_create();
    sfRectangleShape_setSize(a->hitbox, (sfVector2f){20, 20});
    sfRectangleShape_setOrigin(a->hitbox, (sfVector2f){10, 10});
    sfRectangleShape_setPosition(a->hitbox, a->pos);
    sfRectangleShape_setFillColor(a->hitbox, sfTransparent);
    sfRectangleShape_setOutlineColor(a->hitbox, sfGreen);
    sfRectangleShape_setOutlineThickness(a->hitbox, 1);
}

aircraft_t *create_aircraft(char *line)
{
    aircraft_t *a = malloc(sizeof(aircraft_t));
    char *ptr = line + 1;

    if (!a)
        return NULL;
    ptr = skip_spaces(ptr);
    a->start.x = parse_value(&ptr);
    a->start.y = parse_value(&ptr);
    a->end.x = parse_value(&ptr);
    a->end.y = parse_value(&ptr);
    a->speed = parse_value(&ptr);
    a->delay = parse_value(&ptr);
    a->pos = a->start;
    a->active = 0;
    a->landed = 0;
    a->destroyed = 0;
    a->velocity = velocity(a);
    aircraft_hitbox(a);
    a->next = NULL;
    return a;
}

static void aircraft_texture(aircraft_t *a, radar_t *radar)
{
    sfVector2u size;

    if (!a || !radar)
        return;
    a->sprite = sfSprite_create();
    sfSprite_setTexture(a->sprite, radar->aircraft_texture, sfTrue);
    size = sfTexture_getSize(radar->aircraft_texture);
    sfSprite_setOrigin(a->sprite, (sfVector2f){size.x / 2.0f, size.y / 2.0f});
    sfSprite_setScale(a->sprite, (sfVector2f){0.078f, 0.078f});
    sfSprite_setPosition(a->sprite, a->pos);
    a->next = radar->aircraft;
    radar->aircraft = a;
}

void parse_aircraft(char *line, radar_t *radar)
{
    aircraft_t *a = create_aircraft(line);

    if (!a)
        return;
    aircraft_texture(a, radar);
}
