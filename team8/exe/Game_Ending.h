#pragma once

#include "SDL.h"
#include "SDL_mixer.h"
#include <string>

using namespace std;

class Ending
{
public:
	Ending();
	~Ending();
	void HandleEvents();
	void Update();
	void Render();
	float ratioW;
	float ratioH;
	string scoretext;
	Mix_Music* g_end_mus;
	int MusicActivate;
	SDL_Rect g_score_kr_rect;
	SDL_Texture* g_score_kr;
	SDL_Rect page_button;
private:
	SDL_Texture* texture_; // the SDL_Texture 
	SDL_Rect source_rectangle_; // the rectangle for source image
	SDL_Rect destination_rectangle_; // for destination
};
