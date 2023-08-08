all:
	g++ main.cc Game.cc TextureManager.cc Player.cc GameObject.cc imgui/*cpp -lSDL2 -lSDL2_image -o zgame && ./zgame



maingui:
	g++ maingui.cc imgui/*cpp -lSDL2 -lSDL2_image




clean:
	rm *.out
