short scorelinks = 0;
short scorerechts = 0;
short paddlepositielinks = 32768;
short paddlepositierechts = 32768;
short balhoek;
short balxpos;
short balypos;
short balrichting = 1;
const short balsnelheid = 5;
const short linkerkant = -64;
const short rechterkant = 64;
const short bovenkant = 48;
const short onderkant = -48;

void balreset() {
    balxpos = 0;
    balypos = 48;
    balrichting = -1;
    balhoek = 255;
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
        balhoek == 225;
    }
    else if ((balypos == 48) && (balrichting == 1)) {
        balhoek == 315;
    }
}

void col_me_onderkant() {
    if ((balypos == -48) && (balrichting == -1)) {
        balhoek == 135;
    }
    else if ((balypos == -48) && (balrichting == 1)) {
        balhoek == 45;
    }
}

void col_me_linker_of_rechtermuur() {
    if (balxpos == linkerkant) {
        scorerechts = scorerechts++;
        balresetrechts();
    }
    else if (balxpos == rechterkant) {
        scorelinks == scorelinks++;
        balresetlinks();
    }
}