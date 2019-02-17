#ifndef UI_H
#define UI_H

void ui_draw_help();
void ui_draw_border();
void ui_draw_debug(float delta);

void ui_draw_sprite(int x, int y, const char **lines, int len);
void ui_clear_sprite(int x, int y, int width, int height);
#endif