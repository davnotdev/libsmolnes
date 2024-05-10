#ifndef LIBSMOLNES_H
#define LIBSMOLNES_H

#include <stdint.h>

//  Initialize smolnes.
//
//      `p_button_states` must outlive smolnes and contain 8 booleans
//      representing button down in the following order: A, B Select, Start,
//      Dpad Up, Dpad Down, Dpad Left, Dpad Right
//
void smolnes_init(const char *p_rom, uint32_t p_rom_size,
                  uint8_t p_button_states[8]);

//  Run one iteration of the emulator.
//  You are in charge of ensuring the emulator runs at 60 FPS.
//
//      `render_callback` is called multiple times per tick, taking in the
//      framebuffer and the `data` field. The is a 256x224 framebuffer storing
//      game colors in the BGR565 format. smolnes skips the top and bottom 8
//      pixels.
//
void smolnes_tick(void (*render_callback)(uint16_t[256 * 224], void *),
                  void *data);

#endif
