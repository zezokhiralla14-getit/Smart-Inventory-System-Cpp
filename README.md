# Smart Inventory Management System (C++)

A robust, terminal-based **Smart Inventory Management System** built from scratch using Modern C++ (C++11/17). This project showcases core software engineering principles, including **Object-Oriented Programming (OOP)**, **Data Persistence**, and a modular **Multi-File Architecture**.

The system is designed to simulate a real-world inventory database with robust input validation, dynamic memory management, and file-based storage.

---

## 🚀 Key Features

- **Dynamic Product Control:** Add, display, search, edit, and delete products seamlessly.
- **Robust Input Validation:** Prevents duplicate Product IDs and handles invalid menu inputs gracefully.
- **Data Persistence (File I/O):** Automatically saves inventory states to a local flat-file database (`inventory.txt`) and loads them on application startup.
- **Low-Stock Detection:** An automated utility that scans and alerts the operator of products with low quantities (threshold-based).
- **Clean Command-Line Interface (CLI):** Interactive, user-friendly menu loop.

---

## 🏗️ Architecture & Engineering Best Practices

This project was built with a strong focus on clean code and system design:

1. **Multi-File Project Structure:** Separated declarations (`.hpp`) from implementations (`.cpp`) to optimize compile times, prevent linking errors, and achieve high code maintainability.
2. **Separation of Concerns (SoC):** - `Product` class manages individual product states.
   - `Inventory` class manages collection operations and file transactions (Business Logic).
   - `main.cpp` handles the UI presentation and user interactions.
3. **Encapsulation:** Attributes are kept private, exposing modification and access only through controlled public getters/setters and methods.
4. **Header Guards:** Implemented `#ifndef` and `#define` guards across all header files to prevent circular dependencies and multiple definition compilation issues.

---

## 🛠️ Tech Stack & Concepts Used

- **Language:** C++ (C++11/C++17)
- **Data Structures:** `std::vector` for dynamic array management.
- **File I/O:** `std::ifstream` and `std::ofstream` for file-based database handling.
- **Compilation:** Manual multi-file compiling using `g++`.

---

## 📂 File Directory

```text
├── main.cpp          # Application Entry Point & Menu UI Loop
├── Product.hpp       # Product Class Declaration (Headers)
├── Product.cpp       # Product Class Implementation
├── Inventory.hpp     # Inventory Class Declaration & File Helpers
├── Inventory.cpp     # Inventory Class Implementation (Business Logic)
└── .gitignore        # Specifies intentionally untracked files to ignore

```
---

## ⚡How to Build & Run

**Prerequisites**

Make sure you have a C++ compiler (like g++) installed on your machine.

**1. Compile the Project**

Open your terminal in the project directory and run:

g++ main.cpp Inventory.cpp Product.cpp -o program

**2. Run the Application**

On Windows:

.\program

On macOS / Linux:

./program

---

## 🧠 Future Roadmap & Learning Outcomes

[ ] Implement Sorting Algorithms (sort products by price/quantity).

[ ] Migrate the flat-file storage to an SQLite database.

[ ] Add categories/tags for better product filtering.
