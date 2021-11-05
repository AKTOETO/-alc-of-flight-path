#include "../stdafx.h"
#include "textObj.h"

textObj::textObj(TextData data)
{
	m_textData = data;

	// font loading
	if (!m_font.loadFromFile("assets/fonts/main.ttf"))
	{
		cout << "did'n load main.ttf\n";
	}

	// setting up text
	m_text.setFont(m_font);
	m_text.setStyle(m_textData.style);
	m_text.setString(m_textData.str);
	m_text.setFillColor(m_textData.color);
	m_text.setCharacterSize(m_textData.size);
}

textObj::~textObj()
{
}

void textObj::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_text, states);
}
