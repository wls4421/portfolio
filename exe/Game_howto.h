#pragma once

#include "SDL.h"
#include "SDL_mixer.h"

class Howto
{
public:
	Howto();
	~Howto();
	void HandleEvents();
	void Update();
	void Render();
	Mix_Music* g_intro_mus;
	int MusicActivate;
	int page;
	float ratioW;
	float ratioH;
private:

	SDL_Texture* texture_1;
	SDL_Texture* texture_2;
	SDL_Rect source_rectangle_;
	SDL_Rect destination_rectangle_;
	SDL_Rect page_button;
};
