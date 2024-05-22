#include <SDL2/SDL.h>
#include "smolnes.h"

typedef struct {
    SDL_Renderer* renderer;
    SDL_Texture* texture;
} RenderData;

void render_callback(uint16_t out_fb[256 * 224], void* data);

int main(int argc, char** argv) {
    //  Read the ROM
    char rombuf[1024 * 1024];
    SDL_RWread(SDL_RWFromFile(argv[1], "rb"), rombuf, 1024 * 800, 1);

    //  Init SDL
    SDL_Init(SDL_INIT_VIDEO);

    void *renderer = SDL_CreateRenderer(
            SDL_CreateWindow("smolnes", 0, 0, 1024, 840, SDL_WINDOW_SHOWN), -1,
            SDL_RENDERER_PRESENTVSYNC);
    void *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_BGR565,
            SDL_TEXTUREACCESS_STREAMING, 256, 224);

    uint8_t* key_state;
    key_state = (uint8_t*)SDL_GetKeyboardState(0);

    //  Init smolnes
    uint8_t button_states[8] = { 0 };
    smolnes_init(rombuf, 1024 * 800, button_states);

    while (1) {
        //  Tick smolnes
        button_states[0] = key_state[SDL_SCANCODE_X];
        button_states[1] = key_state[SDL_SCANCODE_Z];
        button_states[2] = key_state[SDL_SCANCODE_TAB];
        button_states[3] = key_state[SDL_SCANCODE_RETURN];
        button_states[4] = key_state[SDL_SCANCODE_UP];
        button_states[5] = key_state[SDL_SCANCODE_DOWN];
        button_states[6] = key_state[SDL_SCANCODE_LEFT];
        button_states[7] = key_state[SDL_SCANCODE_RIGHT];

        RenderData data;
        data.renderer = renderer;
        data.texture = texture;
        smolnes_tick(render_callback, &data);
    }
    return 0;
}

void render_callback(uint16_t out_fb[256 * 224], void* data) {
    RenderData* render_data = (RenderData*)data;

    //  Update SDL
    SDL_UpdateTexture(render_data->texture, 0, out_fb, 512);
    SDL_RenderCopy(render_data->renderer, render_data->texture, 0, 0);
    SDL_RenderPresent(render_data->renderer);

    for (SDL_Event event; SDL_PollEvent(&event);)
        if (event.type == SDL_QUIT)
            exit(0);
}
