# C++ for Financial Engineering

![C++](https://img.shields.io/badge/C%2B%2B-17-blue.svg)
![Build](https://img.shields.io/badge/build-CMake-informational.svg)
![Status](https://img.shields.io/badge/status-in%20progress-yellow.svg)

My coursework and projects for the **C++ Programming for Financial Engineering** course (Baruch). The repository goes from core language fundamentals to implementing option pricing models in modern C++.

---

## Repository Structure

```
.
├── Basics/
│   ├── ...                 # Language fundamentals, classes, templates, STL
│   └── README.md
├── Option Pricing/
│   ├── ...                 # Pricing models and numerical methods
│   └── README.md
├── .gitignore
└── README.md
```

### 📁 Basics

Core C++ concepts built up through exercises and small programs:

- Types, control flow, functions, and references/pointers
- Classes, constructors/destructors, encapsulation
- Inheritance, polymorphism, and virtual functions
- Templates (class and function templates)
- Operator overloading
- STL containers and algorithms
- Header/source organization and the build process

### 📁 Option Pricing

Applying the fundamentals to quantitative finance:

- Black-Scholes closed-form pricing for European options
- Greeks (Delta, Gamma, Vega, Theta, Rho)
- Binomial tree methods
- Monte Carlo simulation
- Finite difference methods (explicit / implicit schemes)
- Put-call parity checks and model comparison

> Update these lists as you complete each topic. Remove anything the course doesn't cover.

---

## Getting Started

### Prerequisites

- A C++17 compatible compiler (GCC 9+, Clang 10+, or MSVC 2019+)
- [CMake](https://cmake.org/) 3.15+ (optional, if a folder includes a `CMakeLists.txt`)

### Clone the repo

```bash
git clone https://github.com/enriquecalixto49-droid/CPP_FFE.git
cd CPP_FFE.git
```

### Build and run a single file

```bash
g++ -std=c++17 -Wall -Wextra -O2 main.cpp -o main
./main
```

### Build with CMake

```bash
mkdir build && cd build
cmake ..
cmake --build .
```

On Windows with MSVC, use `cmake --build . --config Release`.

---

## Example: European Call (Black-Scholes)

```cpp
double call = BlackScholes::call(S, K, r, sigma, T);
```

| Parameter | Meaning               |
|-----------|-----------------------|
| `S`       | Spot price            |
| `K`       | Strike                |
| `r`       | Risk-free rate        |
| `sigma`   | Volatility            |
| `T`       | Time to maturity (yrs)|

---

## Roadmap

- [ ] Basics: very basics and OOP
- [ ] Basics: templates, STL & Boost 
- [ ] Option Pricing: Black-Scholes & Greeks
- [ ] Option Pricing: binomial trees
- [ ] Option Pricing: Monte Carlo
- [ ] Option Pricing: finite difference methods

---

## Notes

- Code follows the course exercises but is written and organized by me.

## References

- Course materials: *C++ Programming for Financial Engineering* (Baruch)
- D. Duffy, *Introduction to C++ for Financial Engineers*
- J. Hull, *Options, Futures, and Other Derivatives*
- [cppreference.com](https://en.cppreference.com/)

