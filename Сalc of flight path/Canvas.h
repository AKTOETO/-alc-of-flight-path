#pragma once
#include "stdafx.h"

typedef pair<Vertex, Vertex> VV;
typedef vector<vector<double>> vvd;

class Canvas : public Drawable
{
private:
	vector<vector<VertexArray>> m_graphs;

public:
	Canvas();
	~Canvas();

	vector<VertexArray> createGraph(Color, string);
	VertexArray createLine(Color, vvd);

	void processLogic();
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const override;
};

