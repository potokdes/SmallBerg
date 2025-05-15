Etap 1: Minimalna funkcjonalna implementacja Iceberg Table (read/write lokalnie)
🎯 Cel:

Zaimplementować podstawową obsługę tabeli Iceberg w formacie lokalnym:

    możliwość tworzenia tabeli,

    dodawanie danych,

    zapisywanie ich jako pliki (np. CSV lub JSON),

    metadane w pliku JSON,

    odczyt danych z metadanych.

📁 Struktura katalogów (propozycja)

iceberg/
├── CMakeLists.txt
├── include/
│   ├── Table.h
│   ├── Schema.h
│   ├── Manifest.h
│   ├── Metadata.h
│   └── util/
│       └── JsonUtils.h
├── src/
│   ├── Table.cpp
│   ├── Schema.cpp
│   ├── Manifest.cpp
│   ├── Metadata.cpp
│   └── util/
│       └── JsonUtils.cpp
├── tests/
│   └── TableTest.cpp
├── data/
│   └── (tu będą zapisywane pliki)
└── main.cpp

🧩 Komponenty Etapu 1
1. Schema (schema kolumn)

    Prosta struktura z kolumnami i typami.

    Zapis do JSON.

2. Table

    Nazwa tabeli.

    Referencja do Schema.

    Metody:

        append_row(vector<string>)

        flush() – zapisuje dane do pliku danych.

        save_metadata() – zapisuje schema i informacje o danych (manifest, ścieżki).

3. Manifest

    Przechowuje listę plików z danymi.

    Powiązane z partiami danych.

    Zapis/Odczyt JSON.

4. Metadata

    Plik JSON zawierający:

        schema

        ścieżki do danych

        manifesty

        timestampy

5. JsonUtils (helper)

    Ładowanie/zapisywanie JSON (np. z użyciem nlohmann/json).

    Funkcja pomocnicza do serializacji i deserializacji.

🔄 Przepływ działania (minimalna funkcjonalność)

Table t("table_name");
t.define_schema({{"id", "int"}, {"name", "string"}});
t.append_row({"1", "Ala"});
t.append_row({"2", "Bob"});
t.flush();              // zapisuje dane do pliku CSV
t.save_metadata();      // zapisuje schema + manifest w JSON

✅ Zakres do zrealizowania w Etapie 1
Komponent	Status docelowy
Podstawowa struktura tabeli	✅
Append danych do pamięci	✅
Zapis danych na dysk	✅
Zapis schema + metadanych	✅
Odczyt tabeli z metadanych	✅
Testy jednostkowe	🔄 (przynajmniej dla Table)
🧪 Propozycje testów jednostkowych

    Tworzenie tabeli i schema.

    Dodawanie i zapisywanie danych.

    Sprawdzenie, czy po odczycie metadanych można zrekonstruować obiekt Table.

    Zgodność schema → dane (np. liczba kolumn).

🚀 Kolejne etapy (dla inspiracji)

    Etap 2: Obsługa wielu plików danych (partycjonowanie).

    Etap 3: Operacje typu delete, merge, snapshot.

    Etap 4: Obsługa wielowątkowości (np. background flush, snapshoting).

    Etap 5: Własny prosty format binarny zamiast CSV.

    Etap 6: API sieciowe lub CLI (dla użytkownika końcowego).