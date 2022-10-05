#include "Game_Clear.h"
#include "Game_Class.h"
#include "Game_Func.h"

GameClear::GameClear()
{
	// For Texture

	SDL_Surface* temp_surface = IMG_Load("../Resources/GameClear.png");
	texture_ = SDL_CreateTextureFromSurface(g_renderer, temp_surface);
	SDL_FreeSurface(temp_surface);
	g_gameclear_mus = Mix_LoadMUS("../Resources/stage_clear.mp3");
	if (g_gameclear_mus != 0) {
		std::cout << "Mix_LoadMUS(\"stage_clear.mp3 activated\"): " << std::endl;
	}
	MusicActivate = 0;
	SDL_QueryTexture(texture_, NULL, NULL, &source_rectangle_.w, &source_rectangle_.h);
	destination_rectangle_.x = source_rectangle_.x = 0;
	destination_rectangle_.y = source_rectangle_.y = 0;
	destination_rectangle_.w = DM.w;
	destination_rectangle_.h = DM.h;

}

GameClear ::~GameClear()
{
	SDL_DestroyTexture(texture_);
	Mix_FreeMusic(g_gameclear_mus);
}

void GameClear::Update()
{
	if (MusicActivate == 0)
	{
		Mix_FadeInMusic(g_gameclear_mus, 1, 2000);
		MusicActivate = 1;
	}
}


void GameClear::Render()
{
	SDL_RenderCopy(g_renderer, texture_, &source_rectangle_, &destination_rectangle_);
	SDL_RenderPresent(g_renderer);
}



void GameClear::HandleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			g_flag_running = false;
			break;

		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_SPACE)
			{
				g_current_game_phase = g_stage_phase+1;
				Mix_FadeOutMusic(2000);
				MusicActivate = 0;
			}

			else if (event.key.keysym.sym == SDLK_DELETE)
			{
				g_flag_running = false;
			}

			break;

		default:
			break;
		}
	}
}