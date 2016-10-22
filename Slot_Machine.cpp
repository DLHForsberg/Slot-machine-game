//
//
// Skapat av Daniel Forsberg
// 841004-5911
// Grundläggande programmering i C++
// Systemvetenskap - Business Intelligence
// 


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

void valkommen();				// Tre stycken egendefinierade funktioner
void insattning();
void satsning();
bool checkSvar(char n);			// Två stycken egendefinierade funktioner med parameter och returvärde
int visaVinst(int linjer, int bet);

int valor;
int saldo;
int bet;
int linjer;
int vinst;



int main()
{
    
    char svar = 0;
    
	valkommen();	//Här kallas funktion för hälsning och insättning av pengar
    insattning();
    
    
    while (svar = 'X')
    {
        satsning();			//Funktionen för att satsa pengar kallas
        
		char symboler[] = {'O','X','P'};	// Spelfält skapas

		char spel[3][3]; 


									
		for (int i = 0; i<3; i++) 	//Slumpar och fyller spelfältet
		{
			for (int j = 0; j<3; j++) 
			{
		    	int rndnum = round((double)rand() / (double) RAND_MAX * 3);
		    	spel[i][j] = symboler[rndnum];
		    	cout << spel[i][j];
		        	if (j == 2)
						cout << endl;
			
			}
		}
        							
               
        					//Kontroll av spelfält och linjeräkning
        int linjer = 0;			
    
        if (spel[0][0] == spel[1][1] && spel[0][0] == spel[2][2]){
            linjer++;
        }
    
        if (spel[0][2] == spel[1][1] && spel[0][2] == spel[2][0]){
            linjer++;
        }
    
        if (spel[0][0] == spel[0][1] && spel[0][0] == spel[0][2]){
            linjer ++;
        }
        
        if (spel[1][0] == spel[1][1] && spel[1][0] == spel[1][2]){
            linjer ++;
        }

        if (spel[2][0] == spel[2][1] && spel[2][0] == spel[2][2]){
            linjer ++;
        }

        if (spel[0][0] == spel[1][0] && spel[0][0] == spel[2][0]){
            linjer ++;
        }

        if (spel[0][1] == spel[1][1] && spel[0][1] == spel[2][1]){
            linjer ++;
        }

        if (spel[0][2] == spel[1][2] && spel[0][2] == spel[2][2]){
            linjer ++;
        }

    	
		vinst=0;
		
        vinst = visaVinst(linjer, bet);		// Funktion kallas för att räkna ut vinst
		
		cout << endl;
		cout << "Du fick " << linjer << " linjer och vann: " << vinst << " kr" << endl;
		saldo=saldo+vinst;

        cout << "Ditt saldo är nu: " << saldo << endl;
        cout << endl;
        
	
		if (saldo == 0)				// Spelet svslutas här om saldot är slut
        {
        	cout << "Tyvärr är dina pengar slut nu, starta spelet och stoppa i mer" << endl;
        	cout << "pengar om du vill spela igen." << endl;
        	return 0;
        }
        	else
        	{							// Spelare får svara på om den vill spela igen
        		cout << "Vill du spela igen? j/n" <<endl;
        		cout << "Om du väljer att inte fortsätta kommer dina pengar" << endl;
        		cout << "att matas ut och spelet avslutas." << endl;
        		cin >> svar;
        	}
        
        
        if (checkSvar(svar))
            
            return 0;
    }
    return 0;
}

			//	Här börjar alla funktioner //

int visaVinst(int linjer, int bet){		//Vinstomräkning och visning av vunna linjer
	if (linjer == 0)	
	{		
		cout << endl;
    	cout << "Tyvärr du förlorade, försök gärna igen." << endl;
	}

		else if (linjer == 1)
		{
    		return (bet*2);
		}

		else if (linjer == 2)
		{
			return (bet*4);
		}

		else if (linjer == 3)
		{
    		return (bet*8);
		}

		else if (linjer == 4)
		{
    		return (bet*16);
		}

		else if (linjer == 8)
		{
    		return (bet*128);
		}
		return 0;
		
}



void valkommen() 			// Funktion för välkomnande och vinstinformation
{
    cout << "Välkommen till Enarmad Bandit!" << endl;
    cout << "Du kan satsa mellan 1-50 kr varje omgång." << endl;
    cout << endl;
    cout << "Vinster ser ut som följande:" << endl;
    cout << endl;
    cout << "1 rad ger 2 ggr insatsen." << endl;
    cout << "2 rader ger 4 ggr insatsen." << endl;
    cout << "3 rader ger 8 ggr insatsen." << endl;
    cout << "4 rader ger 16 ggr insatsen." << endl;
    cout << "Fullt spelfält ger jackpot: 128 ggr insatsen!" << endl;
    cout << endl;
}

void insattning() 				// Funktion för insättning av pengar
{
    
    bool satsningssumma=true;
    while (satsningssumma)
    {
        cout << "Du kan sätta in sedlar med värde 20, 100 eller 500kr." <<endl;
        cout << endl;
        cout << "Vilken valör vill du använda dig av?" <<endl;
        cin >> valor;
        
        if (valor==20 || valor==100 || valor==500)		// Kontroll av sedelvalör
        {
            cout << "Du kan sätta in max 1000 kr." <<endl;
            cout << endl;
            cout << "Hur många sedlar vill du sätta in?" <<endl;
            cin >> saldo;
            saldo=saldo*valor;
            
            if (saldo > 1000)		// Kontroll av insättningsmängd
            {
                cout << "Du kan tyvärr bara sätta in 1000 kr, resterande pengar får du tillbaka." <<endl;
                cout << endl;
                saldo = 1000;
            }
            

            satsningssumma=false;
        }
            else
            {
                cout<<"Tyvärr kan du inte använda den valören, försök igen."<<endl;
                satsningssumma=true;
            }
    }
}

void satsning()					// Funktion för satsning inför spelomgång
{
    bool villkor=true;
    while(villkor)
    {
        cout << "Du kan satsa mellan 1-50 kr per omgång." << endl;
        cout << endl;
        cout << "Ditt saldo är: " << saldo << " kr, hur mycket vill du satsa?" << endl;
        cin >> bet;
        cout << endl;
        
        if(bet > 50)			// Kontroll av hur mycket spelare satsat
        {
            cout << "Du har försökt satsa för mycket, försök igen." << endl;
            cout << endl;
            villkor=true;
        
        }
            else
            {
                saldo=saldo-bet;
                cout << "Du har satsat: " << bet << " kr och ditt saldo är: " << saldo << endl;
                cout <<endl;
                villkor=false;
            }
			
    }
}

bool checkSvar(char n) 	//Funktion för att hålla spelet igång så länge man vill spela
{
    if (n != 'n')
    {
        return false;
    }
    else						
    {
        if (saldo != 0) {		// Kontroll av saldo, är det slut avslutas spelet
            cout << "Ditt resterande saldo på: " << saldo << " kr matas nu ut" << endl;
            cout << endl;
            cout << "Tack för att du ville spela Enarmad Bandit." << endl;
            
        }

        return true;
    }
    
}
