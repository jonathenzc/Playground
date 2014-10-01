#include <iostream>
#include <string>

using namespace std;

bool isCheckedOnRow(char **table, int i, int j, bool iskOrK)
{
	int col = j - 1;

	while (col >= 0)//left row
	{
		if (iskOrK && (table[i][col] == 'R' || table[i][col] == 'Q'))
			return true;
		else if (!iskOrK && (table[i][col] == 'r' || table[i][col] == 'q'))
			return true;
		else if (table[i][col] != '.')
			break;

		col--;
	}

	col = j + 1;
	while (col < 8)//left row
	{
		if (iskOrK && (table[i][col] == 'R' || table[i][col] == 'Q'))
			return true;
		else if (!iskOrK && (table[i][col] == 'r' || table[i][col] == 'q'))
			return true;
		else if (table[i][col] != '.')
			return false;

		col++;
	}

	return false;
}

bool isCheckedOnCol(char **table, int i, int j, bool iskOrK)
{
	int row = i - 1;

	while (row >= 0)//upper row
	{
		if (iskOrK && (table[row][j] == 'R' || table[row][j] == 'Q'))
			return true;
		else if (!iskOrK && (table[row][j] == 'r' || table[row][j] == 'q'))
			return true;
		else if (table[row][j] != '.')
			break;

		row--;
	}

	row = i + 1;
	while (row < 8)//lower row
	{
		if (iskOrK && (table[row][j] == 'R' || table[row][j] == 'Q'))
			return true;
		else if (!iskOrK && (table[row][j] == 'r' || table[row][j] == 'q'))
			return true;
		else if (table[row][j] != '.')
			return false;

		row++;
	}

	return false;
}

//check on oblique line
bool isCheckedOnObl(char **table, int i, int j, bool iskOrK)
{
	//left up row
	int row = i - 1;
	int col = j - 1;

	while (row >= 0 && col >=0)
	{
		if (iskOrK && (table[row][col] == 'P' || table[row][col] == 'Q' || table[row][col] == 'B'))
			return true;
		else if (!iskOrK && (table[row][col] == 'p' || table[row][col] == 'q' || table[row][col] == 'b'))
			return true;
		else if (table[row][col] != '.')
			break;

		row--;
		col--;
	}

	//right up row
	row = i - 1;
	col = j + 1;
	while (row >= 0 && col < 8)
	{
		if (iskOrK && (table[row][col] == 'P' || table[row][col] == 'Q' || table[row][col] == 'B'))
			return true;
		else if (!iskOrK && (table[row][col] == 'p' || table[row][col] == 'q' || table[row][col] == 'b'))
			return true;
		else if (table[row][col] != '.')
			break;

		row--;
		col++;
	}

	//left down row
	row = i + 1;
	col = j - 1;
	while (row < 8 && col >= 0)
	{
		if (iskOrK && (table[row][col] == 'P' || table[row][col] == 'Q' || table[row][col] == 'B'))
			return true;
		else if (!iskOrK && (table[row][col] == 'p' || table[row][col] == 'q' || table[row][col] == 'b'))
			return true;
		else if (table[row][col] != '.')
			break;

		row++;
		col--;
	}
	//right down row
	row = i + 1;
	col = j + 1;
	while (row < 8 && col < 8)
	{
		if (iskOrK && (table[row][col] == 'P' || table[row][col] == 'Q' || table[row][col] == 'B'))
			return true;
		else if (!iskOrK && (table[row][col] == 'p' || table[row][col] == 'q' || table[row][col] == 'b'))
			return true;
		else if (table[row][col] != '.')
			return false;

		row++;
		col++;
	}

	return false;
}

bool isInBoard(int i, int j)
{
	if (i >= 0 && i < 8 && j >= 0 && j < 8)
		return true;
	else
		return false;
}

//check on knight line
bool isCheckedOnKnightLine(char **table, int i, int j, bool iskOrK)
{
	int row[8] = {i-1,i-1,i-2,i-2,i+1,i+1,i+2,i+2};
	int col[8] = {j-2,j+2,j-1,j+1,j-2,j+2,j-1,j+1};

	for (int k = 0; k < 8; k++)
	{
		if (isInBoard(row[k], col[k]) && iskOrK && table[row[k]][col[k]] == 'N')
			return true;
		else if (isInBoard(row[k], col[k]) && !iskOrK && table[row[k]][col[k]] == 'n')
			return true;
		
		if (k == 7)
			return false;

	}
}

bool isKingChecked(char **table,int i, int j, bool iskOrK)
{
	if (isCheckedOnRow(table, i, j, iskOrK))
		return true;
	else if (isCheckedOnCol(table, i, j, iskOrK))
		return true;
	else if (isCheckedOnObl(table, i, j, iskOrK))
		return true;
	else if (isCheckedOnKnightLine(table, i, j, iskOrK))
		return true;
	else
		return false;
}


int main()
{
	char **chessBoard = new char*[8];
	for (int i = 0; i < 8; i++)
		chessBoard[i] = new char[8];

	string table="..k.b...ppp.............r....B................P......P.P.....RK."; //Black
	//string table = "rnbqk.nrpppp.ppp..........b.p..Q..B.P...........PPPP.PPPRNB.K.NR"; //None
	//string table = "..r.........k.......p.....p..........................nPP..B...RK"; //White
	int KiIndex;
	int KjIndex;
	int kiIndex;
	int kjIndex;

	//turn string to a 2D array and record index of k and K
	for (int i = 0; i < table.size(); i++)
	{
		chessBoard[i/8][i%8] = table[i];

		if (table[i] == 'K')
		{
			KiIndex = i/8;
			KjIndex = i%8;
		}

		if (table[i] == 'k')
		{
			kiIndex = i/8;
			kjIndex = i%8;
		}
	}

	//for (int i = 0; i < 8; i++)
	//{
	//	for (int j = 0; j < 8; j++)
	//		cout << chessBoard[i][j]<<" ";

	//	cout << endl;
	//}

	//cout << KiIndex << " " << KjIndex << " " << kiIndex << " " << kjIndex;

	if (isKingChecked(chessBoard, kiIndex, kjIndex, true))
		cout << "Black";
	else if (isKingChecked(chessBoard, KiIndex, KjIndex, false))
		cout << "White";
	else
		cout << "None";

	return 0;
}