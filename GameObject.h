#ifndef __GAME_OBJECT__
#define __GAME_OBJECT__

#include <SDL2/SDL.h>
#include <iostream>

class GameObject{

	public:
		void draw() { std::cout << "draw game object";}
		void update();
		void clean() {std::cout << "clean game object";}

		void load(int x, int y, int width, int height,std::string id);
		void draw(SDL_Renderer* pRender);

	protected:
		std::string m_TextureId;

		int m_CurrentRow;
		int m_CurrentFrame;
		
		int m_x;
		int m_y;


		int m_Width;
		int m_Height;


};

#endif
