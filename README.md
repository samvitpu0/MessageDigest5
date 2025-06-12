# 🔐 MD5 Hash Generator in C++

A simple and educational C++ implementation of the MD5 hashing algorithm, which reads input from a file, processes it, and outputs its MD5 hash. Designed as a low-level exploration of cryptographic hashing fundamentals without using external libraries.

---

## 📌 Features

- Manual implementation of the MD5 hashing algorithm  
- Demonstrates 4 rounds of transformation (F, G, H, I functions)  
- Handles file input and block-based hashing  
- Highlights core C++ concepts: bitwise ops, classes, memory management  

---

## 🛠️ How It Works

This project simulates how the MD5 hashing algorithm functions internally:
1. Initializes 128-bit values (A, B, C, D)  
2. Processes input through four rounds of nonlinear functions (F, G, H, I)  
3. Applies left rotations and message chunking  
4. Combines the values into a final hash output  

> **Note:** This is a learning-based implementation and may not support full RFC-compliant MD5 output for arbitrary-length files.

---

## 📷 Sample Output

```bash
Input: <your string here or padded file block>
Output: MD5 of message is : 3f45acfe9d5a5d12e8f3e234ac774632
