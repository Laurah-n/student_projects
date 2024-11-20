# Program obliczający ilość schodów

Program ma za zadanie obliczyć ile schodów zmieści się w klatce schodowej, której wymiary podaje użytkownik. Następnie wykonywane są testy, które pokażą czy program działa poprawnie.

---

## Opis funkcji 

### Kod: 
```cpp
 double wysokoscKlatki, dlugoscKlatki;
    cout << "Podaj wysokosc klatki schodowej (w cm): ";
    cin >> wysokoscKlatki;
    cout << "Podaj dlugosc klatki schodowej (w cm): ";
    cin >> dlugoscKlatki;

    const double minDlugoscSchodka = 29.0, maxDlugoscSchodka = 32.0;
    const double minWysokoscSchodka = 15.0, maxWysokoscSchodka = 17.0;

    bool znalezionoRozwiazanie = false;
```

- Na początku użytkownik proszony jest o wpisanie danych do klatki schodowej.
- Następnie mamy zakresy, w których zawarte są standardowe wymiary schodka.
- Na końcu mamy zmienną **bool** `znalezionoRozwiazanie`, która przyjmuje wartość `false`, ponieważ początkoo nie wiemy, czy istnieje rozwiązanie, które spełni warunki programu.

## Pętla `for`:
```cpp
    for (double dlugoscSchodka = minDlugoscSchodka; dlugoscSchodka <= maxDlugoscSchodka; dlugoscSchodka += 0.1) {
        int liczbaSchodowDlugosc = static_cast<int>(dlugoscKlatki / dlugoscSchodka);
        if (dlugoscSchodka * liczbaSchodowDlugosc == dlugoscKlatki) { 
            for (double wysokoscSchodka = minWysokoscSchodka; wysokoscSchodka <= maxWysokoscSchodka; wysokoscSchodka += 0.1) {
                int liczbaSchodowWysokosc = static_cast<int>(wysokoscKlatki / wysokoscSchodka);
                if (wysokoscSchodka * liczbaSchodowWysokosc == wysokoscKlatki) { 
                    if (liczbaSchodowDlugosc == liczbaSchodowWysokosc) {
                        cout << "Liczba schodow: " << liczbaSchodowDlugosc << endl;
                        cout << "Dlugosc schodka: " << dlugoscSchodka << " cm" << endl;
                        cout << "Wysokosc schodka: " << wysokoscSchodka << " cm" << endl;
                        znalezionoRozwiazanie = true;
                        break;
                    }
                }
            }
        }
    }
```


