#include "TextureManager.h"


TextureManager* TextureManager::m_Instance = 0;


bool TextureManager::load(std::string fileName,std::string id,SDL_Renderer* pRenderer){

SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());
if(pTempSurface == 0) return false;

SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer,pTempSurface);
SDL_FreeSurface(pTempSurface);

if(pTexture!=nullptr) this->m_TextureMap[id] = pTexture; return true;

return false;
}





void TextureManager::draw(std::string id,int x, int y,
		int width, int height,SDL_Renderer* pRender,SDL_RendererFlip flip){

SDL_Rect srcRect;
SDL_Rect destRect;

srcRect.x = 0; srcRect.y = 0; srcRect.w = destRect.w = width; srcRect.h = destRect.h = height;

destRect.x = x;
destRect.y = y;

SDL_RenderCopyEx(pRender,this->m_TextureMap[id],&srcRect,&destRect,0,0,flip);

}


void TextureManager::drawFrame(std::string id, int x, int y, int width,int height,int currentRow,int currentFrame,SDL_Renderer* pRender,
		SDL_RendererFlip flip){

SDL_Rect srcRect;
SDL_Rect destRect;

srcRect.x = width * currentFrame;
srcRect.y = height * (currentRow - 1);

srcRect.w = destRect.w = width;
srcRect.h = destRect.h = height;

destRect.x = x;
destRect.y = y;


SDL_RenderCopyEx(pRender, this->m_TextureMap[id],&srcRect,&destRect,0,0,flip);


}

