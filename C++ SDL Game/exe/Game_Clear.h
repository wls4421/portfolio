#pragma once

#include "SDL.h"
#include "SDL_mixer.h"

class GameClear
{
public:
	GameClear();
	~GameClear();
	void HandleEvents();
	void Update();
	void Render();
	Mix_Music* g_gameclear_mus;
	int MusicActivate;
private:
	SDL_Texture* texture_;
	SDL_Rect source_rectangle_;
	SDL_Rect destination_rectangle_;
};
