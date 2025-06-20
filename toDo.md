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
- sprawdzenie działania przyszlego calego budzetu


## Zastanawianie sie
- haszowniae hasel? XDD
- co z edycją xd (czy jest ok?)
- czym jest generuj raport w sekcji dzieci? xd
- uporządkowanie wpisów do bazy danych
- co z raportami? xd 

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
- dodaj guzik go generowania raportów tylko dla własnych wpisów (już zrobiłem sot w Tab_Raporty):
```cpp
Tab_Raporty::GenerujMyRaportClicked()
```
- dodaj miejsce na wyświetlanie kieszokowego bo na razie wszzystko dalem do salda (saldo i kieszonkowe) w zakładce dzieci, albo usun ten wielki prostokat dla kieosznkowego.
- dodaj w sekcji raport możliwość wyboru użytkownika (dla admina) dla którego chce on wygenerować raport. Wybieramy po mailu, ale chcemy dostać ID.Każdy inny będzie generował tylko dla siebie:
```cpp
int get_ID_by_mail(QString mail);
m_dbManager->getMyBudzetData(startDate, endDate, m_dbManager->get_user_ID());
m_dbManager->getMyPrzychody(startDate, endDate, m_dbManager->get_user_ID()); 
m_dbManager->getMyWydatki(startDate, endDate, m_dbManager->get_user_ID());
```
- dodaj wybór kategorii od czego chemy mieć raport. Jeśli wybierzemy kategorię to powinnaś dawać wtedy ( i tylko wtedy) nazwe kategorii do wywołania tych funkcji:
```cpp
int get_ID_by_mail(QString mail);
m_dbManager->getMyBudzetData(startDate, endDate, m_dbManager->get_user_ID(),"Pensja");
m_dbManager->getMyPrzychody(startDate, endDate, m_dbManager->get_user_ID(),"Pensja"); 
m_dbManager->getMyWydatki(startDate, endDate, m_dbManager->get_user_ID(),"Pensja");
```
-dodaj wybor daty dla generowania przyszlego stanu konta (zależne też to będzie od tego wyboru uzytkownika dla admina) można tez dodać przycisk który otworzy okienko z do wyobru datą i użytkownikiem jak wolisz, jak nie wybierzemy uzytkownika to dla calego budzetu (lae wtedy dziecko nie moze) to mozesz dodac do wyboru budzet np:
```cpp
double user_future_Budzet(int user_ID, QDate future_Date);
double whole_future_Budzet(QDate future_Date);
```
- pierwszy uzytkownik ma byc adminem,
- nowi maja bc uzytkownikiem,
- sprawdzenie czy wszystko jest i jest ok,


## What to do on 08.06
 Z poprzednich zadań (nie wiem czy to aktualne):
 
- ✅ 
- ✅ sprwadzić czy to jest tak jak miało być: dodaj wybor daty dla generowania przyszlego stanu konta (zależne też to będzie od tego wyboru uzytkownika dla admina) można tez dodać przycisk który otworzy okienko z do wyobru datą i użytkownikiem jak wolisz, jak nie wybierzemy uzytkownika to dla calego budzetu (lae wtedy dziecko nie moze) to mozesz dodac do wyboru budzet np:
```cpp
double user_future_Budzet(int user_ID, QDate future_Date);
double whole_future_Budzet(QDate future_Date);
```
Po konsultacjach: 

- ✅ wyświetlać datę następnego wpływu kieszonkowego (???) - PP
- ✅ usunąć przycisk edytuj z cykliczne - PP
- ✅ zamiast 0 1 w 'czy zablokowany?' to wyświetlać napis zablokowany/aktywny - DR
- ✅ zamiast id wyświetlać imię i nazwisko (cykliczne, budzet, dzieci)- DR
- ✅ gdy aktualizuje się budżet to trzeba zrobić, żeby zaktualizowały się pola w zakładce budżet - DR
- ✅ poblokować zakładki dla dzieci(tych których i tak nie mogą używać)  -> żeby się nie wyświetlały - PP
- ✅ przy przelogowaniu nie zmieniają się dane - DR
- ✅ moje dane zakładka (zmiana nazwy pierwszej zakładki) - PP
- ✅ cykliczna / jednorazowa (napis zamiast 0/1) - DR
- ✅ wyświetlać przyczynę błędu, gdy nie może usunąć kategorii - DR
- 🟡 od razu wyświetlać że nie jest wybrany (chodziło o kolejność pokazywania się okienek z ostrzeżeniami/błędami przy wybieraniu pól z tabeli) - PP
- ✅ wykres budżet schodki, reszta słupki - DR
- ✅ cały rok, czyli inny format daty - DR
- ✅ lista roli w użytkownicy (zamiast wpisywać z palca, żeby była rozwiajna lista) - PP
- ✅ tabela z rodzicami żeby było widać jakich rodziców ma dziecko (dodać kolumnę z rodzicami tam gdzie jest podpinanie relacji) - PP
- ✅ imiona i nazwiska zamiast id - w Relacjach
- 🟡✅ sprawdzić dla różnych ról czy mają dostęp tylko do tych opcji i zakładek do których powinni (zgodnie z naszą dokumentacją) - (zrobiłam funkcję i wstępnie ukryłam zakładki, ale to trzeba jeszcze przemyśleć) PP/DR
- ✅ dodać kolor dla tabeli budżetu - PP
- ✅ dodać dla progrnozy poczatkową date - PP
- ✅ kolorki dla użytkowników zależne od ról - PP -> tego nie robię bo jest już ładnie
- ✅ zapis raportów - DR
- ✅ ustawić odpowiednie rozmiary dla tabeli i innych pól - PP
- ✅ wyrzucenie przycisków edytuj tam gdzie nie są potrzebne - PP
- ✅ usunąć możliwość edycji imie i nazwisko w cykliczne P - DR
- ✅ co ostatecznie z raportem generowanym przez dziecko -- przycisk generuj raport w sekcji dzieci - PP
- ✅ poprawić zablokowania usuwania admina - DR

- ✅ (wyskakiwała przecież wiadomość że nie rozpoznał czestotliwosci wiec nie był w stanie ustawić nowej...) jak się dodaje cykliczny to chyba nie aktualizuje się data kolejnego, więc za każdym razem jak wchodzi się do aplikacji to odejmuje się jeśli jest ten dzień w którym ta operacja ma się wykonać, może trzeba przy zamianie częstotliwości obliczać na nowo następną datę?


## 18.06.2025
- ✅ raport: moje czy twoje przychody? -- dac moje -- DR
- ✅ rola podstawowa? : -- ustalamy że użytkownik (nie dziecko)
    - ogólnie w pliku jest że dziecko,
    - moim zdaniem to nie dobrze zeby to bylo dziecko i powinien to byc uzytkownik ( w domysle niezdefiniowany),
- ✅ dodanie: sprawdzenie informacji na temat aplikacji: - PP
    - musi być dla niezalogowanego
    - może przycisk co wświetli okienko,
    - info o autorach,
    - info o wersji
    - info o wykorzystanych technologiach (MySQL, Qt5),
- skasować stare wpisy, zrobić porządne nowe - PP
- ✅ poprawić prognozy bo są stałe - DR
- ✅dodać możliwość segregacji danych w tabelce budzet domowy - PP
- ✅ po zmianie hasła nie aktualizuje się w "moje dane"
- prognozy bez dnia --> sam rok i miesiąc PP

- porządki w kodzie (np. wyrzucić niepotrzebne qDebug())
- sprawdzać i czytać dokładnie to co się wyświetla i czy to ma sens (czy nie ma literówek, czy dany użytkownik powinien mieć do tego dostęp itp.)





