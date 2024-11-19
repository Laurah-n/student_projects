# Porównanie funkcji `if` oraz `switch`

## Cel programu:
Program ma za zadanie porównać, jak szybko wykonują się dwie funkcje: `if` oraz `switch`. W ramach testów program wykonuje obie instrukcje, mierzy czas ich działania i wyświetla wyniki.

---

## Opis funkcji

### Funkcja  `testIf`:

### Kod:

```cpp
void test_if(int day) {
    if (day == 1) {
        cout << "Monday";
    } else if (day == 2) {
        cout << "Tuesday";
    } else if (day == 3) {
        cout << "Wednesday";
    } else if (day == 4) {
        cout << "Thursday";
    } else if (day == 5) {
        cout << "Friday";
    } else if (day == 6) {
        cout << "Saturday";
    } else if (day == 7) {
        cout << "Sunday";
    }
}
```
.
- Zawiera instrukcje warunkowe `if`, które na podstawie wartości zmiennej `day` wypisują nazwę dnia tygodnia.
- Celem jest zmierzenie, jak długo zajmuje wykonanie się instrukcji.

### Funkcja `testSwitch`:

### Kod:

```cpp
void test_case(int day){
    switch (day) {
      case 1:
        cout << "Monday";
        break;
      case 2:
        cout << "Tuesday";
        break;
      case 3:
        cout << "Wednesday";
        break;
      case 4:
        cout << "Thursday";
        break;
      case 5:
        cout << "Friday";
        break;
      case 6:
        cout << "Saturday";
        break;
      case 7:
        cout << "Sunday";
        break;
    }
}
```

- Funkcja używa struktury `switch-case`, aby wpisać odpowiedni dzień tygodnia w zależności od wartości zmiennej `day`.
- Celem jest zmierzenie, jak długo zajmuje wykonanie się instrukcji.
  
---

## Testy wydajnościowe

Program wykonuje dwa testy wydajnościowe dla obu funkcji:
- Uruchamia funkcje `test_if` i mierzy jej czas wykoniania.
- Uruchamia funkcje `test_case` i również mierzy jej czas wykonania.

### Test dla instrukcji `if`

```cpp
TEST(BenchmarkTest, IfBenchmark)
{
	auto start = chrono::high_resolution_clock::now();

    test_if(day);

	auto end = chrono::high_resolution_clock::now();

	chrono::duration<double> elapsed_seconds = end - start;

	cout << "Czas dla instrukcji if: " << elapsed_seconds.count() << "s" << endl;
}
```

### Test dla instrukcji `switch`:

```cpp
TEST(BenchmarkTest, CaseBenchmark)
{
	auto start = chrono::high_resolution_clock::now();

    test_case(day);

	auto end = chrono::high_resolution_clock::now();

	chrono::duration<double> elapsed_seconds = end - start;

    cout << "Czas dla instrukcji case: " << elapsed_seconds.count() << "s" << endl;
}
```

---

## Funkcja `main`

### Kod:
```cpp
int main(int argc, char **argv)
{
	cout << "Podaj liczbe (1-7): ";
	cin >> day;

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```

- Użytkownik proszony jest o wpisanie liczby od 1-7.
- Uruchamia testy sprawdzające, która funkcja wykonia się szybciej (`if` lub `switch`).

---

## Wnioski z testów

Wyniki testów pokażą, która z konstrukcji działa szybciej. W większości przypadków `switch` jest szybsza niż `if`. Ten test pozwala lepiej zrozumieć, która struktura jest bardziej efektywna w konkretnych sytuacjach.
