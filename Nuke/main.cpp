#include<iostream>
#include<SDL.h>

int main(int argc, char** argv) {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cout << "Couldn't initialize SDL. SDL Error: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}
	const auto SCREEN_WIDTH = 640;
	const auto SCREEN_HEIGHT = 480;
	std::string path = "aish.jpg";
	SDL_Surface* surface = SDL_LoadBMP("LAND2.BMP");
	if (!surface) {
		std::cout << "Couldn't load the image" << std::endl;
		return EXIT_FAILURE;
	}
	SDL_Window* win = SDL_CreateWindow("ashwin window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
	SDL_Renderer* ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, surface);
	SDL_RenderClear(ren);
	SDL_RenderCopy(ren, tex, 0, 0);
	SDL_RenderPresent(ren);
	SDL_Delay(5000);
	return EXIT_SUCCESS;

}