/*
** EPITECH PROJECT, 2025
** my_radar.h
** File description:
** header file
*/

#ifndef _MY_RADAR_
    #define _MY_RADAR_

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <math.h>
    #include "../lib/my/my_printf/my_printf.h"
    #include "../lib/my/my.h"

typedef struct aircraft_s {
    sfVector2f start;
    sfVector2f end;
    sfVector2f pos;
    sfVector2f velocity;
    float speed;
    float delay;
    int active;
    int destroyed;
    int landed;
    sfSprite *sprite;
    sfRectangleShape *hitbox;
    struct aircraft_s *next;
} aircraft_t;

typedef struct tower_s {
    sfVector2f pos;
    float radius;
    sfCircleShape *area;
    sfSprite *sprite;
    struct tower_s *next;
} tower_t;

typedef struct {
    sfRenderWindow *window;
    sfClock *clock;
    aircraft_t *aircraft;
    tower_t *towers;
    int show_hitbox;
    int show_sprite;
    sfTexture *aircraft_texture;
    sfTexture *tower_texture;
    sfClock *timer_clock;
    sfText *timer_text;
    sfFont *font;
    sfTexture *bg_texture;
    sfSprite *background;
} radar_t;

void background(radar_t *radar);
char *skip_spaces(char *str);
void parse_tower(char *line, radar_t *radar);
void parse_aircraft(char *line, radar_t *radar);
float parse_value(char **ptr);
void render(radar_t *radar);
int parse_file(const char *path, radar_t *radar);
void update_aircrafts(radar_t *radar);
void handle_collision(radar_t *radar);
sfRenderWindow *create_window(void);
void init_aircraft(aircraft_t *a, const sfVector2f *pos,
    const sfVector2f *velocity, const sfColor *color);
void handle_events(radar_t *radar);
void handle_collision(radar_t *radar);
void render(radar_t *radar);
void update_aircrafts(radar_t *radar);
int all_aircrafts_done(aircraft_t *a);
int init_radar(radar_t *radar, const char *file_path);
int h_dash(int argc, char **argv);

#endif /* _MY_RADAR_ */
