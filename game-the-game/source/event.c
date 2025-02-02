#include "event.h"
#include "gamepad.h"
#include "state.h"
#include <stdio.h>
#include <SDL3/SDL.h>

bool events()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_EVENT_QUIT:
                state.running = false;
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
    return true;
}