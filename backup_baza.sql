-- MySQL dump 10.13  Distrib 8.0.42, for Linux (x86_64)
--
-- Host: localhost    Database: BUDZET_DOMOWY
-- ------------------------------------------------------
-- Server version	8.0.42

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
) ENGINE=InnoDB AUTO_INCREMENT=23 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Budzet domowy`
--

LOCK TABLES `Budzet domowy` WRITE;
/*!40000 ALTER TABLE `Budzet domowy` DISABLE KEYS */;
INSERT INTO `Budzet domowy` VALUES (1,10,18),(2,5,19),(3,22,20),(4,22,21),(5,12322,22),(6,11122,23),(7,11142,24),(8,11265,25),(9,11365,26),(10,11368,29),(12,11371,30),(13,11374,31),(14,11377,32),(15,11380,33),(16,11383,34),(17,11386,35),(18,11390,36),(19,11385,37),(20,11380,38),(21,11375,39),(22,11370,40);
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
INSERT INTO `Dziecko` VALUES (7,17,10,3,NULL,'2025-06-20'),(10,0,5,3,NULL,NULL),(11,0,0,3,NULL,NULL);
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
) ENGINE=InnoDB AUTO_INCREMENT=41 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Operacja`
--

LOCK TABLES `Operacja` WRITE;
/*!40000 ALTER TABLE `Operacja` DISABLE KEYS */;
INSERT INTO `Operacja` VALUES (2,0,'2025-05-15','1234',5,'Pensja',0,NULL),(3,0,'2025-05-15','123',5,'Pensja',0,NULL),(4,20,'2025-05-15','123334',5,'Prezent',0,NULL),(5,15,'2025-05-12','635',5,'Prezent',0,NULL),(6,2,'2025-05-15','111',5,'Pensja',0,NULL),(16,10,'2025-05-22','1',11,'Inne',0,NULL),(17,14,'2025-05-24','cudowna notatka',5,'Hobby',0,NULL),(18,10,'2025-05-25','na budzet',5,'Hobby',0,NULL),(19,-5,'2025-05-25','z budzetu',5,'Hobby',0,NULL),(20,17,'2025-05-25','wielki przychod do buzdetu',5,'Sport',0,NULL),(21,0,'2025-05-25',NULL,5,'Hobby',0,NULL),(22,12300,'2025-05-25','wielkie piniądze',5,'Pensja',0,NULL),(23,-1200,'2025-05-25','psychiatra po AiR',5,'rozrywka',0,NULL),(24,20,'2025-02-25',NULL,5,'Hobby',0,NULL),(25,123,'2025-05-20',NULL,5,'Hobby',0,NULL),(26,100,'2025-05-22',NULL,5,'Hobby',0,NULL),(27,12,'2025-05-25','dziecinne przychodeszki',7,'Hobby',0,NULL),(28,-5,'2025-05-25','lizaki i inne toskyczne wynalazki',7,'Jedzenie',0,NULL),(29,3,'2025-05-25','małe co nie co',5,'Hobby',1,26),(30,3,'2025-05-25','małe co nie co',5,'Hobby',1,26),(31,3,'2025-05-25','małe co nie co',5,'Hobby',1,26),(32,3,'2025-05-25','małe co nie co',5,'Hobby',1,26),(33,3,'2025-05-25','małe co nie co',5,'Hobby',1,26),(34,3,'2025-05-25','małe co nie co',5,'Hobby',1,26),(35,3,'2025-05-25','małe co nie co',5,'Hobby',1,26),(36,4,'2025-05-25','test2',5,'Hobby',0,NULL),(37,-5,'2025-05-22','wielkie grzybobranie',5,'Hobby',1,30),(38,-5,'2025-05-23','wielkie grzybobranie',5,'Hobby',1,30),(39,-5,'2025-05-24','wielkie grzybobranie',5,'Hobby',1,30),(40,-5,'2025-05-25','wielkie grzybobranie',5,'Hobby',1,30);
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
) ENGINE=InnoDB AUTO_INCREMENT=31 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Operacja cykliczna`
--

LOCK TABLES `Operacja cykliczna` WRITE;
/*!40000 ALTER TABLE `Operacja cykliczna` DISABLE KEYS */;
INSERT INTO `Operacja cykliczna` VALUES (8,3,'2025-05-24','pieniążki','Codziennie',5,'Hobby',NULL),(10,3,'2025-05-24','edycja','Codziennie',5,'Hobby',NULL),(12,0.25,'2025-05-24','stypendium od pwr','Co miesiąc',5,'Pensja',NULL),(13,4,'2025-05-24','moje wielkie inwestycje','Co rok',1,'Dywidenda',NULL),(14,2,'2025-05-24','ranczo','Co rok',5,'Podróże',NULL),(15,2,'2025-05-24','ranczo2','Co rok',5,'Podróże',NULL),(16,7,'2025-05-24','miodowe lata','Co rok',5,'Renta',NULL),(17,6,'2025-05-24','wielka polska nieśmiertelna :P','Co rok',5,'Podróże',NULL),(23,1.01,'2025-05-24','Czego się boi Jarek? Pieczarek','Codziennie',5,'Hobby',NULL),(26,3,'2025-05-24','małe co nie co','Codziennie',5,'Hobby','2025-05-26'),(27,10,'2025-05-24','smutek żal i rozpacz','Codziennie',5,'Dywidenda',NULL),(28,3,'2025-05-24','kiedy koniec','Codziennie',5,'Hobby',NULL),(29,-4,'2025-05-24','dżuma','Codziennie',5,'Hobby',NULL),(30,-5,'2025-05-25','wielkie grzybobranie','Codziennie',5,'Hobby','2025-05-26');
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
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Uzytkownik zalogowany`
--

LOCK TABLES `Uzytkownik zalogowany` WRITE;
/*!40000 ALTER TABLE `Uzytkownik zalogowany` DISABLE KEYS */;
INSERT INTO `Uzytkownik zalogowany` VALUES (1,'JanuszEK','Janski','januszek@gmail.com','haslo123',0,'2021-01-20','Admin'),(2,'mikolaj','wielki','mikolaj96@gmail.com','asdasdasd',0,'2025-05-10','Użytkownik'),(3,'Basia','Maczna','chamia@playa.com','makabasi',0,'2025-05-10','Rodzic'),(4,'AS','DO','asd@asd.com','asdasdasdasdasd',0,'2025-05-10','Rodzic'),(5,'Jan','Prus','janprus@poczta.com','haslo123',0,'2025-05-14','Admin'),(6,'Jakub','Test','jakub.test@gmail.com','testjakub',0,'2005-03-20','Rodzic'),(7,'Aleksandra','Gral','ola.gral@wp.pl','aleksandra',0,'2009-01-20','Dziecko'),(8,'Jan','Nowak','abc@gmail.com','haslo123',1,'2001-01-20','Użytkownik'),(9,'Teresa','Sad','teresa@gmail.com','sad54321',0,'1955-05-22','Użytkownik'),(10,'','Kot','elakot@wp.pl','abcabc123',1,'1979-05-22','Dziecko'),(11,'Szaralinda','Łączka','krzysztof222@o2.pl','popopoko',1,'2000-03-01','Dziecko');
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

-- Dump completed on 2025-05-25 18:13:26
