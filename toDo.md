## What to do on May 23 for DR
- zmiana hasla
- notatka na string xd
- kwota na float
- dodawanie kategorii tylko administrator
- dodawanie, edycja cyklicznych
- blokowanie, odblokowywanie
- generacja raportu
- edytowanie danych uzytkownikow
- funkcjonalność dziecka
- czyszczenie tego co wypełnimy
- cały budzet
- poprawność formularzy
- zmiana kieszonkowego
- widocznosc tylko swoich dzieci,
- dziecko nie moze cyklicznych
- dziecko przychody wydatki do swojego salda
- implementacja systemu
- tylko admin rodzica do dzieci
- czy ktos jest dzieckiem
- saldo
- kieszonkowe

## What to do on May 25 for DR
- Generowanie raportów o przyszłych stanach budżetu na podstawie dostępnych rekordów i wybranych typów regresji.
- Generowanie raportów dotyczących tylko konkretnych użytkowników. 
- Generowanie raportów dla określonych kategorii dla zadanego okresu. Uwzględnienie podziału raportów na takie generowane przez dzieci (dotyczące tylko ich konta) oraz raporty dotyczące całego budżetu rodzinnego. 


## Jeszcze nie zrealizowane dla DR on May 25
- Generowanie raportów o przyszłych stanach budżetu na podstawie dostępnych rekordów i wybranych typów regresji.
- Generowanie raportów dotyczących tylko konkretnych użytkowników. 
- Generowanie raportów dla określonych kategorii dla zadanego okresu. Uwzględnienie podziału raportów na takie generowane przez dzieci (dotyczące tylko ich konta) oraz raporty dotyczące całego budżetu rodzinnego. 


## Zastanawianie sie
- haszowniae hasel? XDD
- co z edycją xd (czy jest ok?)
- czym jest generuj raport w sekcji dzieci? xd
- uporządkowanie wpisów do bazy danych
- co z raportami? xd -- chcesz pomóc? xd

## What to do on May 25 for PP
- tak by kwoty były większe niż 99.99 dla przychodow i wydatków cyklicznych (dla tych zwyklych jest ok),
- edytowanie cyklicznych: tak by czestotliwosc i kategoria były listami, bo teraz mozna z pacla zmnienic a to psuje baze,
- dla kategorii: by była tabelka z tymi kategoriami,
- dodaj przycisk usun kategorie i mozliwosc tylko dla admina -- patrz usuwanie cyklicznych:
```cpp
bool deleteCategory(const QString &nazwa);
bool mIadmin();
```
- przycisk na ukrywanie hasel dla tabelki z uzytkownikami dla admina (ze mozesz pokazac hasla i ukryc),
- wartość aktualnego budzetu i daty aktualizacji:
```cpp
double get_whole_budzet();
QDate get_update_Date();
```
- tabelki dla przychodow i wydatkow (bez edycji ale z taką samą widocznością jak cykliczne -- patrz cykliczne),
- przycisk dodaj rodzica nr.2 -- patrz przcisk dodaj rodzica (nr.1):
```cpp
bool addFirstParent(int IDchild, int IDparent1);
bool addSecondParent(int IDchild, int IDparent2);
```
- dodaj przycisk "update Children" bedzie on tworzyl te encje dzieci dla uzytkownikow z rola dziecko jesli nie ma on encji dzieci (poki co podpiąłem pod wylogowywanie):
```cpp
bool update_Children();
```
- dodaj zeby dla uzytkownikow rola nie byla z palca tylko wybierane (żeby było rozwijane i wybieram z dostępnych),
- do danych uzytkownika saldo i kieszonkowe jesli dziecko:
```cpp
bool amIChild();
float get_kieszonkowe(int child_ID);
float get_saldo(int child_ID);
int get_user_ID();
```
- dodaj miejsce na wyświetlanie kieszokowego bo na razie wszzystko dalem do salda (saldo i kieszonkowe) w zakładce dzieci, albo usun ten wielki prostokat dla kieosznkowego.
- sprawdzenie czy wszystko jest i jest ok,
