#include <iostream> 
#include <iomanip> 
#include <cstdlib>
#include <ctime>
using namespace std;

int rollDice(); 

int main()
{
   setlocale(LC_ALL,"Russian");
   enum Outcome { CONTINUE, WIN, LOSE };
   const int SIZE = 22;
   const int ROLLS = 1000;
   int gameStatus;
   int sum;
   int myPoint;
   int roll;
   int length = 0;
   int wins[ SIZE ] = {};
   int losses[ SIZE ] = {};
   int winSum = 0; 
   int loseSum = 0;

   srand( time( 0 ) );
   
 
   for ( int i = 1; i <= ROLLS; i++ ) 
   {
      sum = rollDice();
      roll = 1;
	
      
      switch ( sum ) 
      {
         case 7: case 11:
            gameStatus = WIN;
            break;
         case 2: case 3: case 12:
            gameStatus = LOSE;
            break;
         default:
            gameStatus = CONTINUE;
            myPoint = sum;
            break;
      } 
	
      
      while ( gameStatus == CONTINUE ) 
      {
         sum = rollDice();
         roll++;

         if ( sum == myPoint )
            gameStatus = WIN;
         else if ( sum == 7 )
            gameStatus = LOSE;
      }	

     
      if ( roll > 21 )
         roll = 21;

      if ( gameStatus == WIN ) 
      {
         wins[ roll ]++;
         winSum++;
      } // end if
      else 
      {
         losses[ roll ]++;
         loseSum++;
      } 
   } 
   
   cout << "Ігри, виграв він чи програв після 20-рол" 
      << "\n відображаються у вигляді 21-рол.\n\n";

   
   for ( int z = 1; z <= 21; ++z ) 
      cout << setw( 3 ) << wins[ z ] << " виграних ігор і" << setw( 3 )
         << losses[ z ] << " гри lost on / roll " << z << '\n';
   
  
   cout << fixed << showpoint << "\nШанси на перемогу " << winSum 
      << " / " << winSum + loseSum << " = " << setprecision( 2 )
      << 100.0 * winSum / ( winSum + loseSum ) << "%\n";
   
 
   for ( int k = 1; k <= 21; k++ )
      length += wins[ k ] * k + losses[ k ] * k;

   cout << "Середня довжина ігри " << setprecision( 2 )
      << length / 1000.0 << " rolls." << endl;
   system("pause");
} 

int rollDice()
{
   int die1 = 1 + rand() % 6;
   int die2 = 1 + rand() % 6;
   return die1 + die2; 
} 
