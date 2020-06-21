/******************************************************************************/
/* User Level #define Macros                                                  */
/******************************************************************************/


#define CMP1_PIN        RA0
#define CMP2_PIN        RA1
#define VREF_PIN        RA2

#define MAX_REACHED_LED RA3
#define MIN_REACHED_LED RA4

#define LIGHT_ON        0
#define LIGHT_OFF       1


#define AUTOVOLUME      RA5

#define IS_PRESSED         0
#define IS_UNPRESSED       1


/* TODO Application specific user parameters used in user.c may go here */

/******************************************************************************/
/* User Function Prototypes                                                   */
/******************************************************************************/

/* TODO User level functions prototypes (i.e. InitApp) go here */

void InitApp(void);         /* I/O and Peripheral Initialization */
