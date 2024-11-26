# Program obliczający ilość schodów

Program oblicza parametry schodów, takie jak liczba stopni, długość i wysokość pojedynczego stopnia, na podstawie wartości które podaje użytkownik. Uwzględnia wymagania dotyczące minimalnej i maksymalnej wysokości oraz długości stopni, aby generowane schody spełniały swoją funkcje i były odpowiedznich wymiarów.

---

## Struktura programu

Program składa się z trzech plików:

1. `functions.cpp` - zawiera implementacje funkcji
2. `main.cpp` - główny plik programu
3. `main_tests.cpp` - zawiera testy funcji

---

## Plik `functions.cpp`

Implementacja funkcji, które później są użyte w pliku `main.cpp` oraz `main_tests.cpp`.

### Kod:
```cpp
#include <iostream>
#include <cmath>
#include <algorithm>

void wprowadzenieWymiarow(double& wysokosc, double& dlugosc) {
    std::cout << "Podaj wysokość schodów (w cm): ";
    std::cin >> wysokosc;
    std::cout << "Podaj długość schodów (w cm): ";
    std::cin >> dlugosc;
}

int obliczIloscStopni(double wysokosc, double dlugosc) {
    const double minWysokosc = 15.0;
    const double maxWysokosc = 17.0;
    const double minDlugosc = 28.0;
    const double maxDlugosc = 30.0;

    int iloscStopniWysokosc = std::floor(wysokosc / minWysokosc);
    int iloscStopniDlugosc = std::floor(dlugosc / minDlugosc);

    if (iloscStopniWysokosc <= 0 || iloscStopniDlugosc <= 0) {
        return -1;
    }

    int iloscStopni = std::min(iloscStopniWysokosc, iloscStopniDlugosc);

    double dlugoscStopnia = dlugosc / iloscStopni;
    if (dlugoscStopnia > maxDlugosc) {
        return -1;
    }

    return iloscStopni;
}

void obliczWymiaryStopnia(double dlugosc, double wysokosc, int iloscStopni, double& dlugoscStopnia, double& wysokoscStopnia) {
    dlugoscStopnia = dlugosc / iloscStopni;
    wysokoscStopnia = wysokosc / iloscStopni;
}
```

---

### Opis funkcji:

1. **`void wprowadzenieWymiarow`**

- Funkcja pobiera od użytkownika dane wejściowe: wysokość i długość całkowitą schodów.

**Parametry:**

- wysokosc – referencja do zmiennej, gdzie zapisana zostanie wysokość.
- dlugosc – referencja do zmiennej, gdzie zapisana zostanie długość.

**Zwraca:** brak.

2. **`int obliczIloscStopni`**

- Oblicza maksymalną liczbę stopni, biorąc pod uwagę minimalne i maksymalne wartości dla wysokości oraz długości stopnia.
- Sprawdza, czy długość stopnia nie przekracza dopuszczalnej wartości.

**Parametry:**

- wysokosc – wysokość schodów.
- dlugosc – długość schodów.

**Zwraca:**

- Liczbę stopni (int), jeśli jest możliwe ich wygenerowanie.
- -1, jeśli schody nie spełniają wymagań.

3. **`void obliczWymiaryStopnia`**

- Oblicza wymiary pojedynczego stopnia.

**Parametry:**

- dlugosc – długość schodów.
- wysokosc – wysokość schodów.
- iloscStopni – liczba stopni.
- dlugoscStopnia – referencja do zmiennej, gdzie zapisana zostanie długość pojedynczego stopnia.
- wysokoscStopnia – referencja do zmiennej, gdzie zapisana zostanie wysokość pojedynczego stopnia.

**Zwraca:** brak.

---

## Plik `main.cpp`

Kod główny programu. Steruje jego przebiegiem.

### Kod:
```cpp
#include <iostream>
#include "functions.cpp"

int main() {
    double wysokosc, dlugosc;
    wprowadzenieWymiarow(wysokosc, dlugosc);

    int iloscStopni = obliczIloscStopni(wysokosc, dlugosc);

    if (iloscStopni == -1) {
        std::cerr << "Nie można wygenerować schodów o podanych wymiarach." << std::endl;
        return 1;
    }

    double dlugoscStopnia, wysokoscStopnia;
    obliczWymiaryStopnia(dlugosc, wysokosc, iloscStopni, dlugoscStopnia, wysokoscStopnia);

    std::cout << "Ilość stopni schodów: " << iloscStopni << std::endl;
    std::cout << "Długość pojedynczego stopnia: " << dlugoscStopnia << " cm" << std::endl;
    std::cout << "Wysokość pojedynczego stopnia: " << wysokoscStopnia << " cm" << std::endl;

    return 0;
}
```

---

### Opis działania programu:

1. **Wprowadzenie danych:**

- Użytkownik podaje wysokość i długość schodów.

2. **Obliczenie liczby stopni:**

- Program wyznacza liczbę stopni w oparciu o podane zakresy.

3. **Sprawdzenie poprawności wymiarów:**

- Jeśli którakolwiek podana wartość nie pozwala na wygenerowanie wymiarowych schodów, program zwraca komunikat o błędzie.

4. **Obliczenie wymiarów pojedynczego stopnia:**

- Na podstawie liczby stopni program oblicza długość i wysokość każdego stopnia.

5. **Wyświetlenie wyników:**

- Liczba stopni, długość i wysokość pojedynczego stopnia są wyświetlane użytkownikowi.

---

## Przykład działania programu:

| Wysokość schodów (cm) | Długość schodów (cm) | Ilość schodów | Wysokość 1 schodka (cm) | Długość 1 schodka (cm) |
|-----------------------|----------------------|---------------|-------------------------|------------------------|
| 150                   | 420                  | Nie można wygenerować schodów o podanych wymiarach               |
| 150                   | 200                  | 7             | 21.43                   | 28.57                  |
| 50                    | 70                   | Nie można wygenerować schodów o takich wymiarach                 |
| 30                    | 900                  | Nie można wygenerować schodów o takich wymiarach                 |
| 180                   | 280                  | 10            | 18                      | 28                     |

---

## Testy programu

Testy jednostkowe sprawdzają czy funkcje w pliku `functions.cpp` działają poprawnie. Znajdują się w pliku `main_tests.cpp`.

### Kod:
```cpp
#include <gtest/gtest.h>
#include "functions.cpp"

TEST(SchodyTests, TestIloscStopni){
	EXPECT_EQ(obliczIloscStopni(150, 200), 7);
	EXPECT_EQ(obliczIloscStopni(180, 280), 10);
	EXPECT_EQ(obliczIloscStopni(50, 70), -1);
}

TEST(SchodyTests, TestWymiarySchodka){
	double dlugoscStopnia, wysokoscStopnia;

	obliczWymiaryStopnia(300.0, 150.0, 10, dlugoscStopnia, wysokoscStopnia);
	EXPECT_DOUBLE_EQ(dlugoscStopnia, 30.0);
	EXPECT_DOUBLE_EQ(wysokoscStopnia, 15.0);

	obliczWymiaryStopnia(200.0, 150.0, 7, dlugoscStopnia, wysokoscStopnia);
	EXPECT_DOUBLE_EQ(dlugoscStopnia, 28.57);
	EXPECT_DOUBLE_EQ(wysokoscStopnia, 21.43);
}

int main(int argc, char **argv){
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
```

---

### Działanie kodu:

1. Google Test uruchamia testy zdefiniowane w TEST().
- (EXPECT_EQ, EXPECT_DOUBLE_EQ) sprawdza wynik zwracany przez funkcję porównując go z oczekiwanym.
2. W przypadku błędów testy wypisują szczegóły, takie jak:
- Wartość zwrócona przez funkcję.
- Wartość oczekiwana.
3. Jeśli wszystkie testy przejdą, program zwraca 0, co oznacza sukces.

---

### Zastosowanie testów:

1. **Testowanie poprawności funkcji:**
	- Funkcja `obliczIloscStopni` sprawdzana jest pod kątem poprawnych i niepoprawnych danych wejściowych.
	- Funkcja `obliczWymiaryStopnia` testowana jest na różnych przypadkach.
2. **Sprawdzanie stabilności programu:**
	- Testy pozwalają upewnić się, że zmiany w kodzie nie psują jego funkcjonalności.

---

### Przykład działania:

![maszynatesty](https://github.com/user-attachments/assets/180d372b-3b20-4f8f-8dc1-416dc97348bc)

