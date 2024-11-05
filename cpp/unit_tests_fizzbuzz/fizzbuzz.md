# Funkcja FizzBuzz i Testy

To repozytorium zawiera prostą implementację funkcji "FizzBuzz", oraz jej testy jednostkowe przy użyciu frameworka Google Test.

## Spis Treści
- Opis
- Struktura Kodu
- Szczegóły Funkcji FizzBuzz
- Testy Jednostkowe

---

## Opis

Funkcja FizzBuzz to ćwiczenie programistyczne, w którym:
- Jeśli liczba jest podzielna przez 3, funkcja zwraca "Fizz".
- Jeśli liczba jest podzielna przez 5, funkcja zwraca "Buzz".
- Jeśli liczba jest podzielna zarówno przez 3, jak i przez 5, funkcja zwraca "FizzBuzz".
- Jeśli liczba nie jest podzielna ani przez 3, ani przez 5, funkcja zwraca pusty ciąg znaków.

## Struktura Kodu

Repozytorium zawiera dwa główne pliki:
1. `functions.cpp`: Zawiera definicję funkcji `FizzBuzz`.
2. `main_test.cpp`: Zawiera testy jednostkowe dla funkcji `FizzBuzz`.

---

## Szczegóły Funkcji FizzBuzz

Funkcja `FizzBuzz` przyjmuje liczbę całkowitą jako argument i zwraca `string` w zależności od podzielności liczby przez 3 i 5.

### Kod:
```cpp
#include <string>

using namespace std;

string FizzBuzz(int liczba) {
    string result = "";
    if (liczba % 3 == 0) {
        result += "Fizz";
    }
    if (liczba % 5 == 0) {
        result += "Buzz";
    }
    return result;
}
```

## Wyjaśnienie

- **Parametry**:

   - `liczba` (int): Liczba całkowita przekazana do sprawdzenia.

- **Logika**:

  - Jeśli liczba jest podzielna przez 3, do zmiennej `result` dodawany jest tekst "Fizz".
  - Jeśli liczba jest podzielna przez 5, do zmiennej `result` dodawany jest tekst "Buzz".
  - Jeśli liczba jest podzielna zarówno przez 3, jak i przez 5, obie powyższe instrukcje są spełnione, a `result` staje się "FizzBuzz".
  - Jeśli liczba nie jest podzielna ani przez 3, ani przez 5, `result` pozostaje pusty.
 
- **Wartość zwracana**:

  - Zwraca "Fizz", "Buzz", "FizzBuzz" lub pusty ciąg znaków w zależności od podzielności.
 
---

## Testy jednostkowe

### Plik Testów: `main_test.cpp`

Testy jednostkowe zostały zaimplementowane przy użyciu frameworka Google Test, aby sprawdzić, czy `FizzBuzz` działa zgodnie z oczekiwaniami. Każdy test weryfikuje konkretny scenariusz dotyczący podzielności liczby wejściowej.

### Kod:
```cpp
#include <gtest/gtest.h>
#include "functions.cpp"
#include <string>

TEST(FizzBuzzTests, ReturnsFizzForMultipleOf3) {
    string result = FizzBuzz(3);
    EXPECT_EQ(result, "Fizz");
}

TEST(FizzBuzzTests, ReturnsBuzzForMultipleOf5) {
    string result = FizzBuzz(5);
    EXPECT_EQ(result, "Buzz");
}

TEST(FizzBuzzTests, ReturnsFizzBuzzForMultipleOf15) {
    string result = FizzBuzz(15);
    EXPECT_EQ(result, "FizzBuzz");
}

TEST(FizzBuzzTests, ReturnsEmptyStringForNonMultipleOf3Or5) {
    string result = FizzBuzz(7);
    EXPECT_EQ(result, "");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```

### Opis Testów:

1. `ReturnsFizzForMultipleOf3`: Sprawdza, czy dla wielokrotności liczby 3 zwracany jest tekst "Fizz".
2. `ReturnsBuzzForMultipleOf5`: Sprawdza, czy dla wielokrotności liczby 5 zwracany jest tekst "Buzz".
3. `ReturnsFizzBuzzForMultipleOf15`: Sprawdza, czy dla liczb podzielnych zarówno przez 3, jak i przez 5 zwracany jest tekst "FizzBuzz".
4. `ReturnsEmptyStringForNonMultipleOf3Or5`: Sprawdza, czy dla liczb niepodzielnych ani przez 3, ani przez 5 zwracany jest pusty ciąg znaków.

### Uruchamianie Testów:

Po kompilacji możesz uruchomić testy, używając:
```
./main_test.cpp
```

To polecenie wykona wszystkie testy, a Google Test wyświetli wyniki, wskazując, czy każdy test zakończył się pomyślnie czy nie.
