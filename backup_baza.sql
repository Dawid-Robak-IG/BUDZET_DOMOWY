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
) ENGINE=InnoDB AUTO_INCREMENT=10874 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Budzet domowy`
--

LOCK TABLES `Budzet domowy` WRITE;
/*!40000 ALTER TABLE `Budzet domowy` DISABLE KEYS */;
INSERT INTO `Budzet domowy` VALUES (10746,-150,10774),(10747,-200,10775),(10748,-212,10776),(10749,-122,10777),(10750,4878,10778),(10751,4678,10779),(10752,4478,10780),(10753,4278,10781),(10754,4078,10782),(10755,3878,10783),(10756,3678,10784),(10757,3478,10785),(10758,3278,10786),(10759,3078,10787),(10760,6078,10790),(10761,11078,10791),(10762,10878,10792),(10763,10678,10793),(10764,10478,10794),(10765,10278,10795),(10766,10078,10796),(10767,9878,10797),(10768,9678,10798),(10769,9478,10799),(10770,9278,10800),(10771,9078,10801),(10772,8878,10802),(10773,8678,10803),(10774,8478,10804),(10775,8278,10805),(10776,8078,10806),(10777,7878,10807),(10778,7678,10808),(10779,7478,10809),(10780,7278,10810),(10781,7078,10811),(10782,6878,10812),(10783,6678,10813),(10784,6478,10814),(10785,6278,10815),(10786,6078,10816),(10787,5878,10817),(10788,5678,10818),(10789,5478,10819),(10790,5278,10820),(10791,5078,10821),(10792,4878,10822),(10793,4678,10823),(10794,4478,10824),(10795,4278,10825),(10796,4078,10826),(10797,3878,10827),(10798,3678,10828),(10799,3478,10829),(10800,3278,10830),(10801,3078,10831),(10802,2878,10832),(10803,2678,10833),(10804,2478,10834),(10805,2278,10835),(10806,2078,10836),(10807,1878,10837),(10808,1678,10838),(10809,1478,10839),(10810,1278,10840),(10811,1078,10841),(10812,878,10842),(10813,678,10843),(10814,478,10844),(10815,278,10845),(10816,78,10846),(10817,-122,10847),(10818,-322,10848),(10819,499678,10849),(10820,499478,10850),(10821,499278,10851),(10822,499274,10852),(10823,499074,10853),(10824,499070,10854),(10825,499057,10855),(10826,498857,10856),(10827,500857,10857),(10828,500707,10858),(10829,500507,10859),(10830,500357,10860),(10831,500157,10861),(10832,500007,10862),(10833,499807,10863),(10834,499657,10864),(10835,499457,10865),(10836,499307,10866),(10837,499107,10867),(10838,498957,10868),(10839,498757,10869),(10840,498607,10870),(10841,498407,10871),(10842,498257,10872),(10843,498057,10873),(10844,497907,10874),(10845,497707,10875),(10846,497557,10876),(10847,497357,10877),(10848,497207,10878),(10849,497007,10879),(10850,496857,10880),(10851,496657,10881),(10852,496507,10882),(10853,496307,10883),(10854,496157,10884),(10855,495957,10885),(10856,495807,10886),(10857,495607,10887),(10858,495457,10888),(10859,495257,10889),(10860,495107,10890),(10861,494907,10891),(10862,494757,10892),(10863,494557,10893),(10864,494407,10894),(10865,494207,10895),(10866,494057,10896),(10867,493857,10897),(10868,493707,10898),(10869,493507,10899),(10870,493357,10900),(10871,493157,10901),(10872,493007,10902),(10873,492807,10903);
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
INSERT INTO `Dziecko` VALUES (7,150,150,3,4,'2025-07-01'),(8,150,150,3,4,'2025-07-01'),(10,130,130,4,3,'2025-07-01'),(11,200,200,NULL,NULL,'2025-07-01'),(12,-256,0,NULL,NULL,'2025-07-01');
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
) ENGINE=InnoDB AUTO_INCREMENT=10904 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Operacja`
--

LOCK TABLES `Operacja` WRITE;
/*!40000 ALTER TABLE `Operacja` DISABLE KEYS */;
INSERT INTO `Operacja` VALUES (10772,50,'2025-05-17','Urodziny',12,'Inne',0,NULL),(10773,-6,'2025-05-24','Pączek',12,'Jedzenie',0,NULL),(10774,-150,'2025-05-25','zakupy - odzież',1,'Inne',0,NULL),(10775,-50,'2025-05-04','basen',1,'Sport',0,NULL),(10776,-12,'2025-04-09','Fryzjer',3,'Inne',0,NULL),(10777,90,'2025-05-20','Korepetycje',3,'Inne',0,NULL),(10778,5000,'2025-05-02','',3,'Pensja',1,37),(10779,-200,'2025-05-09','',3,'Rachunki',1,38),(10780,-200,'2025-05-09','',3,'Rachunki',1,38),(10781,-200,'2025-05-09','',3,'Rachunki',1,38),(10782,-200,'2025-05-09','',3,'Rachunki',1,38),(10783,-200,'2025-05-09','',3,'Rachunki',1,38),(10784,-200,'2025-05-09','',3,'Rachunki',1,38),(10785,-200,'2025-05-09','',3,'Rachunki',1,38),(10786,-200,'2025-05-09','',3,'Rachunki',1,38),(10787,-200,'2025-05-09','',3,'Rachunki',1,38),(10788,130,'2025-05-29',NULL,12,'Prezent',0,NULL),(10789,-430,'2025-05-23',NULL,12,'Jedzenie',0,NULL),(10790,3000,'2025-06-02','',1,'Pensja',1,35),(10791,5000,'2025-06-02','',3,'Pensja',1,37),(10792,-200,'2025-05-09','',3,'Rachunki',1,38),(10793,-200,'2025-05-09','',3,'Rachunki',1,38),(10794,-200,'2025-05-09','',3,'Rachunki',1,38),(10795,-200,'2025-05-09','',3,'Rachunki',1,38),(10796,-200,'2025-05-09','',3,'Rachunki',1,38),(10797,-200,'2025-05-09','',3,'Rachunki',1,38),(10798,-200,'2025-05-09','',3,'Rachunki',1,38),(10799,-200,'2025-05-09','',3,'Rachunki',1,38),(10800,-200,'2025-05-09','',3,'Rachunki',1,38),(10801,-200,'2025-05-09','',3,'Rachunki',1,38),(10802,-200,'2025-05-09','',3,'Rachunki',1,38),(10803,-200,'2025-05-09','',3,'Rachunki',1,38),(10804,-200,'2025-05-09','',3,'Rachunki',1,38),(10805,-200,'2025-05-09','',3,'Rachunki',1,38),(10806,-200,'2025-05-09','',3,'Rachunki',1,38),(10807,-200,'2025-05-09','',3,'Rachunki',1,38),(10808,-200,'2025-05-09','',3,'Rachunki',1,38),(10809,-200,'2025-05-09','',3,'Rachunki',1,38),(10810,-200,'2025-05-09','',3,'Rachunki',1,38),(10811,-200,'2025-05-09','',3,'Rachunki',1,38),(10812,-200,'2025-05-09','',3,'Rachunki',1,38),(10813,-200,'2025-05-09','',3,'Rachunki',1,38),(10814,-200,'2025-05-09','',3,'Rachunki',1,38),(10815,-200,'2025-05-09','',3,'Rachunki',1,38),(10816,-200,'2025-05-09','',3,'Rachunki',1,38),(10817,-200,'2025-05-09','',3,'Rachunki',1,38),(10818,-200,'2025-05-09','',3,'Rachunki',1,38),(10819,-200,'2025-05-09','',3,'Rachunki',1,38),(10820,-200,'2025-05-09','',3,'Rachunki',1,38),(10821,-200,'2025-05-09','',3,'Rachunki',1,38),(10822,-200,'2025-05-09','',3,'Rachunki',1,38),(10823,-200,'2025-05-09','',3,'Rachunki',1,38),(10824,-200,'2025-05-09','',3,'Rachunki',1,38),(10825,-200,'2025-05-09','',3,'Rachunki',1,38),(10826,-200,'2025-05-09','',3,'Rachunki',1,38),(10827,-200,'2025-05-09','',3,'Rachunki',1,38),(10828,-200,'2025-05-09','',3,'Rachunki',1,38),(10829,-200,'2025-05-09','',3,'Rachunki',1,38),(10830,-200,'2025-05-09','',3,'Rachunki',1,38),(10831,-200,'2025-05-09','',3,'Rachunki',1,38),(10832,-200,'2025-05-09','',3,'Rachunki',1,38),(10833,-200,'2025-05-09','',3,'Rachunki',1,38),(10834,-200,'2025-05-09','',3,'Rachunki',1,38),(10835,-200,'2025-05-09','',3,'Rachunki',1,38),(10836,-200,'2025-05-09','',3,'Rachunki',1,38),(10837,-200,'2025-05-09','',3,'Rachunki',1,38),(10838,-200,'2025-05-09','',3,'Rachunki',1,38),(10839,-200,'2025-05-09','',3,'Rachunki',1,38),(10840,-200,'2025-05-09','',3,'Rachunki',1,38),(10841,-200,'2025-05-09','',3,'Rachunki',1,38),(10842,-200,'2025-05-09','',3,'Rachunki',1,38),(10843,-200,'2025-05-09','',3,'Rachunki',1,38),(10844,-200,'2025-05-09','',3,'Rachunki',1,38),(10845,-200,'2025-05-09','',3,'Rachunki',1,38),(10846,-200,'2025-05-09','',3,'Rachunki',1,38),(10847,-200,'2025-05-09','',3,'Rachunki',1,38),(10848,-200,'2025-05-09','',3,'Rachunki',1,38),(10849,500000,'2025-06-12','Napad na bank',5,'Prezent',0,NULL),(10850,-200,'2025-05-09','',3,'Rachunki',1,38),(10851,-200,'2025-05-09','',3,'Rachunki',1,38),(10852,-4,'2025-06-12',NULL,5,'Jedzenie',0,NULL),(10853,-200,'2025-05-09','',3,'Rachunki',1,38),(10854,-4,'2025-06-12',NULL,5,'Inne',0,NULL),(10855,-13,'2025-06-12','tosty',5,'Jedzenie',0,NULL),(10856,-200,'2025-05-09','',3,'Rachunki',1,38),(10857,2000,'2025-06-12','Znalezione',5,'Prezent',0,NULL),(10858,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10859,-200,'2025-05-09','',3,'Rachunki',1,38),(10860,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10861,-200,'2025-05-09','',3,'Rachunki',1,38),(10862,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10863,-200,'2025-05-09','',3,'Rachunki',1,38),(10864,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10865,-200,'2025-05-09','',3,'Rachunki',1,38),(10866,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10867,-200,'2025-05-09','',3,'Rachunki',1,38),(10868,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10869,-200,'2025-05-09','',3,'Rachunki',1,38),(10870,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10871,-200,'2025-05-09','',3,'Rachunki',1,38),(10872,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10873,-200,'2025-05-09','',3,'Rachunki',1,38),(10874,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10875,-200,'2025-05-09','',3,'Rachunki',1,38),(10876,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10877,-200,'2025-05-09','',3,'Rachunki',1,38),(10878,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10879,-200,'2025-05-09','',3,'Rachunki',1,38),(10880,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10881,-200,'2025-05-09','',3,'Rachunki',1,38),(10882,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10883,-200,'2025-05-09','',3,'Rachunki',1,38),(10884,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10885,-200,'2025-05-09','',3,'Rachunki',1,38),(10886,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10887,-200,'2025-05-09','',3,'Rachunki',1,38),(10888,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10889,-200,'2025-05-09','',3,'Rachunki',1,38),(10890,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10891,-200,'2025-05-09','',3,'Rachunki',1,38),(10892,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10893,-200,'2025-05-09','',3,'Rachunki',1,38),(10894,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10895,-200,'2025-05-09','',3,'Rachunki',1,38),(10896,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10897,-200,'2025-05-09','',3,'Rachunki',1,38),(10898,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10899,-200,'2025-05-09','',3,'Rachunki',1,38),(10900,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10901,-200,'2025-05-09','',3,'Rachunki',1,38),(10902,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10903,-200,'2025-05-09','',3,'Rachunki',1,38);
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
INSERT INTO `Operacja cykliczna` VALUES (35,3000,'2025-05-02','','Co tydzień',1,'Pensja','2025-07-02'),(36,-150,'2025-05-13','Internet i telefon','Co tydzień',1,'Rachunki','2025-06-13'),(37,5000,'2025-04-02','','Co miesiąc',3,'Pensja','2025-07-02'),(38,-200,'2025-05-02','','Co tydzień',3,'Rachunki','2025-05-09');
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
INSERT INTO `Uzytkownik zalogowany` VALUES (1,'Janusz','Janski','januszek@gmail.com','haslo123',0,'2021-01-20','Admin'),(2,'Mikolaj','Wielki','mikolaj96@gmail.com','asdasdasd',0,'2025-05-10','Użytkownik'),(3,'Basia','Maczna','baska@ya.com','makabasi',0,'2025-05-10','Rodzic'),(4,'Artur','Dobry','asd@asd.com','asdasdasdasdasd',0,'2025-05-10','Rodzic'),(5,'Jan','Prus','janprus@poczta.com','haslo123',0,'2025-05-14','Admin'),(6,'Jakub','Test','jakub.test@gmail.com','testjakub',0,'2005-03-20','Rodzic'),(7,'Aleksandra','Gral','ola.gral@wp.pl','aleksandra',0,'2009-01-20','Dziecko'),(8,'Jan','Nowak','abc@gmail.com','haslo123',1,'2001-01-20','Dziecko'),(9,'Teresa','Sad','teresa@gmail.com','sad54321',0,'1955-05-22','Użytkownik'),(10,'Ela','Kot','elakot@wp.pl','abcabcabc',0,'1979-05-22','Dziecko'),(11,'Szaralinda','Łączka','krzysztof222@o2.pl','popopoko',1,'2000-03-01','Dziecko'),(12,'Maja','Ełska','me@gmail.com','haslo123',0,'2025-05-26','Rodzic');
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

-- Dump completed on 2025-06-13  7:27:26
