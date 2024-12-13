## 💨 ATmega128 Fan Control Project

This project uses an **ATmega128 microcontroller** to implement a fan control system. The system manages fan speed and operation based on various input conditions and user controls. It includes peripheral drivers, application logic, and real-time functionality.

---

### 🔄 Features

1. **Fan Speed Control**:
   - Control fan speed using Pulse Width Modulation (PWM).

2. **Button Controls**:
   - Start, stop, and adjust fan speed using buttons.

3. **LCD Display**:
   - Display current fan status, speed, and mode on an LCD screen.

4. **Real-Time Monitoring**:
   - Monitor system status and display real-time feedback.

---

### 🛠️ Hardware Used

- **ATmega128 Microcontroller**
- **DC Fan**
- **16x2 LCD Display**
- **Push Buttons** (for controlling fan speed and power)
- **PWM Control Circuit**
- **Power Supply**

---

### 📖 Installation and Setup

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/yourusername/atmega128-fan-project.git
   cd atmega128-fan-project
   ```

2. **Open the Project in AVR Studio/Atmel Studio**:
   - Open `Fan_Project.atsln` in Atmel Studio.

3. **Compile and Upload**:
   - Compile the project and upload the hex file to the ATmega128 microcontroller.

---

### 📚 Project Structure

```
Fan_Project/
|
├── ap/                    # Application code
├── driver/                # Driver code for peripherals
├── periph/                # Peripheral control code
├── main.c                 # Main source file
├── Fan_Project.cproj      # Project configuration file
└── Fan_Project.atsln      # Atmel Studio solution file
```

---

### 🛠️ Key Code Snippets

**Fan Speed Control (PWM) in `main.c`**:

```c
#include <avr/io.h>

void pwm_init() {
    // Set PWM mode and prescaler
    TCCR0 = (1 << WGM00) | (1 << WGM01) | (1 << COM01) | (1 << CS01);
    DDRB |= (1 << PB3); // Set PB3 as output for PWM
}

void set_fan_speed(uint8_t speed) {
    OCR0 = speed; // Set PWM duty cycle
}

int main() {
    pwm_init();
    while (1) {
        set_fan_speed(128); // Example: Set fan speed to 50%
    }
}
```

---

### 🌟 Contributing

Contributions are welcome! Feel free to submit issues or pull requests.

---

### 👇 Let's Connect!

[![GitHub](https://img.shields.io/badge/GitHub-Profile-blue?logo=github)](https://github.com/yourusername)

