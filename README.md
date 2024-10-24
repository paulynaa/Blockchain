# Užduoties formuluotė
Sukurti "centralizuotą" blokų grandinę ir imituoti jos veikimą kuo realistiškiau.
1. Sugeneruoti ~1000 tinklo vartotojų, turinčių šiuos atributus:
- vardą,
- viešąjį raktą,
- atsitiktinį valiutos balansą.
2. Sugeneruoti ~10000 naujų transakcijų, kurios dar nėra įtrauktos į jokį bloką. Transakcijos struktūra turi turėti šiuos atributus:
- transakcijos ID,
- siuntėjas,
- gavėjas,
- suma.
3. Atsitiktinai pasirinkite 100 transakcijų iš transakcijų sąrašo ir pabandykite jas įtraukti į naują bloką.
4. Realizuokite naujų blokų kasimo procesą, naudojant Proof-of-Work (PoW) algoritmą. Tikslas – rasti naujo bloko
maišos reikšmę, atitinkančią Difficulty Target reikalavimą. Nulių skaičius priklauso
nuo jūsų sukurtos maišos funkcijos.
5. Suradus tinkamą naujo bloko maišos reikšmę:
- ištrinkite į bloką įtrauktas transakcijas iš transakcijų sąrašo;
- "įvykdykite" transakcijas, t.y. atnaujinkite vartotojų balansus;
- pridėkite naują bloką prie blokų grandinės.

# Reikalavimai versijai v0.1
1. Realizuoti supaprastintą "centralizuotą" blokų grandinę. Maišos funkcijai naudoti savo sukurtą funkciją.
2. Transakcijų ir blokų kūrimo procesas turi būti matomas. Sukurti funkcijas, kurios leidžia atspausdinti bet
kurią transakciją ir bloką. Išvedimo detalumas ir vizualumas turės įtakos balui.
3. Vietoj dvejetainio Merkle medžio, galite naudoti visų bloko transakcijų ID maišos reikšmę.
4. Saugumas yra labai svarbus blokų grandinėms, todėl naudokite gerąsias OOP praktikas (pvz., enkapsuliavimą,
konstruktorius, RAII idiomą).


![image](https://github.com/user-attachments/assets/7e6d471d-ec13-4ae0-bb27-63105052478a)
