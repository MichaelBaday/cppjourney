#include <iostream>
#include <cctype>
#include <string>

void header() {
    std::cout << "-------------------------------------------------------";
    std::cout << "|     Selamat datang di SISTEM LOGIN BANK XXX         |";
    std::cout << "-------------------------------------------------------";
}

void input (std::string& PIN) {
    std::cout << "Silahkan Masukkan PIN Anda: ";
    std::cin >> PIN;

}

bool checkPIN(const std::string& PIN) {
    if (PIN.length() != 6) {
        return false;
    }

    for (char digit : PIN) {
        if (!std::isdigit(static_cast<unsigned char>(digit))) {
            return false;
        }
    }

    return true;
}

bool verify(const std::string& PIN) {
    const std::string PINbenar = "676767";
    return PINbenar == PIN;
}

void nyoba(int& maxPercobaan, ) {
    
}

int main () {
    std::string PIN;
    int maxPercobaan = 3;

    do {
        input(PIN);
        if (!checkPIN(PIN)) {
            std::cout << "PIN harus terdiri dari tepat 6 digit.\n";
        } 
    } while (!checkPIN(PIN));

}