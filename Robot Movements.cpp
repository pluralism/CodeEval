#include <iostream>
using namespace std;


int caminhos(bool board[4][4], int x, int y, int w, int h)
{
	if (board[x][y])
		return 0;

	if (x == w - 1 && y == h - 1)
		return 1;

	int contagem = 0;
	board[x][y] = 1;

	if (x > 0)
		contagem += caminhos(board, x - 1, y, w, h);

	if (x < w - 1)
		contagem += caminhos(board, x + 1, y, w, h);

	if (y > 0)
		contagem += caminhos(board, x, y - 1, w, h);

	if (y < h - 1)
		contagem += caminhos(board, x, y + 1, w, h);

	board[x][y] = 0;

	return contagem;
}

int main(int argc, char* argv[])
{
	bool board[4][4] = { 0 };

	cout << caminhos(board, 0, 0, 4, 4);

	return 0;
}

