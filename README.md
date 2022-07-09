# Raytracer
<p align="center">
  <img src="https://github.com/M-Komorek/Raytracer/blob/main/screen/tested_scene.png?style=centerme">
</p>
Simple C++ project for rendering images using ray tracing. The ray tracing algorithm has been implemented in two different versions: single-threaded and multi-threaded. In the case of the multithreaded version, two different technologies were used, such as OpenMp and the usual asynchronous calls from the C++ standard library (see branch multi_open_MP and multi_std_async).

## Performance analysis

### Testing environment
All tests were performed on two hardware configurations. The same software configuration was on both hardware configurations.

| Cluster | Intel i7 | Intel i9 |
| --- | --- | --- |
| Processor | Intel Core i7-7500U (Cores: 2 Threads: 4) |  Intel Core i9-11900 (Cores: 8 Threads: 16) |
| Graphics Card | NVIDIA GeForce 940MX | None |

| Cluster | Intel i7 | Intel i9 |
| ---  | --- | --- |
| Operating System | Ubuntu 18.04 | Ubuntu 18.04 |
| C++ Version | C++17 | C++17 |
| Compiler | GNU Compiler Collection 9.4.0 | GNU Compiler Collection 9.4.0 |
| OpenMp vesrion | 5.1 | 5.1 |


### Results
The time complexity measure was used to evaluate the efficiency of the implemented ray tracing algorithm. The time required to execute a single-threaded CPU program is defined as:
$$t_S = t_O + F_P W_L(S)$$
where $t_O$ is the time introduced by the non-deterministic overhead of the operating system due to the fact that at any point in time the operating system can perform tasks necessary for proper operation, $F_P$ is the floating-point operation time of the processor, and $W_L(S)$ is the total scene-dependent workload specified as follows:
$$W_L(S) = \sum_{i=0}^{I_H} \sum_{j=0}^{I_W} g(S, x_j, y_i)$$
where:
- $I_H$ is the height of the rendered image,
- $I_W$ is the width of the rendered image,
- $g(S,x_i,y_j)$ is a function that defines the computational load depending on the scene $S$ and the specific pixel ($x_j, y_i$) of the image.

The relationship describing the time needed to execute a multi-threaded CPU program on $N$ threads is defined as:
$$t_M = t_O + \frac{F_P W_L(S)}{N} + t_H$$
where $t_H$ is the total central processing unit time spent on threads handling. Due to the non-deterministic component $t_O$ present in the definitions of equations $t_S$ and $t_M$, averaged time measurements were introduced. Average execution time of a program running on single thread is specified as:
$$T_S = \frac{\sum_{i=1}^{10}{t_{Si}}}{10}$$
and average execution time of a program running on multi-threads:
$$T_M = \frac{\sum_{i=1}^{10}{t_{Mi}}}{10}$$
Finally, based on the equations $T_S and $T_M$ the formula for the acceleration could be defined as follows:
$$S_M = \frac{T_S}{T_M}$$

<p align="center">
  <img src="https://github.com/M-Komorek/Raytracer/blob/main/screen/speed_up.png?style=centerme">
</p>

In another test, image rendering using the same ray tracing algorithm using the graphics card was added to the comparison (represented as $T_G$ in the graph). It was also checked how the increase in the resolution of the rendered image affects the performance.

<p align="center">
  <img src="https://github.com/M-Komorek/Raytracer/blob/main/screen/resolution.png?style=centerme">
</p>

### Conclusions
The conducted tests lead to the following conclusions:
- Skillful implementation of parallel computing leads to an increase in the efficiency of the algorithm.
- In the context of parallel computing, the CPU cannot compete with the GPU. The results of the much older NVIDIA GeForce 940MX (year of introduction 2016) outperformed the modern Intel i9 processor (year of introduction 2021).
- In the case of the central processing unit, increasing the number of compute units (threads) significantly improves the performance of the algorithms, the critical point is the number of physical threads in the CPU from that point on, there is no visible improvement.

## Run Locally

Clone the project:

```bash
  git clone https://github.com/M-Komorek/Raytracer.git
```

Go to the project directory and compile code:

```bash
  cd Raytracer
  ./compile.sh
```

Rander image:

```bash
  ./build/Raytracer > image.ppm
```

## Running Tests

To run tests, run the following command:

```bash
  ./compileAndTest.sh
```

## Tech Stack

C++17 - https://en.cppreference.com/w/cpp/17

OpenMp - https://www.openmp.org/

Google Test - https://github.com/google/googletest

CMake - https://cmake.org/
