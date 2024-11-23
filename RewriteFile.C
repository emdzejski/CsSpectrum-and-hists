// Mateusz Janus, 23.11.2024
#include <iostream>
#include <fstream>

void RewriteFile(string n_file = "Cs-137.dat"){
    fstream widmo;
    fstream wid_bin; //widmo w pliku binarnym
    widmo.open(n_file, ios::in);
    wid_bin.open("Cs-137.bin", ios::out | ios::binary );
    double d;
    while(widmo >> d) {
       //cout<< d << endl;
      wid_bin.write((char*)&d, sizeof d);
   }

}