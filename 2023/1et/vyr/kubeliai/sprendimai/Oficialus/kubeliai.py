"""

Sprendimo idėja: yra du atskiri atvejai. Vienas, kai K = 2, ir
kitas, kai K > 2. Juos galima nagrinėti atskirai:

1) Jeigu K = 2, tai pradinė seka galėjo būti vienas iš dviejų
variantų:
   a) 1, 2, 1, 2, 1, 2, ...
   b) 2, 1, 2, 1, 2, 1, ...
Belieka abu šiuos variantus pamėginti ir patikrinti, ar kuris
nors jų galėjo būti pradinė seka. Jei nė vienas negalėjo būti,
tuomet atsakymas yra -1.

2) Jeigu K > 2, atsakymas visada egzistuos, tereikia sugalvoti,
kaip jį sukonstruoti. Galima eiti per kubelius iš eilės nuo pirmojo
iki paskutinio ir žiūrėti, kurie buvo išimti, o kurie ne. Jei kubelis
buvo išimtas, tai į šią vietą galima įdėti bet kokį kubelį, tik
svarbu, kad jo spalva nesutaptų su prieš jį ir po jo esančiais
kubeliais. Toks konstravimo būdas visada gaus atsakymą, kuris atitinka
sąlygos ribojimus.

"""

n, k = map(int, input().split())
kubeliai = [int(x) for x in input().split()]

if k == 2:
    # reikia išmėginti du atvejus:
    #  1) blokelių seka buvo: 1 2 1 2 1 2 ...
    #  2) blokelių seka buvo: 2 1 2 1 2 1 ...
    # kai k == 2, jokios kitos sekos nėra įmanomos

    # mėginam pirmąjį atvejį
    seka = []
    for i in range(n):
        if i % 2 == 0:
            seka.append(1)
        else:
            seka.append(2)

    # patikrinam, ar ši seka galėjo būti pradinė
    arTinkamaSeka = True
    for i in range(n):
        if kubeliai[i] != 0 and seka[i] != kubeliai[i]:
            arTinkamaSeka = False
    
    if arTinkamaSeka:
        atsakymas = ""
        for i in range(n):
            atsakymas += str(seka[i]) + " "
        print(atsakymas)
        exit(0)

    # mėginam antrąjį atvejį
    seka = []
    for i in range(n):
        if i % 2 == 0:
            seka.append(2)
        else:
            seka.append(1)

    # patikrinam, ar ši seka galėjo būti pradinė
    arTinkamaSeka = True
    for i in range(n):
        if kubeliai[i] != 0 and seka[i] != kubeliai[i]:
            arTinkamaSeka = False
    
    if arTinkamaSeka:
        atsakymas = ""
        for i in range(n):
            atsakymas += str(seka[i]) + " "
        print(atsakymas)
    else:
        print("-1")

    exit(0)
    

# toliau sprendžiam k > 2 atvejį
# šiuo atveju atsakymas visada egzistuoja - tereikia
# į išimtų kubelių vietą dėti tokius kubelius, kurių
# spalvos nesutaptų su gretimais

for i in range(n):
    if kubeliai[i] == 0: # jei išimtas kubelis, mėginsim įdėti naują
        for spalva in range(1, k+1):
            # tikrinam, ar galim įdėti šią spalvą
            arGalimDeti = True

            if i > 0 and kubeliai[i-1] == spalva:  # jei prieš tai buvęs kubelis
                                                   # yra tos pačios spalvos,
                arGalimDeti = False                # tai dėti šios spalvos negalim

            if i < n-1 and kubeliai[i+1] == spalva:  # jei po to esantis kubelis
                                                     # yra tos pačios spalvos,
                arGalimDeti = False                  # tai dėti šios spalvos negalim

            if arGalimDeti: # jei galim dėti šią spalvą
                kubeliai[i] = spalva
                break

# spausdinam atsakymą
atsakymas = ""
for i in range(n):
    atsakymas += str(kubeliai[i]) + " "
print(atsakymas)