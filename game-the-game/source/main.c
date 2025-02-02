#include <stdio.h>

#include <SDL3/SDL.h>

#define MAX_GAMEPADS 4

typedef struct
{
    SDL_Gamepad *sdl;
    SDL_JoystickID id;
    bool connected;
} gamepad_t;

const gamepad_t null_gamepad = {nullptr, -1, false};

gamepad_t gamepads[MAX_GAMEPADS] = { null_gamepad };

bool sdl_error = false;

void close_gamepads()
{
    for(int player = 0; player < MAX_GAMEPADS; ++player)
    {
        SDL_CloseGamepad(gamepads[player].sdl);
        gamepads[player] = null_gamepad;
    }
}

void sdl_init_cleanup(bool *initialized)
{
    if(sdl_error)
    {
        fprintf(stderr, "%s\n", SDL_GetError());
    }
    if(*initialized)
    {
        close_gamepads();
        SDL_Quit();
        *initialized = false;
    }
}

void window_cleanup(SDL_Window **window)
{
    if(*window)
    {
        SDL_DestroyWindow(*window);
        *window = nullptr;
    }
}

void renderer_cleanup(SDL_Renderer **renderer)
{
    if(*renderer)
    {
        SDL_DestroyRenderer(*renderer);
        *renderer = nullptr;
    }
}

bool add_gamepad(SDL_JoystickID id)
{
    int player = SDL_GetGamepadPlayerIndexForID(id);
    if(player < 0 || player >= 4)
    {
        return false;
    }
    gamepads[player].id = id;
    gamepads[player].sdl = SDL_OpenGamepad(id);
    if(gamepads[player].sdl)
    {
        gamepads[player].connected = true;
        printf("player %d connected\n", player);
        return true;
    }
    gamepads[player].connected = false;
    return false;
}

void remove_gamepad(SDL_JoystickID id)
{
    for(int player = 0; player < MAX_GAMEPADS; ++player)
    {
        if(gamepads[player].id == id)
        {
            SDL_CloseGamepad(gamepads[player].sdl);
            printf("player %d disconnected\n", player);
        }
    }
}

int main()
{
    printf("%s\n", SDL_GetRevision());
    if(!SDL_SetHint(SDL_HINT_JOYSTICK_ALLOW_BACKGROUND_EVENTS, "1"))
    {
        sdl_error = true;
        return 1;
    }
    [[gnu::cleanup(sdl_init_cleanup)]]
    bool initialized = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMEPAD);
    if(!initialized)
    {
        sdl_error = true;
        return 1;
    }
    [[gnu::cleanup(window_cleanup)]]
    SDL_Window *window = SDL_CreateWindow("Game The Game", 1024, 512, SDL_WINDOW_HIDDEN);
    if(!window)
    {
        sdl_error = true;
        return 1;
    }
    [[gnu::cleanup(renderer_cleanup)]]
    SDL_Renderer *renderer = SDL_CreateRenderer(window, nullptr);
    if(!renderer)
    {
        sdl_error = true;
        return 1;
    }
    if(!SDL_SetRenderVSync(renderer, 1))
    {
        sdl_error = true;
        return 1;
    }
    if(!SDL_ShowWindow(window))
    {
        sdl_error = true;
        return 1;
    }
    Uint64 past_time = SDL_GetTicks(), delta = 16, current_time;
    float fps = 60;
    int fps_counter = 0;
    bool running = true;
    while (running)
    {
        SDL_SetRenderDrawColorFloat(renderer, 0, 0, 0, 1);
        SDL_RenderClear(renderer);
        if(fps_counter % 16 == 0)
        {
            fps = 1'000.0 / delta;
        }
        fps_counter = ++fps_counter % 16;
        SDL_SetRenderDrawColorFloat(renderer, 1, 1, 1, 1);
        SDL_RenderDebugTextFormat(renderer, 0, 0, "fps %.3f", fps);
        SDL_RenderPresent(renderer);
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_EVENT_QUIT:
                    running = false;
                    break;
                case SDL_EVENT_GAMEPAD_ADDED:
                    add_gamepad(event.gdevice.which);  
                    break;
                case SDL_EVENT_GAMEPAD_REMOVED:
                    remove_gamepad(event.gdevice.which);
                    break;
                case SDL_EVENT_GAMEPAD_AXIS_MOTION:
                    printf("axis %d\n", (event.gaxis.axis));
                    break;
                case SDL_EVENT_GAMEPAD_BUTTON_DOWN:
                    printf("button %d\n", event.gbutton.button);
                    break;
            }
        }
        current_time = SDL_GetTicks();
        delta = current_time - past_time;
        past_time = current_time;
    }
}