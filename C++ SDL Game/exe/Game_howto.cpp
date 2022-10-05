#include "Game_howto.h"
#include "Game_Class.h"

using namespace std;

Howto::Howto()
{
	// For Texture

	SDL_Surface* temp_surface = IMG_Load("../Resources/howto1.png");
	texture_1 = SDL_CreateTextureFromSurface(g_renderer, temp_surface);
	SDL_FreeSurface(temp_surface);
	SDL_Surface* temp_surface2 = IMG_Load("../Resources/howto2.png");
	texture_2 = SDL_CreateTextureFromSurface(g_renderer, temp_surface2);
	SDL_FreeSurface(temp_surface2);
	SDL_QueryTexture(texture_1, NULL, NULL, &source_rectangle_.w, &source_rectangle_.h);
	destination_rectangle_.x = source_rectangle_.x = 0;
	destination_rectangle_.y = source_rectangle_.y = 0;
	destination_rectangle_.w = DM.w;
	destination_rectangle_.h = DM.h;
	ratioW = DM.w / 1920.;
	ratioW = ceil(ratioW * 100) / 100;
	ratioH = DM.h / 1080.;
	ratioH = ceil(ratioH * 100) / 100;
	int pageX = 1640 * ratioW;
	int pageY = 940 * ratioH;
	int pageW = ratioW * 220;
	int pageH = ratioH * 80;
	page = 1;
	page_button = {pageX, pageY, pageW, pageH};
}

Howto::~Howto()
{
	SDL_DestroyTexture(texture_1);
	SDL_DestroyTexture(texture_2);
}

void Howto::Update()
{
	
}


void Howto::Render()
{
	SDL_SetRenderDrawColor(g_renderer, 255, 255, 255, 255);
	SDL_RenderClear(g_renderer);
	if (page == 1)
	{
		SDL_RenderCopy(g_renderer, texture_1, &source_rectangle_, &destination_rectangle_);
	}
	else if (page == 2)
	{
		SDL_RenderCopy(g_renderer, texture_2, &source_rectangle_, &destination_rectangle_);
	}
	
	SDL_RenderPresent(g_renderer);
}



void Howto::HandleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			g_flag_running = false;
			break;

		case SDL_MOUSEBUTTONDOWN:
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				int mouse_x = event.button.x;
				int mouse_y = event.button.y;

				if (mouse_x > page_button.x &&
					mouse_y > page_button.y &&
					mouse_x < page_button.x + page_button.w &&
					mouse_y < page_button.y + page_button.h
					)
				{
					cout << "button DOWN" << endl;
					if (page == 1)
					{
						page = 2;
					}
					else if (page == 2)
					{
						page = 1;
					}
				}

			}
		case SDL_KEYDOWN:

			if (event.key.keysym.sym == SDLK_SPACE)
			{
				g_current_game_phase = PHASE_STAGE;
			}

			else if (event.key.keysym.sym == SDLK_DELETE)
			{
				g_flag_running = false;
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
			break;

		default:
			break;
		}
	}
}