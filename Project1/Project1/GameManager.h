#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Manager.h"

// D e f a u l t frame t ime ( game l o o p t ime ) i n m i l l i s e c o n d s (3 3 ms == 30 f / s ) .
 const int FRAME_TIME_DEFAULT = 33;

#define GM df::GameManager::getInstance()

 namespace df {
	 class GameManager : public Manager {

	 private:
		 GameManager(); // P r i v a t e s i n c e a s i n g l e t o n .
		 GameManager(GameManager const&); // Don ’ t a l l o w copy .
		 void operator =(GameManager const&); // Don ’ t a l l o w a s s i g nm e n t .
		 bool game_over; // True , t h e n game l o o p s h o u l d s t o p .
		 int frame_time; // T a rge t t ime p e r game l o o p , i n m i l l i s e c o n d s .

	 public:

		 static GameManager& getInstance();

		 int startUp();

		 void shutDown();

		 void run();

		 void setGameOver(bool new_game_over = true);

		 bool getGameOver() const;

		 int getFrameTime() const;

		 void testGameManager();
	 };

 }