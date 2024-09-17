#include "globals.h"
#include <SDL2/SDL.h>

SDL_Texture *loadTexture(SDL_Renderer *renderer, const char *file) {
	SDL_Surface *surface = SDL_LoadBMP(file);
	if (!surface) {
		printf("Error loading BMP file %s: %s\n", file, SDL_GetError());
		return NULL;
	}
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	if (!texture) {
		printf("Error creating texture from surface: %s\n", SDL_GetError());
	}
	return texture;
}
