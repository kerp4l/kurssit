# CT30A3370 Käyttöjärjestelmät ja systeemiohjelmointi
# Harjoitus viikko 2, tehtävä 1
# Topi Jussinniemi 0401301

def summa(x, y):
	a = x
	b = y
	
	if a == b:
		summa = a << 1
		print(a, "+", a, "=", summa)
	else:
		aAb = a & b
		ylivuoto = aAb << 1
		aXb = a ^ b
		while ylivuoto != 0:
			aAb = ylivuoto & aXb
			ylivuoto2 = aAb << 1
			aXb = ylivuoto ^ aXb
			ylivuoto = ylivuoto2
		print(a, "+", b,"=", aXb)


summa(15, 5)
summa(5, 3)
summa(12, 12)
summa(130, 96)
summa(123, 321)
summa(123, 456)
summa(456, 789)

#eof
