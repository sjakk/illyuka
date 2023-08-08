#include "Game.h"




int main(){

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();



Game* g_Game = new Game();


g_Game->init("Sexo",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,640,420,0);


while(g_Game->running()){
	g_Game->handleEvents();
	g_Game->render();
	g_Game->update();



SDL_Delay(10);
}

g_Game->clean();
}








