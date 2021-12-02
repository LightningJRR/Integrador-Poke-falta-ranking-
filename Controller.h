#pragma once
#include "Pikachu.h"
#include "Pokeball.h"
#include "SuperBall.h"
#include "UltraBall.h"
#include "MasterBall.h"
#include <vector>

using namespace std;

class Controller {
private:
	vector<Pikachu*>pikachu;
	vector<Pokeball*>ball;
	vector<SuperBall*>sball;
	vector<UltraBall*>uball;
	vector<MasterBall*>mball;
	int tiempo;
	int cantP, cantS, cantU, cantM;
	int contGotcha;
public:
	Controller(Bitmap^ pika, Bitmap^ bola){
		for (int i = 0;i < 1;i++) {
			agregarpika(pika);
		}
		tiempo = 100;
		cantP = 10;
		cantS = 4;
		cantU = 3;
		cantM = 1;
		contGotcha = 0;
	}

	~Controller(){}

	vector<Pikachu*> getPika() { return pikachu; }	
	int gettiempo() { return tiempo; }

	int getCantP() { return cantP; }
	int getCantS() { return cantS; }
	int getCantU() { return cantU; }
	int getCantM() { return cantM; }

	void reducirP() {  cantP--; }
	void reducirS() {  cantS--; }
	void reducirU() {  cantU--; }
	void reducirM() { cantM--; }

	int getPuntosAcumulados() { return contGotcha * 100; }

	vector<Pokeball*> getCantballs() { return this->ball; }
	vector<SuperBall*> getCantSballs() { return this->sball; }
	vector<UltraBall*> getCantUballs() { return this->uball; }
	vector<MasterBall*> getCantMballs() { return this->mball; }
	vector<Pikachu*> getCantPika() { return this->pikachu; }

	void setArrPika(vector<Pikachu*> vector) {
		this->pikachu = vector;
	}

	void setArrBalls(vector<Pokeball*> vector) {
		this->ball = vector;
	}

	void setArrSB(vector<SuperBall*> vector) {
		this->sball = vector;
	}

	void setArrUB(vector<UltraBall*> vector) {
		this->uball = vector;
	}

	void setArrMB(vector<MasterBall*> vector) {
		this->mball = vector;
	}

	void borrartodo() {
		pikachu.clear();
		ball.clear();
		sball.clear();
		uball.clear();
		mball.clear();
	}

	void agregarPokeball(Bitmap^ bola) {
		ball.push_back(new Pokeball(bola->Width / 3, bola->Height));
	}

	void agregarPokeTemp(Pokeball* poke) {
		ball.push_back(poke);
	}

	void agregarSuperBall(Bitmap^ sbola) {
		sball.push_back(new SuperBall(sbola->Width / 3, sbola->Height));
	}

	void agregarSuperTemp(SuperBall* spoke) {
		sball.push_back(spoke);
	}

	void agregarUltraBall(Bitmap^ ubola) {
		uball.push_back(new UltraBall(ubola->Width / 3, ubola->Height));
	}

	void agregarUltraTemp(UltraBall* upoke) {
		uball.push_back(upoke);
	}

	void agregarMasterBall(Bitmap^ mbola) {
		mball.push_back(new MasterBall(mbola->Width / 3, mbola->Height));
	}

	void agregarMasterTemp(MasterBall* mpoke) {
		mball.push_back(mpoke);
	}

	void agregarpika(Bitmap^ pika) {
		pikachu.push_back(new Pikachu(pika->Width / 4, pika->Height/4));
	}

	void agregarPikaTemp(Pikachu* pika) {
		pikachu.push_back(pika);
	}

	void drawEverything(Graphics^ g, Bitmap^ pika, Bitmap^ bola, Bitmap^ sbola, Bitmap^ ubola, Bitmap^ mbola) {
		for (int i = 0;i < pikachu.size();i++) {
			pikachu[i]->draw(g, pika);
		}
		for (int i = 0;i < ball.size();i++) {
			ball[i]->draw(g, bola);
		}
		for (int i = 0;i < sball.size();i++) {
			sball[i]->draw(g, sbola);
		}
		for (int i = 0;i < mball.size();i++) {
			mball[i]->draw(g, mbola);
		}
		for (int i = 0;i < uball.size();i++) {
			uball[i]->draw(g, ubola);
		}
	}

	void moverEverything(Graphics^ g) {
		for (int i = 0;i < ball.size();i++) {
			ball[i]->move(g);
		}
		for (int i = 0;i < sball.size();i++) {
			sball[i]->move(g);
		}
		for (int i = 0;i < uball.size();i++) {
			uball[i]->move(g);
		}
		for (int i = 0;i < mball.size();i++) {
			mball[i]->move(g, getPika());
		}
		for (int i = 0;i < pikachu.size();i++) {
			pikachu[i]->move(g);
		}
	}

	void colision(Graphics^ g, Bitmap^ pika) {
		for (int i = 0; i < pikachu.size(); i++) {
			for (int b = 0;b < ball.size();b++) {
				if (ball[b]->getRectangle().IntersectsWith(pikachu[i]->getRectangle())) {
					pikachu.erase(pikachu.begin() + i);
					agregarpika(pika);
					contGotcha++;
				}
			}
		}
		for (int i = 0; i < pikachu.size(); i++) {
			for (int sb = 0;sb < sball.size();sb++) {
				if (sball[sb]->getRectangle().IntersectsWith(pikachu[i]->getRectangle())) {
					pikachu.erase(pikachu.begin() + i);
					agregarpika(pika);
					contGotcha++;
				}
			}
		}
		for (int i = 0; i < pikachu.size(); i++) {
			for (int ub = 0;ub < uball.size();ub++) {
				if (uball[ub]->getRectangle().IntersectsWith(pikachu[i]->getRectangle())) {
					pikachu.erase(pikachu.begin() + i);
					agregarpika(pika);
					contGotcha++;
				}
			}
		}
		for (int i = 0; i < pikachu.size(); i++) {
			for (int mb = 0;mb < mball.size();mb++) {
				if (mball[mb]->getRectangle().IntersectsWith(pikachu[i]->getRectangle())) {
					pikachu.erase(pikachu.begin() + i);
					agregarpika(pika);
					contGotcha++;
				}
				if (mball[mb]->getContChoque() == 3) {
					pikachu.erase(pikachu.begin() + i);
					agregarpika(pika);
					contGotcha++;
				}
			}
		}
	}

	void colisioneEntrePokeball() {
		//POKEBALL
		for(int i=0;i<ball.size();i++){
			for(int j=0;j<sball.size();j++){
				if (ball[i]->getRectangle().IntersectsWith(sball[j]->getRectangle())) {
					ball.erase(ball.begin() + i);
					sball.erase(sball.begin() + j);
				}
			}
			for (int j = 0;j < uball.size();j++) {
				if (ball[i]->getRectangle().IntersectsWith(uball[j]->getRectangle())) {
					ball.erase(ball.begin() + i);
					uball.erase(uball.begin() + j);
				}
			}
			for (int j = 0;j < mball.size();j++) {
				if (ball[i]->getRectangle().IntersectsWith(mball[j]->getRectangle())) {
					ball.erase(ball.begin() + i);
					mball.erase(mball.begin() + j);
				}
			}
		}
		//SUPER BALL
		for (int i = 0;i < sball.size();i++) {
			for (int j = 0;j < ball.size();j++) {
				if (sball[i]->getRectangle().IntersectsWith(ball[j]->getRectangle())) {
					sball.erase(sball.begin() + i);
					ball.erase(ball.begin() + j);
				}
			}
			for (int j = 0;j < uball.size();j++) {
				if (sball[i]->getRectangle().IntersectsWith(uball[j]->getRectangle())) {
					sball.erase(sball.begin() + i);
					uball.erase(uball.begin() + j);
				}
			}
			for (int j = 0;j < mball.size();j++) {
				if (sball[i]->getRectangle().IntersectsWith(mball[j]->getRectangle())) {
					sball.erase(sball.begin() + i);
					mball.erase(mball.begin() + j);
				}
			}
		}
		////ULTRA BALL
		for (int i = 0;i < uball.size();i++) {
			for (int j = 0;j < ball.size();j++) {
				if (uball[i]->getRectangle().IntersectsWith(ball[j]->getRectangle())) {
					uball.erase(uball.begin() + i);
					ball.erase(ball.begin() + j);
				}
			}
			for (int j = 0;j < sball.size();j++) {
				if (uball[i]->getRectangle().IntersectsWith(sball[j]->getRectangle())) {
					uball.erase(uball.begin() + i);
					sball.erase(sball.begin() + j);
				}
			}
			for (int j = 0;j < mball.size();j++) {
				if (uball[i]->getRectangle().IntersectsWith(mball[j]->getRectangle())) {
					uball.erase(uball.begin() + i);
					mball.erase(mball.begin() + j);
				}
			}
		}
		////MASTER BALL
		for (int i = 0;i < mball.size();i++) {
			for (int j = 0;j < ball.size();j++) {
				if (mball[i]->getRectangle().IntersectsWith(ball[j]->getRectangle())) {
					mball.erase(mball.begin() + i);
					ball.erase(ball.begin() + j);
				}
			}
			for (int j = 0;j < sball.size();j++) {
				if (mball[i]->getRectangle().IntersectsWith(sball[j]->getRectangle())) {
					mball.erase(mball.begin() + i);
					sball.erase(sball.begin() + j);
				}
			}
			for (int j = 0;j < uball.size();j++) {
				if (mball[i]->getRectangle().IntersectsWith(uball[j]->getRectangle())) {
					mball.erase(mball.begin() + i);
					uball.erase(uball.begin() + j);
				}
			}
		}
	}

	void colisionFINAL() {
		//POKEBALL
		for (int i = 0; i < ball.size(); i++) {
			for (int j = i + 1; j < ball.size(); j++) {
				if (ball[i]->getRectangle().IntersectsWith(ball[j]->getRectangle())) {
					ball[i]->setVisible(false);
					ball[j]->setVisible(false);
				}
			}
		}
		for (int i = 0; i < ball.size(); i++) {
			for (int j = 0; j < sball.size(); j++) {
				if (ball[i]->getRectangle().IntersectsWith(sball[j]->getRectangle())) {
					ball[i]->setVisible(false);
					sball[j]->setVisible(false);
				}
			}
		}

		for (int i = 0; i < ball.size(); i++) {
			for (int j = 0; j < uball.size(); j++) {
				if (ball[i]->getRectangle().IntersectsWith(uball[j]->getRectangle())) {
					ball[i]->setVisible(false);
					uball[j]->setVisible(false);
				}
			}
		}
		for (int i = 0; i < ball.size(); i++) {
			for (int j = 0; j < mball.size(); j++) {
				if (ball[i]->getRectangle().IntersectsWith(mball[j]->getRectangle())) {
					ball[i]->setVisible(false);
					mball[j]->setVisible(false);
				}
			}
		}
		//SUPERBALL
		for (int i = 0; i < sball.size(); i++) {
			for (int j = i + 1; j < sball.size(); j++) {
				if (sball[i]->getRectangle().IntersectsWith(sball[j]->getRectangle())) {
					sball[i]->setVisible(false);
					sball[j]->setVisible(false);
				}
			}
		}
		for (int i = 0; i < sball.size(); i++) {
			for (int j = 0; j < uball.size(); j++) {
				if (sball[i]->getRectangle().IntersectsWith(uball[j]->getRectangle())) {
					sball[i]->setVisible(false);
					uball[j]->setVisible(false);
				}
			}
		}
		for (int i = 0; i < sball.size(); i++) {
			for (int j = 0; j < mball.size(); j++) {
				if (sball[i]->getRectangle().IntersectsWith(mball[j]->getRectangle())) {
					sball[i]->setVisible(false);
					mball[j]->setVisible(false);
				}
			}
		}
		//ULTRABALL
		for (int i = 0; i < uball.size(); i++) {
			for (int j = i + 1; j < uball.size(); j++) {
				if (uball[i]->getRectangle().IntersectsWith(uball[j]->getRectangle())) {
					uball[i]->setVisible(false);
					uball[j]->setVisible(false);
				}
			}
		}
		for (int i = 0; i < uball.size(); i++) {
			for (int j = 0; j < mball.size(); j++) {
				if (uball[i]->getRectangle().IntersectsWith(mball[j]->getRectangle())) {
					uball[i]->setVisible(false);
					mball[j]->setVisible(false);
				}
			}
		}
		//MASTER BALL
		for (int i = 0; i < mball.size(); i++) {
			for (int j = i + 1; j < mball.size(); j++) {
				if (mball[i]->getRectangle().IntersectsWith(mball[j]->getRectangle())) {
					mball[i]->setVisible(false);
					mball[j]->setVisible(false);
				}
			}
		}
		for (int i = 0; i < ball.size(); i++) {
			if (ball[i]->getVisible() == false) {
				ball.erase(ball.begin() + i);
			}
		}
		for (int i = 0; i < sball.size(); i++) {
			if (sball[i]->getVisible() == false) {
				sball.erase(sball.begin() + i);
			}
		}
		for (int i = 0; i < uball.size(); i++) {
			if (uball[i]->getVisible() == false) {
				uball.erase(uball.begin() + i);
			}
		}
		for (int i = 0; i < mball.size(); i++) {
			if (mball[i]->getVisible() == false) {
				mball.erase(mball.begin() + i);
			}
		}
	}
};