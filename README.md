# CsSpectrum-and-hists
**Do wykonania zawartych w repozytorium plików potrzebne jest zainstalowane środowisko ROOT** \
**Aby sklonować repozytorium, w terminalu należy wpisać *`git clone git@github.com:emdzejski/CsSpectrum-and-hists.git`***

W repozytorium znajdują się cztery makra:
1. WidmoCs.C: Makro ładuje dane z pliku tekstowego (domyślnie Cs-137.dat zamieszczony w repozytorium), wyświetla zawartość pliku w przypadku poprawnego załadowania, wyświetla histogram oraz zapisuje go wraz z utworzonym płótnem (canvas) do osbnych plików z rozszerzeniem .root. Uruchamianie: po uruchomieniu ROOT-a w terminalu należy wywołać funkcję podając ścieżkę do pliku - `.x WidmoCs.C("sciezka_do_pliku")`. W przypadku wywołania funkcji bez argumentu, makro obsłuży plik Cs-137.dat.
2. RewriteFile.C: Generuje plik binarny na podstawie pliku tekstowego. Uruchamianie: po uruchomieniu ROOT-a w terminalu należy wywołać funkcję podając ścieżkę do pliku - `.x RewriteFile.C("sciezka_do_pliku")`. W przypadku wywołania funkcji bez argumentu, makro obsłuży plik Cs-137.dat.
3. WidmoCsBin.C: Działa analogicznie do WidmoCs.C, ale ładuje dane z pliku binarnego. Uruchamianie: po uruchomieniu ROOT-a w terminalu należy wywołać funkcję podając ścieżkę do pliku - `.x WidmoCsBin.C("sciezka_do_pliku")`. W przypadku wywołania funkcji bez argumentu, makro obsłuży plik Cs-137.bin, wygenerowany przez 2. makro.
4. HistogramStack.C: Tworzy 4 histogramy wypełnione różńymi rozkładami i wyświetla je na jednym wykresie. Uruchamianie: po uruchomieniu ROOT-a w terminalu należy wywołać funkcję - `.x HistogramStack.C()`. Funkcja nie przyjmuje argumentów.
