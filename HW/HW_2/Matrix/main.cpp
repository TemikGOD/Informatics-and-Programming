#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<pair<string, pair <vector<vector<int>>, int>>> MyMatrices;

void showMenu()
{
	system("cls");
	cout << "\tTriangle Matrix Menu" << endl << endl;
	cout << "1 - Show my matrices" << endl;
	cout << "2 - Create matrix" << endl;
	cout << "3 - Sum matrces" << endl;
	cout << "4 - Subtract matrices" << endl;
	cout << "5 - Multyply by matrix" << endl;
	cout << "6 - Multyply by vector" << endl;
	cout << "7 - Transpose matrix" << endl;
	cout << "8 - Delete Matrix" << endl;
	cout << "0 - Exit" << endl;
	cout << "Insert number from menu: ";
}

void printMatrix(vector<vector<int>> _matrix)
{
	for (int i = 0; i != _matrix.size(); i++)
	{
		for (int j = 0; j != _matrix[i].size(); j++)
			cout << _matrix[i][j] << "\t";
		cout << endl;
	}
}

void showMyMatrices()
{
	if (MyMatrices.empty())
		cout << "You don't have any" << endl;
	else
	{
		for (int i = 0; i != MyMatrices.size(); i++)
		{
			cout << MyMatrices[i].first << endl;
			printMatrix(MyMatrices[i].second.first);
		}
	}
}

void createMatrix()
{
	system ("cls");
	pair<string, pair<vector<vector<int>>, unsigned int>> matrix;
	int degree, lu;
	cout << "Your's Matrix name: ";
	cin >> matrix.first;
	cout << endl;
	while (true)
	{
		cout << "Your Matrix is:\n1 - Lower\n2 - Upper" << endl;
		string number;
		cin >> number;
		try
		{
			lu = stoi(number);
		}
		catch (exception& e)
		{
			lu = 0;
		}
		if (lu != 1 && lu != 2)
			cout << "Incorect value, try again" << endl;
		else
			break;
	}
	while (true)
	{
		cout << "Your Matrix degree: ";
		string number;
		cin >> number;
		try
		{
			degree = stoi(number);
		}
		catch (exception&)
		{
			degree = 0;
		}
		if (degree < 1)
			cout << "Incorect value, try again" << endl;
		else
			break;
	}
	if (lu == 1)
	{
		for (int i = 0; i < degree; i++)
		{
			vector<int> vec;
			for (int j = 0; j <= i; j++)
			{
				int value;
				while (true)
				{
					cout << "Insert value: ";
					string _value;
					bool exit = 1;
					cin >> _value;
					try
					{
						value = stoi(_value);
					}
					catch (const exception&)
					{
						cout << "Incorect value, try again" << endl;
						exit = 0;
					}
					if (exit)
						break;
				}
				vec.push_back(value);
			}
			cout << endl;
			for (int v = degree - 1; v > i; v--)
				vec.push_back(0);
			matrix.second.first.push_back(vec);
		}
	}
	else
	{
		for (int i = 0; i < degree; i++)
		{
			vector<int> vec;
			for (int j = degree; j > i; j--)
			{
				int value;
				while (true)
				{
					cout << "Insert value: ";
					string _value;
					bool exit = 1;
					cin >> _value;
					try
					{
						value = stoi(_value);
					}
					catch (const exception&)
					{
						cout << "Incorect value, try again" << endl;
						exit = 0;
					}
					if (exit)
						break;
				}
				vec.push_back(value);
			}
			cout << endl;
			for (int v = degree - i; v < degree; v++)
				vec.insert(vec.begin(), 0);
			matrix.second.first.push_back(vec);
		}
	}
	matrix.second.second = degree;
	MyMatrices.push_back(matrix);
}

bool checkMatrices()
{
	int sameDeg = 0;
	for (int i = 0; i < MyMatrices.size() - 1; i++)
		for (int j = i + 1; j < MyMatrices.size(); j++)
			if (MyMatrices[i].second.second - 1 == MyMatrices[j].second.second - 1)
			{
				sameDeg++;
				break;
			}
	if (sameDeg > 0)
		return 1;
	else
		return 0;
}

int chooseMatrix()
{
	if (MyMatrices.size() < 1)
	{
		cout << "You need at least one matrix for this" << endl;
		system("pause");
	}
	else
		cout << "Choose matrix" << endl;
	for (int i = 0; i < MyMatrices.size(); i++)
		cout << i + 1 << " " << MyMatrices[i].first << endl;
	int mat;
	while (true)
	{
		cout << "Matrix: ";
		string _mat;
		cin >> _mat;
		try
		{
			mat = stoi(_mat);
		}
		catch (const exception&)
		{
			mat = 0;
		}
		mat--;
		if (mat < 0 || mat > MyMatrices.size() - 1)
			cout << "Incorect value, try again" << endl;
		else
			if (MyMatrices[mat].second.second < 0)
				cout << "You cant choose vector" << endl;
			else
				return mat;
	}

}

void sumMatrices()
{
	if (checkMatrices())
	{
		int matFirst = chooseMatrix();
		int matSecond = chooseMatrix();
		vector<vector<int>> sumFSMat;
		for (int i = 0; i < MyMatrices[matFirst].second.second; i++)
		{
			vector<int> vec;
			for (int j = 0; j < MyMatrices[matFirst].second.second; j++)
				vec.push_back(MyMatrices[matFirst].second.first[i][j] + MyMatrices[matSecond].second.first[i][j]);
			sumFSMat.push_back(vec);
		}
		pair<string, pair <vector<vector<int>>, int>> sumFS;
		sumFS = { MyMatrices[matFirst].first + "+" + MyMatrices[matSecond].first, {sumFSMat, MyMatrices[matFirst].second.second} };
		MyMatrices.push_back(sumFS);
	}
	else
	{
		cout << "You need to create at least 2 matrices with same degree" << endl;
		system("pause");
	}
}

void substractMatrices()
{
	if (checkMatrices())
	{
		int matFirst = chooseMatrix();
		int matSecond = chooseMatrix();
		vector<vector<int>> subFSMat;
		for (int i = 0; i < MyMatrices[matFirst].second.second; i++)
		{
			vector<int> vec;
			for (int j = 0; j < MyMatrices[matFirst].second.second; j++)
				vec.push_back(MyMatrices[matFirst].second.first[i][j] - MyMatrices[matSecond].second.first[i][j]);
			subFSMat.push_back(vec);
		}
		pair<string, pair <vector<vector<int>>, int>> subFS;
		subFS = { MyMatrices[matFirst].first + "-" + MyMatrices[matSecond].first, {subFSMat, MyMatrices[matFirst].second.second} };
		MyMatrices.push_back(subFS);
	}
	else
	{
		cout << "You need to create at least 2 matrices with same degree" << endl;
		system("pause");
	}
}

void multyplyMatrix()
{
	if (checkMatrices())
	{
		int matFirst = chooseMatrix();
		int matSecond = chooseMatrix();
		vector<vector<int>> mulFSMat;
		for (int i = 0; i < MyMatrices[matFirst].second.second; i++)
		{
			vector<int> vec;
			for (int j = 0; j < MyMatrices[matFirst].second.second; j++)
			{
				int value = 0;
				for (int k = 0; k < MyMatrices[matFirst].second.second; k++)
					value += MyMatrices[matFirst].second.first[i][k] * MyMatrices[matSecond].second.first[k][j];
				vec.push_back(value);
			}
			mulFSMat.push_back(vec);
		}
		pair<string, pair <vector<vector<int>>, int>> mulFS;
		mulFS = { MyMatrices[matFirst].first + "*" + MyMatrices[matSecond].first, {mulFSMat, MyMatrices[matFirst].second.second} };
		MyMatrices.push_back(mulFS);
	}
	else
	{
		cout << "You need to create at least 2 matrices with same degree" << endl;
		system("pause");
	}
}

void multiplyMatByVec()
{
	int mat = chooseMatrix();
	vector<int> vec;
	string vecName;
	cout << "Your vector name: ";
	cin >> vecName;
	for (int i = 0; i < MyMatrices[mat].second.second; i++)
	{
		int value;
		while (true)
		{
			string _value;
			bool exit = 1;
			cout << "Insert value: ";
			cin >> _value;
			try
			{
				value = stoi(_value);
			}
			catch (const exception&)
			{
				cout << "Incorect value, try again" << endl;
				exit = 0;
			}
			if (exit)
				break;
		}
	}
	for (int i = 0; i < MyMatrices[mat].second.second; i++)
	{
		int value = 0;
		for (int j = 0; j < MyMatrices[mat].second.second; j++)
		{
			value += MyMatrices[mat].second.first[i][j] * vec[j];
		vec.push_back(value);
		}
	}
	vector<vector<int>> _vec{ vec };
	MyMatrices.push_back({ MyMatrices[mat].first + "*" + vecName, {_vec , -MyMatrices[mat].second.second} });
}

void transposeMatrix()
{
	int mat = chooseMatrix();
	vector<vector<int>> matT;
	for (int i = 0; i < MyMatrices[mat].second.second; i++)
	{
		vector<int> vec;
		for (int j = 0; j < MyMatrices[mat].second.second; j++)
			vec.push_back(MyMatrices[mat].second.first[j][i]);
		matT.push_back(vec);
	}
	pair<string, pair <vector<vector<int>>, int>> _matT = { "Transposed_" + MyMatrices[mat].first, {matT, MyMatrices[mat].second.second}};
	MyMatrices.push_back(_matT);
}

void deleteMatrix()
{
	int mat = chooseMatrix();
	MyMatrices.erase(MyMatrices.begin() + mat);
}

int main()
{
	int switch_on = 1;
	while (switch_on != 0)
	{
		showMenu();
		cin >> switch_on;
		switch (switch_on)
		{
		case 1:
		{
			system("cls");
			showMyMatrices();
			system("pause");
			break;
		}
		case 2:
		{
			createMatrix();
			break;
		}
		case 3:
		{
			sumMatrices();
			break;
		}
		case 4:
		{
			substractMatrices();
			break;
		}
		case 5:
		{
			multyplyMatrix();
			break;
		}
		case 6:
		{
			multiplyMatByVec();
			break;
		}
		case 7:
		{
			transposeMatrix();
			break;
		}
		case 8:
		{
			if (MyMatrices.size() == 0)
			{
				cout << "To do this, you need to create at least one matrix" << endl;
				system("pause");
			}
			else
				deleteMatrix();
			break;
		}
		case 0:
		{
			break;
		}
		default:
		{
			cout << "Incorect value, try again" << endl;
			system("pause");
			break;
		}
		}
	}
}