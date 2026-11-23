/* Native 2D rendering + optional Bink playback smoke test.
 * Builds/runs without fastfood2.exe, Wine, DirectDraw, or Bink DLLs. */
#include "pc2_vk.h"
#include "pc2_movie.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

static int try_movie(pc2_vk *renderer,const char *path) {
    FILE *f=fopen(path,"rb");
    if (!f) {perror(path);return 0;}
    fseek(f,0,SEEK_END);long length=ftell(f);rewind(f);
    if (length<32||length>256*1024*1024) {fclose(f);return 0;}
    uint8_t *bytes=malloc((size_t)length);
    if (!bytes) {fclose(f);return 0;}
    int ok=fread(bytes,1,(size_t)length,f)==(size_t)length;
    fclose(f);
    if (!ok) {free(bytes);return 0;}
    pc2_movie *movie=pc2_movie_open_memory(bytes,(size_t)length);
    if (!movie) {free(bytes);return 0;}
    pc2_movie_reset_clock(movie);
    int running=1,frames=0;
    while (running) {
        SDL_Event ev;
        while (SDL_PollEvent(&ev)) {
            if (ev.type==SDL_QUIT || (ev.type==SDL_KEYDOWN && ev.key.keysym.sym==SDLK_ESCAPE))
                running=0;
            if (ev.type==SDL_WINDOWEVENT && ev.window.event==SDL_WINDOWEVENT_SIZE_CHANGED)
                pc2_vk_resize(renderer);
        }
        if (!running) break;
        const uint8_t *rgba;uint32_t w,h;double pts;
        int result=pc2_movie_next(movie,&rgba,&w,&h,&pts);
        if (result<=0) {if(result<0)fprintf(stderr,"movie decode: %s\n",pc2_movie_error(movie));break;}
        while (pc2_movie_clock(movie)<pts && running) {
            SDL_Delay(1);
            SDL_Event ev;
            while (SDL_PollEvent(&ev)) {
                if (ev.type==SDL_QUIT || (ev.type==SDL_KEYDOWN && ev.key.keysym.sym==SDLK_ESCAPE))running=0;
            }
        }
        if (running && !pc2_movie_draw(movie,renderer,rgba,w,h)) {
            fprintf(stderr,"movie Vulkan draw: %s\n",pc2_vk_error(renderer));break;
        }
        frames++;
    }
    fprintf(stderr,"[smoke] movie frames displayed: %d\n",frames);
    pc2_movie_release_gpu(movie,renderer);
    pc2_movie_close(movie);
    free(bytes);
    return frames>0;
}
int main(int argc,char **argv) {
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_EVENTS)<0) {
        fprintf(stderr,"SDL: %s\n",SDL_GetError());return 1;
    }
    SDL_Window *window=SDL_CreateWindow("OpenPizza2 Native Vulkan",
        SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1200,900,
        SDL_WINDOW_VULKAN|SDL_WINDOW_RESIZABLE|SDL_WINDOW_ALLOW_HIGHDPI);
    if (!window) {fprintf(stderr,"window: %s\n",SDL_GetError());SDL_Quit();return 2;}
    pc2_vk *r=pc2_vk_create(window,"shaders");
    if (!r) {SDL_DestroyWindow(window);SDL_Quit();return 3;}
    if (argc>1) {
        int ok=try_movie(r,argv[1]);
        pc2_vk_destroy(r);SDL_DestroyWindow(window);SDL_Quit();return ok?0:4;
    }
    uint8_t pixels[64*64*4];
    for (int y=0;y<64;y++)for(int x=0;x<64;x++) {
        int i=(y*64+x)*4;
        pixels[i+0]=255;pixels[i+1]=(uint8_t)(x*4);pixels[i+2]=0;
        pixels[i+3]=(uint8_t)((x+y)%20<10?255:180);
    }
    pc2_vk_texture *sprite=pc2_vk_texture_create(r,64,64,pixels,64*4);
    if (!sprite) {fprintf(stderr,"sprite upload failed\n");pc2_vk_destroy(r);return 5;}
    int running=1;
    while (running) {
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type==SDL_QUIT || (e.type==SDL_KEYDOWN&&e.key.keysym.sym==SDLK_ESCAPE))running=0;
            if (e.type==SDL_WINDOWEVENT&&e.window.event==SDL_WINDOWEVENT_SIZE_CHANGED)
                pc2_vk_resize(r);
        }
        if (!pc2_vk_begin(r,0.02f,0.04f,0.08f,1))break;
        pc2_vk_draw(r,sprite,100,100,256,256,0,0,1,1,0,0,800,600);
        pc2_vk_draw(r,sprite,250,150,256,256,0,0,1,1,200,160,300,260);
        if (!pc2_vk_end(r))break;
        SDL_Delay(16);
    }
    pc2_vk_texture_destroy(r,sprite);
    pc2_vk_destroy(r);SDL_DestroyWindow(window);SDL_Quit();return 0;
}
