#pragma once

#include <iostream>
#include "SDL_image.h"
#include <windows.h>
#include <SDL_keyboard.h>
#include "SDL_mixer.h"
#include <stdio.h>
#include <SDL_scancode.h>
#include "SDL_ttf.h"
#include <string>
#include <atlstr.h>
#include "SDL.h"
#include <vector>

void InitGame();
void ClearGame();

const int PHASE_INTRO = 0;
const int PHASE_GAMEOVER = 1;
const int PHASE_GAMECLEAR = 2;
const int PHASE_HOWTO = 3;
const int PHASE_STAGE = 4;
const int PHASE_STAGE2 = 5;
const int PHASE_STAGE3 = 6;
const int PHASE_STAGE4 = 7;
const int PHASE_STAGE5 = 8;
const int PHASE_ENDING = 9;

extern int score;
extern int g_stage_phase;
extern int g_current_game_phase;
extern bool g_flag_running;
extern SDL_Renderer* g_renderer;
extern SDL_Window* g_window;
extern SDL_DisplayMode DM;
extern Uint32 g_frame_per_sec;
