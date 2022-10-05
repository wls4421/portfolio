#include "Game_Class.h"
#include "Game_Func.h"
#include "Game_Func2.h"
#include "Game_Func3.h"
#include "Game_Func4.h"
#include "Game_Func5.h"
#include "Game_Intro.h"
#include "Game_Ending.h"
#include "Game_Over.h"
#include "Game_Clear.h"
#include "Game_howto.h"

bool g_flag_running;
Uint32 g_last_time_ms;
SDL_Window* g_window;
SDL_Renderer* g_renderer;
SDL_DisplayMode DM;
int g_current_game_phase;
int g_stage_phase;

int main(int argc, char* argv[]) {

	// Initializing SDL library
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();

	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
	{
		cout << "Mix_OpenAudio" << Mix_GetError() << endl;
		exit(2);
	}
	Mix_VolumeMusic(20);
	SDL_GetCurrentDisplayMode(0, &DM);

	//auto Width = DM.w;
	//auto Height = DM.h;
	
	DM.w = 1920;
	DM.h = 1080;

	g_window = SDL_CreateWindow("First Window", 100, 100, DM.w , DM.h, 0);
			
	g_renderer = SDL_CreateRenderer(g_window, -1, 0);
	SDL_SetWindowFullscreen(g_window, SDL_TRUE);
	g_current_game_phase = PHASE_INTRO;
	g_stage_phase = PHASE_STAGE;

	InitGame();

	Intro intro;
	Stage stage;
	Stage2 stage2;
	Stage3 stage3;
	Stage4 stage4;
	Stage5 stage5;
	Ending ending;
	GameOver gameover;
	GameClear gameclear;
	Howto howto;

	score = 0;

	g_last_time_ms = SDL_GetTicks();

	while (g_flag_running) {

		Uint32 cur_time_ms = SDL_GetTicks();
		if (cur_time_ms - g_last_time_ms < 33)
			continue;

		if (g_current_game_phase == PHASE_INTRO)
		{
			intro.Update();
			intro.Render();
			intro.HandleEvents();
		}
		else if (g_current_game_phase == PHASE_HOWTO)
		{
			howto.Update();
			howto.Render();
			howto.HandleEvents();
		}
		else if (g_current_game_phase == PHASE_STAGE)
		{
			stage.HandleEvents();
			stage.Update();
			stage.Render();
		}
		else if (g_current_game_phase == PHASE_STAGE2)
		{
			stage2.HandleEvents();
			stage2.Update();
			stage2.Render();
		}
		else if (g_current_game_phase == PHASE_STAGE3)
		{
			stage3.HandleEvents();
			stage3.Update();
			stage3.Render();
		}
		else if (g_current_game_phase == PHASE_STAGE4)
		{
			stage4.HandleEvents();
			stage4.Update();
			stage4.Render();
		}
		else if (g_current_game_phase == PHASE_STAGE5)
		{
			stage5.HandleEvents();
			stage5.Update();
			stage5.Render();
		}
		else if (g_current_game_phase == PHASE_ENDING)
		{
			ending.Update();
			ending.Render();
			ending.HandleEvents();
		}
		else if (g_current_game_phase == PHASE_GAMEOVER)
		{
			gameover.Update();
			gameover.Render();
			gameover.HandleEvents();
		}
		else if (g_current_game_phase == PHASE_GAMECLEAR)
		{
			gameclear.Update();
			gameclear.Render();
			gameclear.HandleEvents();
		}

		g_last_time_ms = cur_time_ms;
	}


	SDL_DestroyRenderer(g_renderer);
	SDL_DestroyWindow(g_window);

	ClearGame();
	Mix_CloseAudio();
	SDL_Quit();
	TTF_Quit();
	return 0;
}