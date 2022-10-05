#include "Game_Func3.h"
#include "Game_Class.h"


Stage3::Stage3() {

	sliceNum = 9;
	charCount = 73;
	MAX = 3;
	ratioW = DM.w / 1920.;
	ratioW = ceil(ratioW * 100) / 100;
	ratioH = DM.h / 1080.;
	ratioH = ceil(ratioH * 100) / 100;
	mp = 20;
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
	gate_activate = 0;

	g_get_item_sound = Mix_LoadWAV("../Resources/gate.mp3");

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

	cout << "ratioW = " << ratioW << endl;
	cout << "ratioH = " << ratioH << endl;
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

	SDL_Surface* gate_surface = IMG_Load("../Resources/gate.png");
	gate_texture = SDL_CreateTextureFromSurface(g_renderer, gate_surface);
	SDL_FreeSurface(gate_surface);

	tile_source_rect.x = 0;
	tile_source_rect.y = 0;
	tile_source_rect.w = 96;
	tile_source_rect.h = 96;


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

Stage3::~Stage3()
{
	Mix_FreeChunk(g_get_item_sound);
	Mix_FadeOutMusic(2000);
	Mix_FreeMusic(g_stage_mus);
	SDL_DestroyTexture(char_texture);
	SDL_DestroyTexture(jump_texture);
	SDL_DestroyTexture(jump_location_texture);
	SDL_DestroyTexture(stealth_texture);
	SDL_DestroyTexture(gate_texture);
	SDL_DestroyTexture(tile1_texture);
	SDL_DestroyTexture(tile2_texture);
	SDL_DestroyTexture(tile3_texture);
	SDL_DestroyTexture(tile4_texture);
	SDL_DestroyTexture(g_mp_kr);
	SDL_DestroyTexture(g_score_kr);

	
}

void Stage3::Update() {

	//gate 10 15   28 81   46 40   42 80   71 26 
	if (gate_activate == 0 && char_destination_rect.x == greed[10].x && char_destination_rect.y == greed[10].y)
	{
		char_destination_rect.x = greed[15].x;
		char_destination_rect.y = greed[15].y;
		charCount = 15;
		gate_activate = 1;
		int Chunk = Mix_PlayChannel(1, g_get_item_sound, 0);
	}
	else if (gate_activate == 0 && char_destination_rect.x == greed[15].x && char_destination_rect.y == greed[15].y)
	{
		char_destination_rect.x = greed[10].x;
		char_destination_rect.y = greed[10].y;
		charCount = 10;
		gate_activate = 1;
		int Chunk = Mix_PlayChannel(1, g_get_item_sound, 0);
	}
	else if (gate_activate == 0 && char_destination_rect.x == greed[28].x && char_destination_rect.y == greed[28].y)
	{
		char_destination_rect.x = greed[81].x;
		char_destination_rect.y = greed[81].y;
		charCount = 81;
		gate_activate = 1;
		int Chunk = Mix_PlayChannel(1, g_get_item_sound, 0);
	}
	else if (gate_activate == 0 && char_destination_rect.x == greed[81].x && char_destination_rect.y == greed[81].y)
	{
		char_destination_rect.x = greed[28].x;
		char_destination_rect.y = greed[28].y;
		charCount = 28;
		gate_activate = 1;
		int Chunk = Mix_PlayChannel(1, g_get_item_sound, 0);
	}
	else if (gate_activate == 0 && char_destination_rect.x == greed[46].x && char_destination_rect.y == greed[46].y)
	{
		char_destination_rect.x = greed[40].x;
		char_destination_rect.y = greed[40].y;
		charCount = 40;
		gate_activate = 1;
		int Chunk = Mix_PlayChannel(1, g_get_item_sound, 0);
	}
	else if (gate_activate == 0 && char_destination_rect.x == greed[40].x && char_destination_rect.y == greed[40].y)
	{
		char_destination_rect.x = greed[46].x;
		char_destination_rect.y = greed[46].y;
		charCount = 46;
		gate_activate = 1;
		int Chunk = Mix_PlayChannel(1, g_get_item_sound, 0);
	}
	else if (gate_activate == 0 && char_destination_rect.x == greed[42].x && char_destination_rect.y == greed[42].y)
	{
		char_destination_rect.x = greed[80].x;
		char_destination_rect.y = greed[80].y;
		charCount = 80;
		gate_activate = 1;
		int Chunk = Mix_PlayChannel(1, g_get_item_sound, 0);
	}
	else if (gate_activate == 0 && char_destination_rect.x == greed[80].x && char_destination_rect.y == greed[80].y)
	{
		char_destination_rect.x = greed[42].x;
		char_destination_rect.y = greed[42].y;
		charCount = 42;
		gate_activate = 1;
		int Chunk = Mix_PlayChannel(1, g_get_item_sound, 0);
	}
	else if (gate_activate == 0 && char_destination_rect.x == greed[71].x && char_destination_rect.y == greed[71].y)
	{
		char_destination_rect.x = greed[26].x;
		char_destination_rect.y = greed[26].y;
		charCount = 26;
		gate_activate = 1;
		int Chunk = Mix_PlayChannel(1, g_get_item_sound, 0);
	}
	else if (gate_activate == 0 && char_destination_rect.x == greed[26].x && char_destination_rect.y == greed[26].y)
	{
		char_destination_rect.x = greed[71].x;
		char_destination_rect.y = greed[71].y;
		charCount = 71;
		gate_activate = 1;
		int Chunk = Mix_PlayChannel(1, g_get_item_sound, 0);
	}
	else if (gate_activate == 0 && char_destination_rect.x == greed[13].x && char_destination_rect.y == greed[13].y)
	{
		char_destination_rect.x = greed[72].x;
		char_destination_rect.y = greed[72].y;
		charCount = 72;
		gate_activate = 1;
		int Chunk = Mix_PlayChannel(1, g_get_item_sound, 0);
	}
	else if (gate_activate == 0 && char_destination_rect.x == greed[72].x && char_destination_rect.y == greed[72].y)
	{
		char_destination_rect.x = greed[13].x;
		char_destination_rect.y = greed[13].y;
		charCount = 13;
		gate_activate = 1;
		int Chunk = Mix_PlayChannel(1, g_get_item_sound, 0);
	}
	
	


	if (MusicActivate == 0)
	{
		Mix_FadeInMusic(g_stage_mus, -1, 2000);
		MusicActivate = 1;
	}

	g_time = SDL_GetTicks();
	//1초에 1000정도 증가



	if (g_input == 1)
	{

		char_destination_rect.x -= 30;
		if (char_destination_rect.x < greed[charCount].x)
		{
			g_input = 0;
			char_destination_rect.x = greed[charCount].x;
			gate_activate = 0;
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
			gate_activate = 0;
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
			gate_activate = 0;
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
			gate_activate = 0;
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
		cout << "Game Clear!";
		score += mp * 1000;
		SDL_Delay(250);
		mp = 20;
		charCount = 73;
		stealth_activate = 1;
		jump_activate = 1;
		char_destination_rect.x = greed[73].x;
		char_destination_rect.y = greed[73].y;
		MusicActivate = 0;
		g_current_game_phase = PHASE_GAMECLEAR;
		g_stage_phase = PHASE_STAGE3;
		g_flag_running = true;
	}
	if (mp == 0)
	{
		SDL_Delay(250);
		mp = 20;
		charCount = 73;
		char_destination_rect.x = greed[37].x;
		char_destination_rect.y = greed[37].y;
		MusicActivate = 0;
		g_current_game_phase = PHASE_GAMEOVER;
		g_stage_phase = PHASE_STAGE3;
		g_flag_running = true;
	}
	


}


void Stage3::Render() {
	SDL_RenderCopy(g_renderer, background_texture, &background_source_rect, &background_destination_rect);



	for (int i = 1; i < 82; i++)
	{
		tile_destination_rect.x = greed[i].x - (25 * ratioW);
		tile_destination_rect.y = greed[i].y - (20 * ratioH);
		tile_destination_rect.w = slicedW;
		tile_destination_rect.h = slicedH;
		if ((i == 1) || (i == 2) || (i == 3) || (i == 4) || (i == 5) || (i == 6) || (i == 7) || (i == 12) || (i == 16) ||
			(i == 19) || (i == 21) || (i == 25) || (i == 30) || (i == 34) || (i == 35) || (i == 36) || (i == 37) || (i == 39) ||
			(i == 43) || (i == 44) || (i == 45) || (i == 48) || (i == 52) || (i == 53) || (i == 54) || (i == 55) || (i == 57) ||
			(i == 61) || (i == 62) || (i == 63) || (i == 64) || (i == 66) || (i == 67) || (i == 68) || (i == 69) || (i == 70) ||
			(i == 75) || (i == 76) || (i == 77) || (i == 78) || (i == 79))
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
			if ((i == 10) || (i == 13) || (i == 15) || (i == 26) || (i == 28) || (i == 40) || (i == 42) || (i == 71) ||
				(i == 80) || (i == 81) || (i == 72) || (i == 46))
		{
		SDL_RenderCopy(g_renderer, gate_texture, &tile_source_rect, &tile_destination_rect);
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

void Stage3::HandleEvents()
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
					if ((charCount == 1) || (charCount == 2) || (charCount == 3) || (charCount == 4) || (charCount == 5) || (charCount == 6) || (charCount == 7) || (charCount == 12) || (charCount == 16) ||
						(charCount == 19) || (charCount == 21) || (charCount == 25) || (charCount == 30) || (charCount == 34) || (charCount == 35) || (charCount == 36) || (charCount == 37) || (charCount == 39) ||
						(charCount == 43) || (charCount == 44) || (charCount == 45) || (charCount == 48) || (charCount == 52) || (charCount == 53) || (charCount == 54) || (charCount == 55) || (charCount == 57) ||
						(charCount == 61) || (charCount == 62) || (charCount == 63) || (charCount == 64) || (charCount == 66) || (charCount == 67) || (charCount == 68) || (charCount == 69) || (charCount == 70) ||
						(charCount == 75) || (charCount == 76) || (charCount == 77) || (charCount == 78) || (charCount == 79))

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
					if ((charCount == 1) || (charCount == 2) || (charCount == 3) || (charCount == 4) || (charCount == 5) || (charCount == 6) || (charCount == 7) || (charCount == 12) || (charCount == 16) ||
						(charCount == 19) || (charCount == 21) || (charCount == 25) || (charCount == 30) || (charCount == 34) || (charCount == 35) || (charCount == 36) || (charCount == 37) || (charCount == 39) ||
						(charCount == 43) || (charCount == 44) || (charCount == 45) || (charCount == 48) || (charCount == 52) || (charCount == 53) || (charCount == 54) || (charCount == 55) || (charCount == 57) ||
						(charCount == 61) || (charCount == 62) || (charCount == 63) || (charCount == 64) || (charCount == 66) || (charCount == 67) || (charCount == 68) || (charCount == 69) || (charCount == 70) ||
						(charCount == 75) || (charCount == 76) || (charCount == 77) || (charCount == 78) || (charCount == 79))

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
					if ((charCount == 1) || (charCount == 2) || (charCount == 3) || (charCount == 4) || (charCount == 5) || (charCount == 6) || (charCount == 7) || (charCount == 12) || (charCount == 16) ||
						(charCount == 19) || (charCount == 21) || (charCount == 25) || (charCount == 30) || (charCount == 34) || (charCount == 35) || (charCount == 36) || (charCount == 37) || (charCount == 39) ||
						(charCount == 43) || (charCount == 44) || (charCount == 45) || (charCount == 48) || (charCount == 52) || (charCount == 53) || (charCount == 54) || (charCount == 55) || (charCount == 57) ||
						(charCount == 61) || (charCount == 62) || (charCount == 63) || (charCount == 64) || (charCount == 66) || (charCount == 67) || (charCount == 68) || (charCount == 69) || (charCount == 70) ||
						(charCount == 75) || (charCount == 76) || (charCount == 77) || (charCount == 78) || (charCount == 79))

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
					if ((charCount == 1) || (charCount == 2) || (charCount == 3) || (charCount == 4) || (charCount == 5) || (charCount == 6) || (charCount == 7) || (charCount == 12) || (charCount == 16) ||
						(charCount == 19) || (charCount == 21) || (charCount == 25) || (charCount == 30) || (charCount == 34) || (charCount == 35) || (charCount == 36) || (charCount == 37) || (charCount == 39) ||
						(charCount == 43) || (charCount == 44) || (charCount == 45) || (charCount == 48) || (charCount == 52) || (charCount == 53) || (charCount == 54) || (charCount == 55) || (charCount == 57) ||
						(charCount == 61) || (charCount == 62) || (charCount == 63) || (charCount == 64) || (charCount == 66) || (charCount == 67) || (charCount == 68) || (charCount == 69) || (charCount == 70) ||
						(charCount == 75) || (charCount == 76) || (charCount == 77) || (charCount == 78) || (charCount == 79))

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
					if ((charCount == 1) || (charCount == 2) || (charCount == 3) || (charCount == 4) || (charCount == 5) || (charCount == 6) || (charCount == 7) || (charCount == 12) || (charCount == 16) ||
						(charCount == 19) || (charCount == 21) || (charCount == 25) || (charCount == 30) || (charCount == 34) || (charCount == 35) || (charCount == 36) || (charCount == 37) || (charCount == 39) ||
						(charCount == 43) || (charCount == 44) || (charCount == 45) || (charCount == 48) || (charCount == 52) || (charCount == 53) || (charCount == 54) || (charCount == 55) || (charCount == 57) ||
						(charCount == 61) || (charCount == 62) || (charCount == 63) || (charCount == 64) || (charCount == 66) || (charCount == 67) || (charCount == 68) || (charCount == 69) || (charCount == 70) ||
						(charCount == 75) || (charCount == 76) || (charCount == 77) || (charCount == 78) || (charCount == 79))

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
					if ((charCount == 1) || (charCount == 2) || (charCount == 3) || (charCount == 4) || (charCount == 5) || (charCount == 6) || (charCount == 7) || (charCount == 12) || (charCount == 16) ||
						(charCount == 19) || (charCount == 21) || (charCount == 25) || (charCount == 30) || (charCount == 34) || (charCount == 35) || (charCount == 36) || (charCount == 37) || (charCount == 39) ||
						(charCount == 43) || (charCount == 44) || (charCount == 45) || (charCount == 48) || (charCount == 52) || (charCount == 53) || (charCount == 54) || (charCount == 55) || (charCount == 57) ||
						(charCount == 61) || (charCount == 62) || (charCount == 63) || (charCount == 64) || (charCount == 66) || (charCount == 67) || (charCount == 68) || (charCount == 69) || (charCount == 70) ||
						(charCount == 75) || (charCount == 76) || (charCount == 77) || (charCount == 78) || (charCount == 79))

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
					if ((charCount == 1) || (charCount == 2) || (charCount == 3) || (charCount == 4) || (charCount == 5) || (charCount == 6) || (charCount == 7) || (charCount == 12) || (charCount == 16) ||
						(charCount == 19) || (charCount == 21) || (charCount == 25) || (charCount == 30) || (charCount == 34) || (charCount == 35) || (charCount == 36) || (charCount == 37) || (charCount == 39) ||
						(charCount == 43) || (charCount == 44) || (charCount == 45) || (charCount == 48) || (charCount == 52) || (charCount == 53) || (charCount == 54) || (charCount == 55) || (charCount == 57) ||
						(charCount == 61) || (charCount == 62) || (charCount == 63) || (charCount == 64) || (charCount == 66) || (charCount == 67) || (charCount == 68) || (charCount == 69) || (charCount == 70) ||
						(charCount == 75) || (charCount == 76) || (charCount == 77) || (charCount == 78) || (charCount == 79))

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
					if ((charCount == 1) || (charCount == 2) || (charCount == 3) || (charCount == 4) || (charCount == 5) || (charCount == 6) || (charCount == 7) || (charCount == 12) || (charCount == 16) ||
						(charCount == 19) || (charCount == 21) || (charCount == 25) || (charCount == 30) || (charCount == 34) || (charCount == 35) || (charCount == 36) || (charCount == 37) || (charCount == 39) ||
						(charCount == 43) || (charCount == 44) || (charCount == 45) || (charCount == 48) || (charCount == 52) || (charCount == 53) || (charCount == 54) || (charCount == 55) || (charCount == 57) ||
						(charCount == 61) || (charCount == 62) || (charCount == 63) || (charCount == 64) || (charCount == 66) || (charCount == 67) || (charCount == 68) || (charCount == 69) || (charCount == 70) ||
						(charCount == 75) || (charCount == 76) || (charCount == 77) || (charCount == 78) || (charCount == 79))

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
				if (charCount == 42 && jump_activate == 1)
				{
					jump_activate = 0;
					int Chunk = Mix_PlayChannel(1, g_get_item_sound, 0);
				}
				else if (charCount == 39 && stealth_activate == 1)
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

