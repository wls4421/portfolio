#include "Game_Intro.h"
#include "Game_Class.h"

Intro::Intro()
{
	// For Texture

	SDL_Surface* temp_surface = IMG_Load("../Resources/introimg.jpg");
	texture_ = SDL_CreateTextureFromSurface(g_renderer, temp_surface);
	SDL_FreeSurface(temp_surface);
	g_intro_mus = Mix_LoadMUS("../Resources/intro.mp3");
	if (g_intro_mus != 0) {
		std::cout << "Mix_LoadMUS(\"intro.mp3 activated\"): " << std::endl;
	}
	MusicActivate = 0;
	SDL_QueryTexture(texture_, NULL, NULL, &source_rectangle_.w, &source_rectangle_.h);
	destination_rectangle_.x = source_rectangle_.x = 0;
	destination_rectangle_.y = source_rectangle_.y = 0;
	destination_rectangle_.w = DM.w;
	destination_rectangle_.h = DM.h;

}

Intro::~Intro()
{
	SDL_DestroyTexture(texture_);
	Mix_FreeMusic(g_intro_mus);
}

void Intro::Update()
{
	if (MusicActivate == 0)
	{
		Mix_FadeInMusic(g_intro_mus, -1, 2000);
		MusicActivate = 1;
	}
}


void Intro::Render()
{
	SDL_SetRenderDrawColor(g_renderer, 255, 255, 255, 255);
	SDL_RenderClear(g_renderer);

	SDL_RenderCopy(g_renderer, texture_, &source_rectangle_, &destination_rectangle_);

	SDL_RenderPresent(g_renderer);
}



void Intro::HandleEvents()
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
				g_current_game_phase = PHASE_HOWTO;
				Mix_FadeOutMusic(2000);
				MusicActivate = 0;
			}
			else if (event.key.keysym.sym == SDLK_1)
			{
				g_current_game_phase = PHASE_STAGE;
				g_stage_phase = PHASE_STAGE;
			}
			else if (event.key.keysym.sym == SDLK_2)
			{
				g_current_game_phase = PHASE_STAGE2;
				g_stage_phase = PHASE_STAGE2;
			}
			else if (event.key.keysym.sym == SDLK_3)
			{
				g_current_game_phase = PHASE_STAGE3;
				g_stage_phase = PHASE_STAGE3;
			}
			else if (event.key.keysym.sym == SDLK_4)
			{
				g_current_game_phase = PHASE_STAGE4;
				g_stage_phase = PHASE_STAGE4;
			}
			else if (event.key.keysym.sym == SDLK_5)
			{
				g_current_game_phase = PHASE_STAGE5;
				g_stage_phase = PHASE_STAGE5;
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