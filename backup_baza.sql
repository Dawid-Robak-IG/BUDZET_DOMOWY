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
) ENGINE=InnoDB AUTO_INCREMENT=11126 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Budzet domowy`
--

LOCK TABLES `Budzet domowy` WRITE;
/*!40000 ALTER TABLE `Budzet domowy` DISABLE KEYS */;
INSERT INTO `Budzet domowy` VALUES (10746,-150,10774),(10747,-200,10775),(10748,-212,10776),(10749,-122,10777),(10750,4878,10778),(10751,4678,10779),(10752,4478,10780),(10753,4278,10781),(10754,4078,10782),(10755,3878,10783),(10756,3678,10784),(10757,3478,10785),(10758,3278,10786),(10759,3078,10787),(10760,6078,10790),(10761,11078,10791),(10762,10878,10792),(10763,10678,10793),(10764,10478,10794),(10765,10278,10795),(10766,10078,10796),(10767,9878,10797),(10768,9678,10798),(10769,9478,10799),(10770,9278,10800),(10771,9078,10801),(10772,8878,10802),(10773,8678,10803),(10774,8478,10804),(10775,8278,10805),(10776,8078,10806),(10777,7878,10807),(10778,7678,10808),(10779,7478,10809),(10780,7278,10810),(10781,7078,10811),(10782,6878,10812),(10783,6678,10813),(10784,6478,10814),(10785,6278,10815),(10786,6078,10816),(10787,5878,10817),(10788,5678,10818),(10789,5478,10819),(10790,5278,10820),(10791,5078,10821),(10792,4878,10822),(10793,4678,10823),(10794,4478,10824),(10795,4278,10825),(10796,4078,10826),(10797,3878,10827),(10798,3678,10828),(10799,3478,10829),(10800,3278,10830),(10801,3078,10831),(10802,2878,10832),(10803,2678,10833),(10804,2478,10834),(10805,2278,10835),(10806,2078,10836),(10807,1878,10837),(10808,1678,10838),(10809,1478,10839),(10810,1278,10840),(10811,1078,10841),(10812,878,10842),(10813,678,10843),(10814,478,10844),(10815,278,10845),(10816,78,10846),(10817,-122,10847),(10818,-322,10848),(10819,499678,10849),(10820,499478,10850),(10821,499278,10851),(10822,499274,10852),(10823,499074,10853),(10824,499070,10854),(10825,499057,10855),(10826,498857,10856),(10827,500857,10857),(10828,500707,10858),(10829,500507,10859),(10830,500357,10860),(10831,500157,10861),(10832,500007,10862),(10833,499807,10863),(10834,499657,10864),(10835,499457,10865),(10836,499307,10866),(10837,499107,10867),(10838,498957,10868),(10839,498757,10869),(10840,498607,10870),(10841,498407,10871),(10842,498257,10872),(10843,498057,10873),(10844,497907,10874),(10845,497707,10875),(10846,497557,10876),(10847,497357,10877),(10848,497207,10878),(10849,497007,10879),(10850,496857,10880),(10851,496657,10881),(10852,496507,10882),(10853,496307,10883),(10854,496157,10884),(10855,495957,10885),(10856,495807,10886),(10857,495607,10887),(10858,495457,10888),(10859,495257,10889),(10860,495107,10890),(10861,494907,10891),(10862,494757,10892),(10863,494557,10893),(10864,494407,10894),(10865,494207,10895),(10866,494057,10896),(10867,493857,10897),(10868,493707,10898),(10869,493507,10899),(10870,493357,10900),(10871,493157,10901),(10872,493007,10902),(10873,492807,10903),(10874,492657,10904),(10875,492457,10905),(10876,492307,10906),(10877,492107,10907),(10878,491957,10908),(10879,491757,10909),(10880,491607,10910),(10881,491407,10911),(10882,491257,10912),(10883,491057,10913),(10884,490907,10914),(10885,490707,10915),(10886,490557,10916),(10887,490357,10917),(10888,490207,10918),(10889,490007,10919),(10890,489857,10920),(10891,489657,10921),(10892,489507,10922),(10893,489307,10923),(10894,489157,10924),(10895,488957,10925),(10896,488807,10926),(10897,488607,10927),(10898,488457,10928),(10899,488257,10929),(10900,488107,10930),(10901,487907,10931),(10902,487757,10932),(10903,487557,10933),(10904,487407,10934),(10905,487207,10935),(10906,487057,10936),(10907,486857,10937),(10908,486707,10938),(10909,486507,10939),(10910,486357,10940),(10911,486157,10941),(10912,486007,10942),(10913,485807,10943),(10914,485657,10944),(10915,485457,10945),(10916,485307,10946),(10917,485107,10947),(10918,484957,10948),(10919,484757,10949),(10920,484607,10950),(10921,484407,10951),(10922,484257,10952),(10923,484057,10953),(10924,483907,10954),(10925,483707,10955),(10926,483557,10956),(10927,483357,10957),(10928,483207,10958),(10929,483007,10959),(10930,482857,10960),(10931,482657,10961),(10932,482507,10962),(10933,482307,10963),(10934,482157,10964),(10935,481957,10965),(10936,481807,10966),(10937,481607,10967),(10938,481457,10968),(10939,481257,10969),(10940,481107,10970),(10941,480907,10971),(10942,480757,10972),(10943,480557,10973),(10944,480407,10974),(10945,480207,10975),(10946,480057,10976),(10947,479857,10977),(10948,479707,10978),(10949,479507,10979),(10950,479357,10980),(10951,479157,10981),(10952,479007,10982),(10953,478807,10983),(10954,478657,10984),(10955,478457,10985),(10956,478307,10986),(10957,478107,10987),(10958,477957,10988),(10959,477757,10989),(10960,477607,10990),(10961,477407,10991),(10962,477257,10992),(10963,477057,10993),(10964,476907,10994),(10965,476707,10995),(10966,476557,10996),(10967,476357,10997),(10968,476207,10998),(10969,476007,10999),(10970,475857,11000),(10971,475657,11001),(10972,475507,11002),(10973,475307,11003),(10974,475157,11004),(10975,474957,11005),(10976,462957,11006),(10977,462807,11007),(10978,462607,11008),(10979,462457,11009),(10980,462257,11010),(10981,462107,11016),(10982,461907,11017),(10983,461757,11019),(10984,461557,11020),(10985,461407,11021),(10986,461207,11022),(10987,461057,11024),(10988,460857,11025),(10989,460707,11026),(10990,460507,11027),(10991,460357,11028),(10992,460157,11029),(10993,460007,11030),(10994,459807,11031),(10995,459657,11037),(10996,459457,11038),(10997,459307,11039),(10998,459107,11040),(10999,458957,11041),(11000,458757,11042),(11001,458607,11043),(11002,458407,11044),(11003,458257,11046),(11004,458057,11047),(11005,457907,11048),(11006,457707,11049),(11007,457557,11051),(11008,457357,11052),(11009,457207,11053),(11010,457007,11054),(11011,456857,11055),(11012,456657,11056),(11013,456507,11057),(11014,456307,11058),(11015,456157,11059),(11016,455957,11060),(11017,455807,11061),(11018,455607,11062),(11019,455457,11063),(11020,455257,11064),(11021,455107,11065),(11022,454907,11066),(11023,454757,11067),(11024,454557,11068),(11025,454407,11069),(11026,454207,11070),(11027,454057,11071),(11028,453857,11072),(11029,453707,11073),(11030,453507,11074),(11031,453357,11075),(11032,453157,11076),(11033,453007,11077),(11034,452807,11078),(11035,452657,11079),(11036,452457,11080),(11037,452307,11081),(11038,452107,11082),(11039,451957,11083),(11040,451757,11084),(11041,451607,11085),(11042,451407,11086),(11043,451257,11087),(11044,451057,11088),(11045,450907,11089),(11046,450707,11090),(11047,450557,11091),(11048,450357,11092),(11049,450207,11093),(11050,450007,11094),(11051,449857,11095),(11052,449657,11096),(11053,449507,11097),(11054,449307,11098),(11055,449157,11099),(11056,448957,11100),(11057,448807,11101),(11058,448607,11102),(11059,448457,11103),(11060,448257,11104),(11061,448107,11105),(11062,447907,11106),(11063,447757,11108),(11064,447557,11109),(11065,447407,11110),(11066,447207,11111),(11067,447057,11112),(11068,446857,11113),(11069,446707,11114),(11070,446507,11115),(11071,446357,11116),(11072,446157,11117),(11073,446007,11118),(11074,445807,11119),(11075,445657,11120),(11076,445457,11121),(11077,445307,11122),(11078,445107,11123),(11079,444957,11124),(11080,444757,11125),(11081,444607,11126),(11082,444407,11127),(11083,444257,11128),(11084,444057,11129),(11085,443907,11130),(11086,443707,11131),(11087,443557,11132),(11088,443357,11133),(11089,443207,11134),(11090,443007,11135),(11091,442857,11136),(11092,442657,11137),(11093,442507,11138),(11094,442307,11139),(11095,442157,11140),(11096,441957,11141),(11097,441807,11142),(11098,441607,11143),(11099,441457,11144),(11100,441257,11145),(11101,441107,11146),(11102,440907,11147),(11103,440757,11148),(11104,440557,11149),(11105,440407,11150),(11106,440207,11151),(11107,440057,11152),(11108,439857,11153),(11109,439707,11154),(11110,439507,11155),(11111,439357,11156),(11112,439157,11157),(11113,439007,11158),(11114,438807,11159),(11115,438657,11160),(11116,438457,11161),(11117,438307,11162),(11118,438107,11163),(11119,437957,11164),(11120,437757,11165),(11121,437557,11166),(11122,437357,11167),(11123,437157,11168),(11124,436957,11169),(11125,436757,11170);
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
INSERT INTO `Dziecko` VALUES (7,150,12.5,4,4,'2025-07-01'),(8,20,150,3,4,'2025-07-01'),(10,130,130,6,4,'2025-07-01'),(11,200,200,NULL,NULL,'2025-07-01'),(12,-256,0,NULL,NULL,'2025-07-01');
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
) ENGINE=InnoDB AUTO_INCREMENT=11171 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Operacja`
--

LOCK TABLES `Operacja` WRITE;
/*!40000 ALTER TABLE `Operacja` DISABLE KEYS */;
INSERT INTO `Operacja` VALUES (10772,50,'2025-05-17','Urodziny',12,'Inne',0,NULL),(10773,-6,'2025-05-24','Pączek',12,'Jedzenie',0,NULL),(10774,-150,'2025-05-25','zakupy - odzież',1,'Inne',0,NULL),(10775,-50,'2025-05-04','basen',1,'Sport',0,NULL),(10776,-12,'2025-04-09','Fryzjer',3,'Inne',0,NULL),(10777,90,'2025-05-20','Korepetycje',3,'Inne',0,NULL),(10778,5000,'2025-05-02','',3,'Pensja',1,37),(10779,-200,'2025-05-09','',3,'Rachunki',1,38),(10780,-200,'2025-05-09','',3,'Rachunki',1,38),(10781,-200,'2025-05-09','',3,'Rachunki',1,38),(10782,-200,'2025-05-09','',3,'Rachunki',1,38),(10783,-200,'2025-05-09','',3,'Rachunki',1,38),(10784,-200,'2025-05-09','',3,'Rachunki',1,38),(10785,-200,'2025-05-09','',3,'Rachunki',1,38),(10786,-200,'2025-05-09','',3,'Rachunki',1,38),(10787,-200,'2025-05-09','',3,'Rachunki',1,38),(10788,130,'2025-05-29',NULL,12,'Prezent',0,NULL),(10789,-430,'2025-05-23',NULL,12,'Jedzenie',0,NULL),(10790,3000,'2025-06-02','',1,'Pensja',1,35),(10791,5000,'2025-06-02','',3,'Pensja',1,37),(10792,-200,'2025-05-09','',3,'Rachunki',1,38),(10793,-200,'2025-05-09','',3,'Rachunki',1,38),(10794,-200,'2025-05-09','',3,'Rachunki',1,38),(10795,-200,'2025-05-09','',3,'Rachunki',1,38),(10796,-200,'2025-05-09','',3,'Rachunki',1,38),(10797,-200,'2025-05-09','',3,'Rachunki',1,38),(10798,-200,'2025-05-09','',3,'Rachunki',1,38),(10799,-200,'2025-05-09','',3,'Rachunki',1,38),(10800,-200,'2025-05-09','',3,'Rachunki',1,38),(10801,-200,'2025-05-09','',3,'Rachunki',1,38),(10802,-200,'2025-05-09','',3,'Rachunki',1,38),(10803,-200,'2025-05-09','',3,'Rachunki',1,38),(10804,-200,'2025-05-09','',3,'Rachunki',1,38),(10805,-200,'2025-05-09','',3,'Rachunki',1,38),(10806,-200,'2025-05-09','',3,'Rachunki',1,38),(10807,-200,'2025-05-09','',3,'Rachunki',1,38),(10808,-200,'2025-05-09','',3,'Rachunki',1,38),(10809,-200,'2025-05-09','',3,'Rachunki',1,38),(10810,-200,'2025-05-09','',3,'Rachunki',1,38),(10811,-200,'2025-05-09','',3,'Rachunki',1,38),(10812,-200,'2025-05-09','',3,'Rachunki',1,38),(10813,-200,'2025-05-09','',3,'Rachunki',1,38),(10814,-200,'2025-05-09','',3,'Rachunki',1,38),(10815,-200,'2025-05-09','',3,'Rachunki',1,38),(10816,-200,'2025-05-09','',3,'Rachunki',1,38),(10817,-200,'2025-05-09','',3,'Rachunki',1,38),(10818,-200,'2025-05-09','',3,'Rachunki',1,38),(10819,-200,'2025-05-09','',3,'Rachunki',1,38),(10820,-200,'2025-05-09','',3,'Rachunki',1,38),(10821,-200,'2025-05-09','',3,'Rachunki',1,38),(10822,-200,'2025-05-09','',3,'Rachunki',1,38),(10823,-200,'2025-05-09','',3,'Rachunki',1,38),(10824,-200,'2025-05-09','',3,'Rachunki',1,38),(10825,-200,'2025-05-09','',3,'Rachunki',1,38),(10826,-200,'2025-05-09','',3,'Rachunki',1,38),(10827,-200,'2025-05-09','',3,'Rachunki',1,38),(10828,-200,'2025-05-09','',3,'Rachunki',1,38),(10829,-200,'2025-05-09','',3,'Rachunki',1,38),(10830,-200,'2025-05-09','',3,'Rachunki',1,38),(10831,-200,'2025-05-09','',3,'Rachunki',1,38),(10832,-200,'2025-05-09','',3,'Rachunki',1,38),(10833,-200,'2025-05-09','',3,'Rachunki',1,38),(10834,-200,'2025-05-09','',3,'Rachunki',1,38),(10835,-200,'2025-05-09','',3,'Rachunki',1,38),(10836,-200,'2025-05-09','',3,'Rachunki',1,38),(10837,-200,'2025-05-09','',3,'Rachunki',1,38),(10838,-200,'2025-05-09','',3,'Rachunki',1,38),(10839,-200,'2025-05-09','',3,'Rachunki',1,38),(10840,-200,'2025-05-09','',3,'Rachunki',1,38),(10841,-200,'2025-05-09','',3,'Rachunki',1,38),(10842,-200,'2025-05-09','',3,'Rachunki',1,38),(10843,-200,'2025-05-09','',3,'Rachunki',1,38),(10844,-200,'2025-05-09','',3,'Rachunki',1,38),(10845,-200,'2025-05-09','',3,'Rachunki',1,38),(10846,-200,'2025-05-09','',3,'Rachunki',1,38),(10847,-200,'2025-05-09','',3,'Rachunki',1,38),(10848,-200,'2025-05-09','',3,'Rachunki',1,38),(10849,500000,'2025-06-12','Napad na bank',5,'Prezent',0,NULL),(10850,-200,'2025-05-09','',3,'Rachunki',1,38),(10851,-200,'2025-05-09','',3,'Rachunki',1,38),(10852,-4,'2025-06-12',NULL,5,'Jedzenie',0,NULL),(10853,-200,'2025-05-09','',3,'Rachunki',1,38),(10854,-4,'2025-06-12',NULL,5,'Inne',0,NULL),(10855,-13,'2025-06-12','tosty',5,'Jedzenie',0,NULL),(10856,-200,'2025-05-09','',3,'Rachunki',1,38),(10857,2000,'2025-06-12','Znalezione',5,'Prezent',0,NULL),(10858,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10859,-200,'2025-05-09','',3,'Rachunki',1,38),(10860,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10861,-200,'2025-05-09','',3,'Rachunki',1,38),(10862,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10863,-200,'2025-05-09','',3,'Rachunki',1,38),(10864,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10865,-200,'2025-05-09','',3,'Rachunki',1,38),(10866,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10867,-200,'2025-05-09','',3,'Rachunki',1,38),(10868,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10869,-200,'2025-05-09','',3,'Rachunki',1,38),(10870,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10871,-200,'2025-05-09','',3,'Rachunki',1,38),(10872,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10873,-200,'2025-05-09','',3,'Rachunki',1,38),(10874,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10875,-200,'2025-05-09','',3,'Rachunki',1,38),(10876,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10877,-200,'2025-05-09','',3,'Rachunki',1,38),(10878,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10879,-200,'2025-05-09','',3,'Rachunki',1,38),(10880,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10881,-200,'2025-05-09','',3,'Rachunki',1,38),(10882,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10883,-200,'2025-05-09','',3,'Rachunki',1,38),(10884,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10885,-200,'2025-05-09','',3,'Rachunki',1,38),(10886,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10887,-200,'2025-05-09','',3,'Rachunki',1,38),(10888,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10889,-200,'2025-05-09','',3,'Rachunki',1,38),(10890,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10891,-200,'2025-05-09','',3,'Rachunki',1,38),(10892,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10893,-200,'2025-05-09','',3,'Rachunki',1,38),(10894,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10895,-200,'2025-05-09','',3,'Rachunki',1,38),(10896,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10897,-200,'2025-05-09','',3,'Rachunki',1,38),(10898,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10899,-200,'2025-05-09','',3,'Rachunki',1,38),(10900,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10901,-200,'2025-05-09','',3,'Rachunki',1,38),(10902,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10903,-200,'2025-05-09','',3,'Rachunki',1,38),(10904,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10905,-200,'2025-05-09','',3,'Rachunki',1,38),(10906,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10907,-200,'2025-05-09','',3,'Rachunki',1,38),(10908,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10909,-200,'2025-05-09','',3,'Rachunki',1,38),(10910,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10911,-200,'2025-05-09','',3,'Rachunki',1,38),(10912,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10913,-200,'2025-05-09','',3,'Rachunki',1,38),(10914,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10915,-200,'2025-05-09','',3,'Rachunki',1,38),(10916,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10917,-200,'2025-05-09','',3,'Rachunki',1,38),(10918,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10919,-200,'2025-05-09','',3,'Rachunki',1,38),(10920,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10921,-200,'2025-05-09','',3,'Rachunki',1,38),(10922,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10923,-200,'2025-05-09','',3,'Rachunki',1,38),(10924,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10925,-200,'2025-05-09','',3,'Rachunki',1,38),(10926,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10927,-200,'2025-05-09','',3,'Rachunki',1,38),(10928,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10929,-200,'2025-05-09','',3,'Rachunki',1,38),(10930,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10931,-200,'2025-05-09','',3,'Rachunki',1,38),(10932,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10933,-200,'2025-05-09','',3,'Rachunki',1,38),(10934,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10935,-200,'2025-05-09','',3,'Rachunki',1,38),(10936,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10937,-200,'2025-05-09','',3,'Rachunki',1,38),(10938,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10939,-200,'2025-05-09','',3,'Rachunki',1,38),(10940,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10941,-200,'2025-05-09','',3,'Rachunki',1,38),(10942,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10943,-200,'2025-05-09','',3,'Rachunki',1,38),(10944,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10945,-200,'2025-05-09','',3,'Rachunki',1,38),(10946,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10947,-200,'2025-05-09','',3,'Rachunki',1,38),(10948,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10949,-200,'2025-05-09','',3,'Rachunki',1,38),(10950,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10951,-200,'2025-05-09','',3,'Rachunki',1,38),(10952,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10953,-200,'2025-05-09','',3,'Rachunki',1,38),(10954,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10955,-200,'2025-05-09','',3,'Rachunki',1,38),(10956,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10957,-200,'2025-05-09','',3,'Rachunki',1,38),(10958,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10959,-200,'2025-05-09','',3,'Rachunki',1,38),(10960,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10961,-200,'2025-05-09','',3,'Rachunki',1,38),(10962,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10963,-200,'2025-05-09','',3,'Rachunki',1,38),(10964,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10965,-200,'2025-05-09','',3,'Rachunki',1,38),(10966,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10967,-200,'2025-05-09','',3,'Rachunki',1,38),(10968,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10969,-200,'2025-05-09','',3,'Rachunki',1,38),(10970,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10971,-200,'2025-05-09','',3,'Rachunki',1,38),(10972,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10973,-200,'2025-05-09','',3,'Rachunki',1,38),(10974,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10975,-200,'2025-05-09','',3,'Rachunki',1,38),(10976,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10977,-200,'2025-05-09','',3,'Rachunki',1,38),(10978,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10979,-200,'2025-05-09','',3,'Rachunki',1,38),(10980,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10981,-200,'2025-05-09','',3,'Rachunki',1,38),(10982,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10983,-200,'2025-05-09','',3,'Rachunki',1,38),(10984,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10985,-200,'2025-05-09','',3,'Rachunki',1,38),(10986,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10987,-200,'2025-05-09','',3,'Rachunki',1,38),(10988,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10989,-200,'2025-05-09','',3,'Rachunki',1,38),(10990,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10991,-200,'2025-05-09','',3,'Rachunki',1,38),(10992,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10993,-200,'2025-05-09','',3,'Rachunki',1,38),(10994,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10995,-200,'2025-05-09','',3,'Rachunki',1,38),(10996,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10997,-200,'2025-05-09','',3,'Rachunki',1,38),(10998,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(10999,-200,'2025-05-09','',3,'Rachunki',1,38),(11000,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11001,-200,'2025-05-09','',3,'Rachunki',1,38),(11002,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11003,-200,'2025-05-09','',3,'Rachunki',1,38),(11004,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11005,-200,'2025-05-09','',3,'Rachunki',1,38),(11006,-12000,'2025-06-12','obiad kacpra',5,'Jedzenie',0,NULL),(11007,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11008,-200,'2025-05-09','',3,'Rachunki',1,38),(11009,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11010,-200,'2025-05-09','',3,'Rachunki',1,38),(11011,100,'2025-06-10',NULL,5,'Rachunki',0,NULL),(11012,-500,'2025-06-11',NULL,5,'Rachunki',0,NULL),(11013,30,'2025-06-12',NULL,5,'Rachunki',0,NULL),(11014,-10,'2025-06-14',NULL,5,'Rachunki',0,NULL),(11015,40,'2025-06-17',NULL,5,'Rachunki',0,NULL),(11016,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11017,-200,'2025-05-09','',3,'Rachunki',1,38),(11018,200,'2025-06-10',NULL,8,'Rachunki',0,NULL),(11019,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11020,-200,'2025-05-09','',3,'Rachunki',1,38),(11021,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11022,-200,'2025-05-09','',3,'Rachunki',1,38),(11023,-50,'2025-06-11',NULL,5,'Rachunki',0,NULL),(11024,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11025,-200,'2025-05-09','',3,'Rachunki',1,38),(11026,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11027,-200,'2025-05-09','',3,'Rachunki',1,38),(11028,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11029,-200,'2025-05-09','',3,'Rachunki',1,38),(11030,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11031,-200,'2025-05-09','',3,'Rachunki',1,38),(11032,200,'2025-06-18',NULL,8,'Rachunki',0,NULL),(11033,100,'2025-06-10',NULL,8,'Rachunki',0,NULL),(11034,-50,'2025-06-18',NULL,8,'Rachunki',0,NULL),(11035,-50,'2025-06-12',NULL,8,'Rachunki',0,NULL),(11036,10,'2025-06-16',NULL,8,'Rachunki',0,NULL),(11037,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11038,-200,'2025-05-09','',3,'Rachunki',1,38),(11039,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11040,-200,'2025-05-09','',3,'Rachunki',1,38),(11041,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11042,-200,'2025-05-09','',3,'Rachunki',1,38),(11043,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11044,-200,'2025-05-09','',3,'Rachunki',1,38),(11045,-100,'2025-06-14',NULL,8,'Rachunki',0,NULL),(11046,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11047,-200,'2025-05-09','',3,'Rachunki',1,38),(11048,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11049,-200,'2025-05-09','',3,'Rachunki',1,38),(11050,-50,'2025-06-11',NULL,8,'Rachunki',0,NULL),(11051,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11052,-200,'2025-05-09','',3,'Rachunki',1,38),(11053,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11054,-200,'2025-05-09','',3,'Rachunki',1,38),(11055,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11056,-200,'2025-05-09','',3,'Rachunki',1,38),(11057,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11058,-200,'2025-05-09','',3,'Rachunki',1,38),(11059,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11060,-200,'2025-05-09','',3,'Rachunki',1,38),(11061,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11062,-200,'2025-05-09','',3,'Rachunki',1,38),(11063,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11064,-200,'2025-05-09','',3,'Rachunki',1,38),(11065,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11066,-200,'2025-05-09','',3,'Rachunki',1,38),(11067,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11068,-200,'2025-05-09','',3,'Rachunki',1,38),(11069,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11070,-200,'2025-05-09','',3,'Rachunki',1,38),(11071,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11072,-200,'2025-05-09','',3,'Rachunki',1,38),(11073,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11074,-200,'2025-05-09','',3,'Rachunki',1,38),(11075,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11076,-200,'2025-05-09','',3,'Rachunki',1,38),(11077,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11078,-200,'2025-05-09','',3,'Rachunki',1,38),(11079,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11080,-200,'2025-05-09','',3,'Rachunki',1,38),(11081,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11082,-200,'2025-05-09','',3,'Rachunki',1,38),(11083,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11084,-200,'2025-05-09','',3,'Rachunki',1,38),(11085,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11086,-200,'2025-05-09','',3,'Rachunki',1,38),(11087,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11088,-200,'2025-05-09','',3,'Rachunki',1,38),(11089,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11090,-200,'2025-05-09','',3,'Rachunki',1,38),(11091,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11092,-200,'2025-05-09','',3,'Rachunki',1,38),(11093,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11094,-200,'2025-05-09','',3,'Rachunki',1,38),(11095,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11096,-200,'2025-05-09','',3,'Rachunki',1,38),(11097,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11098,-200,'2025-05-09','',3,'Rachunki',1,38),(11099,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11100,-200,'2025-05-09','',3,'Rachunki',1,38),(11101,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11102,-200,'2025-05-09','',3,'Rachunki',1,38),(11103,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11104,-200,'2025-05-09','',3,'Rachunki',1,38),(11105,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11106,-200,'2025-05-09','',3,'Rachunki',1,38),(11108,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11109,-200,'2025-05-09','',3,'Rachunki',1,38),(11110,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11111,-200,'2025-05-09','',3,'Rachunki',1,38),(11112,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11113,-200,'2025-05-09','',3,'Rachunki',1,38),(11114,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11115,-200,'2025-05-09','',3,'Rachunki',1,38),(11116,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11117,-200,'2025-05-09','',3,'Rachunki',1,38),(11118,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11119,-200,'2025-05-09','',3,'Rachunki',1,38),(11120,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11121,-200,'2025-05-09','',3,'Rachunki',1,38),(11122,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11123,-200,'2025-05-09','',3,'Rachunki',1,38),(11124,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11125,-200,'2025-05-09','',3,'Rachunki',1,38),(11126,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11127,-200,'2025-05-09','',3,'Rachunki',1,38),(11128,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11129,-200,'2025-05-09','',3,'Rachunki',1,38),(11130,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11131,-200,'2025-05-09','',3,'Rachunki',1,38),(11132,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11133,-200,'2025-05-09','',3,'Rachunki',1,38),(11134,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11135,-200,'2025-05-09','',3,'Rachunki',1,38),(11136,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11137,-200,'2025-05-09','',3,'Rachunki',1,38),(11138,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11139,-200,'2025-05-09','',3,'Rachunki',1,38),(11140,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11141,-200,'2025-05-09','',3,'Rachunki',1,38),(11142,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11143,-200,'2025-05-09','',3,'Rachunki',1,38),(11144,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11145,-200,'2025-05-09','',3,'Rachunki',1,38),(11146,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11147,-200,'2025-05-09','',3,'Rachunki',1,38),(11148,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11149,-200,'2025-05-09','',3,'Rachunki',1,38),(11150,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11151,-200,'2025-05-09','',3,'Rachunki',1,38),(11152,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11153,-200,'2025-05-09','',3,'Rachunki',1,38),(11154,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11155,-200,'2025-05-09','',3,'Rachunki',1,38),(11156,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11157,-200,'2025-05-09','',3,'Rachunki',1,38),(11158,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11159,-200,'2025-05-09','',3,'Rachunki',1,38),(11160,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11161,-200,'2025-05-09','',3,'Rachunki',1,38),(11162,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11163,-200,'2025-05-09','',3,'Rachunki',1,38),(11164,-150,'2025-06-13','Internet i telefon',1,'Rachunki',1,36),(11165,-200,'2025-05-09','',3,'Rachunki',1,38),(11166,-200,'2025-05-16','',3,'Rachunki',1,38),(11167,-200,'2025-05-23','',3,'Rachunki',1,38),(11168,-200,'2025-05-30','',3,'Rachunki',1,38),(11169,-200,'2025-06-06','',3,'Rachunki',1,38),(11170,-200,'2025-06-13','',3,'Rachunki',1,38);
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
INSERT INTO `Operacja cykliczna` VALUES (35,3000,'2025-05-02','','Co tydzień',1,'Pensja','2025-07-02'),(36,-150,'2025-05-13','Internet i telefon','Co tydzień',1,'Rachunki','2025-06-20'),(37,5000,'2025-04-02','','Co miesiąc',3,'Pensja','2025-07-02'),(38,-200,'2025-05-02','','Co tydzień',3,'Rachunki','2025-06-20');
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
) ENGINE=InnoDB AUTO_INCREMENT=15 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Uzytkownik zalogowany`
--

LOCK TABLES `Uzytkownik zalogowany` WRITE;
/*!40000 ALTER TABLE `Uzytkownik zalogowany` DISABLE KEYS */;
INSERT INTO `Uzytkownik zalogowany` VALUES (1,'Janusz','Janski','januszek@gmail.com','haslo123',0,'2021-01-20','Admin'),(2,'Mikolaj','Wielki','mikolaj96@gmail.com','asdasdasd',0,'2025-05-10','Użytkownik'),(3,'Basia','Maczna','baska@ya.com','makabasi',0,'2025-05-10','Rodzic'),(4,'Artur','Dobry','asd@asd.com','asdasdasdasdasd',0,'2025-05-10','Rodzic'),(5,'Jan','Prus','janprus@poczta.com','haslo123',0,'2025-05-14','Admin'),(6,'Jakub','Test','jakub.test@gmail.com','testjakub',0,'2005-03-20','Rodzic'),(7,'Aleksandra','Gral','ola.gral@wp.pl','aleksandra',0,'2009-01-20','Dziecko'),(8,'Jan','Nowak','abc@gmail.com','haslo123',0,'2001-01-20','Dziecko'),(9,'Teresa','Sad','teresa@gmail.com','sad54321',0,'1955-05-22','Użytkownik'),(10,'Ela','Kot','elakot@wp.pl','abcabcabc',0,'1979-05-22','Dziecko'),(11,'Szaralinda','Łączka','krzysztof222@o2.pl','popopoko',1,'2000-03-01','Dziecko'),(12,'Maja','Ełska','me@gmail.com','haslo123',0,'2025-05-26','Rodzic'),(14,'a','b','a@g.c','haslo123',0,'2025-06-18','Niezdefiniowany');
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

-- Dump completed on 2025-06-18  4:30:24
