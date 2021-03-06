#include "stdafx.h"
#include "utils.h"
using namespace std;
#pragma warning(disable : 4996)

int offset = 0;
int main()
{
	Utils::Initialize();

	Interpreter in;
	in.cm = Utils::GetCatalogManager();

	API ap;
	ap.cm = Utils::GetCatalogManager();
	ap.im = Utils::GetIndexManager();
	ap.rm = Utils::GetRecordManager();
	ap.cm->SetBM(Utils::GetBufferManager());
	ap.rm->bm = Utils::GetBufferManager();
	ap.rm->api = &ap;

	ap.ip = &in;
	in.ap = &ap;

	cout << "************************" << endl;
	cout << "*        miniSQL       *" << endl;
	cout << "************************" << endl;
	cout << "*     Contributors     *" << endl;
	cout << "*    SDW WSZ LJH KZY   *" << endl;
	cout << "************************\n" << endl;
	//freopen("a.txt", "w", stdout);
	int p = sizeof(float);
	do {
		cout << "miniSQL >";
		in.read();
		//cout << in.s << endl;
	} while (!in.syntax());
	//fclose(stdout);
	Utils::DeleteUtils();
	return 0;
}

