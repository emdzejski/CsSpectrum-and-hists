# CsSpectrum-and-hists
**Do wykonania zawartych w repozytorium plików potrzebne jest zainstalowane środowisko ROOT** \
**Aby sklonować repozytorium, w terminalu należy wpisać *`git clone git@github.com:emdzejski/CsSpectrum-and-hists.git`***

W repozytorium znajdują się cztery makra:
1. WidmoCs.C: Makro ładuje dane z pliku tekstowego (domyślnie Cs-137.dat), wyświetla zawartość pliku w przypadku poprawnego załadowania, wyświetla histogram oraz zapisuje go wraz z utworzonym płótnem (canvas) do osbnych plików z rozszerzeniem .root. Uruchamianie w ROOT: w terminalu należy wpisać `root –q 'WidmoCs.C("sciezka_do_pliku")'`. W przypadku wywołania funkcji bez argumentu, makro obsłuży plik Cs-137.dat.
2. RewriteFile.C: Generuje plik binarny na podstawie pliku tekstowego. Uruchamianie w ROOT: w terminalu należy wpisać `root –q 'RewriteFile.C("sciezka_do_pliku")'`. W przypadku wywołania funkcji bez argumentu, makro obsłuży plik Cs-137.dat.
3. WidmoCsBin.C: Działa analogicznie do WidmoCs.C, ale ładuje dane z pliku binarnego. Uruchamianie w ROOT: w terminalu należy wpisać `root –q 'WidmoCsBin.C("sciezka_do_pliku")'`. W przypadku wywołania funkcji bez argumentu, makro obsłuży plik Cs-137.bin, wygenerowany przez 2. makro.
4. 
