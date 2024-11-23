// Mateusz Janus, 23.11.2024
#include <iostream>

Bool_t HistogramStack(){
    TRandom random;
    auto hs = new THStack("hs","");
    
    auto h1 = new TH1F("h1","Gaussian dist.",50,-15,-5);
    for(Int_t i=1; i<=50000; i++){
        Double_t value = random.Gaus(-10, 2);
        h1->Fill(value);
    }
    h1->SetFillColor(kRed);
    hs->Add(h1);
    
    auto h2 = new TH1F("h2","Exp dist.",50,0,10);
    for(Int_t i=1; i<=50000; i++){
        Double_t value = random.Exp(5);
        h2->Fill(value);
    }
    h2->SetFillColor(kBlue);
    hs->Add(h2);
    
    auto h3 = new TH1F("h3","Breit-Wigner dist.",50,-10,10);
    for(Int_t i=1; i<=50000; i++){
        Double_t value = random.BreitWigner(-5, 3);
        h3->Fill(value);
    }
    h3->SetFillColor(kGreen);
    hs->Add(h3);

    auto h4 = new TH1F("h4","Uniform dist.",50,10,15);
    for(Int_t i=1; i<=50000; i++){
        Double_t value = random.Uniform(10,14);
        h4->Fill(value);
    }
    h4->SetFillColor(kMagenta);
    hs->Add(h4);

    hs->Draw("nostack");

    TLegend *leg = new TLegend(0.6,0.7,0.9,0.9);
    TH1F *hists[4] = {h1,h2,h3,h4};
    for(Int_t i=0; i<4; i++){
        leg->AddEntry(hists[i], Form("%s",hists[i]->GetTitle()), "f");
    }
    leg->SetHeader("legend","C");
    leg->Draw();
    

    return kTRUE;
}