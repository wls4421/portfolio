#include "Game_Ending.h"
#include "Game_Class.h"

Ending::Ending()
{
	// For Texture

	SDL_Surface* temp_surface = IMG_Load("../Resources/endingimg.jpg");
	texture_ = SDL_CreateTextureFromSurface(g_renderer, temp_surface);
	SDL_FreeSurface(temp_surface);

	g_end_mus = Mix_LoadMUS("../Resources/endingbgm.mp3");
	if (g_end_mus != 0) {
		std::cout << "Mix_LoadMUS(\"endmusic.mp3 activated\"): " << Mix_GetError() << std::endl;
	}
	MusicActivate = 0;

	SDL_QueryTexture(texture_, NULL, NULL, &source_rectangle_.w, &source_rectangle_.h);
	destination_rectangle_.x = source_rectangle_.x = 0;
	destination_rectangle_.y = source_rectangle_.y = 0;
	destination_rectangle_.w = DM.w;
	destination_rectangle_.h = DM.h;

	ratioW = DM.w / 1920.;
	ratioW = ceil(ratioW * 100) / 100;
	ratioH = DM.h / 1080.;
	ratioH = ceil(ratioH * 100) / 100;

	int pageX = 1600 * ratioW;
	int pageY = 30 * ratioH;
	int pageW = ratioW * 300;
	int pageH = ratioH * 70;

	page_button = { pageX, pageY, pageW, pageH };
}

Ending::~Ending()
{
	SDL_DestroyTexture(texture_);
	SDL_DestroyTexture(g_score_kr);
	Mix_FreeMusic(g_end_mus);
}

void Ending::Update()
{
	if (MusicActivate == 0) {
		Mix_FadeInMusic(g_end_mus, -1, 2000);
		MusicActivate = 1;
	}

	int fontsize = 150 * ratioW;

	TTF_Font* font = TTF_OpenFont("../Resources/American Captain.ttf", fontsize);
	SDL_Color white = { 255, 255, 255, 255 };

	scoretext = to_string(score);

	SDL_Surface* tmp_surface = TTF_RenderText_Solid(font, scoretext.c_str(), white);

	g_score_kr_rect.x = 0;
	g_score_kr_rect.y = 0;
	g_score_kr_rect.w = tmp_surface->w;
	g_score_kr_rect.h = tmp_surface->h;

	g_score_kr = SDL_CreateTextureFromSurface(g_renderer, tmp_surface);
	SDL_FreeSurface(tmp_surface);


	
}


void Ending::Render()
{
	SDL_SetRenderDrawColor(g_renderer, 255, 255, 255, 255);
	SDL_RenderClear(g_renderer);

	SDL_RenderCopy(g_renderer, texture_, &source_rectangle_, &destination_rectangle_);

	{
		SDL_Rect tmp_r;
		tmp_r.x = 250 * ratioW;
		tmp_r.y = 840 * ratioH;
		tmp_r.w = g_score_kr_rect.w;
		tmp_r.h = g_score_kr_rect.h;

		SDL_RenderCopy(g_renderer, g_score_kr, &g_score_kr_rect, &tmp_r);
	}

	SDL_RenderPresent(g_renderer);
}



void Ending::HandleEvents()
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
					g_current_game_phase = PHASE_INTRO;
					Mix_FadeOutMusic(2000);
					MusicActivate = 0;
				}

			}

		case SDL_KEYDOWN:

			if (event.key.keysym.sym == SDLK_SPACE)
			{
				g_current_game_phase = PHASE_INTRO;
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