#include <iostream>
#include <vector>
using namespace std;

class penerbit;
class pengarang {
public:
	string nama;
	vector<penerbit*> daftar_penerbit;
	pengarang(string pNama) :nama(pNama) {
		cout << "pengarang \"" << nama << "\" tidak ada\n";
	}
	~pengarang() {
		cout << "pengarang \"" << nama << "\" tidak ada\n";
	}
	void tambahpenerbit(penerbit*);
	void cetakpenerbit();
};
class penerbit {
public:
	string nama;
	vector<pengarang*> daftar_pengarang;
	penerbit(string pNama) :nama(pNama) {
		cout << "penerbit \"" << nama << "\" ada\n";
	}
	~penerbit() {
		cout << "penerbit \"" << nama << "\" tidak ada\n";
	}
	void tambahpengarang(pengarang*);
	void cetakpengarang();
};
void pengarang::tambahpenerbit(penerbit* ppenerbit) {
	daftar_penerbit.push_back(ppenerbit);
}
void pengarang::cetakpenerbit() {
	cout << "Daftar pengarang pada penerbit \"" << this->nama << "\":n";
	for (auto& a : daftar_penerbit) {
		cout << a->nama << "\n";
	}
	cout << endl;
}
void penerbit::tambahpengarang(pengarang* ppengarang) {
	daftar_pengarang.push_back(ppengarang);
	ppengarang->tambahpenerbit(this);
}
void penerbit::cetakpengarang() {
	cout << "Daftar penerbit yang diikuti Giga \"" << this->nama << "\":\n";
	for (auto& a : daftar_pengarang) {
		cout << a->nama << "\n";
	}
	cout << endl;
}


int main() {
	penerbit* varpenerbit1 = new penerbit("joko,lia,giga");
	penerbit* varpenerbit2 = new penerbit("asroni,giga");
	pengarang* varPengarang1 = new pengarang("Andi");
	pengarang* varPengarang2 = new pengarang("Lia");

	varpenerbit1->tambahpengarang(varPengarang1);
	varpenerbit2->tambahpengarang(varPengarang2);

	return 0;
}