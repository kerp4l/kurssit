# CT30A3370 Käyttöjärjestelmät ja systeemiohjelmointi
# Harjoitus 2, tehtävä 1
# Topi Jussinniemi 0401301

def summa(x, y):
	a = x
	b = y
	if a == b:
			summa = a << 1
	else:
		aAb = a & b
		carry = aAb << 1
		aXb = a ^ b
		while carry != 0:
			aAb = carry & aXb
			aXb = carry ^ aXb
			carry = aAb << 1
		summa = aXb
	print(a, "+", b, "=", summa)


# Funktion toiminnan testaaminen erilaisilla syötteillä

summa(5, 5)
summa(7, 5)
summa(13, 17)
summa(32, 64)
summa(67, 112)
summa(100, 100)
summa(154, 189)

# eof
