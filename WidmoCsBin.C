// Mateusz Janus, 23.11.2024
#include <iostream>
#include <fstream> 
#include <string>

using namespace std;

Bool_t WidmoCsBin(string n_file = "Cs-137.bin"){

    fstream widmo;

    widmo.open(n_file, ios::binary | ios::in);
    
    vector<Double_t> data; // tablica zawierające liczbę zliczeń w kanałach
    vector<Double_t> errors; //niepewności zliczeń

    double* x;
    char * temp = new char[sizeof(double)];

    while(!widmo.eof()){
        widmo.read(temp, sizeof(double));
        x = (double*)temp;
        data.push_back(*x);
        errors.push_back(sqrt(*x));
        cout << *x << endl;
    }

   
    
    if (widmo.is_open()){
        cout << "plik poprawnie załadowany" << endl;
        //string line;
        
        for (auto i: data){
            cout << i << endl;
        }
        
    }
    
        
        //cout << widmo.rdbuf() << endl;
    
    else{
        cout << "błąd w ładowaniu pliku" << endl;
    }
    widmo.close();
    
    
    
    const Int_t nbins = data.size();
    

    
    TH1F *hSpec = new TH1F("hSpec","Cs 137 spectrum", nbins , 0, nbins);

    for(Int_t i=1; i<=nbins; i++){
        hSpec->SetBinContent(i, data[i-1]);
        hSpec->SetBinError(i, errors[i-1]);
    }
    TCanvas *can = new TCanvas("can", "can", 700 ,400);
    can->cd();
    hSpec->Draw();
    //hSpec->GetYaxis()->SetRange(22,23);
    hSpec->GetXaxis()->SetRange(0,400);
    hSpec->GetXaxis()->SetTitle("nr kanalu"); // ustalenie tytułów osi i histogramu
    hSpec->GetYaxis()->SetTitle("liczba zliczen");
    
    TLine fotopik;
    TLine kraw;
    fotopik.SetLineColor(kRed);
    fotopik.DrawLine(260, 0, 260, 1500);
    kraw.SetLineColor(kRed);
    kraw.DrawLine(190, 0, 190, 1500);
    
    TLatex text;
    text.SetTextSize(0.03);
    text.SetTextColor(kRed);
    text.SetTextFont(42);
    text.DrawLatex(265, 1400,"661 keV");
    
    TLatex text_kraw;
    text_kraw.SetTextSize(0.03);
    text_kraw.SetTextColor(kRed);
    text_kraw.SetTextFont(42);
    text_kraw.DrawLatex(195, 1400,"kraw. Comptona");

    TFile *file = new TFile("myHist.root", "RECREATE");
    TFile *canvas = new TFile("mycanvas.root", "RECREATE");
    hSpec->Write();
    can->Write();
    canvas->Close();
    file->Close();
    
    return kTRUE;


}