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
) ENGINE=InnoDB AUTO_INCREMENT=10752 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Budzet domowy`
--

LOCK TABLES `Budzet domowy` WRITE;
/*!40000 ALTER TABLE `Budzet domowy` DISABLE KEYS */;
INSERT INTO `Budzet domowy` VALUES (10746,-150,10774),(10747,-200,10775),(10748,-212,10776),(10749,-122,10777),(10750,4878,10778),(10751,4678,10779);
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
INSERT INTO `Dziecko` VALUES (7,0,150,3,4,'2025-06-01'),(8,0,150,NULL,NULL,'2025-06-01'),(10,0,130,4,3,'2025-06-01'),(11,0,200,NULL,NULL,'2025-06-01'),(12,44,0,NULL,NULL,'2025-06-01');
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
INSERT INTO `Kategoria` VALUES ('Rachunki',1),('Inne',5),('Jedzenie',5),('Pensja',5),('Prezent',5),('Renta',5),('Sport',5),('Dywidenda',8);
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
) ENGINE=InnoDB AUTO_INCREMENT=10780 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Operacja`
--

LOCK TABLES `Operacja` WRITE;
/*!40000 ALTER TABLE `Operacja` DISABLE KEYS */;
INSERT INTO `Operacja` VALUES (10772,50,'2025-05-17','Urodziny',12,'Inne',0,NULL),(10773,-6,'2025-05-24','Pączek',12,'Jedzenie',0,NULL),(10774,-150,'2025-05-25','zakupy - odzież',1,'Inne',0,NULL),(10775,-50,'2025-05-04','basen',1,'Sport',0,NULL),(10776,-12,'2025-04-09','Fryzjer',3,'Inne',0,NULL),(10777,90,'2025-05-20','Korepetycje',3,'Inne',0,NULL),(10778,5000,'2025-05-02','',3,'Pensja',1,37),(10779,-200,'2025-05-09','',3,'Rachunki',1,38);
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
) ENGINE=InnoDB AUTO_INCREMENT=39 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Operacja cykliczna`
--

LOCK TABLES `Operacja cykliczna` WRITE;
/*!40000 ALTER TABLE `Operacja cykliczna` DISABLE KEYS */;
INSERT INTO `Operacja cykliczna` VALUES (35,3000,'2025-05-02','','Co miesiąc',1,'Pensja','2025-06-02'),(36,-150,'2025-05-13','Internet i telefon','Co miesiąc',1,'Rachunki','2025-06-13'),(37,5000,'2025-04-02','','Co miesiąc',3,'Pensja','2025-06-02'),(38,-200,'2025-05-02','','Co tydzień',3,'Rachunki','2025-05-09');
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
) ENGINE=InnoDB AUTO_INCREMENT=13 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Uzytkownik zalogowany`
--

LOCK TABLES `Uzytkownik zalogowany` WRITE;
/*!40000 ALTER TABLE `Uzytkownik zalogowany` DISABLE KEYS */;
INSERT INTO `Uzytkownik zalogowany` VALUES (1,'Janusz','Janski','januszek@gmail.com','haslo123',0,'2021-01-20','Admin'),(2,'Mikolaj','Wielki','mikolaj96@gmail.com','asdasdasd',0,'2025-05-10','Użytkownik'),(3,'Basia','Maczna','baska@ya.com','makabasi',0,'2025-05-10','Rodzic'),(4,'Artur','Dobry','asd@asd.com','asdasdasdasdasd',0,'2025-05-10','Rodzic'),(5,'Jan','Prus','janprus@poczta.com','haslo123',0,'2025-05-14','Admin'),(6,'Jakub','Test','jakub.test@gmail.com','testjakub',0,'2005-03-20','Rodzic'),(7,'Aleksandra','Gral','ola.gral@wp.pl','aleksandra',0,'2009-01-20','Dziecko'),(8,'Jan','Nowak','abc@gmail.com','haslo123',1,'2001-01-20','Dziecko'),(9,'Teresa','Sad','teresa@gmail.com','sad54321',0,'1955-05-22','Użytkownik'),(10,'Ela','Kot','elakot@wp.pl','abcabc123',1,'1979-05-22','Dziecko'),(11,'Szaralinda','Łączka','krzysztof222@o2.pl','popopoko',1,'2000-03-01','Dziecko'),(12,'Maja','Ełska','me@gmail.com','haslo123',0,'2025-05-26','Dziecko');
/*!40000 ALTER TABLE `Uzytkownik zalogowany` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2025-05-29  8:00:38
