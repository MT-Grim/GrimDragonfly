#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/Color.hpp>

#include "DisplayManager.h"
#include "LogManager.h"

namespace df {

	DisplayManager::DisplayManager() {

		m_p_window = NULL;
		
	}

	DisplayManager& DisplayManager::getInstance() {

		static DisplayManager instance;
		return instance;

	}

	int DisplayManager::startUp() {

		if (m_p_window != NULL) {

			return 0;

		}

		m_p_window = new sf::RenderWindow;

		m_p_window->setMouseCursorVisible(false);

		m_p_window->setVerticalSyncEnabled(true);

		m_font.loadFromFile(FONT_FILE_DEFAULT);

		if (m_font.loadFromFile(FONT_FILE_DEFAULT)) {

			LM.writeLog("Font File Loaded");

		}

		if ( m_font.loadFromFile(FONT_FILE_DEFAULT) && m_p_window != NULL) { //ask how to do this.

			Manager::startUp();

			return 0;

		}
		else {

			return -1;

		}
	}

	void DisplayManager::shutDown() {

		m_p_window->close();
	
	}

	int DisplayManager::getHorizontal() const {

		return m_window_horizontal_chars;

	}

	int DisplayManager::getVertical() const {

		return m_window_vertical_chars;

	}

	int DisplayManager::getHorizontalPixels() const {

		return m_window_horizontal_pixels;

	}

	int DisplayManager::getVerticalPixels() const {

		return m_window_horizontal_pixels;

	}

	sf::RenderWindow* DisplayManager::getWindow() const {

		return m_p_window;

	}

	float charHeight() {

		df::DisplayManager &dm = DM.getInstance();
		
		//vert pixels / vert characters

		return dm.getVerticalPixels() / dm.getVertical();

	}

	float charWidth() {

		df::DisplayManager& dm = DM.getInstance();

		//vert pixels / vert characters

		return dm.getHorizontalPixels() / dm.getHorizontal();

	}

	Vector spacesToPixels(Vector spaces) {


		return Vector(spaces.getX() * df::charWidth(), spaces.getY() * df::charHeight());

	}

	Vector pixelsToSpaces(Vector pixels) {


		return Vector(pixels.getX() / df::charWidth(), pixels.getY() / df::charHeight());

	}

	int DisplayManager::drawCh(Vector world_pos, char ch, Color color) const {

		if (m_p_window == NULL) {

			return -1;

		}

		Vector pixel_pos = spacesToPixels(world_pos);

		static sf::RectangleShape rectangle;

		rectangle.setSize(sf::Vector2f(charWidth(), charHeight()));

		rectangle.setFillColor(WINDOW_BACKGROUND_COLOR_DEFAULT);

		rectangle.setPosition(pixel_pos.getX() - charWidth() / 10, pixel_pos.getY() + charHeight() / 5);

		m_p_window->draw(rectangle);

		static sf::Text text("", m_font);
		text.setString(ch);
		text.setStyle(sf::Text::Bold);

		if (charWidth() < charHeight()) {

			text.setCharacterSize(charWidth() * 2);

		}
		else {

			text.setCharacterSize(charHeight() * 2);

		}

		switch (color) {
		case YELLOW:
			text.setFillColor(sf::Color::Yellow);
			break;
		case RED:
			text.setFillColor(sf::Color::Red);
			break;
		case GREEN:
			text.setFillColor(sf::Color::Green);
			break;
		case BLUE:
			text.setFillColor(sf::Color::Blue);
			break;
		case MAGENTA:
			text.setFillColor(sf::Color::Magenta);
			break;
		case CYAN:
			text.setFillColor(sf::Color::Cyan);
			break;
		default:
			WHITE;
		}

		text.setPosition(pixel_pos.getX(), pixel_pos.getY());

		return 0;

	}

	int DisplayManager::swapBuffers() {

		if (m_p_window == NULL) {

			return -1;

		}

		m_p_window->display();

		m_p_window->clear();

		return 0;

	}
}
