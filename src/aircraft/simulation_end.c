/*
** EPITECH PROJECT, 2025
** simulation.c
** File description:
** simulation
*/

#include "../../include/my_radar.h"

int all_aircrafts_done(aircraft_t *a)
{
    while (a) {
        if (!a->destroyed && !a->landed)
            return 0;
        a = a->next;
    }
    return 1;
}
