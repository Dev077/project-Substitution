# Substitution Cipher Program

This C program encrypts and decrypts messages using the substitution cipher technique. The substitution cipher involves replacing each plaintext character with another character based on a given key.

## Table of Contents

- [Description](#description)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
- [Features](#features)
- [How to Compile](#how-to-compile)
- [Input Validation](#input-validation)
- [Sample Output](#sample-outputs)
- [Contributing](#contributing)

## Description <a name="description"></a>

This C program provides functionalities to encrypt and decrypt messages based on a substitution key provided by the user. It offers a command-line interface for user interaction and performs input validation to ensure the key meets specific criteria.

## Getting Started <a name="getting-started"></a>

### Prerequisites <a name="prerequisites"></a>

To compile and run this program, ensure you have a C compiler installed. If not, install GCC (GNU Compiler Collection) or any other C compiler compatible with your operating system.

### Installation <a name="installation"></a>

1. Clone the repository:

    ```bash
    git clone https://github.com/your-username/substitution-cipher.git
    ```

2. Navigate to the directory:

    ```bash
    cd substitution-cipher
    ```

3. Compile the code:

    ```bash
    gcc -o substitution substitution.c
    or make substitution 
    ```

## Usage <a name="usage"></a>

Run the program with the following command:

```bash
./substitution key
```

## Features

- **Encryption**: Converts plaintext messages into ciphertext using the provided substitution key.
- **Decryption**: Converts ciphertext back into plaintext using the same key.
- **Input Validation**: Ensures the key meets specific criteria:
  - Contains 26 characters
  - Consists only of alphabetic characters without duplicates

## Input Validation

The program performs multiple checks on the provided key to ensure its validity:

- User provides a single command-line argument (the substitution key).
- The substitution key contains 26 characters.
- The substitution key consists only of alphabetic characters without duplicates.
- User inputs 1 for encryption and 2 for decryption.

## Sample Output

### Encrypting a Message

#### Command:

```bash
./substitution qwertyuiopasdfghjklzxcvbnm
Plaintext = Hello, world!
Ciphertext: Itssg, vgksr!
```

### Decrypting a Message
```bash
./substitution qwertyuiopasdfghjklzxcvbnm
Ciphertext = Itssg, vgksr!
Plaintext: Hello, world!
```

## Contributing
Contributions are welcome! If you have suggestions, improvements, or bug fixes, please feel free to open an issue or create a pull request.

##



