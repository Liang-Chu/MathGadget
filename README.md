# MathGadget Arduino Project

Welcome to the MathGadget Arduino project! This interactive program runs on an Arduino device and helps users perform various mathematical operations. You can also try it out in an online simulator: [MathGadget Simulator](https://wokwi.com/projects/381588157809932289)

## Author

- **Author:** Liam Chu

## Description/Instruction

The MathGadget Arduino program allows users to perform mathematical operations using a 4x4 keypad and a 16x2 LCD display. 
Here's the function of non-digital keys:

- **A (Enter):** Finds and displays a pair of prime numbers whose sum equals the input value
- **B (Delete):** Delete the last digit entered.
- **C (Reset):** Clear the display.
- **D (Next Prime):** Display the next prime number after the entered number.
- **# (Is Prime):** Check if the entered number is prime and display the result.
- **\* (Lock device):** Lock the device until it is clicked again.

# System Requirements

## Hardware Requirements

### 1. Arduino Uno Board

- **Type:** Arduino Uno
- **Model:** Official Arduino Uno board or compatible clones
- **Attributes:** Must support standard Arduino programming and be compatible with the required libraries.

### 2. Membrane Keypad

- **Type:** Membrane keypad
- **Model:** Wokwi Membrane Keypad
- **Attributes:** Should be connected to the Arduino Uno board as per the provided diagram.json file.

### 3. LCD Display

- **Type:** LCD1602
- **Model:** Wokwi LCD1602
- **Attributes:** Should be connected to the Arduino Uno board using I2C communication as per the provided diagram.json file.

## Software Requirements

### 1. Arduino IDE

- **Version:** Latest stable version
- **Download:** [Arduino IDE Download](https://www.arduino.cc/en/software)

### 2. Required Libraries

The following libraries should be installed in your Arduino IDE:

- **LiquidCrystal_I2C:** This library is required for interfacing with the LCD1602 display via I2C.
  - **Installation:** You can install this library from the Arduino Library Manager.
- **Keypad:** This library is necessary to interface with the membrane keypad.
  - **Installation:** You can install this library from the Arduino Library Manager.

## Connection Diagram

Make sure to connect the hardware components as per the provided diagram.json file. The connections are specified in the "connections" section of the file.

## Operating System Compatibility

MathGadget does not have specific operating system requirements as it runs directly on the Arduino Uno board. You can use any operating system (Windows, macOS, Linux) to program the Arduino board using the Arduino IDE.

## License

MathGadget is open-source software released under the MIT License. You are free to modify and distribute the code as per the terms of the MIT License.


## Building the Project

This project is designed to be run on an Arduino device. To build and upload the code to your Arduino, follow these steps:

1. Set up your Arduino development environment.
2. Create a new project and copy the MathGadget code into your Arduino IDE.
3. Connect your Arduino device to your computer via USB.
4. Select the appropriate board and port in the Arduino IDE.
5. Click the "Upload" button to compile and upload the code to your Arduino.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

Feel free to contribute or modify this project as needed. Enjoy using MathGadget for your mathematical operations!
