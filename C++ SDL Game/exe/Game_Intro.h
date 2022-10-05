#pragma once

#include "SDL.h"
#include "SDL_mixer.h"

class Intro
{
public:
	Intro();
	~Intro();
	void HandleEvents();
	void Update();
	void Render();
	Mix_Music* g_intro_mus;
	int MusicActivate;
private:

	SDL_Texture* texture_;
	SDL_Rect source_rectangle_;
	SDL_Rect destination_rectangle_;
};
