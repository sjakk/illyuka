#include "GameObject.h"


class Player : public GameObject{

	public:

		void load(int x, int y, int width, int height,std::string id);



		void draw(SDL_Renderer* pRender);
		
		void update();
		void clean();

};
