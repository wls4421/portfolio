#include "Game_Func4.h"
#include "Game_Class.h"


Stage4::Stage4() {

	sliceNum = 9;
	charCount = 73;
	MAX = 3;
	ratioW = DM.w / 1920.;
	ratioW = ceil(ratioW * 100) / 100;
	ratioH = DM.h / 1080.;
	ratioH = ceil(ratioH * 100) / 100;
	mp = 40;
	mptext = to_string(mp);
	temp = "MP : ";
	temp += mptext;
	text = temp;
	g_key_lock = 0;
	g_delay = 0;
	g_input = 0;
	stealth_activate = 1;
	jump_activate = 1;
	stealthing = 0;


	g_get_item_sound = Mix_LoadWAV("../Resources/get_item.mp3");

	g_stage_mus = Mix_LoadMUS("../Resources/stage_bgm.mp3");
	if (g_stage_mus != 0) {
		std::cout << "Mix_LoadMUS(\"intro.mp3 activated\"): " << std::endl;
	}
	MusicActivate = 0;


	screen_w = DM.w * 0.984 - (100 * ratioW);
	screen_h = DM.h * 0.984 - (100 * ratioH);
	//slicedW = screen_w / sliceNum;
	slicedW = 96 * ratioW;
	//slicedH = screen_h / sliceNum;
	slicedH = 96 * ratioH;
	spacingW = slicedW / sliceNum;
	spacingH = slicedH / sliceNum;

	cout << "spacing.w = " << spacingW << endl;
	cout << "spacing.h = " << spacingH << endl;

	cout << "DM.w = " << DM.w << endl;
	cout << "DM.h = " << DM.h << endl;

	for (int i = 1; i < 82; i++)
	{
		if (i % sliceNum == 0)
		{
			greed[i].x = ceil((500 * ratioW) + 8.5 * slicedW);
		}
		else
		{
			greed[i].x = ceil((500 * ratioW) + ((i % sliceNum) - 0.5) * slicedW);
		}
		if (i % sliceNum == 0)
		{
			//greed[i].y = ((((i - 1) / sliceNum) + 0.5) * slicedH) - (spacingH*2) + (80 * ratioH);
			greed[i].y = ceil((100 * ratioH) + (((i - 1) / sliceNum) + 0.5) * slicedH);
		}
		else {
			//greed[i].y = (((i / sliceNum) + 0.5) * slicedH) - (spacingH*2) + (80 * ratioH);
			greed[i].y = ceil((100 * ratioH) + ((i / sliceNum) + 0.5) * slicedH);

		}



	}

	g_input = 0;
	g_flag_running = true;
	g_elapsed_time_ms = 0;
	//background


	SDL_Surface* background_surface = IMG_Load("../Resources/background.jpg");
	background_texture = SDL_CreateTextureFromSurface(g_renderer, background_surface);
	SDL_FreeSurface(background_surface);

	background_source_rect.x = 0;
	background_source_rect.y = 0;
	background_source_rect.w = 1920;
	background_source_rect.h = 1080;

	background_destination_rect.x = 0;
	background_destination_rect.y = 0;
	background_destination_rect.w = DM.w;
	background_destination_rect.h = DM.h;

	SDL_Surface* tile1_surface = IMG_Load("../Resources/tile1.png");
	tile1_texture = SDL_CreateTextureFromSurface(g_renderer, tile1_surface);
	SDL_FreeSurface(tile1_surface);

	SDL_Surface* tile2_surface = IMG_Load("../Resources/tile2.png");
	tile2_texture = SDL_CreateTextureFromSurface(g_renderer, tile2_surface);
	SDL_FreeSurface(tile2_surface);

	SDL_Surface* tile3_surface = IMG_Load("../Resources/tile3.png");
	tile3_texture = SDL_CreateTextureFromSurface(g_renderer, tile3_surface);
	SDL_FreeSurface(tile3_surface);

	tile_source_rect.x = 0;
	tile_source_rect.y = 0;
	tile_source_rect.w = 96;
	tile_source_rect.h = 96;

	SDL_Surface* jump_surface = IMG_Load("../Resources/jump.png");
	jump_texture = SDL_CreateTextureFromSurface(g_renderer, jump_surface);
	SDL_FreeSurface(jump_surface);

	SDL_Surface* jump_location_surface = IMG_Load("../Resources/jump_location.png");
	jump_location_texture = SDL_CreateTextureFromSurface(g_renderer, jump_location_surface);
	SDL_FreeSurface(jump_location_surface);

	jump_location_source_rect = { 0, 0, 384, 384 };

	SDL_Surface* stealth_surface = IMG_Load("../Resources/stealth.png");
	stealth_texture = SDL_CreateTextureFromSurface(g_renderer, stealth_surface);
	SDL_FreeSurface(stealth_surface);


	SDL_Surface* char_surface = IMG_Load("../Resources/animatetest.png");
	char_texture = SDL_CreateTextureFromSurface(g_renderer, char_surface);
	SDL_FreeSurface(char_surface);

	char_source_rect[0] = { 1, 72 , 14 , 24 };
	char_source_rect[1] = { 15, 72 , 17 , 24 };
	char_source_rect[2] = { 33, 72 , 14 , 24 };
	char_source_rect[3] = { 48, 72 , 17 , 24 };

	char_sprite_num = 4;
	char_current = 0;
	time_mode = 0;

	char_destination_rect.x = greed[73].x;
	char_destination_rect.y = greed[73].y;
	char_destination_rect.w = char_source_rect[0].w * 3 * ratioW;
	char_destination_rect.h = char_source_rect[0].h * 3 * ratioH;

	SDL_Surface* guard_surface = IMG_Load("../Resources/guard.png");
	guard_texture[0] = SDL_CreateTextureFromSurface(g_renderer, guard_surface);
	SDL_FreeSurface(guard_surface);

	SDL_Surface* guard2_surface = IMG_Load("../Resources/guard.png");
	guard_texture[1] = SDL_CreateTextureFromSurface(g_renderer, guard2_surface);
	SDL_FreeSurface(guard2_surface);

	SDL_Surface* guard3_surface = IMG_Load("../Resources/guard.png");
	guard_texture[2] = SDL_CreateTextureFromSurface(g_renderer, guard3_surface);
	SDL_FreeSurface(guard3_surface);

	SDL_Surface* guard4_surface = IMG_Load("../Resources/guard.png");
	guard_texture[3] = SDL_CreateTextureFromSurface(g_renderer, guard4_surface);
	SDL_FreeSurface(guard4_surface);

	SDL_Surface* guard5_surface = IMG_Load("../Resources/guard.png");
	guard_texture[4] = SDL_CreateTextureFromSurface(g_renderer, guard5_surface);
	SDL_FreeSurface(guard5_surface);

	SDL_Surface* guard6_surface = IMG_Load("../Resources/guard.png");
	guard_texture[5] = SDL_CreateTextureFromSurface(g_renderer, guard6_surface);
	SDL_FreeSurface(guard6_surface);

	SDL_Surface* guard7_surface = IMG_Load("../Resources/guard.png");
	guard_texture[6] = SDL_CreateTextureFromSurface(g_renderer, guard6_surface);
	SDL_FreeSurface(guard6_surface);

	guard_source_rect[0] = { 0, 72 , 15 , 23 };
	guard_source_rect[1] = { 16, 72 , 15 , 23 };
	guard_source_rect[2] = { 32, 72 , 15 , 23 };
	guard_source_rect[3] = { 48, 72 , 15 , 23 };

	guard_destination_rect[0].x = greed[55].x;
	guard_destination_rect[0].y = greed[55].y;
	guard_destination_rect[0].w = guard_source_rect[0].w * 3 * ratioW;
	guard_destination_rect[0].h = guard_source_rect[0].h * 3 * ratioH;

	guard_destination_rect[1].x = greed[22].x;
	guard_destination_rect[1].y = greed[22].y;
	guard_destination_rect[1].w = guard_source_rect[0].w * 3 * ratioW;
	guard_destination_rect[1].h = guard_source_rect[0].h * 3 * ratioH;

	guard_destination_rect[2].x = greed[39].x;
	guard_destination_rect[2].y = greed[39].y;
	guard_destination_rect[2].w = guard_source_rect[0].w * 3 * ratioW;
	guard_destination_rect[2].h = guard_source_rect[0].h * 3 * ratioH;

	guard_destination_rect[3].x = greed[41].x;
	guard_destination_rect[3].y = greed[41].y;
	guard_destination_rect[3].w = guard_source_rect[0].w * 3 * ratioW;
	guard_destination_rect[3].h = guard_source_rect[0].h * 3 * ratioH;

	guard_destination_rect[4].x = greed[62].x;
	guard_destination_rect[4].y = greed[62].y;
	guard_destination_rect[4].w = guard_source_rect[0].w * 3 * ratioW;
	guard_destination_rect[4].h = guard_source_rect[0].h * 3 * ratioH;

	guard_destination_rect[5].x = greed[68].x;
	guard_destination_rect[5].y = greed[68].y;
	guard_destination_rect[5].w = guard_source_rect[0].w * 3 * ratioW;
	guard_destination_rect[5].h = guard_source_rect[0].h * 3 * ratioH;

	guard_destination_rect[6].x = greed[66].x;
	guard_destination_rect[6].y = greed[66].y;
	guard_destination_rect[6].w = guard_source_rect[0].w * 3 * ratioW;
	guard_destination_rect[6].h = guard_source_rect[0].h * 3 * ratioH;

	SDL_Surface* warning_surface = IMG_Load("../Resources/warning.png");
	warning_texture = SDL_CreateTextureFromSurface(g_renderer, warning_surface);
	SDL_FreeSurface(warning_surface);


	warning_source_rect = { 0 , 0 , 192 , 96 };

	for (int i = 0; i < 7; i++)
	{
		warning_destination_rect[i].x = guard_destination_rect[i].x - 96;
		warning_destination_rect[i].y = guard_destination_rect[i].y + 48;
		warning_destination_rect[i].w = 192;
		warning_destination_rect[i].h = 96;
	}
	
	warning_destination_rect[7].x = guard_destination_rect[6].x - 96;
	warning_destination_rect[7].y = guard_destination_rect[6].y + 48;
	warning_destination_rect[7].w = 192;
	warning_destination_rect[7].h = 96;

	warning_destination_rect[8].x = guard_destination_rect[6].x - 96;
	warning_destination_rect[8].y = guard_destination_rect[6].y + 48;
	warning_destination_rect[8].w = 192;
	warning_destination_rect[8].h = 96;

	warning_destination_rect[9].x = guard_destination_rect[6].x - 96;
	warning_destination_rect[9].y = guard_destination_rect[6].y + 48;
	warning_destination_rect[9].w = 192;
	warning_destination_rect[9].h = 96;

	warningArea[0].x = greed[64].x;
	warningArea[0].y = greed[64].y;
	warningArea[1].x = greed[31].x;
	warningArea[1].y = greed[31].y;
	warningArea[2].x = greed[40].x;
	warningArea[2].y = greed[40].y;
	warningArea[3].x = greed[50].x;
	warningArea[3].y = greed[50].y;
	warningArea[4].x = greed[53].x;
	warningArea[4].y = greed[53].y;
	warningArea[5].x = greed[77].x;
	warningArea[5].y = greed[77].y;
	warningArea[6].x = greed[67].x;
	warningArea[6].y = greed[67].y;
	warningArea[7].x = greed[75].x;
	warningArea[7].y = greed[75].y;
	warningArea[8].x = greed[65].x;
	warningArea[8].y = greed[65].y;
	warningArea[9].x = greed[57].x;
	warningArea[9].y = greed[57].y;

	for (int i = 0; i < 7; i++)
	{
		ActivedArea[i].x = warningArea[i].x;
		ActivedArea[i].y = warningArea[i].y;
	}
	
	int jumpX = 1530 * ratioW;
	int jumpY = 820 * ratioH;
	int jumpW = 96 * ratioW;
	int jumpH = 96 * ratioH;

	int stealthX = 1720 * ratioW;
	int stealthY = 820 * ratioH;
	int stealthW = 96 * ratioW;
	int stealthH = 96 * ratioH;

	jump_item_destination = { jumpX, jumpY, jumpW, jumpH };
	stealth_item_destination = { stealthX, stealthY, stealthW, stealthH };
}

Stage4::~Stage4()
{
	Mix_FreeChunk(g_get_item_sound);
	Mix_FadeOutMusic(2000);
	Mix_FreeMusic(g_stage_mus);
	for (int i = 0; i < 7; i++)
	{
		SDL_DestroyTexture(guard_texture[i]);
	}
	SDL_DestroyTexture(char_texture);
	SDL_DestroyTexture(warning_texture);
	SDL_DestroyTexture(jump_texture);
	SDL_DestroyTexture(jump_location_texture);
	SDL_DestroyTexture(stealth_texture);
	SDL_DestroyTexture(tile1_texture);
	SDL_DestroyTexture(tile2_texture);
	SDL_DestroyTexture(tile3_texture);
	SDL_DestroyTexture(tile4_texture);
	SDL_DestroyTexture(g_mp_kr);
	SDL_DestroyTexture(g_score_kr);
}

void Stage4::Update() {

	movement = mp % 4; //Initial = 0

	if (MusicActivate == 0)
	{
		Mix_FadeInMusic(g_stage_mus, -1, 2000);
		MusicActivate = 1;
	}

	g_time = SDL_GetTicks();
	//1초에 1000정도 증가

	if (stealth_activate == 0)
	{
		SDL_Surface* char_surface = IMG_Load("../Resources/animatetest2.png");
		char_texture = SDL_CreateTextureFromSurface(g_renderer, char_surface);
		SDL_FreeSurface(char_surface);
	}
	else if (stealth_activate == 1)
	{
		SDL_Surface* char_surface = IMG_Load("../Resources/animatetest.png");
		char_texture = SDL_CreateTextureFromSurface(g_renderer, char_surface);
		SDL_FreeSurface(char_surface);
	}

	if (g_input == 1)
	{

		char_destination_rect.x -= 30;
		if (char_destination_rect.x < greed[charCount].x)
		{
			g_input = 0;
			char_destination_rect.x = greed[charCount].x;
			g_key_lock = 0;
		}
	}
	else if (g_input == 2)
	{
		char_destination_rect.x += 30;
		if (char_destination_rect.x > greed[charCount].x)
		{
			g_input = 0;
			char_destination_rect.x = greed[charCount].x;
			g_key_lock = 0;

		}
	}
	else if (g_input == 3)
	{
		char_destination_rect.y -= 30;
		if (char_destination_rect.y < greed[charCount].y)
		{
			g_input = 0;
			char_destination_rect.y = greed[charCount].y;
			g_key_lock = 0;
		}
	}
	else if (g_input == 4)
	{
		char_destination_rect.y += 30;
		if (char_destination_rect.y > greed[charCount].y)
		{
			g_input = 0;
			char_destination_rect.y = greed[charCount].y;
			g_key_lock = 0;
		}
	}

	mptext = to_string(mp);
	scoretext = to_string(score);
	temp = "MP : ";
	temp2 = "Score: ";
	temp += mptext;
	temp2 += scoretext;
	text = temp;
	scoreshow = temp2;

	int fontsize1 = 140 * ratioW;
	int fontsize2 = 80 * ratioW;

	TTF_Font* font1 = TTF_OpenFont("../Resources/American Captain.ttf", fontsize1);
	TTF_Font* font2 = TTF_OpenFont("../Resources/American Captain.ttf", fontsize2);
	SDL_Color white = { 255, 255, 255, 255 };

	SDL_Surface* tmp_surface = TTF_RenderText_Solid(font1, text.c_str(), white);
	SDL_Surface* tmp_surface2 = TTF_RenderText_Solid(font2, scoreshow.c_str(), white);

	g_mp_kr_rect.x = 0;
	g_mp_kr_rect.y = 0;
	g_mp_kr_rect.w = tmp_surface->w;
	g_mp_kr_rect.h = tmp_surface->h;

	g_score_kr_rect.x = 0;
	g_score_kr_rect.y = 0;
	g_score_kr_rect.w = tmp_surface2->w;
	g_score_kr_rect.h = tmp_surface2->h;

	g_mp_kr = SDL_CreateTextureFromSurface(g_renderer, tmp_surface);
	SDL_FreeSurface(tmp_surface);

	g_score_kr = SDL_CreateTextureFromSurface(g_renderer, tmp_surface2);
	SDL_FreeSurface(tmp_surface2);

	if (time_mode < 31)
	{
		time_mode++;
		char_current = time_mode / 8;
	}
	else
	{
		time_mode = 0;
		char_current = 0;
	}

	//Game Clear + Over

	if (char_destination_rect.x == greed[9].x && char_destination_rect.y == greed[9].y)
	{
		score += mp * 1000;
		SDL_Delay(250);
		mp = 40;
		charCount = 73;
		stealth_activate = 1;
		jump_activate = 1;
		char_destination_rect.x = greed[73].x;
		char_destination_rect.y = greed[73].y;
		MusicActivate = 0;
		g_current_game_phase = PHASE_GAMECLEAR;
		g_stage_phase = PHASE_STAGE4;
		g_flag_running = true;
	}
	else if (mp == 0 || (char_destination_rect.x == ActivedArea[0].x && char_destination_rect.y == ActivedArea[0].y && stealth_activate == 1 && stealthing == 0)
		|| (char_destination_rect.x == ActivedArea[1].x && char_destination_rect.y == ActivedArea[1].y && stealth_activate == 1 && stealthing == 0)
		|| (char_destination_rect.x == ActivedArea[2].x && char_destination_rect.y == ActivedArea[2].y && stealth_activate == 1 && stealthing == 0)
		|| (char_destination_rect.x == ActivedArea[3].x && char_destination_rect.y == ActivedArea[3].y && stealth_activate == 1 && stealthing == 0)
		|| (char_destination_rect.x == ActivedArea[4].x && char_destination_rect.y == ActivedArea[4].y && stealth_activate == 1 && stealthing == 0)
		|| (char_destination_rect.x == ActivedArea[5].x && char_destination_rect.y == ActivedArea[5].y && stealth_activate == 1 && stealthing == 0)
		|| (char_destination_rect.x == ActivedArea[6].x && char_destination_rect.y == ActivedArea[6].y && stealth_activate == 1 && stealthing == 0))
	{
		SDL_Delay(250);
		mp = 40;
		charCount = 73;
		char_destination_rect.x = greed[73].x;
		char_destination_rect.y = greed[73].y;
		stealth_activate = 1;
		jump_activate = 1;
		MusicActivate = 0;
		g_current_game_phase = PHASE_GAMEOVER;
		g_stage_phase = PHASE_STAGE4;
		g_flag_running = true;
	}
	else if ((char_destination_rect.x == ActivedArea[0].x && char_destination_rect.y == ActivedArea[0].y && stealth_activate == 0)
		|| (char_destination_rect.x == ActivedArea[1].x && char_destination_rect.y == ActivedArea[1].y && stealth_activate == 0)
		|| (char_destination_rect.x == ActivedArea[2].x && char_destination_rect.y == ActivedArea[2].y && stealth_activate == 0)
		|| (char_destination_rect.x == ActivedArea[3].x && char_destination_rect.y == ActivedArea[3].y && stealth_activate == 0)
		|| (char_destination_rect.x == ActivedArea[4].x && char_destination_rect.y == ActivedArea[4].y && stealth_activate == 0)
		|| (char_destination_rect.x == ActivedArea[5].x && char_destination_rect.y == ActivedArea[5].y && stealth_activate == 0)
		|| (char_destination_rect.x == ActivedArea[6].x && char_destination_rect.y == ActivedArea[6].y && stealth_activate == 0))
	{
		stealth_activate = 1;
		stealthing = 1;
	}


}


void Stage4::Render() {
	SDL_RenderCopy(g_renderer, background_texture, &background_source_rect, &background_destination_rect);



	for (int i = 1; i < 82; i++)
	{
		tile_destination_rect.x = greed[i].x - (25 * ratioW);
		tile_destination_rect.y = greed[i].y - (20 * ratioH);
		tile_destination_rect.w = slicedW;
		tile_destination_rect.h = slicedH;
		if ((i == 1) || (i == 2) || (i == 3) || (i == 4) || (i == 5) || (i == 6) || (i == 7) || (i == 8) || (i == 10) ||
			(i == 13) || (i == 17) || (i == 19) || (i == 24) || (i == 26) || (i == 28) || (i == 33) || (i == 35) || (i == 37) ||
			(i == 42) || (i == 44) || (i == 46) || (i == 51) || (i == 60) || (i == 69) || (i == 70) || (i == 71) || (i == 72) ||
			(i == 78) || (i == 79) || (i == 80) || (i == 81))
		{
			SDL_RenderCopy(g_renderer, tile2_texture, &tile_source_rect, &tile_destination_rect);
		}
		else if (i == 9)
		{
			SDL_RenderCopy(g_renderer, tile3_texture, &tile_source_rect, &tile_destination_rect);
		}
		else
		{

			SDL_RenderCopy(g_renderer, tile1_texture, &tile_source_rect, &tile_destination_rect);
			if ((i == 34 || i == 59))
			{
				SDL_RenderCopy(g_renderer, stealth_texture, &tile_source_rect, &tile_destination_rect);
			}
			else if ( i == 30)
			{
				SDL_RenderCopy(g_renderer, jump_texture, &tile_source_rect, &tile_destination_rect);
			}
		}
	}


	if (stealth_activate == 0)
	{
		SDL_RenderCopy(g_renderer, stealth_texture, &tile_source_rect, &stealth_item_destination);
	}

	if (jump_activate == 0)
	{
		SDL_RenderCopy(g_renderer, jump_texture, &tile_source_rect, &jump_item_destination);
	}

	SDL_RenderCopy(g_renderer, char_texture, &char_source_rect[char_current], &char_destination_rect);
	if (jump_activate == 2)
	{
		SDL_RenderCopy(g_renderer, jump_location_texture, &jump_location_source_rect, &char_destination_rect);
	}

	for (int i = 0; i < 7; i++)
	{
		if (i == 2)
		{
			guard_source_rect[0] = { 0, 96 , 15 , 23 };
			guard_source_rect[1] = { 16, 96 , 15 , 23 };
			guard_source_rect[2] = { 32, 96 , 15 , 23 };
			guard_source_rect[3] = { 48, 96 , 15 , 23 };
			warning_destination_rect[i].x = guard_destination_rect[i].x - 30;
			warning_destination_rect[i].y = guard_destination_rect[i].y;
			SDL_RenderCopyEx(g_renderer, warning_texture, &warning_source_rect, &warning_destination_rect[i], 180.0f, NULL, SDL_FLIP_NONE);
		}
		else if (i == 4)
		{
			guard_source_rect[0] = { 0, 24 , 15 , 23 };
			guard_source_rect[1] = { 16, 24 , 15 , 23 };
			guard_source_rect[2] = { 32, 24 , 15 , 23 };
			guard_source_rect[3] = { 48, 24 , 15 , 23 };
			warning_destination_rect[i].x = guard_destination_rect[i].x - 55;
			warning_destination_rect[i].y = guard_destination_rect[i].y - 60;


			SDL_RenderCopyEx(g_renderer, warning_texture, &warning_source_rect, &warning_destination_rect[i], 90.0f, NULL, SDL_FLIP_NONE);
		}
		else if (i == 6)
		{
			if (movement == 0)
			{
				guard_source_rect[0] = { 0, 96 , 15 , 23 };
				guard_source_rect[1] = { 16, 96 , 15 , 23 };
				guard_source_rect[2] = { 32, 96 , 15 , 23 };
				guard_source_rect[3] = { 48, 96 , 15 , 23 };
				warning_destination_rect[i].x = guard_destination_rect[i].x - 30;
				warning_destination_rect[i].y = guard_destination_rect[i].y;
				ActivedArea[6].x = warningArea[6].x;
				ActivedArea[6].y = warningArea[6].y;
				SDL_RenderCopyEx(g_renderer, warning_texture, &warning_source_rect, &warning_destination_rect[i], 180.0f, NULL, SDL_FLIP_NONE);
			}
			else if (movement == 3)
			{
				guard_source_rect[0] = { 0, 72 , 15 , 23 };
				guard_source_rect[1] = { 16, 72 , 15 , 23 };
				guard_source_rect[2] = { 32, 72 , 15 , 23 };
				guard_source_rect[3] = { 48, 72 , 15 , 23 };
				warning_destination_rect[i].x = guard_destination_rect[i].x - 96;
				warning_destination_rect[i].y = guard_destination_rect[i].y + 40 ;
				ActivedArea[6].x = warningArea[7].x;
				ActivedArea[6].y = warningArea[7].y;
				SDL_RenderCopyEx(g_renderer, warning_texture, &warning_source_rect, &warning_destination_rect[i], 270.0f, NULL, SDL_FLIP_NONE);
			}
			else if (movement == 2)
			{
				guard_source_rect[0] = { 0, 47 , 15 , 23 };
				guard_source_rect[1] = { 16, 47 , 15 , 23 };
				guard_source_rect[2] = { 32, 47 , 15 , 23 };
				guard_source_rect[3] = { 48, 47 , 15 , 23 };
				warning_destination_rect[i].x = guard_destination_rect[i].x - 120;
				warning_destination_rect[i].y = guard_destination_rect[i].y - 20;
				ActivedArea[6].x = warningArea[8].x;
				ActivedArea[6].y = warningArea[8].y;
				SDL_RenderCopyEx(g_renderer, warning_texture, &warning_source_rect, &warning_destination_rect[i], 0.0f, NULL, SDL_FLIP_NONE);
			}
			else if (movement == 1)
			{
				guard_source_rect[0] = { 0, 24 , 15 , 23 };
				guard_source_rect[1] = { 16, 24 , 15 , 23 };
				guard_source_rect[2] = { 32, 24 , 15 , 23 };
				guard_source_rect[3] = { 48, 24 , 15 , 23 };
				warning_destination_rect[i].x = guard_destination_rect[i].x - 88;
				warning_destination_rect[i].y = guard_destination_rect[i].y - 55;
				ActivedArea[6].x = warningArea[9].x;
				ActivedArea[6].y = warningArea[9].y;
				SDL_RenderCopyEx(g_renderer, warning_texture, &warning_source_rect, &warning_destination_rect[i], 90.0f, NULL, SDL_FLIP_NONE);
			}
		}
		else
		{
			guard_source_rect[0] = { 0, 72 , 15 , 23 };
			guard_source_rect[1] = { 16, 72 , 15 , 23 };
			guard_source_rect[2] = { 32, 72 , 15 , 23 };
			guard_source_rect[3] = { 48, 72 , 15 , 23 };
			SDL_RenderCopyEx(g_renderer, warning_texture, &warning_source_rect, &warning_destination_rect[i], 270.0f, NULL, SDL_FLIP_NONE);

		}
		SDL_RenderCopy(g_renderer, guard_texture[i], &guard_source_rect[char_current], &guard_destination_rect[i]);
		
	}
	

	

	//font
	SDL_SetRenderDrawColor(g_renderer, 255, 255, 255, 255);

	{
		SDL_Rect tmp_r;
		tmp_r.x = DM.w - 400 * ratioW;
		tmp_r.y = 260 * ratioH;
		tmp_r.w = g_mp_kr_rect.w;
		tmp_r.h = g_mp_kr_rect.h;

		SDL_RenderCopy(g_renderer, g_mp_kr, &g_mp_kr_rect, &tmp_r);
	}

	{
		SDL_Rect tmp_r2;
		tmp_r2.x = 100 * ratioW;
		tmp_r2.y = DM.h - 375 * ratioH;
		tmp_r2.w = g_score_kr_rect.w;
		tmp_r2.h = g_score_kr_rect.h;

		SDL_RenderCopy(g_renderer, g_score_kr, &g_score_kr_rect, &tmp_r2);
	}

	SDL_RenderPresent(g_renderer);

}

void Stage4::HandleEvents()
{

	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		switch (event.type) {

		case SDL_QUIT:
			g_flag_running = false;

		case SDL_MOUSEBUTTONDOWN:

			if (event.button.button == SDL_BUTTON_RIGHT)
			{
				g_current_game_phase = PHASE_ENDING;
				g_flag_running = true;
			}

			break;

		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_LEFT && g_key_lock == 0) {
				if (charCount % sliceNum == 1)
				{
					cout << "Blocked by Wall";
				}
				else if (jump_activate == 0 || jump_activate == 1)
				{
					charCount -= 1;
					if ((charCount == 1) || (charCount == 2) || (charCount == 3) || (charCount == 4) || (charCount == 5) || (charCount == 6) || (charCount == 7) || (charCount == 8) || (charCount == 10) ||
						(charCount == 13) || (charCount == 17) || (charCount == 19) || (charCount == 24) || (charCount == 26) || (charCount == 28) || (charCount == 33) || (charCount == 35) || (charCount == 37) ||
						(charCount == 42) || (charCount == 44) || (charCount == 46) || (charCount == 51) || (charCount == 60) || (charCount == 69) || (charCount == 70) || (charCount == 71) || (charCount == 72) ||
						(charCount == 78) || (charCount == 79) || (charCount == 80) || (charCount == 81) || (charCount == 22) || (charCount == 39) || (charCount == 41) || (charCount == 55) || (charCount == 62) || (charCount == 66) || (charCount == 68))

					{
						cout << "Blocked by Wall";
						charCount += 1;
					}
					else {
						g_input = 1;
						cout << "mp" << mp << endl;
						mp -= 1;
						g_key_lock = 1;
						char_source_rect[0] = { 1, 47 , 14 , 24 };
						char_source_rect[1] = { 15, 47 , 17 , 24 };
						char_source_rect[2] = { 33, 47 , 14 , 24 };
						char_source_rect[3] = { 48, 47 , 17 , 24 };
						if (stealthing == 1)
						{
							stealthing = 0;
						}
					}
				}
				else if (jump_activate == 2)
				{
					charCount -= 2;
					if ((charCount == 1) || (charCount == 2) || (charCount == 3) || (charCount == 4) || (charCount == 5) || (charCount == 6) || (charCount == 7) || (charCount == 8) || (charCount == 10) ||
						(charCount == 13) || (charCount == 17) || (charCount == 19) || (charCount == 24) || (charCount == 26) || (charCount == 28) || (charCount == 33) || (charCount == 35) || (charCount == 37) ||
						(charCount == 42) || (charCount == 44) || (charCount == 46) || (charCount == 51) || (charCount == 60) || (charCount == 69) || (charCount == 70) || (charCount == 71) || (charCount == 72) ||
						(charCount == 78) || (charCount == 79) || (charCount == 80) || (charCount == 81) || (charCount == 22) || (charCount == 39) || (charCount == 41) || (charCount == 55) || (charCount == 62) || (charCount == 66) || (charCount == 68))
					{
						cout << "Blocked by Wall";
						charCount += 2;
					}
					else
					{
						g_input = 1;
						cout << "mp" << mp << endl;
						mp -= 1;
						g_key_lock = 1;
						jump_activate = 1;
						char_source_rect[0] = { 1, 47 , 14 , 24 };
						char_source_rect[1] = { 15, 47 , 17 , 24 };
						char_source_rect[2] = { 33, 47 , 14 , 24 };
						char_source_rect[3] = { 48, 47 , 17 , 24 };
						if (stealthing == 1)
						{
							stealthing = 0;
						}
					}
				}
			}
			else if (event.key.keysym.sym == SDLK_RIGHT && g_key_lock == 0) {
				if (charCount % sliceNum == 0)
				{
					cout << "Blocked by Wall";
				}
				else if (jump_activate == 0 || jump_activate == 1)
				{
					charCount += 1;
					if ((charCount == 1) || (charCount == 2) || (charCount == 3) || (charCount == 4) || (charCount == 5) || (charCount == 6) || (charCount == 7) || (charCount == 8) || (charCount == 10) ||
						(charCount == 13) || (charCount == 17) || (charCount == 19) || (charCount == 24) || (charCount == 26) || (charCount == 28) || (charCount == 33) || (charCount == 35) || (charCount == 37) ||
						(charCount == 42) || (charCount == 44) || (charCount == 46) || (charCount == 51) || (charCount == 60) || (charCount == 69) || (charCount == 70) || (charCount == 71) || (charCount == 72) ||
						(charCount == 78) || (charCount == 79) || (charCount == 80) || (charCount == 81) || (charCount == 22) || (charCount == 39) || (charCount == 41) || (charCount == 55) || (charCount == 62) || (charCount == 66) || (charCount == 68))

					{
						cout << "Blocked by Wall";
						charCount -= 1;
					}
					else {
						g_input = 2;
						cout << "mp" << mp << endl;
						mp -= 1;
						g_key_lock = 1;
						char_source_rect[0] = { 1, 95 , 14 , 24 };
						char_source_rect[1] = { 15, 95 , 17 , 24 };
						char_source_rect[2] = { 33, 95 , 14 , 24 };
						char_source_rect[3] = { 48, 95 , 17 , 24 };
						if (stealthing == 1)
						{
							stealthing = 0;
						}
					}
				}
				else if (jump_activate == 2)
				{
					charCount += 2;
					if ((charCount == 1) || (charCount == 2) || (charCount == 3) || (charCount == 4) || (charCount == 5) || (charCount == 6) || (charCount == 7) || (charCount == 8) || (charCount == 10) ||
						(charCount == 13) || (charCount == 17) || (charCount == 19) || (charCount == 24) || (charCount == 26) || (charCount == 28) || (charCount == 33) || (charCount == 35) || (charCount == 37) ||
						(charCount == 42) || (charCount == 44) || (charCount == 46) || (charCount == 51) || (charCount == 60) || (charCount == 69) || (charCount == 70) || (charCount == 71) || (charCount == 72) ||
						(charCount == 78) || (charCount == 79) || (charCount == 80) || (charCount == 81) || (charCount == 22) || (charCount == 39) || (charCount == 41) || (charCount == 55) || (charCount == 62) || (charCount == 66) || (charCount == 68))

					{
						cout << "Blocked by Wall";
						charCount -= 2;
					}
					else {
						g_input = 2;
						cout << "mp" << mp << endl;
						mp -= 1;
						g_key_lock = 1;
						jump_activate = 1;
						char_source_rect[0] = { 1, 95 , 14 , 24 };
						char_source_rect[1] = { 15, 95 , 17 , 24 };
						char_source_rect[2] = { 33, 95 , 14 , 24 };
						char_source_rect[3] = { 48, 95 , 17 , 24 };
						if (stealthing == 1)
						{
							stealthing = 0;
						}
					}
				}
			}
			else if (event.key.keysym.sym == SDLK_UP && g_key_lock == 0) {
				if ((charCount - sliceNum) < 1)
				{
					cout << "Blocked by Wall";
				}
				else if (jump_activate == 0 || jump_activate == 1)
				{
					charCount -= sliceNum;
					if ((charCount == 1) || (charCount == 2) || (charCount == 3) || (charCount == 4) || (charCount == 5) || (charCount == 6) || (charCount == 7) || (charCount == 8) || (charCount == 10) ||
						(charCount == 13) || (charCount == 17) || (charCount == 19) || (charCount == 24) || (charCount == 26) || (charCount == 28) || (charCount == 33) || (charCount == 35) || (charCount == 37) ||
						(charCount == 42) || (charCount == 44) || (charCount == 46) || (charCount == 51) || (charCount == 60) || (charCount == 69) || (charCount == 70) || (charCount == 71) || (charCount == 72) ||
						(charCount == 78) || (charCount == 79) || (charCount == 80) || (charCount == 81) || (charCount == 22) || (charCount == 39) || (charCount == 41) || (charCount == 55) || (charCount == 62) || (charCount == 66) || (charCount == 68))

					{
						cout << "Blocked by Wall";
						charCount += sliceNum;
					}
					else
					{
						g_input = 3;
						cout << "mp" << mp << endl;
						mp -= 1;
						g_key_lock = 1;
						char_source_rect[0] = { 1, 22 , 14 , 24 };
						char_source_rect[1] = { 15, 22 , 17 , 24 };
						char_source_rect[2] = { 33, 22 , 14 , 24 };
						char_source_rect[3] = { 48, 22 , 17 , 24 };
						if (stealthing == 1)
						{
							stealthing = 0;
						}
					}
				}
				else if (jump_activate == 2)
				{
					charCount -= sliceNum * 2;
					if ((charCount == 1) || (charCount == 2) || (charCount == 3) || (charCount == 4) || (charCount == 5) || (charCount == 6) || (charCount == 7) || (charCount == 8) || (charCount == 10) ||
						(charCount == 13) || (charCount == 17) || (charCount == 19) || (charCount == 24) || (charCount == 26) || (charCount == 28) || (charCount == 33) || (charCount == 35) || (charCount == 37) ||
						(charCount == 42) || (charCount == 44) || (charCount == 46) || (charCount == 51) || (charCount == 60) || (charCount == 69) || (charCount == 70) || (charCount == 71) || (charCount == 72) ||
						(charCount == 78) || (charCount == 79) || (charCount == 80) || (charCount == 81) || (charCount == 22) || (charCount == 39) || (charCount == 41) || (charCount == 55) || (charCount == 62) || (charCount == 66) || (charCount == 68))

					{
						cout << "Blocked by Wall";
						charCount += sliceNum * 2;
					}
					else
					{
						g_input = 3;
						cout << "mp" << mp << endl;
						mp -= 1;
						g_key_lock = 1;
						jump_activate = 1;
						char_source_rect[0] = { 1, 22 , 14 , 24 };
						char_source_rect[1] = { 15, 22 , 17 , 24 };
						char_source_rect[2] = { 33, 22 , 14 , 24 };
						char_source_rect[3] = { 48, 22 , 17 , 24 };

						if (stealthing == 1)
						{
							stealthing = 0;
						}
					}
				}
			}
			else if (event.key.keysym.sym == SDLK_DOWN && g_key_lock == 0) {
				if ((charCount + sliceNum) > (sliceNum * sliceNum))
				{
					cout << "Blocked by Wall";
				}
				else if (jump_activate == 0 || jump_activate == 1)
				{
					charCount += sliceNum;
					if ((charCount == 1) || (charCount == 2) || (charCount == 3) || (charCount == 4) || (charCount == 5) || (charCount == 6) || (charCount == 7) || (charCount == 8) || (charCount == 10) ||
						(charCount == 13) || (charCount == 17) || (charCount == 19) || (charCount == 24) || (charCount == 26) || (charCount == 28) || (charCount == 33) || (charCount == 35) || (charCount == 37) ||
						(charCount == 42) || (charCount == 44) || (charCount == 46) || (charCount == 51) || (charCount == 60) || (charCount == 69) || (charCount == 70) || (charCount == 71) || (charCount == 72) ||
						(charCount == 78) || (charCount == 79) || (charCount == 80) || (charCount == 81) || (charCount == 22) || (charCount == 39) || (charCount == 41) || (charCount == 55) || (charCount == 62) || (charCount == 66) || (charCount == 68))

					{
						cout << "Blocked by Wall";
						charCount -= sliceNum;
					}
					else {
						g_input = 4;
						cout << "mp" << mp << endl;
						mp -= 1;
						g_key_lock = 1;
						char_source_rect[0] = { 1, 72 , 14 , 24 };
						char_source_rect[1] = { 15, 72 , 17 , 24 };
						char_source_rect[2] = { 33, 72 , 14 , 24 };
						char_source_rect[3] = { 48, 72 , 17 , 24 };
						if (stealthing == 1)
						{
							stealthing = 0;
						}
					}
				}
				else if (jump_activate == 2)
				{
					charCount += sliceNum * 2;
					if ((charCount == 1) || (charCount == 2) || (charCount == 3) || (charCount == 4) || (charCount == 5) || (charCount == 6) || (charCount == 7) || (charCount == 8) || (charCount == 10) ||
						(charCount == 13) || (charCount == 17) || (charCount == 19) || (charCount == 24) || (charCount == 26) || (charCount == 28) || (charCount == 33) || (charCount == 35) || (charCount == 37) ||
						(charCount == 42) || (charCount == 44) || (charCount == 46) || (charCount == 51) || (charCount == 60) || (charCount == 69) || (charCount == 70) || (charCount == 71) || (charCount == 72) ||
						(charCount == 78) || (charCount == 79) || (charCount == 80) || (charCount == 81) || (charCount == 22) || (charCount == 39) || (charCount == 41) || (charCount == 55) || (charCount == 62) || (charCount == 66) || (charCount == 68))

					{
						cout << "Blocked by Wall";
						charCount -= sliceNum * 2;
					}
					else
					{
						g_input = 4;
						cout << "mp" << mp << endl;
						mp -= 1;
						g_key_lock = 1;
						jump_activate = 1;
						char_source_rect[0] = { 1, 72 , 14 , 24 };
						char_source_rect[1] = { 15, 72 , 17 , 24 };
						char_source_rect[2] = { 33, 72 , 14 , 24 };
						char_source_rect[3] = { 48, 72 , 17 , 24 };
						if (stealthing == 1)
						{
							stealthing = 0;
						}
					}
				}
			}
			else if (event.key.keysym.sym == SDLK_SPACE && g_key_lock == 0) {
				if (jump_activate == 1 && charCount == 30)
				{
					jump_activate = 0;
					int Chunk = Mix_PlayChannel(1, g_get_item_sound, 0);
				}
				else if ((charCount == 34 || charCount == 59) && stealth_activate == 1)
				{
					stealth_activate = 0;
					int Chunk = Mix_PlayChannel(1, g_get_item_sound, 0);
				}
				else if (jump_activate == 0)
				{
					jump_activate = 2;
				}

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
		}
	}
}

