#include<iostream>
#include<fstream>

using namespace std;

class table{
public:
	unsigned short int value[9][9];
	unsigned short int row_num, col_num;
	void printTable();
	void inputValue();
	void setGame();
	bool finish();
};


int main(){
	table *t;
	t->setGame();
	while (!(t->finish())){
		t->inputValue();
		t->printTable();
	}
	return 0;
}

void table::setGame(){
	table *t = new table;
	FILE * fp = fopen("array.txt", "r+");
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
		    int n;
		    fscanf(fp, "%d", &n);
		    t->value[i][j] = n;
		}
	}


/*	table *t = new table;
	for (int i = 0; i<9; i++){
		for (int j = 0; j<9; j++){
			t->value[i][j] = 0;
		}
	}
	t->printTable();	*/
}

bool table::finish(){
	bool end = false;
	int counter = 0;
	table *t;
	for (int i = 0; i<9; i++){
		for (int j = 0; j<9; j++){
			if (t->value[i][j] == 0){
				counter++;
			}
		}
	}
	if (counter == 0){
		end = true;
	}
	return end;
}

void table::printTable(){
	table *t;
	cout << endl << endl;
	for (int i = 0; i<9; i++){
		for (int j = 0; j<9; j++){
			cout << t->value[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
}

void table::inputValue(){
	unsigned short int row, col;
	unsigned short int input;
	table *t;
	cout << "Enter the both row and column where are you wanted to enter input: " << endl;
	cin >> row;
	cin >> col;
	if (0 < row && row < 10){
		if (0 < col && col < 10){
			if (t->value[row-1][col-1] == 0){
				cout << "Enter the input: ";
				cin >> input;
				if (0 < input && input < 10){
					for (int i=0; i<9; i++ ){
						if ( t->value[i][col-1] == input ){
							cout << "Same numbers!" << endl;
							return;
						}
					}
					for (int i=0; i<9; i++ ){
						if ( t->value[row-1][i] == input ){
							cout << "Same numbers!" << endl;
							return;
						}
					}
					switch (row){
					case 1: case 2: case 3:
						switch (col){
						case 1: case 2: case 3:
							for (int i=0; i<3; i++){
								for (int j=0; j<3; j++){
									if (t->value[i][j] == input){
										cout << "Same numbers!" << endl;
										return;
									}
								}
							}
							break;
						case 4: case 5: case 6:
							for (int i=0; i<3; i++){
								for (int j=3; j<6; j++){
									if (t->value[i][j] == input){
										cout << "Same numbers!" << endl;
										return;
									}
								}
							}
							break;
						case 7: case 8: case 9:
							for (int i=0; i<3; i++){
								for (int j=6; j<9; j++){
									if (t->value[i][j] == input){
										cout << "Same numbers!" << endl;
										return;
									}
								}
							}
							break;
						}
						break;
					case 4: case 5: case 6:
						switch (col){
						case 1: case 2: case 3:
							for (int i=3; i<6; i++){
								for (int j=0; j<3; j++){
									if (t->value[i][j] == input){
										cout << "Same numbers!" << endl;
										return;
									}
								}
							}
							break;
						case 4: case 5: case 6:
							for (int i=3; i<6; i++){
								for (int j=3; j<6; j++){
									if (t->value[i][j] == input){
										cout << "Same numbers!" << endl;
										return;
									}
								}
							}
							break;
						case 7: case 8: case 9:
							for (int i=3; i<6; i++){
								for (int j=6; j<9; j++){
									if (t->value[i][j] == input){
										cout << "Same numbers!" << endl;
										return;
									}
								}
							}
							break;
						}
						break;
					case 7: case 8: case 9:
						switch (col){
						case 1: case 2: case 3:
							for (int i=6; i<9; i++){
								for (int j=0; j<3; j++){
									if (t->value[i][j] == input){
										cout << "Same numbers!" << endl;
										return;
									}
								}
							}
							break;
						case 4: case 5: case 6:
							for (int i=6; i<9; i++){
								for (int j=3; j<6; j++){
									if (t->value[i][j] == input){
										cout << "Same numbers!" << endl;
										return;
									}
								}
							}
							break;
						case 7: case 8: case 9:
							for (int i=6; i<9; i++){
								for (int j=6; j<9; j++){
									if (t->value[i][j] == input){
										cout << "Same numbers!" << endl;
										return;
									}
								}
							}
							break;
						}
						break;
					}
					t->value[row-1][col-1] = input;
				}
				else{
					cout << "Input should be between 1-9" << endl;
					return;
				}
			}
		}
		else{
			cout << "Column number should be between 1-9" << endl;
			return;
		}
	}
	else{
		cout << "Row number should be between 1-9" << endl;
		return;
	}
}
