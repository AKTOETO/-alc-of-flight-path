#include "stdafx.h"
#include "Canvas.h"

void load_coords(vvd& coords, string file = "1.txt");

Canvas::Canvas()
{
	m_graphs.resize(0);
	m_graphs.push_back(createGraph(Color::Magenta, "1.txt"));
	m_graphs.push_back(createGraph(Color::Red, "2.txt"));
	m_graphs.push_back(createGraph(Color::Blue, "3.txt"));

	cout << "Canvas created\n";
}

Canvas::~Canvas()
{
	cout << "Canvas destructed\n";
}

vector<VertexArray> Canvas::createGraph(Color color, string file)
{
	cout << "\t\t====== creating  graph ======\n";
	vector<VertexArray> line;

	vvd coords;
	load_coords(coords, file);

	for (int j = 0,i = 0; i < coords.size() - 1; i++)
	{
		if (abs(coords[i][1] - coords[i + 1][1]) > 100 || i == coords.size() - 2)
		{
			vvd tcoords(coords.begin() + j, coords.begin() + i + 1);
			line.push_back(createLine(color, tcoords));
			j = i + 1;
		}
	}
	cout << "\t\t====== graph's created ======\n\n";
	return line;
}

VertexArray Canvas::createLine(Color color, vvd coords)
{
	cout << "\t\t====== creating  line ======\n";

	VertexArray graph(LinesStrip);

	for (int i = 0; i < coords.size(); i++)
	{
		double coordX = (WIDTH / 2 + coords[i][1] * CELLX); // o
		double coordY = (HEIGHT / 2 - coords[i][0] * CELLY); // i
		cout << "|point #" << fixed << setw(2) << setfill(' ') << i
			<< "| |x: " << setprecision(3) << setw(8) << setfill(' ') << coordX
			<< "| |y: " << setprecision(3) << setw(8) << setfill(' ') << coordY
			<< "| |i: " << setprecision(3) << setw(8) << setfill(' ') << coords[i][0]
			<< "| |o: " << setprecision(3) << setw(8) << setfill(' ') << coords[i][1]
			<< "|\n";
		graph.append(Vertex(Vector2f(coordX, coordY), color));
	}
	cout << "\t\t====== line's created ======\n";
	return graph;
}

void Canvas::processLogic()
{
}

void Canvas::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (auto el : m_graphs)
		for (auto pel : el)
			target.draw(pel, states);
}

void load_coords(vvd& coords, string file)
{
	ifstream fin("assets/coordinates/" + file);
	coords.resize(0);
	while (!fin.eof())
	{
		double i, o;
		fin >> i >> o;
		coords.push_back(vector<double>{i, o});
		//cout << "i: " << i << " o: " << o << endl;
	}
}