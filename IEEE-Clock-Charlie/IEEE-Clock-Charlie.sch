EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MCU_Module:Arduino_Nano_v3.x A1
U 1 1 5E1FF514
P 5550 5700
F 0 "A1" H 5550 4611 50  0000 C CNN
F 1 "Arduino_Nano_v3.x" H 5550 4520 50  0000 C CNN
F 2 "Module:Arduino_Nano" H 5700 4750 50  0001 L CNN
F 3 "http://www.mouser.com/pdfdocs/Gravitech_Arduino_Nano3_0.pdf" H 5550 4700 50  0001 C CNN
	1    5550 5700
	1    0    0    -1  
$EndComp
$Comp
L ADA_CHARLIE:ADA_CHARLIE U2
U 1 1 5E23BD19
P 5600 2850
F 0 "U2" H 5600 3815 50  0000 C CNN
F 1 "ADA_CHARLIE" H 5600 3724 50  0000 C CNN
F 2 "IEEE-Clock-Charlie:DIP-26_1000_ELL" H 5600 2850 50  0001 C CNN
F 3 "DOCUMENTATION" H 5600 2850 50  0001 C CNN
	1    5600 2850
	1    0    0    -1  
$EndComp
$Comp
L ADA_CHARLIE:ADA_CHARLIE U3
U 1 1 5E23D5CF
P 8400 2800
F 0 "U3" H 8400 3765 50  0000 C CNN
F 1 "ADA_CHARLIE" H 8400 3674 50  0000 C CNN
F 2 "IEEE-Clock-Charlie:DIP-26_1000_ELL" H 8400 2800 50  0001 C CNN
F 3 "DOCUMENTATION" H 8400 2800 50  0001 C CNN
	1    8400 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	10000 3950 10000 3200
Wire Wire Line
	10000 3200 9150 3200
Wire Wire Line
	10100 4050 10100 3100
Wire Wire Line
	10100 3100 9150 3100
Wire Wire Line
	6350 3250 7350 3250
Wire Wire Line
	7350 3250 7350 3950
Wire Wire Line
	6350 3150 7450 3150
Wire Wire Line
	7450 3150 7450 4050
Connection ~ 7450 4050
Wire Wire Line
	7450 4050 10100 4050
Wire Wire Line
	7450 6100 7450 4050
Wire Wire Line
	6050 6100 7450 6100
Wire Wire Line
	6050 6200 7350 6200
Wire Wire Line
	4600 3100 4600 4050
Wire Wire Line
	4600 4050 7450 4050
Wire Wire Line
	4500 3200 4500 3950
Wire Wire Line
	4500 3950 4750 3950
Connection ~ 7350 3950
Wire Wire Line
	7350 3950 7350 6200
Wire Wire Line
	7350 3950 10000 3950
Wire Wire Line
	4400 3300 4400 4250
Wire Wire Line
	4400 4250 6450 4250
Wire Wire Line
	9500 4250 9500 3300
Wire Wire Line
	9500 3300 9150 3300
Wire Wire Line
	6350 3350 6450 3350
Wire Wire Line
	6450 3350 6450 4250
Connection ~ 6450 4250
Wire Wire Line
	6450 4250 7550 4250
Wire Wire Line
	9200 4350 9200 3400
Wire Wire Line
	9200 3400 9150 3400
Wire Wire Line
	5750 4350 5750 4700
Connection ~ 5750 4350
Wire Wire Line
	5750 4350 6350 4350
$Comp
L power:GND #PWR0101
U 1 1 5E24D885
P 4400 4550
F 0 "#PWR0101" H 4400 4300 50  0001 C CNN
F 1 "GND" H 4405 4377 50  0000 C CNN
F 2 "" H 4400 4550 50  0001 C CNN
F 3 "" H 4400 4550 50  0001 C CNN
	1    4400 4550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 5E24E445
P 5600 7150
F 0 "#PWR0102" H 5600 6900 50  0001 C CNN
F 1 "GND" H 5605 6977 50  0000 C CNN
F 2 "" H 5600 7150 50  0001 C CNN
F 3 "" H 5600 7150 50  0001 C CNN
	1    5600 7150
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 6700 5650 7050
Wire Wire Line
	5650 7050 5600 7050
Wire Wire Line
	5600 7050 5600 7150
Wire Wire Line
	5550 6700 5550 7050
Wire Wire Line
	5550 7050 5600 7050
Connection ~ 5600 7050
Wire Wire Line
	4400 4250 4400 4550
Connection ~ 4400 4250
Wire Wire Line
	6350 3450 6350 4350
Connection ~ 6350 4350
Wire Wire Line
	6350 4350 9200 4350
Wire Wire Line
	4300 3100 4600 3100
Wire Wire Line
	4300 3200 4500 3200
Wire Wire Line
	4300 3300 4400 3300
Wire Wire Line
	4300 4350 5750 4350
$Comp
L ADA_CHARLIE:ADA_CHARLIE U1
U 1 1 5E23A680
P 3550 2800
F 0 "U1" H 3550 3765 50  0000 C CNN
F 1 "ADA_CHARLIE" H 3550 3674 50  0000 C CNN
F 2 "IEEE-Clock-Charlie:DIP-26_1000_ELL" H 3550 2800 50  0001 C CNN
F 3 "DOCUMENTATION" H 3550 2800 50  0001 C CNN
	1    3550 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 3400 4300 4350
Connection ~ 9150 3400
Wire Wire Line
	9150 3400 9100 3400
Connection ~ 9150 3300
Wire Wire Line
	9150 3300 9100 3300
Connection ~ 9150 3200
Wire Wire Line
	9150 3200 9100 3200
Connection ~ 9150 3100
Wire Wire Line
	9150 3100 9100 3100
Wire Wire Line
	7650 2300 7550 2300
Wire Wire Line
	7550 2300 7550 4250
Connection ~ 7550 4250
Wire Wire Line
	7550 4250 9500 4250
Wire Wire Line
	4850 2350 4750 2350
Wire Wire Line
	4750 2350 4750 3950
Connection ~ 4750 3950
Wire Wire Line
	4750 3950 7350 3950
Wire Wire Line
	2800 2300 2600 2300
Wire Wire Line
	2600 2300 2600 4050
Wire Wire Line
	2600 4050 3700 4050
Connection ~ 4600 4050
$Comp
L ADA_DS3231:ADA_DS3231 U4
U 1 1 5E30AA37
P 2450 5450
F 0 "U4" H 2292 6165 50  0000 C CNN
F 1 "ADA_DS3231" H 2292 6074 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x08_P2.54mm_Vertical" H 2450 5450 50  0001 C CNN
F 3 "DOCUMENTATION" H 2450 5450 50  0001 C CNN
	1    2450 5450
	-1   0    0    -1  
$EndComp
Wire Wire Line
	3200 5300 3600 5300
Wire Wire Line
	3600 5300 3600 3950
Wire Wire Line
	3600 3950 4500 3950
Connection ~ 4500 3950
Wire Wire Line
	3200 5400 3700 5400
Wire Wire Line
	3700 5400 3700 4050
Connection ~ 3700 4050
Wire Wire Line
	3700 4050 4600 4050
Wire Wire Line
	3200 5200 3300 5200
Wire Wire Line
	3300 5200 3300 4250
Wire Wire Line
	3300 4250 4400 4250
Wire Wire Line
	3200 5100 3200 4350
Wire Wire Line
	3200 4350 4300 4350
Connection ~ 4300 4350
Wire Wire Line
	5050 5300 4050 5300
Wire Wire Line
	4050 5600 3200 5600
$Comp
L Device:R R1
U 1 1 5E31C3B9
P 4050 5450
F 0 "R1" H 4120 5496 50  0000 L CNN
F 1 "R" H 4120 5405 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 3980 5450 50  0001 C CNN
F 3 "~" H 4050 5450 50  0001 C CNN
	1    4050 5450
	1    0    0    -1  
$EndComp
$Comp
L ADA_ROTARY:PEC11R-4215F-S0024 S1
U 1 1 5E32775E
P 3950 6250
F 0 "S1" H 3900 6622 60  0000 C CNN
F 1 "PEC11R-4215F-S0024" H 3900 6516 60  0000 C CNN
F 2 "IEEE-Clock-Charlie:RotaryEncoder_Alps_EC11E_Vertical_H20mm" H 4150 6450 60  0001 L CNN
F 3 "https://www.bourns.com/docs/Product-Datasheets/PEC11R.pdf" H 4150 6550 60  0001 L CNN
F 4 "PEC11R-4215F-S0024-ND" H 4150 6650 60  0001 L CNN "Digi-Key_PN"
F 5 "PEC11R-4215F-S0024" H 4150 6750 60  0001 L CNN "MPN"
F 6 "Sensors, Transducers" H 4150 6850 60  0001 L CNN "Category"
F 7 "Encoders" H 4150 6950 60  0001 L CNN "Family"
F 8 "https://www.bourns.com/docs/Product-Datasheets/PEC11R.pdf" H 4150 7050 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/bourns-inc/PEC11R-4215F-S0024/PEC11R-4215F-S0024-ND/4499665" H 4150 7150 60  0001 L CNN "DK_Detail_Page"
F 10 "ROTARY ENCODER MECHANICAL 24PPR" H 4150 7250 60  0001 L CNN "Description"
F 11 "Bourns Inc." H 4150 7350 60  0001 L CNN "Manufacturer"
F 12 "Active" H 4150 7450 60  0001 L CNN "Status"
	1    3950 6250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3250 6550 3650 6550
Wire Wire Line
	3650 6350 3250 6350
Connection ~ 3250 6550
Wire Wire Line
	3250 6350 3250 6550
Wire Wire Line
	3250 6550 3250 6950
Wire Wire Line
	3650 6150 3250 6150
Wire Wire Line
	3250 6150 3250 6350
Connection ~ 3250 6350
Wire Wire Line
	4150 6150 4350 6150
Wire Wire Line
	4350 6150 4350 5800
Wire Wire Line
	4350 5800 5050 5800
Wire Wire Line
	4150 6250 4400 6250
Wire Wire Line
	4400 6250 4400 5900
Wire Wire Line
	4400 5900 5050 5900
Wire Wire Line
	4150 6450 4450 6450
Wire Wire Line
	4450 6450 4450 6000
Wire Wire Line
	4450 6000 5050 6000
$Comp
L power:GND #PWR0103
U 1 1 5E33C229
P 3250 6950
F 0 "#PWR0103" H 3250 6700 50  0001 C CNN
F 1 "GND" H 3255 6777 50  0000 C CNN
F 2 "" H 3250 6950 50  0001 C CNN
F 3 "" H 3250 6950 50  0001 C CNN
	1    3250 6950
	1    0    0    -1  
$EndComp
$Comp
L ADA_ROTARY:IEE_LOGO L1
U 1 1 5E34B000
P 8850 5350
F 0 "L1" H 9078 5463 50  0000 L CNN
F 1 "IEE_LOGO" H 9078 5372 50  0000 L CNN
F 2 "IEEE-Clock-Charlie:IEEE_LOGO" H 8850 5350 50  0001 C CNN
F 3 "" H 8850 5350 50  0001 C CNN
	1    8850 5350
	1    0    0    -1  
$EndComp
Wire Wire Line
	8850 5500 8850 5700
Wire Wire Line
	6050 5650 6050 5700
Wire Wire Line
	6050 5700 8850 5700
$EndSCHEMATC
