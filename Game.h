#ifndef __Game__
#define __Game__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"

#include "imgui/imgui.h"
#include "imgui/imgui_impl_sdl2.h"
#include "imgui/imgui_impl_sdlrenderer2.h"

class Game{

	public:
		Game(){}
		~Game(){}

bool init(const char* name,int x,int y,int width, int height,uint32_t flag);
void render();
void update();
void handleEvents();
void clean();



bool running(){return m_Running;}


private:

SDL_Window* m_Window;
SDL_Renderer* m_Renderer;
SDL_Texture* m_Texture;

SDL_Rect m_SourceRect;
SDL_Rect m_DestinationRect;

GameObject m_go;
Player m_Player;

//Imgui

ImGuiIO& io = ImGui::GetIO();
ImVec4 clear_color;
bool show_demo_window = true;
bool show_another_window = false;

bool m_Running;

};


















#endif

