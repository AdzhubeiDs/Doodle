#include <fstream>
#include <iostream>
using namespace std;

int Best_score(int score) {

	ifstream f("Score.txt", ios::in);
	int Bscore;
	f >> Bscore; // ������� ����� �� �����
	f.close();

	if (score > Bscore) {
		ofstream F("Score.txt", ios::out);
		F << score;
		Bscore = score;
		F.close();
	}
	return Bscore;
}