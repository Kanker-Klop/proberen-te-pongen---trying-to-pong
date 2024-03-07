#include <iostream>

short scorelinks = 0;
short scorerechts = 0;
short paddlepositielinks = 32768;
short paddlepositierechts = 32768;
short balhoek;
short balxpos;
short balypos;
short balrichting = 1;
const short balsnelheid = 4;
const short linkerkant = -64;
const short rechterkant = 64;
const short bovenkant = 48;
const short onderkant = -48;

void balreset() {
    balxpos = 0;
    balypos = 48;
    balrichting = -1;
    balhoek = 225;
}

void balresetlinks() {
    balxpos = 0;
    balypos = 48;
    balrichting = -1;
}

void balresetrechts() {
    balxpos = 0;
    balypos = 48;
    balrichting = 1;
}

void col_me_bovenkant() {
    if ((balypos == 48) && (balrichting == -1)) {
        balhoek = 225;
    }
    else if ((balypos == 48) && (balrichting == 1)) {
        balhoek = 315;
    }
}

void col_me_onderkant() {
    if ((balypos == -48) && (balrichting == -1)) {
        balhoek = 135;
    }
    else if ((balypos == -48) && (balrichting == 1)) {
        balhoek = 45;
    }
}

void col_me_linker_of_rechtermuur() {
    if (balxpos == linkerkant) {
        scorerechts = scorerechts++;
        balresetrechts();
    }
    else if (balxpos == rechterkant) {
        scorelinks = scorelinks++;
        balresetlinks();
    }
}

void balbeweging() {
    if (balrichting == 1 && balhoek == 45) {
        balxpos = balxpos+balsnelheid;
        balypos = balypos+balsnelheid;
        std::cout << balhoek;
        std::cout << "\n";
        std::cout << balxpos;
        std::cout << "\n";
        std::cout << balypos;
        std::cout << "\n";
        std::cout << balrichting;
        std::cout << "\n";
        std::cout << "\n";
    }
    else if (balrichting == 1 && balhoek == 315) {
        balxpos = balxpos+balsnelheid;
        balypos = balypos-balsnelheid;
        std::cout << balhoek;
        std::cout << "\n";
        std::cout << balxpos;
        std::cout << "\n";
        std::cout << balypos;
        std::cout << "\n";
        std::cout << balrichting;
        std::cout << "\n";
        std::cout << "\n";
    }
    else if (balrichting == -1 && balhoek == 135) {
        balxpos = balxpos-balsnelheid;
        balypos = balypos+balsnelheid;
        std::cout << balhoek;
        std::cout << "\n";
        std::cout << balxpos;
        std::cout << "\n";
        std::cout << balypos;
        std::cout << "\n";
        std::cout << balrichting;
        std::cout << "\n";
        std::cout << "\n";
    }
    else if (balrichting == -1 && balhoek == 225) {
        balxpos = balxpos-balsnelheid;
        balypos = balypos-balsnelheid;
        std::cout << balhoek;
        std::cout << "\n";
        std::cout << balxpos;
        std::cout << "\n";
        std::cout << balypos;
        std::cout << "\n";
        std::cout << balrichting;
        std::cout << "\n";
        std::cout << "\n";
    }
}

int testbeweging = 1;

int main() {
    balreset();
    for (testbeweging = 1; testbeweging<50; testbeweging++) {
        col_me_bovenkant();
        col_me_onderkant();
        col_me_linker_of_rechtermuur();
        balbeweging();
    }
}