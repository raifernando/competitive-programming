// PRIMO
// https://neps.academy/br/exercise/247

#include <iostream>

using namespace std;

bool eh_primo(int x){
	//Seu código aqui.
    if (x <= 2) {
        if (x == 2) return true;
        else return false;
    }

    for (int i = 2; i < x; i++) {
        if (x % i == 0) return false;
        if (i*i > x) return true;
    }

    return true;
}

int main(){
	int x;

	cin>>x;

	if(eh_primo(x)){
		cout << "S" << "\n";
	}else{
		cout << "N" << "\n";
	}
}
