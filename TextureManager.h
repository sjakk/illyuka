#ifndef __TEXTUREMANAGER__
#define __TEXTUREMANAGER__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <map>

class TextureManager{

	public:

static TextureManager* Instance(){
	if(m_Instance == nullptr){
		m_Instance = new TextureManager();
		return m_Instance;
	}
	return m_Instance;
}

bool load(std::string fileName,std::string id,SDL_Renderer* pRenderer);

void draw(std::string id,int x, int y, int width, int height,SDL_Renderer* pRender,SDL_RendererFlip flip = SDL_FLIP_NONE);


void drawFrame(std::string id, int x, int y, int width,int height,int currentRow,int currentFrame,SDL_Renderer* pRender,
		SDL_RendererFlip flip = SDL_FLIP_NONE);



	private:
	TextureManager(){}
	static TextureManager* m_Instance;
	std::map<std::string,SDL_Texture*> m_TextureMap;

};

typedef TextureManager TheTextureManager;

#endif
