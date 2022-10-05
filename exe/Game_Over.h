#pragma once

#include "SDL.h"
#include "SDL_mixer.h"

class GameOver
{
public:
	GameOver();
	~GameOver();
	void HandleEvents();
	void Update();
	void Render();
	Mix_Music* g_gameover_mus;
	int MusicActivate;
private:
	SDL_Texture* texture_;
	SDL_Rect source_rectangle_;
	SDL_Rect destination_rectangle_;
};
