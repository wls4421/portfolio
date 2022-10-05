#pragma once

#include "SDL.h"
#include <string>
#include "SDL_mixer.h"

using namespace std;

class Stage
{

public:
	Stage();
	~Stage();

	void HandleEvents();
	void Update();
	void Render();

	Mix_Chunk* g_get_item_sound;
	Mix_Music* g_stage_mus;

	struct Location {
		float x;
		float y;
	};
	
	Location greed[82];

	int MusicActivate;
	int sliceNum;
	int charCount;
	int MAX;
	float screen_w;
	float screen_h;
	int g_input;
	int g_time;
	int g_delay;
	int g_key_lock;
	int mp;
	int char_current;
	int char_sprite_num;
	int image_mode = 0;
	int time_mode = 0;
	int stealth_activate;
	int jump_activate;
	int stealthing;
	float slicedW;
	float slicedH;
	float spacingW;
	float spacingH;
	string text;
	string temp;
	string temp2;
	string mptext;
	string scoretext;
	string scoreshow;
	int movement;
	SDL_Rect char_source_rect[4];
	SDL_Rect char_destination_rect;
	SDL_Rect guard_source_rect[4];
	SDL_Rect guard_destination_rect;
	SDL_Rect background_source_rect;
	SDL_Rect background_destination_rect;
	SDL_Rect jump_source_rect;
	SDL_Rect jump_destination_rect;
	SDL_Rect stealth_source_rect;
	SDL_Rect stealth_destination_rect;
	SDL_Rect tile_source_rect;
	SDL_Rect tile_destination_rect;
	SDL_Rect warning_source_rect;
	SDL_Rect warning_destination_rect;
	SDL_Rect jump_location_source_rect;
	SDL_Rect jump_item_destination;
	SDL_Rect stealth_item_destination;
	SDL_Texture* char_texture;
	SDL_Texture* guard_texture;
	SDL_Texture* background_texture;
	SDL_Texture* warning_texture;
	SDL_Texture* jump_texture;
	SDL_Texture* jump_location_texture;
	SDL_Texture* stealth_texture;
	SDL_Texture* tile1_texture;
	SDL_Texture* tile2_texture;
	SDL_Texture* tile3_texture;
	SDL_Texture* tile4_texture;
	SDL_Rect g_mp_kr_rect;
	SDL_Texture* g_mp_kr;
	SDL_Rect g_score_kr_rect;
	SDL_Texture* g_score_kr;
	const Uint8* state = SDL_GetKeyboardState(NULL);
	int g_elapsed_time_ms;
	float ratioW;
	float ratioH;

	

	//Font
	SDL_Texture* g_title_kr;
	SDL_Rect g_title_kr_rect;

};
