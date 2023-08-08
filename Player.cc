#include "Player.h"




	void Player::load(int x, int y, int width, int height,std::string id){
		GameObject::load(x,y,width,height,id);

	}



	void Player::draw(SDL_Renderer* pRender){
		GameObject::draw(pRender);
	}


	void Player::update(){
		this->m_x -=1;
		this->m_CurrentFrame = int(((SDL_GetTicks()/100) % 6));
	}
