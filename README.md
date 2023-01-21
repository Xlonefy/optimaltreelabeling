# Optimal Tree Labeling

This is the one implementation of the Optimal Tree Labeling problem as proposed by Hang Zhou (zhouhang32@gmail.com). 

This project was executed by João Marques Andreotti (joao.marques-andreotti@polytechnique.edu) and Guilherme Vieira Manhaes (guilherme.vieira-manhaes@polytechnique.edu) in the scope of the INF421 - _Conception et analyse d'algorithms_ - 2022/2023.

The solution to the problem runs in $O(n)$ time complexity and $O(n)$ space complexity, where $n$ is the number of vertices of the tree. 

This procedure stores the Tree in an adjacency list and makes use of a recursive greedy algorithm to solve the challenge. It outputs the optimal cost of the Tree and it calculates at least one optimal labeling possibility. More information about this can be found in the report (link not available for now).

## Running

To run the input files (stored in the `input` folder): 
```bash
bash ./run ;
```

Or, if you want to run the script properly:
```bash
chmod +x ./run;
./run
```

## Compiling
When running all the tests, the program will compile directly, but if you want to compile it by yourself: 
```bash
make;
```

To create your own makefile (that can be optimized for your system), run: 
```bash
mkdir build;
cd build;
cmake ..;
```


## Entrypoint

The main entrypoint for the project is the `main.cc` file.

After compiling, you can execute the program with: 

```bash
./main <FILENAME>
```

Where FILENAME indicates the path to the desired input file.
