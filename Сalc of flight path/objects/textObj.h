#pragma once
#include "../stdafx.h"

struct TextData
{
	Vector2f pos = { 0, 0 };
	int size = 10;
	Color color = Color::White;
	Uint32 style = sf::Text::Bold;
	string str = "none";

	TextData() {};

	TextData(const TextData& text)
	{
		pos = text.pos;
		size = text.size;
		color = text.color;
		style = text.style;
		str = text.str;
	}

	TextData& operator=(TextData& text)
	{
		pos = text.pos;
		size = text.size;
		color = text.color;
		style = text.style;
		str = text.str;
		return *this;
	}
};

class textObj : public Drawable
{
private:
	TextData m_textData;
	Text m_text;
	Font m_font;

public:
	textObj(TextData);
	~textObj();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

