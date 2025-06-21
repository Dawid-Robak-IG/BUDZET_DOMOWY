-- MySQL dump 10.13  Distrib 8.0.42, for Linux (x86_64)
--
-- Host: localhost    Database: BUDZET_DOMOWY
-- ------------------------------------------------------
-- Server version	8.0.42-0ubuntu0.24.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `Budzet domowy`
--

DROP TABLE IF EXISTS `Budzet domowy`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Budzet domowy` (
  `ID` int NOT NULL AUTO_INCREMENT,
  `Kwota` double NOT NULL,
  `OperacjaID` int NOT NULL,
  PRIMARY KEY (`ID`),
  KEY `FKBud¿et dom282223` (`OperacjaID`),
  CONSTRAINT `FKBud¿et dom282223` FOREIGN KEY (`OperacjaID`) REFERENCES `Operacja` (`ID`)
) ENGINE=InnoDB AUTO_INCREMENT=84 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Budzet domowy`
--

LOCK TABLES `Budzet domowy` WRITE;
/*!40000 ALTER TABLE `Budzet domowy` DISABLE KEYS */;
INSERT INTO `Budzet domowy` VALUES (1,4800,10),(2,9600,11),(3,14400,12),(4,19200,13),(5,24000,14),(6,24250,15),(7,24400,16),(8,24060,17),(9,23939.41,18),(10,23849.41,19),(11,23649.41,20),(12,23539.41,21),(13,23339.41,22),(14,22996.57,23),(15,22796.57,24),(16,22546.57,25),(17,23746.57,26),(18,24096.57,27),(19,24192.31,28),(20,23952.31,29),(21,23876.31,30),(22,23477.31,31),(23,23297.31,32),(24,22737.31,33),(25,22487.31,34),(26,21867.31,35),(27,21247.31,36),(28,20627.31,37),(29,20007.31,38),(30,19387.31,39),(31,24887.31,40),(32,30387.31,41),(33,35887.31,42),(34,41387.31,43),(35,46887.31,44),(36,46612.31,45),(37,46337.31,46),(38,46062.31,47),(39,46562.31,48),(40,46222.31,49),(41,46892.31,50),(42,47091.31,51),(43,52691.31,52),(44,58291.31,53),(45,63891.31,54),(46,63691.31,55),(47,63491.31,56),(48,63291.31,57),(49,63091.31,58),(50,62971.31,59),(51,61481.31,60),(52,61341.31,61),(53,62291.31,73),(54,63241.31,74),(55,64191.31,75),(56,65141.31,76),(57,66091.31,77),(58,65891.31,78),(59,65691.31,79),(60,65491.31,80),(61,65291.31,81),(62,65091.31,82),(63,64891.31,83),(64,64691.31,84),(65,64661.31,85),(66,64611.31,86),(67,64561.31,87),(68,64514.31,88),(69,64264.31,89),(70,63924.31,90),(71,63584.31,91),(72,63497.31,92),(73,63462.31,93),(74,63551.31,94),(75,63456.31,95),(76,63402.31,96),(77,69602.31,97),(78,75802.31,98),(79,82002.31,99),(80,88202.31,100),(81,87882.31,101),(82,87562.31,102),(83,86062.31,103);
/*!40000 ALTER TABLE `Budzet domowy` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Dziecko`
--

DROP TABLE IF EXISTS `Dziecko`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Dziecko` (
  `Uzytkownik zalogowanyID` int NOT NULL,
  `Saldo` double NOT NULL,
  `Kieszonkowe` double DEFAULT NULL,
  `ID_Rodzic1` int DEFAULT NULL,
  `ID_Rodzic2` int DEFAULT NULL,
  `DataKolejnaKieszonkowego` date DEFAULT NULL,
  PRIMARY KEY (`Uzytkownik zalogowanyID`),
  KEY `FKDziecko833546` (`ID_Rodzic1`),
  KEY `FKDziecko833545` (`ID_Rodzic2`),
  CONSTRAINT `FKDziecko833545` FOREIGN KEY (`ID_Rodzic2`) REFERENCES `Uzytkownik zalogowany` (`ID`),
  CONSTRAINT `FKDziecko833546` FOREIGN KEY (`ID_Rodzic1`) REFERENCES `Uzytkownik zalogowany` (`ID`),
  CONSTRAINT `FKDziecko923729` FOREIGN KEY (`Uzytkownik zalogowanyID`) REFERENCES `Uzytkownik zalogowany` (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Dziecko`
--

LOCK TABLES `Dziecko` WRITE;
/*!40000 ALTER TABLE `Dziecko` DISABLE KEYS */;
INSERT INTO `Dziecko` VALUES (2,-17,0,NULL,NULL,'2025-07-01'),(7,-56,0,NULL,NULL,'2025-07-01'),(8,157,0,NULL,NULL,'2025-07-01'),(11,0,0,NULL,NULL,'2025-07-01');
/*!40000 ALTER TABLE `Dziecko` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Kategoria`
--

DROP TABLE IF EXISTS `Kategoria`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Kategoria` (
  `Nazwa` varchar(255) NOT NULL,
  `Uzytkownik zalogowanyID` int NOT NULL,
  PRIMARY KEY (`Nazwa`),
  KEY `FKKategoria 746861` (`Uzytkownik zalogowanyID`),
  CONSTRAINT `FKKategoria 746861` FOREIGN KEY (`Uzytkownik zalogowanyID`) REFERENCES `Uzytkownik zalogowany` (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Kategoria`
--

LOCK TABLES `Kategoria` WRITE;
/*!40000 ALTER TABLE `Kategoria` DISABLE KEYS */;
INSERT INTO `Kategoria` VALUES ('Dom i ogród',1),('Odzież i obuwie',1),('Podróże',1),('Rachunki',1),('Rozrywka',1),('Hobby',5),('Inne',5),('Jedzenie',5),('Pensja',5),('Podatki',5),('Prezent',5),('Renta',5),('Sport',5),('Sprzedaż',5),('Zdrowie',5),('Dywidenda',8);
/*!40000 ALTER TABLE `Kategoria` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Operacja`
--

DROP TABLE IF EXISTS `Operacja`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Operacja` (
  `ID` int NOT NULL AUTO_INCREMENT,
  `Kwota` double NOT NULL,
  `Data` date NOT NULL,
  `Notatka` varchar(255) DEFAULT NULL,
  `Uzytkownik zalogowanyID` int NOT NULL,
  `Kategoria Nazwa` varchar(255) NOT NULL,
  `czy_z_cyklicznego` int NOT NULL,
  `Operacja cyklicznaID` int DEFAULT NULL,
  PRIMARY KEY (`ID`),
  KEY `FKOperacja423377` (`Uzytkownik zalogowanyID`),
  KEY `FKOperacja368305` (`Kategoria Nazwa`),
  KEY `FKOperacja232880` (`Operacja cyklicznaID`),
  CONSTRAINT `FKOperacja232880` FOREIGN KEY (`Operacja cyklicznaID`) REFERENCES `Operacja cykliczna` (`ID`),
  CONSTRAINT `FKOperacja368305` FOREIGN KEY (`Kategoria Nazwa`) REFERENCES `Kategoria` (`Nazwa`),
  CONSTRAINT `FKOperacja423377` FOREIGN KEY (`Uzytkownik zalogowanyID`) REFERENCES `Uzytkownik zalogowany` (`ID`)
) ENGINE=InnoDB AUTO_INCREMENT=104 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Operacja`
--

LOCK TABLES `Operacja` WRITE;
/*!40000 ALTER TABLE `Operacja` DISABLE KEYS */;
INSERT INTO `Operacja` VALUES (1,150,'2025-05-10','od dziadków na urodziny',2,'Prezent',0,NULL),(2,100,'2025-04-07','Nagroda szkolna',2,'Inne',0,NULL),(3,60,'2025-06-21','Pomoc sąsiadce',2,'Inne',0,NULL),(4,-50,'2025-05-28','Gra planszowa',2,'Inne',0,NULL),(5,-12,'2025-01-09','Słodzycze',2,'Jedzenie',0,NULL),(6,-45,'2025-04-05','Prezent dla kolegi',2,'Inne',0,NULL),(7,-5,'2025-06-01','Lody',2,'Jedzenie',0,NULL),(8,-20,'2025-04-30','Frytki',2,'Jedzenie',0,NULL),(9,300,'2025-06-21','Stypendium sportowe',2,'Inne',0,NULL),(10,4800,'2025-02-08','Pensja Basia',3,'Pensja',1,1),(11,4800,'2025-03-08','Pensja Basia',3,'Pensja',1,1),(12,4800,'2025-04-08','Pensja Basia',3,'Pensja',1,1),(13,4800,'2025-05-08','Pensja Basia',3,'Pensja',1,1),(14,4800,'2025-06-08','Pensja Basia',3,'Pensja',1,1),(15,250,'2025-03-06','Zwrot podatku',3,'Podatki',0,NULL),(16,150,'2025-04-12','Sprzedaż fotelika dla dziecka',3,'Inne',0,NULL),(17,-340,'2025-01-08','Tygodniowe zakupy',3,'Jedzenie',0,NULL),(18,-120.59,'2025-03-12','Sukienka',3,'Inne',0,NULL),(19,-90,'2025-02-03','Chemia do sprzątania',3,'Dom i ogród',0,NULL),(20,-200,'2025-03-03','Paliwo',3,'Podróże',0,NULL),(21,-110,'2025-03-19','Ubezpieczenie',3,'Inne',0,NULL),(22,-200,'2025-04-30','Podręcznik do nauki angielskiego',3,'Inne',0,NULL),(23,-342.84,'2025-04-10','Zakupy spożywcze',3,'Jedzenie',0,NULL),(24,-200,'2025-05-15','Fryzjer',3,'Rozrywka',0,NULL),(25,-250,'2025-01-15','Prezenty – „Dzień Babci i Dziadka”',3,'Rozrywka',0,NULL),(26,1200,'2025-03-07','Premia',4,'Pensja',0,NULL),(27,350,'2025-04-16','Zasiłek rodzinny',4,'Inne',0,NULL),(28,95.74,'2025-06-21','Cashback z karty',4,'Inne',0,NULL),(29,-240,'2025-02-04','Wymiana oleju w samochodzie',4,'Podróże',0,NULL),(30,-76,'2025-03-07','Kwiaty ',4,'Prezent',0,NULL),(31,-399,'2025-05-09','Nowy blender',4,'Dom i ogród',0,NULL),(32,-180,'2025-06-06','Kino z rodziną',4,'Rozrywka',0,NULL),(33,-560,'2025-05-12','Ubezpieczenie OC',4,'Inne',0,NULL),(34,-250,'2025-06-21','Paliwo',4,'Podróże',0,NULL),(35,-620,'2025-02-09','Prąd + gaz',4,'Rachunki',1,3),(36,-620,'2025-03-09','Prąd + gaz',4,'Rachunki',1,3),(37,-620,'2025-04-09','Prąd + gaz',4,'Rachunki',1,3),(38,-620,'2025-05-09','Prąd + gaz',4,'Rachunki',1,3),(39,-620,'2025-06-09','Prąd + gaz',4,'Rachunki',1,3),(40,5500,'2025-02-03','Pensja Artur',4,'Pensja',1,4),(41,5500,'2025-03-03','Pensja Artur',4,'Pensja',1,4),(42,5500,'2025-04-03','Pensja Artur',4,'Pensja',1,4),(43,5500,'2025-05-03','Pensja Artur',4,'Pensja',1,4),(44,5500,'2025-06-03','Pensja Artur',4,'Pensja',1,4),(45,-275,'2025-03-24','ajęcia dodatkowe dzieci',4,'Rachunki',1,5),(46,-275,'2025-04-24','ajęcia dodatkowe dzieci',4,'Rachunki',1,5),(47,-275,'2025-05-24','ajęcia dodatkowe dzieci',4,'Rachunki',1,5),(48,500,'2025-05-12','Premia nadgodziny',6,'Pensja',0,NULL),(49,-340,'2025-04-18','Dopłata podatku',6,'Podatki',0,NULL),(50,670,'2025-03-10','Sprzedaż telefonu',6,'Inne',0,NULL),(51,-199,'2025-01-29','Nowy router Wi-Fi',6,'Rozrywka',0,NULL),(52,5600,'2025-04-06','Pensja Jakub',6,'Pensja',1,6),(53,5600,'2025-05-06','Pensja Jakub',6,'Pensja',1,6),(54,5600,'2025-06-06','Pensja Jakub',6,'Pensja',1,6),(55,-200,'2025-03-10','Internet, telefon, telewizja',6,'Rozrywka',1,7),(56,-200,'2025-04-10','Internet, telefon, telewizja',6,'Rozrywka',1,7),(57,-200,'2025-05-10','Internet, telefon, telewizja',6,'Rozrywka',1,7),(58,-200,'2025-06-10','Internet, telefon, telewizja',6,'Rozrywka',1,7),(59,-120,'2025-02-11','Prezent walentynki',6,'Prezent',0,NULL),(60,-1490,'2025-04-10','Kurs IT',6,'Inne',0,NULL),(61,-140,'2025-05-08','Pizza ze znajomymi',6,'Jedzenie',0,NULL),(62,-59,'2025-03-04','Subskrypcja Spotify',7,'Rozrywka',0,NULL),(63,150,'2025-01-20','Na urodziny od babci',7,'Prezent',0,NULL),(64,60,'2025-06-21','Sprzedaż ubrań',7,'Inne',0,NULL),(65,-50,'2025-03-13','Pizza z przyjaciółką',7,'Jedzenie',0,NULL),(66,-20,'2025-04-11','Przybory szkolne',7,'Inne',0,NULL),(67,-42,'2025-06-24','Lody i lemoniada',7,'Jedzenie',0,NULL),(68,-95,'2025-05-23',' Prezent dla mamy',7,'Prezent',0,NULL),(69,150,'2025-01-20','Urodziny – prezent',8,'Prezent',0,NULL),(70,60,'2025-04-17','Pomoc sąsiadowi',8,'Inne',0,NULL),(71,-35,'2025-05-29','Składka na turniej',8,'Sport',0,NULL),(72,-18,'2025-03-12','Lody i napoje',8,'Jedzenie',0,NULL),(73,950,'2025-02-10','Renta Ela',10,'Renta',1,8),(74,950,'2025-03-10','Renta Ela',10,'Renta',1,8),(75,950,'2025-04-10','Renta Ela',10,'Renta',1,8),(76,950,'2025-05-10','Renta Ela',10,'Renta',1,8),(77,950,'2025-06-10','Renta Ela',10,'Renta',1,8),(78,-200,'2025-05-05','Rehabilitacja',10,'Inne',1,9),(79,-200,'2025-05-12','Rehabilitacja',10,'Inne',1,9),(80,-200,'2025-05-19','Rehabilitacja',10,'Inne',1,9),(81,-200,'2025-05-26','Rehabilitacja',10,'Inne',1,9),(82,-200,'2025-06-02','Rehabilitacja',10,'Inne',1,9),(83,-200,'2025-06-09','Rehabilitacja',10,'Inne',1,9),(84,-200,'2025-06-16','Rehabilitacja',10,'Inne',1,9),(85,-30,'2025-02-26','Akcesoria dla kota',10,'Dom i ogród',0,NULL),(86,-50,'2025-05-30','Artykuły biurowe',10,'Rozrywka',0,NULL),(87,-50,'2025-01-28','Kawa ziarnista ',10,'Jedzenie',0,NULL),(88,-47,'2025-04-06','Kabel USB-C i ładowarka',10,'Inne',0,NULL),(89,-250,'2025-06-26','Zapas tuszów do drukarki',10,'Dom i ogród',0,NULL),(90,-340,'2025-06-09','Nowy monitor (używany)',12,'Hobby',0,NULL),(91,-340,'2025-02-25','Kurs \"Python w finansach\"',12,'Hobby',0,NULL),(92,-87,'2025-01-06','Nowy koc i poduszki (IKEA)',12,'Dom i ogród',0,NULL),(93,-35,'2025-06-19','Książka',12,'Hobby',0,NULL),(94,89,'2025-04-04','Sprzedaż obrazu',12,'Hobby',0,NULL),(95,-95,'2025-01-13','Donacja na WOŚP',12,'Inne',0,NULL),(96,-54,'2025-06-21','Bilety na wystawę w muzeum',12,'Rozrywka',0,NULL),(97,6200,'2025-03-12','Pensja Maja',12,'Pensja',1,10),(98,6200,'2025-04-12','Pensja Maja',12,'Pensja',1,10),(99,6200,'2025-05-12','Pensja Maja',12,'Pensja',1,10),(100,6200,'2025-06-12','Pensja Maja',12,'Pensja',1,10),(101,-320,'2025-05-08','Karnet siłownia',12,'Sport',1,11),(102,-320,'2025-06-08','Karnet siłownia',12,'Sport',1,11),(103,-1500,'2025-06-21','Nowy laptop',5,'Rozrywka',0,NULL);
/*!40000 ALTER TABLE `Operacja` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Operacja cykliczna`
--

DROP TABLE IF EXISTS `Operacja cykliczna`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Operacja cykliczna` (
  `ID` int NOT NULL AUTO_INCREMENT,
  `Kwota` double NOT NULL,
  `Data` date NOT NULL,
  `Notatka` varchar(255) DEFAULT NULL,
  `Czestotliwosc` varchar(255) NOT NULL,
  `Uzytkownik zalogowanyID` int NOT NULL,
  `Kategoria` varchar(255) DEFAULT NULL,
  `DataKolejna` date DEFAULT NULL,
  PRIMARY KEY (`ID`),
  KEY `FKOperacja c774395` (`Uzytkownik zalogowanyID`),
  KEY `FKOperacja c719323` (`Kategoria`),
  CONSTRAINT `FKOperacja c719323` FOREIGN KEY (`Kategoria`) REFERENCES `Kategoria` (`Nazwa`),
  CONSTRAINT `FKOperacja c774395` FOREIGN KEY (`Uzytkownik zalogowanyID`) REFERENCES `Uzytkownik zalogowany` (`ID`)
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Operacja cykliczna`
--

LOCK TABLES `Operacja cykliczna` WRITE;
/*!40000 ALTER TABLE `Operacja cykliczna` DISABLE KEYS */;
INSERT INTO `Operacja cykliczna` VALUES (1,4800,'2025-01-08','Pensja Basia','Co miesiąc',3,'Pensja','2025-07-08'),(2,-200,'2025-06-21','Woda','Co miesiąc',3,'Rachunki','2025-07-21'),(3,-620,'2025-01-09','Prąd + gaz','Co miesiąc',4,'Rachunki','2025-07-09'),(4,5500,'2025-01-03','Pensja Artur','Co miesiąc',4,'Pensja','2025-07-03'),(5,-275,'2025-02-24','Zajęcia dodatkowe dzieci','Co miesiąc',4,'Rachunki','2025-06-24'),(6,5600,'2025-03-06','Pensja Jakub','Co miesiąc',6,'Pensja','2025-07-06'),(7,-200,'2025-02-10','Internet, telefon, telewizja','Co miesiąc',6,'Rozrywka','2025-07-10'),(8,950,'2025-01-10','Renta Ela','Co miesiąc',10,'Renta','2025-07-10'),(9,-200,'2025-04-28','Rehabilitacja','Co tydzień',10,'Inne','2025-06-23'),(10,6200,'2025-02-12','Pensja Maja','Co miesiąc',12,'Pensja','2025-07-12'),(11,-320,'2025-04-08','Karnet siłownia','Co miesiąc',12,'Sport','2025-07-08');
/*!40000 ALTER TABLE `Operacja cykliczna` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Uzytkownik zalogowany`
--

DROP TABLE IF EXISTS `Uzytkownik zalogowany`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Uzytkownik zalogowany` (
  `ID` int NOT NULL AUTO_INCREMENT,
  `Imie` varchar(255) NOT NULL,
  `Nazwisko` varchar(255) NOT NULL,
  `Email` varchar(255) NOT NULL,
  `Haslo` varchar(255) NOT NULL,
  `Czy_zablokowany` tinyint(1) NOT NULL DEFAULT '0',
  `Data urodzenia` date NOT NULL,
  `Rola` varchar(255) NOT NULL,
  PRIMARY KEY (`ID`),
  UNIQUE KEY `Email` (`Email`)
) ENGINE=InnoDB AUTO_INCREMENT=16 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Uzytkownik zalogowany`
--

LOCK TABLES `Uzytkownik zalogowany` WRITE;
/*!40000 ALTER TABLE `Uzytkownik zalogowany` DISABLE KEYS */;
INSERT INTO `Uzytkownik zalogowany` VALUES (1,'Janusz','Janski','januszek@gmail.com','haslo123',0,'1975-01-20','Admin'),(2,'Mikołaj','Wielki','mikolaj96@gmail.com','miki018',0,'2020-05-10','Dziecko'),(3,'Basia','Maczna','baska@ya.com','makabasi',0,'1980-01-10','Rodzic'),(4,'Artur','Dobry','asd@asd.com','asdasd',0,'1970-12-29','Rodzic'),(5,'Jan','Prus','janprus@poczta.com','haslo123',0,'2000-03-04','Admin'),(6,'Jakub','Test','jakub.test@gmail.com','testjakub',0,'2005-03-20','Rodzic'),(7,'Aleksandra','Gral','ola.gral@wp.pl','aleksandra63',0,'2009-01-20','Dziecko'),(8,'Jan','Nowak','abc@gmail.com','haslo123',0,'2020-01-20','Dziecko'),(9,'Teresa','Sad','teresa@gmail.com','sad54321',0,'1955-05-22','Użytkownik'),(10,'Ela','Kot','elakot@wp.pl','elaToJa318',0,'1979-05-22','Rodzic'),(11,'Szaralinda','Łączka','szaraL@o2.pl','popopoko',1,'2015-03-01','Dziecko'),(12,'Maja','Ełska','me@gmail.com','hasloMocne)(00',0,'1986-08-26','Rodzic'),(14,'Małgorzata','Prus','gosiaP@gmail.com','mo54yh',0,'2010-06-18','Użytkownik'),(15,'Tomasz','Prus','tPrus@wp.pl','prust749',0,'2000-10-20','Dorosły');
/*!40000 ALTER TABLE `Uzytkownik zalogowany` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Temporary view structure for view `V_Dziecko_Relacje`
--

DROP TABLE IF EXISTS `V_Dziecko_Relacje`;
/*!50001 DROP VIEW IF EXISTS `V_Dziecko_Relacje`*/;
SET @saved_cs_client     = @@character_set_client;
/*!50503 SET character_set_client = utf8mb4 */;
/*!50001 CREATE VIEW `V_Dziecko_Relacje` AS SELECT 
 1 AS `DzieckoUserID`,
 1 AS `DzieckoImieNazwisko`,
 1 AS `saldo`,
 1 AS `kieszonkowe`,
 1 AS `ID_Rodzic1`,
 1 AS `ID_Rodzic2`,
 1 AS `DataKolejnaKieszonkowego`*/;
SET character_set_client = @saved_cs_client;

--
-- Temporary view structure for view `V_UzytkownikWidoczny`
--

DROP TABLE IF EXISTS `V_UzytkownikWidoczny`;
/*!50001 DROP VIEW IF EXISTS `V_UzytkownikWidoczny`*/;
SET @saved_cs_client     = @@character_set_client;
/*!50503 SET character_set_client = utf8mb4 */;
/*!50001 CREATE VIEW `V_UzytkownikWidoczny` AS SELECT 
 1 AS `ID`,
 1 AS `ImieNazwisko`*/;
SET character_set_client = @saved_cs_client;

--
-- Final view structure for view `V_Dziecko_Relacje`
--

/*!50001 DROP VIEW IF EXISTS `V_Dziecko_Relacje`*/;
/*!50001 SET @saved_cs_client          = @@character_set_client */;
/*!50001 SET @saved_cs_results         = @@character_set_results */;
/*!50001 SET @saved_col_connection     = @@collation_connection */;
/*!50001 SET character_set_client      = utf8mb4 */;
/*!50001 SET character_set_results     = utf8mb4 */;
/*!50001 SET collation_connection      = utf8mb4_0900_ai_ci */;
/*!50001 CREATE ALGORITHM=UNDEFINED */
/*!50013 DEFINER=`root`@`localhost` SQL SECURITY DEFINER */
/*!50001 VIEW `V_Dziecko_Relacje` AS select `d`.`Uzytkownik zalogowanyID` AS `DzieckoUserID`,`u`.`ImieNazwisko` AS `DzieckoImieNazwisko`,`d`.`Saldo` AS `saldo`,`d`.`Kieszonkowe` AS `kieszonkowe`,`d`.`ID_Rodzic1` AS `ID_Rodzic1`,`d`.`ID_Rodzic2` AS `ID_Rodzic2`,`d`.`DataKolejnaKieszonkowego` AS `DataKolejnaKieszonkowego` from (`Dziecko` `d` join `V_UzytkownikWidoczny` `u` on((`d`.`Uzytkownik zalogowanyID` = `u`.`ID`))) */;
/*!50001 SET character_set_client      = @saved_cs_client */;
/*!50001 SET character_set_results     = @saved_cs_results */;
/*!50001 SET collation_connection      = @saved_col_connection */;

--
-- Final view structure for view `V_UzytkownikWidoczny`
--

/*!50001 DROP VIEW IF EXISTS `V_UzytkownikWidoczny`*/;
/*!50001 SET @saved_cs_client          = @@character_set_client */;
/*!50001 SET @saved_cs_results         = @@character_set_results */;
/*!50001 SET @saved_col_connection     = @@collation_connection */;
/*!50001 SET character_set_client      = utf8mb4 */;
/*!50001 SET character_set_results     = utf8mb4 */;
/*!50001 SET collation_connection      = utf8mb4_0900_ai_ci */;
/*!50001 CREATE ALGORITHM=UNDEFINED */
/*!50013 DEFINER=`root`@`localhost` SQL SECURITY DEFINER */
/*!50001 VIEW `V_UzytkownikWidoczny` AS select `Uzytkownik zalogowany`.`ID` AS `ID`,concat(`Uzytkownik zalogowany`.`Imie`,' ',`Uzytkownik zalogowany`.`Nazwisko`) AS `ImieNazwisko` from `Uzytkownik zalogowany` */;
/*!50001 SET character_set_client      = @saved_cs_client */;
/*!50001 SET character_set_results     = @saved_cs_results */;
/*!50001 SET collation_connection      = @saved_col_connection */;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2025-06-21 13:59:08
