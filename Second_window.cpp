#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include <sstream>
#include <fstream>

#include "Header.h"
using namespace std;
using namespace sf;

void Open_second_window(float time_of_game, int score, int Bscore) {
	RenderWindow app2(VideoMode(450, 533), "Doodle Game Result");
	Texture t1;
	t1.loadFromFile("images/background2 (2).jpg");
	Sprite sBackground(t1);
	while (app2.isOpen())
	{
		Event e;
		while (app2.pollEvent(e))
		{
			if (e.type == Event::Closed)
				app2.close();

		}
		
		//текст время:
		Font font;
		font.loadFromFile("arial.ttf");
		Text text, text2, text3;

		text.setFont(font);
		text.setCharacterSize(30);
		text.setFillColor(Color::Blue);
		text.setPosition(80, 250);

		text2.setFont(font);
		text2.setCharacterSize(30);
		text2.setFillColor(Color::Blue);
		text2.setPosition(80, 280);

		text3.setFont(font);
		text3.setCharacterSize(35);
		text3.setFillColor(Color::Red);
		text3.setPosition(20, 350);

		ostringstream gameTimeStr, gameScoreStr, BestScoreStr;
		gameTimeStr << time_of_game;
		gameScoreStr << score;
		BestScoreStr << Bscore;
		text.setString("Time: " + gameTimeStr.str()+ " seconds");
		text2.setString("Score: " + gameScoreStr.str()+" points");
		text3.setString("Your best score: " + BestScoreStr.str() + " points");

		app2.draw(sBackground);
		app2.draw(text);
		app2.draw(text2);
		app2.draw(text3);
		app2.display();
	}
	
	
}