#ifndef LIBSMOLNES_H
#define LIBSMOLNES_H

#include <stdint.h>

//  Initialize smolnes.
//
//      `p_rom` is an array of **unsigned** bytes that must outlive smolnes.
//      Ideally, this should be 1024 * 800 which is enough to fit Kirby's Adventure, 
//      the largest official NES game.
//
//      `p_button_states` must outlive smolnes and contain 8 booleans
//      representing button down in the following order: A, B, Select, Start,
//      Dpad Up, Dpad Down, Dpad Left, Dpad Right
//
void smolnes_init(uint8_t *p_rom, uint8_t p_button_states[8]);

//  Run one iteration of the emulator.
//  You are in charge of ensuring the emulator runs at 60 FPS.
//
//      `frame_buffer` is the framebuffer memory that will be written to.
//      This must be of type `uint16_t[256 * 224]` and must outlive smolnes.
//
//      `render_callback` is called multiple times per tick, taking in the
//      framebuffer and the `data` field.
//
//      The framebuffer is a 256x224 framebuffer storing game colors in the BGR565 format.
//      smolnes skips the top and bottom 8 pixels.
//
void smolnes_tick(uint16_t frame_buffer[256 * 224],
                  void (*render_callback)(uint16_t[256 * 224], void *),
                  void *data);

#endif
