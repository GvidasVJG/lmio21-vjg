/*

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

*/

#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    int kubeliai[n];
    for (int i = 0; i < n; i++)
        cin >> kubeliai[i];

    if (k == 2) {
        // reikia išmėginti du atvejus:
        //  1) blokelių seka buvo: 1 2 1 2 1 2 ...
        //  2) blokelių seka buvo: 2 1 2 1 2 1 ...
        // kai k == 2, jokios kitos sekos nėra įmanomos

        // mėginam pirmąjį atvejį
        int seka[n];
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0)
                seka[i] = 1;
            else
                seka[i] = 2;
        }

        // patikrinam, ar ši seka galėjo būti pradinė
        bool arTinkamaSeka = true;
        for (int i = 0; i < n; i++) {
            if (kubeliai[i] != 0 && seka[i] != kubeliai[i])
                arTinkamaSeka = false;
        }

        if (arTinkamaSeka) {
            // radom galimą atsakymą
            for (int i = 0; i < n; i++)
                cout << seka[i] << " ";
            cout << endl;
            return 0;
        }

        // mėginam antrąjį atvejį
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0)
                seka[i] = 2;
            else
                seka[i] = 1;
        }

        // patikrinam, ar ši seka galėjo būti pradinė
        arTinkamaSeka = true;
        for (int i = 0; i < n; i++) {
            if (kubeliai[i] != 0 && seka[i] != kubeliai[i])
                arTinkamaSeka = false;
        }

        if (arTinkamaSeka) {
            // radom galimą atsakymą
            for (int i = 0; i < n; i++)
                cout << seka[i] << " ";
            cout << endl;
        } else { // netiko nei pirmas, nei antras atvejai
            cout << "-1" << endl;
        }

        return 0;
    }

    // toliau sprendžiam k > 2 atvejį
    // šiuo atveju atsakymas visada egzistuoja - tereikia
    // į išimtų kubelių vietą dėti tokius kubelius, kurių
    // spalvos nesutaptų su gretimais

    for (int i = 0; i < n; i++) {
        if (kubeliai[i] == 0) { // jei išimtas kubelis, mėginsim įdėti naują
            for (int spalva = 1; spalva <= k; spalva++) {
                // tikrinam, ar galim įdėti šią spalvą
                bool arGalimDeti = true;

                if (i > 0 && kubeliai[i-1] == spalva)  // jei prieš tai buvęs kubelis
                                                       // yra tos pačios spalvos,
                    arGalimDeti = false;               // tai dėti šios spalvos negalim

                if (i < n-1 && kubeliai[i+1] == spalva)  // jei po to esantis kubelis
                                                         // yra tos pačios spalvos,
                    arGalimDeti = false;                 // tai dėti šios spalvos negalim

                if (arGalimDeti) { // jei galim dėti šią spalvą
                    kubeliai[i] = spalva;
                    break;
                }
            }
        }
    }

    // spausdinam atsakymą
    for (int i = 0; i < n; i++)
        cout << kubeliai[i] << " ";
    cout << endl;

    return 0;
}
