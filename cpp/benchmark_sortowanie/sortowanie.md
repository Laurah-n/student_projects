# Sortowanie Bubble Sort vs Quick Sort

Program ma za zadanie porównać, jak szybko wykonują się dwa sortowania: **Bubble Sort** oraz **Quick Sort**. W ramach testów program wykonuje oba sortowania, mierzy czas ich działania i wyświetla wyniki.

---

## Bubble Sort 

### Kod:
```cpp
void bubbleSort(std::vector<int>& x) {
	for(int i = 0; i < x.size(); i++)
	{
		for(int j = 0; j < x.size() - 1; j++)
		{
			if(x[j] > x[j + 1])
			{
				int tmp = x[j];
				x[j] = x[j + 1];
				x[j + 1] = tmp;
			}
		}
	}
}
```

### Opis funkcji:
- Funkcja polega na wielokrotnym porównywaniu i zamianie miejscami sąsiadujących elementów wektora, jeśli są w złej kolejności.
- Wewnętrzna pętla (po j) sprawia, że największy element "przesuwa się" na koniec nieposortowanej części wektora.
- Zewnętrzna pętla (po i) powtarza cały proces tyle razy, ile potrzeba, aby cała tablica była posortowana.

---

## Quick Sort

### Kod:
```cpp
void quickSort(std::vector<int>& vec) {
    if (vec.size() <= 1) return;
    int pivot = vec[vec.size() / 2];
    std::vector<int> left, right;
    for (size_t i = 0; i < vec.size(); i++) {
        if (vec[i] < pivot) left.push_back(vec[i]);
        else if (vec[i] > pivot) right.push_back(vec[i]);
    }
    quickSort(left);
    quickSort(right);
    vec.clear();
    vec.insert(vec.end(), left.begin(), left.end());
    vec.push_back(pivot);
    vec.insert(vec.end(), right.begin(), right.end());
}
```

### Opis funkcji:
- Funkcja `quickSort` ma za zadanie posortować wektor rosnąco.
- Wybór pivota: Środkowy element wektora.
- Elementy mniejsze od pivota trafiają do wektora `left`, a większe do `right`.
- Wektor `vec` jest odbudowywany w kolejności: posortowany `left`, pivot, posortowany `right`.

---

## Testy wydajnościowe 

### Bubble Sort
```cpp
TEST(BenchmarkTest, BubbleSortBenchmark) {
    std::vector<int> vec(10000); // Tworzymy wektor z 10000 losowymi liczbami
    std::srand(std::time(0)); // Inicjalizacja generatora liczb losowych
    std::generate(vec.begin(), vec.end(), std::rand);

    // Początek pomiaru czasu
    auto start = std::chrono::high_resolution_clock::now();

    bubbleSort(vec); // Sortujemy wektor

    // Koniec pomiaru czasu
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "Czas sortowania: " << elapsed_seconds.count() << "s\n";
}
```

- Tworzy wektor o rozmiarze 10,000 i wypełnia go losowymi liczbami.
- Mierzy czas sortowania za pomocą `bubbleSort`.
- Wynik (w sekundach) wypisywany jest na konsolę.

### Quick Sort
```cpp
TEST(BenchmarkTest, QuickSortBenchmark) {
    std::vector<int> vec(10000); // Tworzymy wektor z 10000 losowymi liczbami
    std::srand(std::time(0)); // Inicjalizacja generatora liczb losowych
    std::generate(vec.begin(), vec.end(), std::rand);

    // Początek pomiaru czasu
    auto start = std::chrono::high_resolution_clock::now();

    quickSort(vec); // Sortujemy wektor

    // Koniec pomiaru czasu
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "Czas sortowania: " << elapsed_seconds.count() << "s\n";
}
```

- Analogicznie do testu dla `bubbleSort`, mierzy czas sortowania wektora o rozmiarze 10,000 za pomocą `quickSort`.

---

## Wnioski

**Bubble Sort** jest znacznie wolniejszy od **Quick Sort**, szczególnie przy dużych zbiorach danych (np. takich jak przy testach powyżej).
