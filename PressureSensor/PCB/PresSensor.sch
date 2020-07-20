EESchema Schematic File Version 4
LIBS:PresSensor-cache
EELAYER 26 0
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
L LPS33HWTR:LPS33HWTR U1
U 1 1 5C7FF841
P 6550 2550
F 0 "U1" H 6550 3317 50  0000 C CNN
F 1 "LPS33HWTR" H 6550 3226 50  0000 C CNN
F 2 "LPS33HWTR:PQFN60P330X330X290-11N" H 6550 2550 50  0001 L BNN
F 3 "Pressure Sensor" H 6550 2550 50  0001 L BNN
F 4 "LPS33HWTR" H 6550 2550 50  0001 L BNN "Field4"
F 5 "497-17590-1-ND" H 6550 2550 50  0001 L BNN "Field5"
F 6 "https://www.digikey.com/product-detail/en/stmicroelectronics/LPS33HWTR/497-17590-1-ND/7565514?utm_source=snapeda&utm_medium=aggregator&utm_campaign=symbol" H 6550 2550 50  0001 L BNN "Field6"
F 7 "STMicroelectronics" H 6550 2550 50  0001 L BNN "Field7"
F 8 "LGA STMicroelectronics" H 6550 2550 50  0001 L BNN "Field8"
	1    6550 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	7350 2050 7400 2050
Wire Wire Line
	7350 2850 7350 2950
Wire Wire Line
	7350 2650 7350 2850
Connection ~ 7350 2850
Wire Wire Line
	5750 2350 5550 2350
Wire Wire Line
	5550 2350 5550 2450
Wire Wire Line
	5550 3950 6350 3950
Wire Wire Line
	7350 2550 7600 2550
Wire Wire Line
	7600 2550 7600 3850
Wire Wire Line
	6850 3850 7600 3850
Wire Wire Line
	7500 2050 7500 3300
$Comp
L Device:C C1
U 1 1 5C809D8C
P 7400 2200
F 0 "C1" H 7515 2246 50  0000 L CNN
F 1 "C" H 7515 2155 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 7438 2050 50  0001 C CNN
F 3 "~" H 7400 2200 50  0001 C CNN
	1    7400 2200
	1    0    0    -1  
$EndComp
Connection ~ 7400 2050
Wire Wire Line
	7400 2050 7500 2050
Wire Wire Line
	7400 2350 7400 2650
Wire Wire Line
	7400 2650 7350 2650
Connection ~ 7350 2650
$Comp
L Device:R R1
U 1 1 5C80AD9A
P 5200 2450
F 0 "R1" V 4993 2450 50  0000 C CNN
F 1 "R" V 5084 2450 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 5130 2450 50  0001 C CNN
F 3 "~" H 5200 2450 50  0001 C CNN
	1    5200 2450
	0    1    1    0   
$EndComp
Wire Wire Line
	5550 2450 5350 2450
Connection ~ 5550 2450
Wire Wire Line
	5550 2450 5550 3950
Wire Wire Line
	5050 2450 5050 3300
Wire Wire Line
	5050 3300 5250 3300
$Comp
L Device:R R2
U 1 1 5C80B62B
P 5250 2850
F 0 "R2" H 5320 2896 50  0000 L CNN
F 1 "R" H 5320 2805 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 5180 2850 50  0001 C CNN
F 3 "~" H 5250 2850 50  0001 C CNN
	1    5250 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	5750 2550 5250 2550
Wire Wire Line
	5250 2550 5250 2700
Wire Wire Line
	5250 3000 5250 3300
Connection ~ 5250 3300
$Comp
L Connector_Generic:Conn_01x04 J1
U 1 1 5C80C96C
P 6550 3850
F 0 "J1" H 6630 3842 50  0000 L CNN
F 1 "Conn_01x04" H 6630 3751 50  0000 L CNN
F 2 "Connector_Wire:SolderWirePad_2x02_P2.54mm_Drill0.8mm" H 6550 3850 50  0001 C CNN
F 3 "~" H 6550 3850 50  0001 C CNN
	1    6550 3850
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x04 J2
U 1 1 5C80C9B0
P 6650 3950
F 0 "J2" H 6570 3525 50  0000 C CNN
F 1 "Conn_01x04" H 6570 3616 50  0000 C CNN
F 2 "Connector_Wire:SolderWirePad_2x02_P2.54mm_Drill0.8mm" H 6650 3950 50  0001 C CNN
F 3 "~" H 6650 3950 50  0001 C CNN
	1    6650 3950
	-1   0    0    1   
$EndComp
Wire Wire Line
	6850 3750 8200 3750
Wire Wire Line
	8200 3750 8200 1700
Wire Wire Line
	8200 1700 5750 1700
Wire Wire Line
	5750 1700 5750 2250
Wire Wire Line
	5750 2450 5650 2450
Wire Wire Line
	5650 2450 5650 4050
Wire Wire Line
	5650 4050 6350 4050
Wire Wire Line
	5750 2550 5750 4200
Wire Wire Line
	5750 4200 7000 4200
Wire Wire Line
	7000 4200 7000 3950
Wire Wire Line
	7000 3950 6850 3950
Connection ~ 5750 2550
Wire Wire Line
	7350 2950 7350 4050
Wire Wire Line
	7350 4050 6850 4050
Connection ~ 7350 2950
Wire Wire Line
	5250 3300 6200 3300
Wire Wire Line
	6200 3300 6200 3850
Wire Wire Line
	6200 3850 6350 3850
Connection ~ 6200 3300
Wire Wire Line
	6200 3300 7500 3300
Wire Wire Line
	7350 2150 7700 2150
Wire Wire Line
	7700 2150 7700 3450
Wire Wire Line
	7700 3450 6350 3450
Wire Wire Line
	6350 3450 6350 3750
$EndSCHEMATC
