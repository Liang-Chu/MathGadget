#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <math.h>
// Global variables
char row_one[17] = ""; // First line content (8 characters + null terminator)
char row_two[17] = ""; // Second line content (8 characters + null terminator)

const unsigned long int MAX_NUM = 99999999;
//initialize the boolean area for prime numbers

// Set the LCD address to 0x27 for a 16 chars and 2-line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Keypad setup
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  // Initialize the LCD
  lcd.init();
  lcd.backlight();
  // Print a welcome message
  lcd.print("Enter number:");
}

bool needReset = false;
void loop() {
  char key = keypad.getKey();
  if (needReset) {
    reset();
    needReset = false;
  }
  if (key) {//ensure key is not empty


    switch (key) {
      case 'A': // A for enter
        calculate();
        needReset = true;
        break;
      case 'B': // B for delete
        deleteLast();
        break;
      case 'C': // C for reset
        reset();
        break;
      case 'D': // D for next prime
        displayNextPrime();
        break;

      case '#': // # for is prime
        if (isPrime(atol(row_one))) {

          strcpy(row_two, "Is a prime");
          break;
        }

        strcpy(row_two, "Is not a prime");
        break;
      case '*': //* for lock the device
        lock_device();
        break;
      default:
        if (isValid(key)) {
          char str[2]; // Create a temporary string to hold the character and null terminator
          str[0] = key; // Assign the character to the temporary string
          str[1] = '\0'; // Null-terminate the temporary string
          strncat(row_one, str, 1); // Concatenate the temporary string to row_one
        }
    }

    // Update the display with the user input
    updateDisplay();
  }
}


void lock_device() {
  char key ;
  while (true) {
    key = keypad.getKey();
    if (key == '*')
      return;
    // Program is locked, do nothing until it's pressed again
  }
}

// Function to display the next prime number

void displayNextPrime() {
  unsigned long int nextP = nextPrime( atol(row_one), MAX_NUM);
  if (nextP == -1) {
    strcpy(row_two, "out of range");
    return;
  }
  snprintf(row_one, sizeof(row_one), "%lu", nextP);
  strcpy(row_two, "is the next");
}

void reset() {
  // Add null terminators
  row_one[0] = '\0';
  row_two[0] = '\0';
}
// update teh display
void updateDisplay() {
  lcd.setCursor(0, 0);
  lcd.print("                ");//clear screen first
  lcd.setCursor(0, 0);
  lcd.print(row_one);
  lcd.setCursor(0, 1);
  lcd.print("                ");//clear screen first
  lcd.setCursor(0, 1);
  lcd.print(row_two);
}
void deleteLast() {
  if (strlen(row_one) != 0) { // Ensure the string is not empty
    row_one[strlen(row_one) - 1] = '\0'; // Replace the last character with null terminator
  }
}


bool isValid(char input) {
  if (strchr("0123456789", input) != nullptr && strlen(row_one) < 8) {
    return true;
  }
  // If not valid.
  if (strlen(row_one) >= 8) {
    strcpy(row_two, "MAX digits");

  }
  //do not do anything if undefined keys are pressed
  updateDisplay();
  return false;
}

void calculate() {
  unsigned long int inputValue = atol(row_one); // Get the digit value of input
  if (inputValue < 4) {
    strcpy(row_two, "Input too small");
    return;
  }
  if (inputValue % 2 == 1) {
    strcpy(row_one, "");
    strcpy(row_two, "Input is odd");
    return;
  }
  // Loop to find a pair of prime numbers with a sum equal to inputValue
  unsigned long int i = 2;
  unsigned long int cap = inputValue / 2;
  while (i <= cap ) {
    if (i == -1) {

      return; // Return if nextPrime returns -1
    }
    if (isPrime(i)) {
      unsigned long int complement = inputValue - i;
      if (isPrime(complement)) {
        // Found a pair of prime numbers with the sum of inputValue
        snprintf(row_one, sizeof(row_one), "Prime1: %lu", i);

        snprintf(row_two, sizeof(row_two), "Prime2: %lu", complement);
        return;
      }
    }
    i = nextPrime(i, cap);

  }

}


unsigned long int nextPrime(unsigned long int number, unsigned long int cap) {
  if (number < 2) {
    return 2; // The next prime after 0 or 1 is 2
  }

  unsigned long int next = number + 1;

  // Keep incrementing 'next' until a prime number is found or cap is reached
  while (next <= cap) {
    if (isPrime(next)) {
      return next;
    }
    next ++;
  }
  return -1;//return -1 if not found.
}


bool isPrime(unsigned long int number) {
  if (number < 2) {
    return false;
  }
  if (number <= 3) {//handle special cases to improve performance
    return true;
  }
  if (number % 2 == 0 || number % 3 == 0) {
    return false;
  }
  // start from 5 cause we will skip 4s with the stepping
  unsigned long int i = 5;
  unsigned long int step = 2;
  while (i * i <= number) {
    if (number % i == 0) {
      return false;
    }
    i += step;
    step = 6 - step; //toggle each "step" between 2 and 4 to reduce unnecessary calculation
  }
  return true;
}
