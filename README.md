# GraphAlgorithms

GraphAlgorithms to projekt implementujący różne algorytmy grafowe w C++, w tym algorytmy minimalnego drzewa rozpinającego (MST) oraz najkrótszej ścieżki (SPT). Projekt zawiera również funkcje do generowania, transformowania i wczytywania grafów.

## Funkcjonalności

### Główne menu
Program umożliwia wybór jednej z trzech głównych opcji:

1. **MST (Minimalne Drzewo Rozpinające):**
    - Generowanie grafu losowo.
    - Wczytywanie grafu z pliku.
    - Wyświetlanie wczytanego grafu.
    - Wykonywanie algorytmu Prima.
    - Wykonywanie algorytmu Kruskala.

2. **SPT (Najkrótsza Ścieżka):**
    - Generowanie grafu losowo.
    - Wczytywanie grafu z pliku.
    - Wyświetlanie wczytanego grafu.
    - Wykonywanie algorytmu Dijkstry.
    - Wykonywanie algorytmu Bellmana-Forda.

3. **Testy:**
    - Automatyczne testowanie wydajności algorytmów.

### Obsługiwane struktury danych
- **Macierz incydencji (IncidenceMatrix):**
- **Lista sąsiedztwa (AdjacencyList):**

## Użycie programu

Program uruchamia się z parametrami w linii komend w następującej kolejności:

```plaintext
<plik> <czas[s]> <populacja> <wsp.krzyżowania> <wsp.mutacji> <typ.krzyżowania>
```

Przykład:

```plaintext
program.exe graph.txt 60 100 0.8 0.01 PMX
```

## Instalacja i kompilacja

Aby skompilować projekt, wykonaj następujące kroki:

1. Sklonuj repozytorium:

   ```bash
   git clone <URL_repozytorium>
   ```

2. Przejdź do katalogu projektu:

   ```bash
   cd GraphAlgorithms
   ```

3. Skorzystaj z dowolnego kompilatora C++:

   ```bash
   g++ -o program src/*.cpp -std=c++17
   ```

## Pliki projektu

Projekt składa się z następujących plików:

- **ui/Menu.h** i **ui/Menu.cpp:** Implementacja głównego menu.
- **utilities/GenerateGraph.h:** Generowanie losowych grafów.
- **utilities/ReadGraph.h:** Wczytywanie grafów z plików.
- **utilities/TransformGenerated.h:** Transformacja grafu między różnymi reprezentacjami.
- **algorithms/BellmanFord.h:** Implementacja algorytmu Bellmana-Forda.
- **algorithms/Dijkstra.h:** Implementacja algorytmu Dijkstry.
- **algorithms/Prim.h:** Implementacja algorytmu Prima.
- **algorithms/Kruskal.h:** Implementacja algorytmu Kruskala.
- **structures/IncidenceMatrix.h:** Reprezentacja grafu w formie macierzy incydencji.
- **structures/AdjacencyList.h:** Reprezentacja grafu w formie listy sąsiedztwa.

## Przykład użycia

1. Po uruchomieniu programu wybierz typ operacji (MST, SPT lub testy).
2. W przypadku MST i SPT:
   - Wybierz opcję generowania grafu lub wczytania z pliku.
   - Wybierz algorytm do uruchomienia.
3. Wyniki algorytmów są wyświetlane w konsoli.

## Wymagania

- Kompilator zgodny z C++17 lub nowszy.
- System operacyjny obsługujący kompilację C++ (Linux, Windows, MacOS).

## Autorzy

- **Kacper Wiącek**

## Licencja

Projekt jest udostępniany na licencji MIT. Szczegóły znajdują się w pliku `LICENSE`.