# 🧮 **Mega Matrix Mania** — Advanced Terminal Matrix Calculator in C

A robust matrix manipulation program written in **pure C**, designed to perform essential and advanced linear algebra operations including determinant, inverse, rank, row echelon form, scalar multiplication, and more — right from your terminal interface with **safety-first input mechanisms** and **vibrant ANSI-styled output**.

> 🛠️ This project was developed as a part of **B.Tech (Engineering)** coursework at **Shah & Anchor Kutchhi Engineering College**, Mumbai by **Anvay Mayekar** for subject **Problem Solving and Programming with C**, with a focus on modular design, efficient matrix handling, and real-world C programming principles.

---

## 📌 Highlights & Safety Notes

> ⚠️ All input is thoroughly validated via dedicated functions (`get_choice`, `get_scalar`) that prevent segmentation faults, malformed input like `3..3`, alphabets, or overflow issues.
> 🧠 All floating-point values are **truncated with a warning**, not rounded.
> 🔂 **Row Echelon Form** logic is **purely iterative** — no recursion used, ensuring memory safety and performance.
> 🖥️ Terminal outputs are color-coded for better readability.

---

## 📁 File Structure

```
mega-matrix-mania/
├── main.c                  // 🧠 Entry point with menu logic
├── matrix.c                // 🧮 All matrix operations (det, adj, inv, etc.)
├── io.c                    // 🔢 Matrix input/output handler
├── utils.c                 // 🧰 Delay, title display, and terminal colors
├── proto.h                 // 📚 All function declarations (merged header)
├── io.h                    // ✍️ I/O-related function declarations
├── utils.h                 // 🎨 Macros for color, delay, and max matrix size
├── mega-matrix-mania.exe   // 🟩 Compiled Windows executable
└── README.md               // 📘 This file
```

---

## ⚙️ Features & Operations

### ✅ Supported Matrix Operations

| Option | Operation             |
| ------ | --------------------- |
| 0      | Change Matrix Order   |
| 1      | Display Matrix        |
| 2      | Transpose             |
| 3      | Scalar Multiplication |
| 4      | Matrix Multiplication |
| 5      | Determinant           |
| 6      | Adjoint               |
| 7      | Inverse               |
| 8      | Identity Check        |
| 9      | Cofactor Matrix       |
| 10     | Row Echelon Form      |
| 11     | Rank                  |
| 12     | Exit                  |

---

## 🧰 Tools & Technologies Used

![C](https://img.shields.io/badge/C_language-00599C?style=for-the-badge\&logo=c\&logoColor=white)
![GCC](https://img.shields.io/badge/GCC-gnu%20compiler-blue?style=for-the-badge\&logo=gnu\&logoColor=white)
![Windows](https://img.shields.io/badge/Windows-Supported-blue?style=for-the-badge\&logo=windows\&logoColor=white)
![Linux](https://img.shields.io/badge/Linux-Compatible-yellowgreen?style=for-the-badge\&logo=linux\&logoColor=white)
![ANSI Terminal](https://img.shields.io/badge/Terminal-ANSI_Colors-lightgrey?style=for-the-badge)

---

## 🧱 C Libraries Used

```c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <windows.h>
#include <unistd.h> // for UNIX

```

> ⚠️ No external libraries used. All logic is handwritten in standard ANSI C.

---

## 🔐 Input Safety Features

✔️ **get\_choice()**
→ Accepts 1 or 2 inputs like `3` or `3 3`
→ Rejects alphabets, symbols, and malformed input (`3..2`)
→ Provides truncation warnings for decimals (e.g., `2.7` → `2`)
→ Validates value range (`1–10`) or custom via `del` variable

✔️ **get\_scalar()**
→ Accepts any real number input (e.g., `-2.5`, `0`, `123`)
→ Rejects invalid or non-numeric entries safely

✔️ **input\_matrix()**
→ Only triggered after valid dimension entry
→ Ensures each matrix element is a valid number (float)

✔️ **Row Echelon**
→ Uses pure **iteration**, not recursion, for efficiency and safety

---

## 🧾 Compilation Instructions

### 🪟 On Windows:

```bash
gcc main.c matrix.c io.c utils.c -o mega-matrix-mania.exe -lm
mega-matrix-mania.exe
```

### 🐧 On Linux/macOS:

```bash
gcc main.c matrix.c io.c utils.c -o mega-matrix-mania -lm
./mega-matrix-mania
```

> 🧠 Make sure `gcc` is installed. Use `sudo apt install gcc` (Linux) or MinGW (Windows).

---

## 🖼️ Output Sample

```
=== Matrix Operations ===

1. Display Matrix
2. Transpose
...
12. Exit

Choice: 5
Enter matrix order (n): 3
Enter matrix elements:
[1 2 3]
[0 1 4]
[5 6 0]

Determinant: 1.00
```
---

## ⚖️ License
This project is licensed under the [MIT License](https://opensource.org/licenses/MIT).  
You are free to use, modify, and distribute this software with proper attribution.

---

## 👨‍💻 Author

> **Anvay Mayekar**
> 🎓 B.Tech in Electronics & Computer Science — SAKEC
>
>[![GitHub](https://img.shields.io/badge/GitHub-181717.svg?style=for-the-badge\&logo=GitHub\&logoColor=white)](https://www.github.com/anvaymayekar)
[![LinkedIn](https://img.shields.io/badge/LinkedIn-0A66C2.svg?style=for-the-badge\&logo=LinkedIn\&logoColor=white)](https://in.linkedin.com/in/anvaymayekar)
[![Instagram](https://img.shields.io/badge/Instagram-%23E4405F.svg?style=for-the-badge\&logo=Instagram\&logoColor=white)](https://www.instagram.com/anvaymayekar)

---
