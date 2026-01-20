/*
** EPITECH PROJECT, 2025
** parse_tower
** File description:
** parse tower
*/

#include "../../include/my_radar.h"
#include <stdio.h>
#include <stdlib.h>

static void create_tower_area(tower_t *t)
{
    t->area = sfCircleShape_create();
    sfCircleShape_setRadius(t->area, t->radius);
    sfCircleShape_setOrigin(t->area, (sfVector2f){t->radius, t->radius});
    sfCircleShape_setPosition(t->area, t->pos);
    sfCircleShape_setFillColor(t->area, sfTransparent);
    sfCircleShape_setOutlineColor(t->area, sfBlue);
    sfCircleShape_setOutlineThickness(t->area, 2);
}

static void tower_area(tower_t *t, radar_t *radar)
{
    sfVector2u size;
    float diameter = t->radius * 2.0f;
    float scale_x;
    float scale_y;

    create_tower_area(t);
    t->sprite = sfSprite_create();
    sfSprite_setTexture(t->sprite, radar->tower_texture, sfTrue);
    size = sfTexture_getSize(radar->tower_texture);
    if (diameter > 80.0f)
        diameter = 80.0f;
    if (diameter < 15.0f)
        diameter = 15.0f;
    scale_x = diameter / size.x;
    scale_y = diameter / size.y;
    sfSprite_setOrigin(t->sprite, (sfVector2f){size.x / 2.0f, size.y / 2.0f});
    sfSprite_setScale(t->sprite, (sfVector2f){scale_x, scale_y});
    sfSprite_setPosition(t->sprite, t->pos);
}

void parse_tower(char *line, radar_t *radar)
{
    tower_t *t = malloc(sizeof(tower_t));
    char *ptr = line + 1;

    if (!t)
        return;
    ptr = skip_spaces(ptr);
    t->pos.x = parse_value(&ptr);
    t->pos.y = parse_value(&ptr);
    t->radius = parse_value(&ptr);
    tower_area(t, radar);
    t->next = radar->towers;
    radar->towers = t;
}
