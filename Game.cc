#include "Game.h"
#include "TextureManager.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_sdl2.h"
#include "imgui/imgui_impl_sdlrenderer2.h"

bool Game::init(const char* name,int x,int y,int width, int height,uint32_t flag){

	if(SDL_Init(SDL_INIT_EVERYTHING) == 0 ){
		// window and renderer
		this->m_Window = SDL_CreateWindow(name,x,y,width,height,flag);
		this->m_Renderer = SDL_CreateRenderer(this->m_Window,-1,0);
		SDL_SetRenderDrawColor(this->m_Renderer,255,255,255,255);	

		//SDL_Surface* pTempSurface = IMG_Load("assets/animate-alpha.png");
		//this->m_Texture = SDL_CreateTextureFromSurface(this->m_Renderer,pTempSurface);
		//SDL_FreeSurface(pTempSurface);

			
		TheTextureManager::Instance()->load("assets/animate-alpha.png","animate",m_Renderer);


		this->m_DestinationRect.x = this->m_SourceRect.x = 0;
		this->m_DestinationRect.y = this->m_SourceRect.y = 0;
		this->m_DestinationRect.w = this->m_SourceRect.w = 128;
		this->m_DestinationRect.h = this->m_SourceRect.h = 82;

			
		this->m_DestinationRect.x = 640-128;
	}
	
	this->m_go.load(100,100,128,82,"animate");
	this->m_Player.load(300,300,128,82,"animate");


	(void)this->io;
    	this->io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    	this->io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;


	this->clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);


	ImGui_ImplSDL2_InitForSDLRenderer(this->m_Window,this->m_Renderer);
	ImGui_ImplSDLRenderer2_Init(this->m_Renderer);



	this->m_Running = true;
	return true;
}


void Game::render(){
	SDL_RenderClear(this->m_Renderer);

	//SDL_RenderCopy(this->m_Renderer,this->m_Texture,nullptr,nullptr);
	//SDL_RenderCopyEx(this->m_Renderer,this->m_Texture,&this->m_SourceRect,&m_DestinationRect,0,0,SDL_FLIP_HORIZONTAL);

	//TheTextureManager::Instance()->draw("animate",0,0,128,82,this->m_Renderer);
	
	TheTextureManager::Instance()->drawFrame("animate",100,100,128,82,1,int(((SDL_GetTicks()/100) % 6)),this->m_Renderer);
	
	this->m_go.draw(this->m_Renderer);
	this->m_Player.draw(this->m_Renderer);


	ImGui_ImplSDLRenderer2_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();

	

	ImGui::Begin("ainnnnnn"); 
	ImGui::Text("mizera mizera");
	
	ImGui::End();

	ImGui::Render();
	SDL_RenderSetScale(this->m_Renderer, io.DisplayFramebufferScale.x, io.DisplayFramebufferScale.y);
        SDL_SetRenderDrawColor(this->m_Renderer, (Uint8)(clear_color.x * 255), (Uint8)(clear_color.y * 255),
	(Uint8)(clear_color.z * 255), (Uint8)(clear_color.w * 255));
        SDL_RenderClear(this->m_Renderer);
        ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData());


	TheTextureManager::Instance()->drawFrame("animate",100,100,128,82,1,int(((SDL_GetTicks()/100) % 6)),this->m_Renderer);

	SDL_RenderPresent(this->m_Renderer);
}


void Game::handleEvents(){
	SDL_Event event;
	if(SDL_PollEvent(&event)){
		switch (event.type){
			case SDL_QUIT:
				this->m_Running = false;
				break;
			case SDL_KEYUP:
				this->m_Running = false;
				break;
			default:
				break;
		}
	}
}

void Game::update(){
	//this->m_SourceRect.x = 128 * int(((SDL_GetTicks() / 100) % 6));
	
	this->m_go.update();
	this->m_Player.update();
}


void Game::clean(){
	std::cout<< "Quiting Game and cleaning resources\n";
	SDL_DestroyWindow(m_Window);
	SDL_DestroyRenderer(m_Renderer);
	SDL_Quit();
}

