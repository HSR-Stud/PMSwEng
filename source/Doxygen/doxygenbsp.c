/**
 * @file TuerschlossNFC.ino
 * @author Luca Mazzoleni
 * @brief  Doorlock with Keypad and NFC
 *
 *  Board: Arduino Leonardo \n
 *  Library: \link{https://blabla.com\endlink \n
 */

/* Includes */
#include <Adafruit_PN532.h>

//set MACROS
/**Keypad Nr. 0 Pin 2*/
#define button0  (2)
//....

/**Check Adafruit library for more Information
 * @param PN532_SCK Serial Clock
 * @param PN532_MISO Master Input, Slave Outpu
 * @param PN532_MOSI Master Output, Slave Input
 * @param PN532_SS Slave Select
 */
Adafruit_PN532 nfc(PN532_SCK,
                   PN532_MISO,
                   PN532_MOSI,
                   PN532_SS);

//set Global Variable
 /**Initialize a Array for the Inputs*/
 char inputCode[maxIN];

//=============================================================================
 void setup()
 {
   //....do setup Code...
 }

 void loop()
 {
    void checkCode(int p);
    //.....do LOOP Code...
 }

void checkCode(int p)
/** @brief Check if Code is correct
*
* Check if input code is the same as the secret code
* @param p Count of pressed Buttons
* @return Void
*/
{
  //....do checkCode...
}
