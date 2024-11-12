# Porównanie funkcji `if` oraz `switch`

## Cel programu:
Program ma za zadanie porównać, jak szybko wykonują się dwie funkcje: `if` oraz `switch`. W ramach testów program wielokrotnie wykonuje obie instrukcje, mierzy czas ich działania i wyświetla wyniki.

---

## Opis funkcji

### Funkcja  `testIf`:

### Kod:

```cpp
void testIf(int value, const std::vector<int>& values) {
    if (value == values[0]) {}
    else if (value == values[1]) {}
    else if (value == values[2]) {}
    else if (value == values[3]) {}
    else if (value == values[4]) {}
    else if (value == values[5]) {}
    else if (value == values[6]) {}
    else if (value == values[7]) {}
    else if (value == values[8]) {}
    else if (value == values[9]) {}
```

- Funkcja `testIf` wykorzystuje szereg instrukcji if do sprawdzania, czy przekazana liczba (value) odpowiada jednej z dziesięciu wartości w wektorze (values).
- Celem jest zmierzenie, jak długo zajmuje przetworzenie tej struktury warunkowej.

### Funkcja `testSwitch`:

### Kod:

```cpp
void testSwitch(int value, const std::vector<int>& values) {
    switch (value) {
        case 0: break;
        case 1: break;
        case 2: break;
        case 3: break;
        case 4: break;
        case 5: break;
        case 6: break;
        case 7: break;
        case 8: break;
        case 9: break;
        default: break;
    }
}
```

- Funkcja ta wykorzystuje instrukcję `switch-case`, aby sprawdzić wartość (value) dla przypadków od 0 do 9.

---

## Testy wydajnościowe

Program wykonuje dwa testy wydajnościowe dla obu funkcji:
- Każdy test wykonuje instrukcje `if` i `switch` 10,000 razy, wykorzystując losowo generowane liczby od 0 do 9.
- Czas wykonania każdej iteracji jest sumowany, aby uzyskać całkowity czas wykonania obu funkcji dla 10,000 iteracji.

### Test dla instrukcji `if`

1. W teście program pyta użytkownika o wartość, którą wykorzystuje w funkcji `testIf`.
2. Następnie wykonuje funkcję `testIf` 10,000 razy i mierzy czas potrzebny na wszystkie iteracje.
3. Wynikowy czas to suma wszystkich iteracji.

```cpp
TEST(BenchmarkTest, IfStatementBenchmark) {
    std::srand(std::time(0));

    // Pobranie jednej wartości od użytkownika
    int userValue;
    std::cout << "Podaj jedną wartość do testu if: ";
    std::cin >> userValue;

    // Zmienna do sumowania czasu
    std::chrono::duration<double> total_time_if(0);

    for (int i = 0; i < 10000; i++) {
        int randomValue = std::rand() % 10;

        auto start = std::chrono::high_resolution_clock::now();
        testIf(randomValue, userValue);
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> elapsed_seconds = end - start;
        total_time_if += elapsed_seconds;
    }

    // Wyświetlenie sumarycznego czasu dla wszystkich iteracji
    std::cout << "Suma czasu wykonania testIf dla 10000 iteracji: " << total_time_if.count() << "s\n";
}
```

### Test dla instrukcji `switch`:

1. Test działa podobnie, ale wywołuje funkcję `testSwitch`.
2. Wynikowy czas wykonania wszystkich iteracji zapisuje się i wyświetla.

```cpp
TEST(BenchmarkTest, SwitchCaseBenchmark) {
    std::srand(std::time(0));

    // Pobranie jednej wartości od użytkownika
    int userValue;
    std::cout << "Podaj jedną wartość do testu switch/case: ";
    std::cin >> userValue;

    // Zmienna do sumowania czasu
    std::chrono::duration<double> total_time_switch(0);

    for (int i = 0; i < 10000; i++) {
        int randomValue = std::rand() % 10;

        auto start = std::chrono::high_resolution_clock::now();
        testSwitch(randomValue, userValue);
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> elapsed_seconds = end - start;
        total_time_switch += elapsed_seconds;
    }

    // Wyświetlenie sumarycznego czasu dla wszystkich iteracji
    std::cout << "Suma czasu wykonania testSwitch dla 10000 iteracji: " << total_time_switch.count() << "s\n";
}
```

---

## Wnioski z testów

Wyniki testów pokażą, która z konstrukcji działa szybciej. W większości przypadków `switch` jest optymalizowane przez kompilator lepiej niż `if`, szczególnie tam gdzie jest potrzeba wielokrotnego sprawdzenia warunków na wartościach całkowitych. Ten test pozwala lepiej zrozumieć, która struktura jest bardziej efektywna w konkretnych sytuacjach.

![image](https://github.com/user-attachments/assets/8ee18c78-2451-4b5a-8d25-d8c3cc095eda)
