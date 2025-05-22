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
  `Kwota` int NOT NULL,
  `OperacjaID` int NOT NULL,
  PRIMARY KEY (`ID`),
  KEY `FKBud¿et dom282223` (`OperacjaID`),
  CONSTRAINT `FKBud¿et dom282223` FOREIGN KEY (`OperacjaID`) REFERENCES `Operacja` (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Budzet domowy`
--

LOCK TABLES `Budzet domowy` WRITE;
/*!40000 ALTER TABLE `Budzet domowy` DISABLE KEYS */;
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
  `Saldo` int NOT NULL,
  `Kieszonkowe` int DEFAULT NULL,
  `ID_Rodzic1` int NOT NULL,
  `ID_Rodzic2` int DEFAULT NULL,
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
INSERT INTO `Kategoria` VALUES ('Hobby',5),('Inne',5),('Jedzenie',5),('Pensja',5),('Podróże',5),('Prezent',5),('Renta',5),('rozrywka',5),('Sport',5),('Dywidenda',8);
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
  `Kwota` int NOT NULL,
  `Data` date NOT NULL,
  `Notatka` int DEFAULT NULL,
  `Uzytkownik zalogowanyID` int NOT NULL,
  `Kategoria Nazwa` varchar(255) NOT NULL,
  `czy_z_cyklicznego` bit(1) NOT NULL,
  `Operacja cyklicznaID` int DEFAULT NULL,
  PRIMARY KEY (`ID`),
  KEY `FKOperacja423377` (`Uzytkownik zalogowanyID`),
  KEY `FKOperacja368305` (`Kategoria Nazwa`),
  KEY `FKOperacja232880` (`Operacja cyklicznaID`),
  CONSTRAINT `FKOperacja232880` FOREIGN KEY (`Operacja cyklicznaID`) REFERENCES `Operacja cykliczna` (`ID`),
  CONSTRAINT `FKOperacja368305` FOREIGN KEY (`Kategoria Nazwa`) REFERENCES `Kategoria` (`Nazwa`),
  CONSTRAINT `FKOperacja423377` FOREIGN KEY (`Uzytkownik zalogowanyID`) REFERENCES `Uzytkownik zalogowany` (`ID`)
) ENGINE=InnoDB AUTO_INCREMENT=17 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Operacja`
--

LOCK TABLES `Operacja` WRITE;
/*!40000 ALTER TABLE `Operacja` DISABLE KEYS */;
INSERT INTO `Operacja` VALUES (2,0,'2025-05-15',1234,5,'Pensja',_binary '\0',NULL),(3,0,'2025-05-15',123,5,'Pensja',_binary '\0',NULL),(4,20,'2025-05-15',123334,5,'Prezent',_binary '\0',NULL),(5,15,'2025-05-12',635,5,'Prezent',_binary '\0',NULL),(6,2,'2025-05-15',111,5,'Pensja',_binary '\0',NULL),(7,123,'2025-05-09',NULL,8,'Dywidenda',_binary '\0',NULL),(8,3,'2025-05-08',NULL,5,'Renta',_binary '\0',NULL),(9,6,'2000-01-04',NULL,5,'Prezent',_binary '\0',NULL),(10,-8,'2009-01-01',NULL,5,'Prezent',_binary '\0',NULL),(11,9,'2025-05-04',NULL,5,'Prezent',_binary '\0',NULL),(12,0,'2009-01-01',NULL,5,'Prezent',_binary '\0',NULL),(13,7,'2025-05-21',NULL,5,'Prezent',_binary '\0',NULL),(14,0,'2025-05-22',NULL,5,'Inne',_binary '\0',NULL),(15,7,'2025-05-22',NULL,5,'Sport',_binary '\0',NULL),(16,10,'2025-05-22',1,11,'Inne',_binary '\0',NULL);
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
  `Kwota` int NOT NULL,
  `Data` date NOT NULL,
  `Notatka` varchar(255) DEFAULT NULL,
  `Czestotliwosc` varchar(255) NOT NULL,
  `Uzytkownik zalogowanyID` int NOT NULL,
  `Kategoria Nazwa` varchar(255) NOT NULL,
  PRIMARY KEY (`ID`),
  KEY `FKOperacja c774395` (`Uzytkownik zalogowanyID`),
  KEY `FKOperacja c719323` (`Kategoria Nazwa`),
  CONSTRAINT `FKOperacja c719323` FOREIGN KEY (`Kategoria Nazwa`) REFERENCES `Kategoria` (`Nazwa`),
  CONSTRAINT `FKOperacja c774395` FOREIGN KEY (`Uzytkownik zalogowanyID`) REFERENCES `Uzytkownik zalogowany` (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Operacja cykliczna`
--

LOCK TABLES `Operacja cykliczna` WRITE;
/*!40000 ALTER TABLE `Operacja cykliczna` DISABLE KEYS */;
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
  `Czy_zablokowany` bit(1) NOT NULL,
  `Data urodzenia` date NOT NULL,
  `Rola` varchar(255) NOT NULL,
  PRIMARY KEY (`ID`),
  UNIQUE KEY `Email` (`Email`)
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Uzytkownik zalogowany`
--

LOCK TABLES `Uzytkownik zalogowany` WRITE;
/*!40000 ALTER TABLE `Uzytkownik zalogowany` DISABLE KEYS */;
INSERT INTO `Uzytkownik zalogowany` VALUES (1,'Janusz','Januszewski','januszek@gmail.com','taktoja',_binary '\0','2021-01-20','Użytkownik'),(2,'mikolaj','wielki','mikolajek@gmail.com','asdasdasd',_binary '\0','2025-05-10','Użytkownik'),(3,'Baska','Maczna','chamia@playa.com','makabasi',_binary '\0','2025-05-10','Rodzic'),(4,'AS','DO','asd@asd.com','asdasdasdasdasd',_binary '\0','2025-05-10','Użytkownik'),(5,'Jan','Prus','janprus@poczta.com','haslo123',_binary '\0','2025-05-14','Rodzic'),(6,'Jakub','Test','jakub.test@gmail.com','testjakub',_binary '\0','2005-03-20','Użytkownik'),(7,'Aleksandra','Gral','ola.gral@wp.pl','aleksandra',_binary '\0','2009-01-20','Dziecko'),(8,'Jan','Nowak','abc@gmail.com','haslo123',_binary '\0','2001-01-20','Użytkownik'),(9,'Teresa','Sad','teresa@gmail.com','sad54321',_binary '\0','1955-05-22','Użytkownik'),(10,'Elżbieta','Kot','elakot@wp.pl','abcabc123',_binary '\0','1979-05-22','Dziecko'),(11,'Szaralinda','Łączka','krzysztof222@o2.pl','popopoko',_binary '\0','2000-03-01','Dziecko');
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

-- Dump completed on 2025-05-22 23:07:05
