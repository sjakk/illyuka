#include "GameObject.h"
#include "TextureManager.h"





void GameObject::load(int x, int y, int width, int height,std::string id){
this->m_x = x;
this->m_y = y;
this->m_Width = width;
this->m_Height = height;
this->m_TextureId = id;
this->m_CurrentRow = 1;
this->m_CurrentFrame = int(((SDL_GetTicks()/100) % 6));
}



void GameObject::draw(SDL_Renderer* pRender){


	TextureManager::Instance()->drawFrame(this->m_TextureId,this->m_x,this->m_y,m_Width,
			this->m_Height,this->m_CurrentRow,this->m_CurrentFrame,pRender);


}



void GameObject::update(){
	this->m_x+=1;
	this->m_CurrentFrame = int(((SDL_GetTicks()/100) % 6));
}







