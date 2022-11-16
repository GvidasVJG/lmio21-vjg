"""
Sprendimo idėja:
Suskaičiuoti, kiek draugų aplenkė Martyną. Tuomet atsakymas bus šis
skaičius, padidintas vienetu.

Pavyzdžiui, jei Martyną aplenkė keturi draugai, tai tuomet Martyno
vieta yra 4+1 = 5.
"""

# įvesties nuskaitymas
n, martyno_laikas = map(int, input().split())
draugu_laikai = map(int, input().split())

kiek_aplenke = 0 # kiek draugų aplenkė Martyną

for draugo_laikas in draugu_laikai:
    if (draugo_laikas < martyno_laikas): # šis draugas greitesnis už Martyną
        kiek_aplenke += 1

vieta = kiek_aplenke + 1

print(vieta)
