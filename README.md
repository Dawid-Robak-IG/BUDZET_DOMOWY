# Budzet_Domowy

## Co zainstalować
- dbeaver
- mysql:
```bash
sudo apt update
sudo apt install mysql-server
sudo apt install dbeaver-ce
```
## Jak sprawdzić czy działa baza danych
```bash
sudo systemctl status mysql
```
## Jak ustawić hasło (admin)
```bash
sudo mysql
ALTER USER 'root'@'localhost' IDENTIFIED WITH mysql_native_password BY 'admin';
```
## Jak wejść w terminal SQL
```bash
mysql -u root -p
```
i wpisujemy hasło **admin**
## Co zrobić by móc wgrać bazę (backup_baza.sql)
Należy stworzyć baze danych w dbeaver: **BUDZET_DOMOWY**.
Następnie nowe zapytanie SQL i wklejamy tam zawartość pliku **backup_baza.sql**. OStatecznie uruchamiamy zapytanie ( taki pomarańzowy trójkącik po lewej stronie).

## Co zrobić by zrobić backup
W terminalu należy wpisać:
```bash
mysqldump -u root -p BUDZET_DOMOWY > backup_baza.sql
```
gdy jest się w folderze z repozytorium.
## Co potrzeba by qt mogło się włączyć
Biblioteki qt dla mysql:
```bash
sudo apt install libqt5sql5-mysql
```