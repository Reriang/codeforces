<p align="center"><img src="./assets/lightning.jpg" width="150"><br><strong>⚡ Codeforces Runner ⚡</strong></p>

<p align="center"><em>"This project contains some problems in codeforces with solution written by Reriang."</em></p>

<p align="center">
<img src="https://img.shields.io/badge/codeforces-START-00eaff?style=for-the-badge&logo=codeforces">
<img src="https://img.shields.io/badge/NEOVIM-LIGHT_SPEED-39ff14?style=for-the-badge&logo=neovim&logoColor=white">
<img src="https://img.shields.io/badge/C++-Compile Succeed-8f00ff?style=for-the-badge&logo=cplusplus&logoColor=white">
</p>

## 📁 File Structure
```
/codeforces/
├── contests/
│    └── 2134/
│      ├── A/
│      ├── B/
│      └── ../
└── practices/
    ├── 1000/
    ├── 1100/
    └── ../
```

Each problems folder contains:
 - solution.cpp -> C++ solution to the problem
 - input.txt -> Sample input test cases
 - expected.txt -> Expected output for the test cases

## 🚀 Getting Started
1. Clone this repository.
```bash
git clone https://github.com/Reriang/codeforces.git
cd codeforces
```

2. Run a solution
```bash
g++ solution.cpp -o solution
./solution < input.txt > output.txt
diff expected.txt output.txt
```
This will compare the program's output with the expected output.

3. Using with my NeoVim setup
   - Open a problem:
```bash
nvim <problemID>
```
   - In normal mode:
     - `CTRL+A` -> Compile & run the solution
     - `CTRL+C` -> Check if your solution passes the test cases 

## 📌 Notes
 - Solutions are written in C++23 (unless otherwise specified).
 - Input/Output files follow Codeforces format.
