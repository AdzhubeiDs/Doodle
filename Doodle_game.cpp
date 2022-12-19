#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <windows.h>


#include "Header.h"

using namespace std;
using namespace sf;


struct point
{
	float x, y;
};



int main()
{
	Clock clock;
	float time_game = 0;
	
	RenderWindow app(VideoMode(450, 533), "Doodle Game!"/*, Style::Fullscreen */);
	app.setFramerateLimit(60);

	Texture t1, t2, t3, t4;
	t1.loadFromFile("images/background2 (2).jpg");
	t2.loadFromFile("images/platform.png");
	t3.loadFromFile("images/doodle.Ukkt2.png");
	t4.loadFromFile("images/leaf.ZOulv.png");

	Sprite sBackground(t1), sPlat(t2), sPers(t3), sleaf(t4);

	point plat[20];

	for (int i = 0; i < 10; i++)
	{
		plat[i].x = (float) (rand() % 450);
		plat[i].y = (float) (rand() % 533);
	}

	float x = 100, y = 100, h = 200, score = 0;
	int flag = 0;
	float dy = 0, dx=0;
	
	//текст время:
		Font font;
		font.loadFromFile("arial.ttf");
		Text text;
		text.setFont(font);
		text.setCharacterSize(20);
		text.setFillColor(Color::White);
		text.setPosition(20, 10);
		

	sleaf.setRotation(sleaf.getRotation() - 60);
	sleaf.setPosition(5, 40);

	//фон паузы
		Image image;
		image.create(100, 100, Color::White);
		Texture t5;
		t5.create(100, 100);
		t5.loadFromImage(image);
		t5.setSmooth(true);
		Sprite SPause(t5);
		SPause.setPosition(200, 200);
	int pause = 0, pause2=0;

	//пауза
	Text text1;
	text1.setFont(font);
	text1.setCharacterSize(20);
	text1.setFillColor(Color::White);
	text1.setPosition(380, 10);
	text1.setString("Pause");

	while (app.isOpen())
	{
		//запись лучшего результата
		int Bscore = Best_score(score);
		Event e;
		
		while (app.pollEvent(e))
		{
			if (e.type == Event::Closed)
				app.close();
			//if (e.type == Event::MouseButtonPressed)//если нажали клавишу мыши
			//	if (e.key.code == Mouse::Left)//а именно левую
			//			pause = true;
			if (e.type == Event::KeyPressed)
				if (e.key.code == Keyboard::Space)
				{
					pause = 1;
					pause2 == 0;
					Sleep(10);
				}
		}
		if (pause==1 && pause2==0) {
			app.draw(SPause);
			app.display();
			/*if (e.type == Event::MouseButtonPressed)
				if (e.key.code == Mouse::Left)
					pause = false;*/
			if (e.type == Event::KeyPressed)
				if (e.key.code == Keyboard::Space)
				{
					pause2 = 1;
					Sleep(10);
				}
		}
		else {
			if (Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right)) { x = x + 2.5; flag = 1; }
			if (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left)) { x = x - 2.5; flag = -1; }
			else { x += flag * 2; }

			dy += 0.2;
			y += dy;
			if (y > 500) {
				if (score > 0) {
					time_game = ((float)(int)(clock.getElapsedTime().asSeconds() * 10)) / 10;
					cout << time_game;
					Open_second_window(time_game, score, Bscore);
					app.close();
				}
				else {
					dy = -10;
				}

			}

			if (y < h) {
				score -= dy / 5;
				for (int i = 0; i < 10; i++)
				{
					y = h;
					plat[i].y -= dy;
					if (plat[i].y > 533) {
						plat[i].y = 0;
						plat[i].x = rand() % 400 - 10;
					}
				}
			}

			for (int i = 0; i < 10; i++)
				if ((x + 50 > plat[i].x) && (x + 20 < plat[i].x + 68)
					&& (y + 70 > plat[i].y) && (y + 70 < plat[i].y + 14) && (dy > 0))  dy = -10;
			if (x > 400 || x < 0) x = abs(400 - x);


			app.clear();
			sPers.setPosition(x, y);
			app.draw(sBackground);
			app.draw(sPers);


			for (int i = 0; i < 10; i++)
			{
				sPlat.setPosition(plat[i].x, plat[i].y);
				app.draw(sPlat);
			}


			app.draw(sleaf);
			score = (int)score;
			ostringstream gameScoreStr;
			gameScoreStr << score;
			text.setString("Score: " + gameScoreStr.str());
			app.draw(text);
			app.draw(text1);
			app.display();
		}
		
	}
	
	return 0;
}


