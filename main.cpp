#include <iostream>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

using namespace std;

SDL_Renderer *g_sdlRenderer{
        nullptr
};
const char *g_applicationName{
        "sdl_test"
};

const int g_screenWidth{
        960
};
const int g_screenHeight{
        640
};

SDL_Window *g_sdlWindow{
        nullptr
};
bool Startup()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        return false;
    }

    SDL_SetHint(SDL_HINT_RENDER_VSYNC, "1");
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

    if ((g_sdlWindow = SDL_CreateWindow(g_applicationName,
                                        SDL_WINDOWPOS_UNDEFINED,
                                        SDL_WINDOWPOS_UNDEFINED,
                                        g_screenWidth,
                                        g_screenHeight,
                                        SDL_WINDOW_SHOWN)) == nullptr)
    {
        return false;
    }

    if ((g_sdlRenderer = SDL_CreateRenderer(g_sdlWindow,
                                            -1,
                                            SDL_RENDERER_ACCELERATED)) == nullptr)
    {
        return false;
    }

    int flags{
            IMG_INIT_PNG
    };

    if (!(IMG_Init(flags) & flags))
    {
        return false;
    }

    if (TTF_Init() == -1)
    {
        return false;
    }

    return true;
}


void Shutdown()
{
    IMG_Quit();
    TTF_Quit();

    SDL_DestroyRenderer(g_sdlRenderer);
    g_sdlRenderer = nullptr;

    SDL_DestroyWindow(g_sdlWindow);
    g_sdlWindow = nullptr;

    SDL_Quit();
}

int main()
{
    if (!Startup())
    {
        return EXIT_FAILURE;
    }

    SDL_Event event;

    Uint32 time1{
            SDL_GetTicks()
    };
    Uint32 time2{
            0
    };

    bool quit{
            false
    };

    SDL_Surface* surf = IMG_Load("assets/image/grass.jpg");

    int width = surf->w;
    int height = surf->h;
    int clipPerRow = 16;
    int clipPerColumn = 16;

    SDL_Texture* grass_texture = SDL_CreateTextureFromSurface(g_sdlRenderer,surf);
    SDL_FreeSurface(surf);
//    SDL_Texture* clip[clipPerRow][clipPerColumn];


    while (!quit)
    {
        while (SDL_PollEvent(&event) != 0)
        {
            switch (event.type)
            {
                case SDL_QUIT:
                {
                    quit = true;
                }
                    break;

                case SDL_KEYDOWN:
                {
                }
                    break;

                case SDL_KEYUP:
                {
                }
                    break;

                case SDL_MOUSEBUTTONDOWN:
                {
                }
                    break;

                case SDL_MOUSEBUTTONUP:
                {
                }
                    break;
                case SDL_MOUSEMOTION:
                {
                }
                    break;
                default:
                {
                }
                    break;
            } // switch
        }


        if (SDL_SetRenderDrawBlendMode(g_sdlRenderer,
                                       SDL_BLENDMODE_BLEND) < 0)
        {
            cerr << "blend error" << endl;
        }

        if (SDL_RenderCopy(g_sdlRenderer,
                           grass_texture,
                           nullptr,
                           nullptr))
        {
            cerr << "render copy error" << endl;
        }

        time2 = SDL_GetTicks();

        SDL_RenderPresent(g_sdlRenderer);

        time1 = time2;
    }

    Shutdown();

    return EXIT_SUCCESS;
}